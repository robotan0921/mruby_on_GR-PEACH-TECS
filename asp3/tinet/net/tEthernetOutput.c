/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tEthernetOutput_template.c => src/tEthernetOutput.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cRawOutput signature: sEthernetRawOutput context:task
 *   ER             cRawOutput_ethernetRawOutput( int8_t* outputp, int32_t size, TMO tmout );
 * call port: cNicDriver signature: sNicDriver context:task
 *   void           cNicDriver_init( );
 *   void           cNicDriver_start( int8_t* outputp, int32_t size, uint8_t align );
 *   T_NET_BUF*     cNicDriver_read( int8_t** inputp, int32_t* size, uint8_t align );
 *   void           cNicDriver_probe( uint8_t* macaddress );
 *   void           cNicDriver_reset( );
 * call port: cArpOutput signature: sArpOutput context:task optional:true
 *   bool_t     is_cArpOutput_joined()                     check if joined
 *   ER             cArpOutput_arpResolve( int8_t* outputp, int32_t size, T_IN4_ADDR dstaddr, const uint8_t* macaddress, TMO tmout );
 * allocator port for call port:cRawOutput func:ethernetRawOutput param: outputp
 *   ER             cRawOutput_ethernetRawOutput_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cRawOutput_ethernetRawOutput_outputp_dealloc( const void* buf );
 *   ER             cRawOutput_ethernetRawOutput_outputp_reuse( void* buf );
 *   ER_UINT        cRawOutput_ethernetRawOutput_outputp_bufferSize( const void* buf );
 *   uint32_t       cRawOutput_ethernetRawOutput_outputp_bufferMaxSize( );
 * allocator port for call port:cNicDriver func:start param: outputp
 *   ER             cNicDriver_start_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cNicDriver_start_outputp_dealloc( const void* buf );
 *   ER             cNicDriver_start_outputp_reuse( void* buf );
 *   ER_UINT        cNicDriver_start_outputp_bufferSize( const void* buf );
 *   uint32_t       cNicDriver_start_outputp_bufferMaxSize( );
 * allocator port for call port:cNicDriver func:read param: inputp
 *   ER             cNicDriver_read_inputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cNicDriver_read_inputp_dealloc( const void* buf );
 *   ER             cNicDriver_read_inputp_reuse( void* buf );
 *   ER_UINT        cNicDriver_read_inputp_bufferSize( const void* buf );
 *   uint32_t       cNicDriver_read_inputp_bufferMaxSize( );
 * allocator port for call port:cArpOutput func:arpResolve param: outputp
 *   ER             cArpOutput_arpResolve_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cArpOutput_arpResolve_outputp_dealloc( const void* buf );
 *   ER             cArpOutput_arpResolve_outputp_reuse( void* buf );
 *   ER_UINT        cArpOutput_arpResolve_outputp_bufferSize( const void* buf );
 *   uint32_t       cArpOutput_arpResolve_outputp_bufferMaxSize( );
 * allocator port for call port:eEthernetOutput func:ethernetOutput param: outputp
 *   ER             eEthernetOutput_ethernetOutput_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             eEthernetOutput_ethernetOutput_outputp_dealloc( const void* buf );
 *   ER             eEthernetOutput_ethernetOutput_outputp_reuse( void* buf );
 *   ER_UINT        eEthernetOutput_ethernetOutput_outputp_bufferSize( const void* buf );
 *   uint32_t       eEthernetOutput_ethernetOutput_outputp_bufferMaxSize( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tEthernetOutput_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

#include <string.h>

#ifdef TARGET_KERNEL_ASP

#include <kernel.h>
#include <sil.h>
#include <t_syslog.h>
#include "kernel_cfg.h"

#endif	/* of #ifdef TARGET_KERNEL_ASP */

#ifdef TARGET_KERNEL_JSP

#include <s_services.h>
#include <t_services.h>
#include "kernel_id.h"

#endif	/* of #ifdef TARGET_KERNEL_JSP */

#include <tinet_defs.h>
#include <tinet_config.h>

#include <net/if.h>
#include <net/ethernet.h>
#include <net/if_llc.h>
#include <net/if_arp.h>
#include <net/net.h>
#include <net/net_var.h>
#include <net/net_buf.h>
#include <net/net_timer.h>
#include <net/net_count.h>

#include <netinet/in.h>
#include <netinet/in_var.h>
#include <netinet/if_ether.h>

#include <netinet6/if6_ether.h>
#include <netinet6/nd6.h>

#include <net/if_var.h>

/* #[<ENTRY_PORT>]# eEthernetOutput
 * entry port: eEthernetOutput
 * signature:  sEthernetOutput
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eEthernetOutput_ethernetOutput
 * name:         eEthernetOutput_ethernetOutput
 * global_name:  tEthernetOutput_eEthernetOutput_ethernetOutput
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eEthernetOutput_ethernetOutput(CELLIDX idx, int8_t* outputp, int32_t size, T_IN4_ADDR dstaddr, TMO tmout)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	T_NET_BUF *output = (T_NET_BUF*)outputp;
	uint8_t mymac[6];
	cNicDriver_probe(mymac);

	/*ヘッダのセット */
	memcpy(GET_ETHER_HDR(output)->shost, mymac, 6);

	if (output->off.protocolflag & FLAG_USE_IPV4) {
		GET_ETHER_HDR(output)->type = htons(ETHER_TYPE_IP);
		if (is_cArpOutput_joined()) {
			return cArpOutput_arpResolve(outputp, size, dstaddr, mymac, tmout);
		}
	}
	else {
		eEthernetOutput_ethernetOutput_outputp_dealloc((void*)outputp);
		return E_PAR;
	}

	return(ercd);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
