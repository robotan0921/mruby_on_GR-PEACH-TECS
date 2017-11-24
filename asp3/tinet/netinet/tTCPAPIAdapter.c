/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tTCPAPIAdapter_template.c => src/tTCPAPIAdapter.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cTCPAPI4 signature: sTCPCEPAPI4 context:task
 *   ER             cTCPAPI4_accept( intptr_t sREP4, T_IPV4EP* dstep4, TMO tmout );
 *   ER             cTCPAPI4_connect( T_IN4_ADDR myaddr, uint16_t myport, T_IN4_ADDR dstaddr, uint16_t dstport, TMO tmout );
 *   ER_UINT        cTCPAPI4_send( const int8_t* data, int32_t len, TMO tmout );
 *   ER_UINT        cTCPAPI4_receive( int8_t* data, int32_t len, TMO tmout );
 *   ER             cTCPAPI4_cancel( FN fncd );
 *   ER             cTCPAPI4_close( TMO tmout );
 *   ER             cTCPAPI4_shutdown( );
 * call port: cREP4_000 signature: sREP4 context:task
 *   T_IPV4EP       cREP4_000_getEndpoint( );
 *   ER             cREP4_000_signal( );
 *   ER             cREP4_000_wait( );
 *   ER             cREP4_000_waitPolling( );
 *   ER             cREP4_000_waitTimeout( TMO timeout );
 *   ER             cREP4_000_initialize( );
 *   ER             cREP4_000_refer( T_RSEM* pk_semaphoreStatus );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tTCPAPIAdapter_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

#include <string.h>

#ifdef TARGET_KERNEL_ASP

#include <kernel.h>
#include <sil.h>
#include "kernel_cfg.h"
#include "tinet_cfg.h"

#endif	/* of #ifdef TARGET_KERNEL_ASP */

#ifdef TARGET_KERNEL_JSP

#include <s_services.h>
#include <t_services.h>
#include "kernel_id.h"
#include "tinet_id.h"

#endif	/* of #ifdef TARGET_KERNEL_JSP */

#include <tinet_defs.h>
#include <tinet_config.h>

#include <net/if.h>
#include <net/if_ppp.h>
#include <net/if_loop.h>
#include <net/ethernet.h>
#include <net/net.h>
#include <net/net_var.h>
#include <net/net_buf.h>
#include <net/net_timer.h>
#include <net/net_count.h>

#include <netinet/in.h>
#include <netinet/in_var.h>
#include <netinet/in_itron.h>
#include <netinet/ip.h>
#include <netinet/ip_var.h>
#include <netinet/tcp.h>
#include <netinet/tcp_var.h>
#include <netinet/tcp_fsm.h>
#include <netinet/tcp_seq.h>
#include <netinet/tcp_timer.h>

#include <net/if_var.h>
/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/

/*
 *  tcp_acp_cep -- 接続要求待ち (受動オープン)【標準機能】
 */
#if 0 	//TODO:
ER
TCP_ACP_CEP (ID cepid, ID repid, T_IPEP *p_dstaddr, TMO tmout) {
	Descriptor(sREP4) desc;
    cRepSelector_getRep(&desc, 0);

	return cTCPAPI4_accept(desc, p_dstaddr, tmout);
}
#endif 	/* of #if 0 */

/*
 *  tcp_snd_dat -- パケットの送信【標準機能】
 */

ER_UINT
tcp_snd_dat (ID cepid, void *data, int_t len, TMO tmout)
{
	return cTCPAPI4_send(data, len, tmout);
}

/*
 *  tcp_rcv_dat -- パケットの受信【標準機能】
 */

ER_UINT
tcp_rcv_dat (ID cepid, void *data, int_t len, TMO tmout)
{
	return cTCPAPI4_receive(data, len, tmout);
}