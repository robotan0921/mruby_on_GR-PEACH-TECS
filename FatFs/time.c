/* musl-1.1.12/src/time/*.c */
/* musl as a whole is licensed under the following standard MIT license:
*
* ----------------------------------------------------------------------
* Copyright (C) 2005-2014 Rich Felker, et al.
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
* ----------------------------------------------------------------------*/
#include <string.h>
#include <limits.h>
#include <time.h>
#include <errno.h>
#include "ff.h"

/* 2000-03-01 (mod 400 year, immediately after feb29 */
#define LEAPOCH (946684800LL + 86400*(31+29))

#define DAYS_PER_400Y (365*400 + 97)
#define DAYS_PER_100Y (365*100 + 24)
#define DAYS_PER_4Y   (365*4   + 1)

int __secs_to_tm(long long t, struct tm* tm)
{
	long long days, secs, years;
	int remdays, remsecs, remyears;
	int qc_cycles, c_cycles, q_cycles;
	int months;
	int wday, yday, leap;
	static const char days_in_month[] = {31,30,31,30,31,31,30,31,30,31,31,29};

	/* Reject time_t values whose year would overflow int */
	if (t < INT_MIN * 31622400LL || t > INT_MAX * 31622400LL)
		return -1;

	secs = t - LEAPOCH;
	days = secs / 86400;
	remsecs = secs % 86400;
	if (remsecs < 0) {
		remsecs += 86400;
		days--;
	}

	wday = (3 + days) % 7;
	if (wday < 0) wday += 7;

	qc_cycles = days / DAYS_PER_400Y;
	remdays = days % DAYS_PER_400Y;
	if (remdays < 0) {
		remdays += DAYS_PER_400Y;
		qc_cycles--;
	}

	c_cycles = remdays / DAYS_PER_100Y;
	if (c_cycles == 4) c_cycles--;
	remdays -= c_cycles * DAYS_PER_100Y;

	q_cycles = remdays / DAYS_PER_4Y;
	if (q_cycles == 25) q_cycles--;
	remdays -= q_cycles * DAYS_PER_4Y;

	remyears = remdays / 365;
	if (remyears == 4) remyears--;
	remdays -= remyears * 365;

	leap = !remyears && (q_cycles || !c_cycles);
	yday = remdays + 31 + 28 + leap;
	if (yday >= 365 + leap) yday -= 365 + leap;

	years = remyears + 4 * q_cycles + 100 * c_cycles + 400LL * qc_cycles;

	for (months = 0; days_in_month[months] <= remdays; months++)
		remdays -= days_in_month[months];

	if (years + 100 > INT_MAX || years + 100 < INT_MIN)
		return -1;

	tm->tm_year = years + 100;
	tm->tm_mon = months + 2;
	if (tm->tm_mon >= 12) {
		tm->tm_mon -= 12;
		tm->tm_year++;
	}
	tm->tm_mday = remdays + 1;
	tm->tm_wday = wday;
	tm->tm_yday = yday;

	tm->tm_hour = remsecs / 3600;
	tm->tm_min = remsecs / 60 % 60;
	tm->tm_sec = remsecs % 60;

	return 0;
}

long long __year_to_secs(long long year, int *is_leap)
{
	if (year - 2ULL <= 136) {
		int y = year;
		int leaps = (y - 68) >> 2;
		if (!((y - 68) & 3)) {
			leaps--;
			if (is_leap) *is_leap = 1;
		}
		else if (is_leap) *is_leap = 0;
		return 31536000 * (y - 70) + 86400 * leaps;
	}

	int cycles, centuries, leaps, rem;

	if (!is_leap) is_leap = &(int) { 0 };
	cycles = (year - 100) / 400;
	rem = (year - 100) % 400;
	if (rem < 0) {
		cycles--;
		rem += 400;
	}
	if (!rem) {
		*is_leap = 1;
		centuries = 0;
		leaps = 0;
	}
	else {
		if (rem >= 200) {
			if (rem >= 300) centuries = 3, rem -= 300;
			else centuries = 2, rem -= 200;
		}
		else {
			if (rem >= 100) centuries = 1, rem -= 100;
			else centuries = 0;
		}
		if (!rem) {
			*is_leap = 0;
			leaps = 0;
		}
		else {
			leaps = rem / 4U;
			rem %= 4U;
			*is_leap = !rem;
		}
	}

	leaps += 97 * cycles + 24 * centuries - *is_leap;

	return (year - 100) * 31536000LL + leaps * 86400LL + 946684800 + 86400;
}

int __month_to_secs(int month, int is_leap)
{
	static const int secs_through_month[] = {
		0, 31 * 86400, 59 * 86400, 90 * 86400,
		120 * 86400, 151 * 86400, 181 * 86400, 212 * 86400,
		243 * 86400, 273 * 86400, 304 * 86400, 334 * 86400};
	int t = secs_through_month[month];
	if (is_leap && month >= 2) t += 86400;
	return t;
}

long long __tm_to_secs(const struct tm *tm)
{
	int is_leap;
	long long year = tm->tm_year;
	int month = tm->tm_mon;
	if (month >= 12 || month < 0) {
		int adj = month / 12;
		month %= 12;
		if (month < 0) {
			adj--;
			month += 12;
		}
		year += adj;
	}
	long long t = __year_to_secs(year, &is_leap);
	t += __month_to_secs(month, is_leap);
	t += 86400LL * (tm->tm_mday - 1);
	t += 3600LL * tm->tm_hour;
	t += 60LL * tm->tm_min;
	t += tm->tm_sec;
	return t;
}

struct tm *localtime_r(const time_t *t, struct tm *tm)
{
	/* Reject time_t values whose year would overflow int because
	* __secs_to_zone cannot safely handle them. */
	if (*t < INT_MIN * 31622400LL || *t > INT_MAX * 31622400LL) {
		errno = EOVERFLOW;
		return 0;
	}
	//TODO:__secs_to_zone(*t, 0, &tm->tm_isdst, &tm->__tm_gmtoff, 0, &tm->__tm_zone);
	if (__secs_to_tm((long long)*t /*+ tm->__tm_gmtoff*/, tm) < 0) {
		errno = EOVERFLOW;
		return 0;
	}
	return tm;
}

struct tm *localtime(const time_t *time)
{
	static struct tm tm;
	return localtime_r(time, &tm);
}

struct tm *gmtime_r(const time_t *t, struct tm *tm)
{
	if (__secs_to_tm(*t, tm) < 0) {
		errno = EOVERFLOW;
		return 0;
	}
	tm->tm_isdst = 0;
	/*tm->__tm_gmtoff = 0;
	tm->__tm_zone = NULL;//__gmt;*/
	return tm;
}

/* There is no other implemented value than TIME_UTC; all other values
 * are considered erroneous. */
/*int timespec_get(struct timespec * ts, int base)
{
	if (base != TIME_UTC) return 0;
	int ret = __clock_gettime(CLOCK_REALTIME, ts);
	return ret < 0 ? 0 : base;
}*/
time_t mktime(struct tm *tm)
{
	struct tm new;
	long opp;
	long long t = __tm_to_secs(tm);

	if (__secs_to_tm(t, &new) < 0) goto error;

	*tm = new;
	return t;

error:
	errno = EOVERFLOW;
	return -1;
}

DWORD get_fattime(void)
{
	time_t temp;
	struct tm _tm;

	time(&temp);
	gmtime_r(&temp, &_tm);

	return	  ((DWORD)(_tm.tm_year - 1980) << 25)
		| ((DWORD)_tm.tm_mon << 21)
		| ((DWORD)_tm.tm_mday << 16)
		| ((DWORD)_tm.tm_hour << 11)
		| ((DWORD)_tm.tm_min << 5)
		| ((DWORD)_tm.tm_sec >> 1);
}
