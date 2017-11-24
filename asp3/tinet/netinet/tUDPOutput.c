/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tUDPOutput_template.c => src/tUDPOutput.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * require port: signature:sKernel context:task
 *   ER             getExtendedInformation( intptr_t* p_exinf );
 *   ER             sleep( );
 *   ER             sleepTimeout( TMO timeout );
 *   ER             delay( RELTIM delayTime );
 *   ER             exit( );
 *   ER             disableTerminate( );
 *   ER             enableTerminate( );
 *   bool_t         senseTerminate( );
 *   ER             setTime( SYSTIM systemTime );
 *   ER             getTime( SYSTIM* p_systemTime );
 *   ER             adjustTime( int32_t adjustTime );
 *   HRTCNT         fetchHighResolutionTimer( );
 *   ER             rotateReadyQueue( PRI taskPriority );
 *   ER             getTaskId( ID* p_taskId );
 *   ER             getLoad( PRI taskPriority, uint_t* p_load );
 *   ER             getNthTask( PRI taskPriority, uint_t nth, ID* p_taskID );
 *   ER             lockCpu( );
 *   ER             unlockCpu( );
 *   ER             disableDispatch( );
 *   ER             enableDispatch( );
 *   bool_t         senseContext( );
 *   bool_t         senseLock( );
 *   bool_t         senseDispatch( );
 *   bool_t         senseDispatchPendingState( );
 *   bool_t         senseKernel( );
 *   ER             exitKernel( );
 *   ER             changeInterruptPriorityMask( PRI interruptPriority );
 *   ER             getInterruptPriorityMask( PRI* p_interruptPriority );
 * call port: cIPv4CheckSum signature: sIPv4CheckSum context:task optional:true
 *   bool_t     is_cIPv4CheckSum_joined()                     check if joined
 *   uint16_t       cIPv4CheckSum_ipv4CheckSum( int8_t* data, int32_t size, uint32_t offset, uint8_t proto );
 * call port: cIPv4Output signature: sIPv4Output context:task optional:true
 *   bool_t     is_cIPv4Output_joined()                     check if joined
 *   ER             cIPv4Output_IPv4Output( int8_t* outputp, int32_t size, TMO tmout );
 *   ER             cIPv4Output_getOffset( T_OFF_BUF* offset );
 *   T_IN4_ADDR     cIPv4Output_getIPv4Address( );
 *   void           cIPv4Output_setHeader( int8_t* outputp, int32_t size, T_IN4_ADDR dstaddr, T_IN4_ADDR srcaddr );
 *   ER             cIPv4Output_IPv4Reply( int8_t* outputp, int32_t size, TMO tmout );
 * allocator port for call port:cIPv4Output func:IPv4Output param: outputp
 *   ER             cIPv4Output_IPv4Output_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cIPv4Output_IPv4Output_outputp_dealloc( const void* buf );
 *   ER             cIPv4Output_IPv4Output_outputp_reuse( void* buf );
 *   ER_UINT        cIPv4Output_IPv4Output_outputp_bufferSize( const void* buf );
 *   uint32_t       cIPv4Output_IPv4Output_outputp_bufferMaxSize( );
 * allocator port for call port:cIPv4Output func:IPv4Reply param: outputp
 *   ER             cIPv4Output_IPv4Reply_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cIPv4Output_IPv4Reply_outputp_dealloc( const void* buf );
 *   ER             cIPv4Output_IPv4Reply_outputp_reuse( void* buf );
 *   ER_UINT        cIPv4Output_IPv4Reply_outputp_bufferSize( const void* buf );
 *   uint32_t       cIPv4Output_IPv4Reply_outputp_bufferMaxSize( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tUDPOutput_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

#include <string.h>

#ifdef TARGET_KERNEL_ASP

#include <kernel.h>
#include <sil.h>
#include <t_syslog.h>
#include "tinet_cfg.h"

#endif	/* of #ifdef TARGET_KERNEL_ASP */

#ifdef TARGET_KERNEL_JSP

#include <s_services.h>
#include <t_services.h>
#include "tinet_id.h"

#endif	/* of #ifdef TARGET_KERNEL_JSP */

#include <tinet_defs.h>
#include <tinet_config.h>

#include <net/if.h>
#include <net/if_loop.h>
#include <net/if_ppp.h>
#include <net/ethernet.h>
#include <net/ppp_ipcp.h>
#include <net/net.h>
#include <net/net_buf.h>
#include <net/net_count.h>

#include <netinet/in.h>
#include <netinet/in_var.h>
#include <netinet/in_itron.h>
#include <netinet/ip.h>
#include <netinet/ip_var.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <netinet/udp_var.h>

#include <net/if_var.h>

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eOutput
 * entry port: eOutput
 * signature:  sUDPOutput
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eOutput_UDPOutput
 * name:         eOutput_UDPOutput
 * global_name:  tUDPOutput_eOutput_UDPOutput
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eOutput_UDPOutput(const int8_t* outputp, int32_t size, const int8_t* dstaddr, const int8_t* srcaddr, int32_t addrlen, uint16_t dstport, uint16_t myport, T_OFF_BUF offset, TMO tmout)
{
	T_NET_BUF	*output;
	T_UDP_HDR	*udph;
	SYSTIM		before, after;
	ER			error = E_OK;
	int32_t len;
	int32_t align;
	int32_t off = offset.ifhdrlen + offset.iphdrlen;

	/* データ長を 4 オクテット境界に調整する。*/
	align = (size + 3) >> 2 << 2;


#ifdef UDP_CFG_OUT_CHECKSUM
	uint16_t	sum;
#endif	/* of #ifdef UDP_CFG_OUT_CHECKSUM */

	// NET_COUNT_UDP(net_count_udp.out_octets,  len);
	// NET_COUNT_UDP(net_count_udp.out_packets, 1);

	/* IP データグラム割り当ての時間を tmout から減ずる。*/
	if (!(tmout == TMO_POL || tmout == TMO_FEVR))
		getTime(&before);

	/* IP データグラムを割り当てる。*/
	// if ((error = IN_GET_DATAGRAM(&output, (uint_t)(UDP_HDR_SIZE + len), 0,
	//                              &p_dstaddr->ipaddr,
	//                              &cep->myaddr.ipaddr,
	//                              IPPROTO_UDP, IP_DEFTTL,
	//                              NBA_SEARCH_ASCENT, tmout)) != E_OK)
	if ((error = cIPv4Output_IPv4Output_outputp_alloc((void**)&output,
													align + off + UDP_HDR_SIZE - offset.ifalign,
													tmout)) != E_OK)
		goto err_ret;

	/* IP データグラム割り当ての時間を tmout から減ずる。*/
	if (!(tmout == TMO_POL || tmout == TMO_FEVR)) {
		getTime(&after);
		if (after - before > tmout) {
			cIPv4Output_IPv4Output_outputp_dealloc((void *)output);
			error = E_TMOUT;
			goto err_ret;
		}
		tmout -= (TMO)(after - before);
	}

	/* UDP ヘッダに情報を設定する。*/
	udph		= GET_UDP_HDR(output, IF_IP_UDP_HDR_OFFSET(output));
	udph->sport	= htons(myport);
	udph->dport	= htons(dstport);
	udph->ulen	= htons(UDP_HDR_SIZE + len);
	udph->sum	= 0;

	/* データをコピーする。*/
	// memcpy((void*)GET_UDP_SDU(output, IF_IP_UDP_HDR_OFFSET(output)), data, (size_t)len);
	memcpy((void*)GET_UDP_SDU(output, off), outputp, (size_t)size);

	/* パディングで埋める */
	if (align > size)
		memset((GET_UDP_SDU(output, off) + size), 0, (size_t)(align - size));

	output->off = offset;

	/* ネットワークバッファ長を調整する。*/
	output->len = (uint16_t)(off + UDP_HDR_SIZE + size - offset.ifalign);
	len = output->len + sizeof(T_NET_BUF) - 4 + offset.ifalign;
	//TODO: output->len = (uint16_t)(IF_IP_UDP_HDR_SIZE(output) + len);

	if ((is_cIPv4Output_joined()) && (output->off.protocolflag & FLAG_USE_IPV4)) {
		T_IN4_ADDR dst = *((T_IN4_ADDR *)dstaddr);
		T_IN4_ADDR src = *((T_IN4_ADDR *)srcaddr);
		cIPv4Output_setHeader(output, len, dst, src);

#ifdef UDP_CFG_OUT_CHECKSUM

		if (is_cIPv4CheckSum_joined()) {
			sum = cIPv4CheckSum_ipv4CheckSum(output, len, off, IPPROTO_UDP);
			//TODO: sum = IN_CKSUM(output, IPPROTO_UDP, IF_IP_UDP_HDR_OFFSET(output), (uint_t)(UDP_HDR_SIZE + len));

			/* 計算したチェックサムの値が 0 なら 0xffff を入れる。*/
			if (sum == 0)
				sum = 0xffff;
			udph->sum = sum;
		}

#endif	/* of #ifdef UDP_CFG_OUT_CHECKSUM */

		/* ネットワーク層 (IP) の出力関数を呼び出す。*/
		if ((error = cIPv4Output_IPv4Output((int8_t*)output, len, tmout)) == E_OK) {
			return size;
		}
	}

	cIPv4Output_IPv4Output_outputp_dealloc((void*)output);

err_ret:
	// NET_COUNT_UDP(net_count_udp.out_err_packets, 1);
	return error;
}

/* #[<ENTRY_FUNC>]# eOutput_getOffset
 * name:         eOutput_getOffset
 * global_name:  tUDPOutput_eOutput_getOffset
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eOutput_getOffset(T_OFF_BUF* offset)
{
	offset->tphdrlen = UDP_HDR_SIZE;

	if ((is_cIPv4Output_joined()) && (offset->protocolflag & FLAG_USE_IPV4))
		return cIPv4Output_getOffset(offset);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
