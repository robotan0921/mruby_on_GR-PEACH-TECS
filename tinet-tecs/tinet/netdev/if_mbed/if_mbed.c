/*
 *  TINET (TCP/IP Protocol Stack)
 * 
 *  Copyright (C) 2001-2009 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2014 Cores Co., Ltd. Japan
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
 *  @(#) $Id: if_mbed.c 969 2016-06-20 10:57:51Z coas-nagasima $
 */

/*
 * Copyright (c) 1995, David Greenman
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice unmodified, this list of conditions, and the following
 *    disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * 
 * $FreeBSD: src/sys/i386/isa/if_mbed.c,v 1.148.2.4 1999/09/25 13:08:18 nyan Exp $
 */

#define CAST(type, val)		((type)(val))

#include <kernel.h>
#include <sil.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "kernel/kernel_impl.h"

#include <tinet_defs.h>
#include <tinet_config.h>

#include <net/if.h>
#include <net/ethernet.h>
#include <net/if_arp.h>
#include <net/net.h>
#include <net/net_timer.h>
#include <net/net_count.h>
#include <net/net_buf.h>
#include <net/ethernet.h>

#include "mbed_interface.h"
#include "ethernet_api.h"
#include "ethernetext_api.h"
#include <string.h>
#include "if_mbed.h"
#include "iodefine.h"

#ifdef _MSC_VER
#include <stdlib.h>
#endif

#if 0 // for TECS
extern uint8_t mac_addr[ETHER_ADDR_LEN];
#endif

// for TECS
//#define ETHER_EESR0_TC 0x00200000

#if 0 // for TECS
/*
 *  ネットワークインタフェースに依存するソフトウェア情報
 */

typedef struct t_mbed_softc {
	bool_t link_pre;
	bool_t link_now;
	bool_t over_flow;
} T_MBED_SOFTC;

/*
 *  ネットワークインタフェースのソフトウェア情報
 */

/* ネットワークインタフェースに依存するソフトウェア情報 */

//static T_MBED_SOFTC mbed_softc;
//T_MBED_SOFTC mbed_softc;	// Debug


/* ネットワークインタフェースに依存しないソフトウェア情報 */

T_IF_SOFTC if_softc = {
	{0,},						/* ネットワークインタフェースのアドレス	*/
	0,							/* 送信タイムアウト			*/
	&mbed_softc,				/* ディバイス依存のソフトウェア情報	*/
	SEM_IF_MBED_SBUF_READY,	/* 送信セマフォ			*/
	SEM_IF_MBED_RBUF_READY,	/* 受信セマフォ			*/

#ifdef SUPPORT_INET6

	IF_MADDR_INIT,				/* マルチキャストアドレスリスト	*/

#endif	/* of #ifdef SUPPORT_INET6 */
};
#endif

#if 0 // for TECS
/*
 *  局所変数
 */

static void if_mbed_stop (T_MBED_SOFTC *sc);
static void if_mbed_init_sub (T_IF_SOFTC *ic);

#ifdef SUPPORT_INET6

static uint32_t ds_crc (uint8_t *addr);
static void ds_getmcaf (T_IF_SOFTC *ic, uint32_t *mcaf);


/*
 *  ds_crc -- イーサネットアドレスの CRC を計算する。
 */

#define POLYNOMIAL	0x04c11db6

static uint32_t
ds_crc (uint8_t *addr)
{
	uint32_t	crc = ULONG_C(0xffffffff);
	int_t		carry, len, bit;
	uint8_t		byte;

	for (len = ETHER_ADDR_LEN; len -- > 0; ) {
		byte = *addr ++;
		for (bit = 8; bit -- > 0; ) {
			carry   = ((crc & ULONG_C(0x80000000)) ? 1 : 0) ^ (byte & UINT_C(0x01));
			crc   <<= 1;
			byte   >>= 1;
			if (carry)
				crc = (crc ^ POLYNOMIAL) | carry;
		}
	}
	return crc;
}

#undef POLYNOMIAL

/*
 *  ds_getmcaf -- マルチキャストアドレスのリストからマルチキャストアドレス
 *                フィルタを計算する。
 */

static void
ds_getmcaf (T_IF_SOFTC *ic, uint32_t *mcaf)
{
	uint32_t	count, index;
	uint8_t		*af = (uint8_t*)mcaf;

	mcaf[0] = mcaf[1] = 0;

	for (count = MAX_IF_MADDR_CNT; count -- > 0; ) {
		index = ds_crc(ic->maddrs[count].lladdr) >> 26;
		af[index >> 3] |= 1 << (index & 7);
	}
}

/*
 * mbed_setrcr -- 受信構成レジスタ (RCR) を設定する。
 */

static void
if_mbed_setrcr (T_IF_SOFTC *ic)
{
	T_MBED_SOFTC	*sc = ic->sc;
}

/*
 * mbed_addmulti -- マルチキャストアドレスを追加する。
 */

ER
if_mbed_addmulti (T_IF_SOFTC *ic)
{
	mbed_setrcr(ic);
	return E_OK;
}

#endif	/* of #ifdef SUPPORT_INET6 */

#endif

#if 0	// For TECS
/*
 *  mbed_stop -- ネットワークインタフェースを停止する。
 *
 *    注意: NIC 割り込み禁止状態で呼び出すこと。
 */

static void
if_mbed_stop (T_MBED_SOFTC *sc)
{
	ethernetext_start_stop(0);
}
#endif

#if 0 // for TECS
static void rza1_recv_callback(void) {
    sig_sem(if_softc.semid_rxb_ready);
}

static void
if_mbed_init_sub (T_IF_SOFTC *ic)
{
    ethernet_cfg_t ethcfg;

    /* Initialize the hardware */
    ethcfg.int_priority = 6;
    ethcfg.recv_cb      = &rza1_recv_callback;
    ethcfg.ether_mac    = (char *)ic->ifaddr.lladdr;
    ethernetext_init(&ethcfg);
}
#endif

#if 0	// For TECS
/*
 * mbed_reset -- ネットワークインタフェースをリセットする。
 */

void
if_mbed_reset (T_IF_SOFTC *ic)
{
    ethernetext_start_stop(0);

	NET_COUNT_ETHER_NIC(net_count_ether_nic[NC_ETHER_NIC_RESETS], 1);
	if_mbed_stop(ic->sc);
	if_mbed_init_sub(ic);

    ethernetext_start_stop(1);
}
#endif
#if 0
/*
 *  get_mbed_softc -- ネットワークインタフェースのソフトウェア情報を返す。
 */

T_IF_SOFTC *
if_mbed_get_softc (void)
{
	return &if_softc;
}
#endif
#if 0
/*
 * mbed_watchdog -- ネットワークインタフェースのワッチドッグタイムアウト
 */

void
if_mbed_watchdog (T_IF_SOFTC *ic)
{
	if_mbed_reset(ic);
}
#endif
#if 0 	// TECS
/*
 * mbed_probe -- ネットワークインタフェースの検出
 */

void
if_mbed_probe (T_IF_SOFTC *ic)
{
#if (MBED_MAC_ADDRESS_SUM != MBED_MAC_ADDR_INTERFACE)
    netif->hwaddr[0] = MBED_MAC_ADDR_0;
    netif->hwaddr[1] = MBED_MAC_ADDR_1;
    netif->hwaddr[2] = MBED_MAC_ADDR_2;
    netif->hwaddr[3] = MBED_MAC_ADDR_3;
    netif->hwaddr[4] = MBED_MAC_ADDR_4;
    netif->hwaddr[5] = MBED_MAC_ADDR_5;
#else
    mbed_mac_address((char *)ic->ifaddr.lladdr);
#endif
}
#endif
#if 0 // for TECS

#define ETHER_EESR0_TC 0x00200000

/*
 * mbed_init -- ネットワークインタフェースの初期化
 */

void
if_mbed_init (T_IF_SOFTC *ic)
{
	T_MBED_SOFTC *sc = ic->sc;

	/* mbed_init 本体を呼び出す。*/
	if_mbed_init_sub(ic);

	act_tsk(IF_MBED_PHY_TASK);

	ethernet_set_link(-1, 0);

	ETHER.EESIPR0 |= ETHER_EESR0_TC;
}
#endif
#if 0
void if_mbed_phy_task(intptr_t arg) {
	T_IFNET *ether = ether_get_ifnet();
    int32_t connect_sts = 0;   /* 0: disconnect, 1:connect */
    int32_t link_sts;
    int32_t link_mode_new = NEGO_FAIL;
    int32_t link_mode_old = NEGO_FAIL;

    while (1) {
        link_sts = ethernet_link();
        if (link_sts == 1) {
            link_mode_new = ethernetext_chk_link_mode();
            if (link_mode_new != link_mode_old) {
                if (connect_sts == 1) {
               		ether_set_link_down(ether);
                }
                if (link_mode_new != NEGO_FAIL) {
                    ethernetext_set_link_mode(link_mode_new);
                    ether_set_link_up(ether);
                    connect_sts = 1;
                }
            }
        } else {
            if (connect_sts != 0) {
            	ether_set_link_down(ether);
                link_mode_new = NEGO_FAIL;
                connect_sts   = 0;
            }
        }
        link_mode_old = link_mode_new;
        dly_tsk(PHY_TASK_WAIT);
    }
}
#endif
#if 0 // TECS
/*
 * mbed_read -- フレームの読み込み
 */
T_NET_BUF *
if_mbed_read (T_IF_SOFTC *ic)
{
	T_NET_BUF *input = NULL;
	uint_t align;
	int len;
	uint8_t *dst;
	ER error;

	len = ethernet_receive();
	if (len <= 0)
		return NULL;

	align = 0;

	if ((error = tget_net_buf(&input, align, TMO_IF_MBED_GET_NET_BUF)) == E_OK && input != NULL) {
		dst = input->buf + IF_ETHER_NIC_HDR_ALIGN;
		input->len = ethernet_read((char *)dst, len);
	}
	else {
		NET_COUNT_ETHER_NIC(net_count_ether_nic[NC_ETHER_NIC_IN_ERR_PACKETS], 1);
		NET_COUNT_ETHER_NIC(net_count_ether_nic[NC_ETHER_NIC_NO_BUFS], 1);
	}

	sig_sem(ic->semid_rxb_ready);

	return input;
}
#endif
#if 0	// TECS
/*
 * mbed_start -- 送信フレームをバッファリングする。
 */

void
if_mbed_start (T_IF_SOFTC *ic, T_NET_BUF *output)
{
	T_MBED_SOFTC *sc = ic->sc;
	int32_t len, res, pos;

	for ( res = output->len, pos = 0; res > 0; res -= len, pos += len ) {
		len = ethernet_write((char *)output->buf + IF_ETHER_NIC_HDR_ALIGN + pos, res);
	}

    ethernet_send();
}
#endif
#if 0
/*
 *  MBED Ethernet Controler 送受信割り込みハンドラ
 */

void
if_mbed_eth_handler (void)
{
	if ((ETHER.EESR0 & ETHER_EESR0_TC) != 0) {
		/* 送信割り込み処理 */
		isig_sem(if_softc.semid_txb_ready);
	}

	INT_Ether();
}
#endif