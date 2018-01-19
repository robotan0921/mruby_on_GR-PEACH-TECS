/*
 *  TOPPERS ECHONET Lite Communication Middleware
 * 
 *  Copyright (C) 2014-2017 Cores Co., Ltd. Japan
 * 
 *  上記著作権者は，以下の(1)～(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 * 
 */

/* 
 *  サンプルプログラム(1)の本体
 */

#include <kernel.h>
#include <stdlib.h>
#include <string.h>
#include "t_stdlib.h"
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "diskio.h"
#include "sdfs.h"
#include "ff.h"
#include "tlsf.h"
// #include "ntstdio.h"

#define SIO_PORTID 1
// extern ntstdio_t ntstdio;

// static tlsf_t sys_tlsf;
// static pool_t sys_pool;
static uint64_t mem_pool[64 * 1024];

// uint32_t  __HeapBase;
// uint32_t  __HeapLimit;
FATFS RomDisk;

gpio_t ins;
sdfs_t sdfs;
#define WP() false

typedef struct SD {
	DSTATUS dst;
	BYTE type;
	FATFS FatFs;
} SD;
SD Sd;

void sys_init(void);
bool_t romdisk_init();
bool_t SD_begin();


void initialize_fatfs()
{
	mruby_arduino_init();
}

int mruby_arduino_init()
{
	int result = -1;

	sys_init();

	/* SD_CD */
	gpio_init_in(&ins, P7_8);

	/* SDカードを初期化 */
	sdfs_init(&sdfs, P8_5, P8_6, P8_3, P8_4, "sd");

	result = SD_begin() ? 0 : -1;
	if (result == 0) {
		// ntstdio_printf(&ntstdio, "SD card (1:) OK!\n");
		syslog(LOG_NOTICE, "SD card (1:) OK!");
	}
	else {
		// ntstdio_printf(&ntstdio, "SD card (1:) NG!\n");
		syslog(LOG_NOTICE, "SD card (1:) NG!");
	}
	sta_cyc(SDFS_CYC);

	if (romdisk_init())
		result = 0;

	if (result == 0) {
		// ntstdio_printf(&ntstdio, "ROM disk (0:) OK!\n");
		syslog(LOG_NOTICE, "ROM disk (0:) OK!");
	}
	else {
		// ntstdio_printf(&ntstdio, "ROM disk (0:) NG!\n");
		syslog(LOG_NOTICE, "ROM disk (0:) NG!");
	}

	/* uploadディレクトリを作成しておく */
	f_mkdir("1:/log");

	serial_ctl_por(SIO_PORTID, IOCTL_FCSND | IOCTL_FCRCV);

	return result;
}

void sys_init(void)
{
	// sys_tlsf = tlsf_create(&__HeapBase);
	// if (sys_tlsf == NULL)
	// 	return;

	// sys_pool = tlsf_add_pool(sys_tlsf, ((uint8_t *)&__HeapBase) + tlsf_size(), ((size_t)&__HeapLimit - (size_t)&__HeapBase) - tlsf_size());
	init_memory_pool(sizeof(mem_pool), mem_pool);
}

void sys_fini(void)
{
	// tlsf_destroy(sys_tlsf);
	destroy_memory_pool(mem_pool);
}

void *sys_malloc(size_t size)
{
	// return tlsf_malloc(sys_tlsf, size);
	return malloc_ex(size, mem_pool);
}

void *sys_calloc(size_t size, size_t count)
{
	// void *result = tlsf_malloc(sys_tlsf, count * size);
	// memset(result, 0, count * size);
	// return result;
	return calloc_ex(count, size, mem_pool);
}

void *sys_realloc(void *ptr, size_t size)
{
	// return tlsf_realloc(sys_tlsf, ptr, size);
	return realloc_ex(ptr, size, mem_pool);
}

void sys_free(void *ptr)
{
	// tlsf_free(sys_tlsf, ptr);
	free_ex(ptr, mem_pool);
}

bool_t romdisk_init()
{
	DSTATUS dst;
	FRESULT res;

	if (RomDisk.fs_type != 0)
		return true;

	if ((dst = ramdisk_initialize()) != RES_OK) {
		return false;
	}

	if ((res = f_mount(&RomDisk, "0:", 1)) != FR_OK) {
		return false;
	}

	return true;
}

bool_t SD_begin()
{
	DSTATUS dst;
	FRESULT res;
	BYTE pdrv = 1, type;

	if (Sd.FatFs.fs_type != 0)
		return true;

	if ((dst = disk_initialize(pdrv)) != RES_OK) {
		return false;
	}

	if ((dst = disk_ioctl(pdrv, MMC_GET_TYPE, &type)) != RES_OK) {
		Sd.dst = dst;
		Sd.type = 0;
	}
	else {
		Sd.dst = RES_OK;
		Sd.type = type;
	}

	if ((res = f_mount(&Sd.FatFs, "1:", 1)) != FR_OK) {
		return false;
	}

	return true;
}

DSTATUS disk_initialize(BYTE pdrv)
{
	switch (pdrv) {
	case 0:
		return ramdisk_initialize();
	case 1:
		return sdfs_initialize(&sdfs);
	}
	return STA_NOINIT;
}

DSTATUS disk_status(BYTE pdrv)
{
	switch (pdrv) {
	case 0:
		return ramdisk_get_status();
	case 1:
		return sdfs_status(&sdfs);
	}
	return STA_NOINIT;
}

DRESULT disk_read(BYTE pdrv, BYTE *buff, DWORD sector, UINT count)
{
	switch (pdrv) {
	case 0:
		return ramdisk_read(buff, sector, count);
	case 1:
		return sdfs_read(&sdfs, buff, sector, count);
	}
	return RES_PARERR;
}

DRESULT disk_write(BYTE pdrv, const BYTE *buff, DWORD sector, UINT count)
{
	switch (pdrv) {
	case 0:
		return ramdisk_write(buff, sector, count);
	case 1:
		return sdfs_write(&sdfs, buff, sector, count);
	}
	return RES_PARERR;
}

DRESULT disk_ioctl(BYTE pdrv, BYTE cmd, void *buff)
{
	switch (pdrv) {
	case 0:
		return RES_PARERR; /* ramdisk_ioctl(cmd, buff); */
	case 1:
		switch(cmd) {
		case CTRL_SYNC:
			return sdfs_sync(&sdfs);
		case GET_SECTOR_COUNT:
			return sdfs_sectors(&sdfs);
		case GET_BLOCK_SIZE:
			*((DWORD*)buff) = 1; // default when not known
			return RES_OK;
		}
	}
	return RES_PARERR;
}

void sdfs_cychdr(intptr_t exinf)
{
	BYTE s;

	s = sdfs._is_initialized;
	if (WP())		/* Write protected */
		s |= STA_PROTECT;
	else		/* Write enabled */
		s &= ~STA_PROTECT;
	if (gpio_read(&ins))	/* Card is in socket */
		s &= ~STA_NODISK;
	else		/* Socket empty */
		s |= (STA_NODISK | STA_NOINIT);
	sdfs._is_initialized = s;
}

int ff_cre_syncobj(BYTE vol, _SYNC_t* sobj)
{
	return 1;
}

int ff_req_grant(_SYNC_t sobj)
{
	ER ret;
	ret = wai_sem(SEM_FILESYSTEM);
	return ret == E_OK;
}

void ff_rel_grant(_SYNC_t sobj)
{
	sig_sem(SEM_FILESYSTEM);
}

int ff_del_syncobj(_SYNC_t sobj)
{
	return 1;
}

void* ff_memalloc (UINT msize)
{
	return sys_malloc(msize);
}

void ff_memfree (void* mblock)
{
	sys_free(mblock);
}
