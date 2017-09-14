#ifndef _TECS_NET_BUF_H_
#define _TECS_NET_BUF_H_

// TODO
#include <target/gr_peach_gcc/tinet_target_defs.h>

#if 0

/*
 *  テンプレート
 */

struct t_net_buf {
	uint16_t	len;	/* データの長さ		*/
	uint8_t		idix;	/* mpfid のインデックス	*/
	uint8_t		flags;	/* フラグ		*/
#ifdef IF_ETHER_NIC_NET_BUF_ALIGN
	uint8_t		nalign[IF_ETHER_NIC_NET_BUF_ALIGN];
#endif
#if CPU_NET_ALIGN == 4 && IF_HDR_ALIGN != 4
	uint8_t		halign[4 - IF_HDR_ALIGN];
#endif
	uint8_t		buf[4];	/* バッファ本体		*/
};

#ifndef T_NET_BUF_DEFINED

typedef struct t_net_buf T_NET_BUF;

#define T_NET_BUF_DEFINED

#endif	/* of #ifndef T_NET_BUF_DEFINED */

#else

struct t_off_buf {
	uint8_t		tphdrlen; 		/* トランスポート層のヘッダ長 */
	uint8_t 	iphdrlen; 		/* IP層のヘッダ長 */
	uint16_t 	ipmss; 			/* ip層を考慮したMSS */
	//uint8_t 	ipaddlen; 		/* IPアドレス長 */
	uint8_t 	ifhdrlen; 		/* データリンク層のヘッダ長 */
	uint8_t 	ifmtu; 			/* データリンク層を考慮したMTU */
	uint8_t 	ifalign; 		/* データリンク層のアライメント補正値 */
	uint8_t 	protocolflag; 	/* protocolflag */
	uint16_t 	tphdrlenall; 	/* トランスポート層のヘッダ長（動的変化分含む） */
	uint16_t 	iphdrlenall; 	/* IP層のヘッダ長（動的変化分含む） */
};

#ifndef T_OFF_BUF_DEFINED

typedef struct t_off_buf T_OFF_BUF;

#define T_OFF_BUF_DEFINED

#endif	/* of #ifndef T_OFF_BUF_DEFINED */

struct t_net_buf {
	uint16_t	len;	/* データの長さ	 */
	uint8_t		idix;	/* mpfid のインデックス */
	uint8_t		flags;	/* フラグ */
#ifdef IF_ETHER_NIC_NET_BUF_ALIGN
	uint8_t		nalign[IF_ETHER_NIC_NET_BUF_ALIGN];
#endif
#if CPU_NET_ALIGN == 4 && IF_HDR_ALIGN != 4
	uint8_t		halign[4 - IF_HDR_ALIGN];
#endif

	T_OFF_BUF off;

	uint8_t		buf[4];	/* バッファ本体 */
};

#ifndef T_NET_BUF_DEFINED

typedef struct t_net_buf T_NET_BUF;

#define T_NET_BUF_DEFINED

#endif	/* of #ifndef T_NET_BUF_DEFINED */

#endif

#endif /* _TECS_NET_BUF_H_ */
