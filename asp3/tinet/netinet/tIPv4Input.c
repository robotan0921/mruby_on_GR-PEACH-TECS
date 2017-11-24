/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tIPv4Input_template.c => src/tIPv4Input.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cUDPInput signature: sUDPInput context:task optional:true
 *   bool_t     is_cUDPInput_joined()                     check if joined
 *   uint32_t       cUDPInput_UDPInput( int8_t* inputp, int32_t size, const int8_t* dstaddr, int32_t addrlen );
 * call port: cTCPInput signature: sTCPInput context:task optional:true
 *   bool_t     is_cTCPInput_joined()                     check if joined
 *   uint32_t       cTCPInput_TCPInput( int8_t* inputp, int32_t size, const int8_t* dstaddr, const int8_t* srcaddr, int32_t addrlen );
 *   void           cTCPInput_TCPNotify( const int8_t* inputp, int32_t size, ER error );
 * call port: cICMP4 signature: sICMP4Input context:task optional:true
 *   bool_t     is_cICMP4_joined()                     check if joined
 *   uint32_t       cICMP4_input( int8_t* inputp, int32_t size );
 * call port: cICMP4Error signature: sICMP4Error context:task optional:true
 *   bool_t     is_cICMP4Error_joined()                     check if joined
 *   void           cICMP4Error_error( int8_t* inputp, int32_t size, uint8_t code );
 * call port: cFunctions signature: sIPv4Functions context:task
 *   uint16_t       cFunctions_checkSum( const int8_t* data, uint32_t len );
 *   T_IN4_ADDR     cFunctions_getIPv4Address( );
 *   T_IN4_ADDR     cFunctions_getIPv4Mask( );
 * allocator port for call port:cUDPInput func:UDPInput param: inputp
 *   ER             cUDPInput_UDPInput_inputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cUDPInput_UDPInput_inputp_dealloc( const void* buf );
 *   ER             cUDPInput_UDPInput_inputp_reuse( void* buf );
 *   ER_UINT        cUDPInput_UDPInput_inputp_bufferSize( const void* buf );
 *   uint32_t       cUDPInput_UDPInput_inputp_bufferMaxSize( );
 * allocator port for call port:cTCPInput func:TCPInput param: inputp
 *   ER             cTCPInput_TCPInput_inputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cTCPInput_TCPInput_inputp_dealloc( const void* buf );
 *   ER             cTCPInput_TCPInput_inputp_reuse( void* buf );
 *   ER_UINT        cTCPInput_TCPInput_inputp_bufferSize( const void* buf );
 *   uint32_t       cTCPInput_TCPInput_inputp_bufferMaxSize( );
 * allocator port for call port:cICMP4 func:input param: inputp
 *   ER             cICMP4_input_inputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cICMP4_input_inputp_dealloc( const void* buf );
 *   ER             cICMP4_input_inputp_reuse( void* buf );
 *   ER_UINT        cICMP4_input_inputp_bufferSize( const void* buf );
 *   uint32_t       cICMP4_input_inputp_bufferMaxSize( );
 * allocator port for call port:cICMP4Error func:error param: inputp
 *   ER             cICMP4Error_error_inputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cICMP4Error_error_inputp_dealloc( const void* buf );
 *   ER             cICMP4Error_error_inputp_reuse( void* buf );
 *   ER_UINT        cICMP4Error_error_inputp_bufferSize( const void* buf );
 *   uint32_t       cICMP4Error_error_inputp_bufferMaxSize( );
 * allocator port for call port:eIPv4Input func:IPv4Input param: inputp
 *   ER             eIPv4Input_IPv4Input_inputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             eIPv4Input_IPv4Input_inputp_dealloc( const void* buf );
 *   ER             eIPv4Input_IPv4Input_inputp_reuse( void* buf );
 *   ER_UINT        eIPv4Input_IPv4Input_inputp_bufferSize( const void* buf );
 *   uint32_t       eIPv4Input_IPv4Input_inputp_bufferMaxSize( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tIPv4Input_tecsgen.h"

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
#include <net/ppp_ipcp.h>
#include <net/net.h>
#include <net/net_buf.h>
#include <net/net_count.h>
#include <net/net_timer.h>

#include <netinet/in.h>
#include <netinet/in_var.h>
#include <netinet/ip.h>
#include <netinet/ip_var.h>
#include <netinet/ip_icmp.h>
#include <netinet/tcp.h>
#include <netinet/tcp_var.h>
#include <netinet/udp.h>
#include <netinet/udp_var.h>
#include <netinet/ip_igmp.h>

#include <net/if_var.h>

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eIPv4Input
 * entry port: eIPv4Input
 * signature:  sIPv4Input
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eIPv4Input_IPv4Input
 * name:         eIPv4Input_IPv4Input
 * global_name:  tIPv4Input_eIPv4Input_IPv4Input
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eIPv4Input_IPv4Input(CELLIDX idx, int8_t* inputp, int32_t size)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	T_NET_BUF 	*input = (T_NET_BUF*)inputp;

	T_IP4_HDR 	*ip4h = GET_IP4_HDR(input);
	//TODO: T_IP4_HDR 	*ip4h = GET_IP4_HDR(input, input->off.ifhdrlen);
	T_IFNET		*ifp = IF_GET_IFNET();
	T_IN4_ADDR	dst, src, bc;
	T_IN4_ADDR 	addr = cFunctions_getIPv4Address();
	T_IN4_ADDR 	mask = cFunctions_getIPv4Mask();
	uint_t		off;
	uint32_t 	hlen = GET_IP4_HDR_SIZE(input);

	/* バッファ情報のセット */
	input->off.protocolflag |= FLAG_USE_IPV4;
	input->off.iphdrlen 	= IP4_HDR_SIZE;
	input->off.ipmss 		= TCP_MSS;
	input->off.iphdrlenall 	= hlen;

	NET_COUNT_IP4(net_count_ip4[NC_IP4_IN_OCTETS], input->len - IF_HDR_SIZE);
	NET_COUNT_IP4(net_count_ip4[NC_IP4_IN_PACKETS], 1);
	NET_COUNT_MIB(ip_stats.ipInReceives, 1);

	/* IP ヘッダの長さをチェックする。*/
	if (input->len < IF_IP4_HDR_SIZE) {
		NET_COUNT_IP4(net_count_ip4[NC_IP4_IN_ERR_SHORT], 1);
		NET_COUNT_MIB(ip_stats.ipInHdrErrors, 1);
		goto buf_rel;
	}

	/* バージョンをチェックする。*/
	if (IP4_VHL_V(ip4h->vhl) != IPV4_VERSION) {
		NET_COUNT_IP4(net_count_ip4[NC_IP4_IN_ERR_VER], 1);
		NET_COUNT_MIB(ip_stats.ipInHdrErrors, 1);
		goto buf_rel;
	}

	/* IP ヘッダの長さをチェックし、オプションを解析する。*/
	if (hlen > IP4_HDR_SIZE) {
		NET_COUNT_IP4(net_count_ip4[NC_IP4_OPTS], 1);
		/* %%% オプションの解析 %%% */
	}

	/* データグラム長をチェックする。*/
	if (ntohs(ip4h->len) > input->len - IF_HDR_SIZE) {
		NET_COUNT_IP4(net_count_ip4[NC_IP4_IN_ERR_SHORT], 1);
		NET_COUNT_MIB(ip_stats.ipInHdrErrors, 1);
		goto buf_rel;
	}

	/* ネットワークバッファの長さをデータグラム長に調整する。*/
	input->len = (uint16_t)(ntohs(ip4h->len) + IF_HDR_SIZE);
	size = input->len + sizeof(T_NET_BUF) - 4;

	/* チェックサムをチェックする。*/
	if (cFunctions_checkSum(ip4h, hlen) != 0) {
		NET_COUNT_IP4(net_count_ip4[NC_IP4_IN_ERR_CKSUM], 1);
		NET_COUNT_MIB(ip_stats.ipInHdrErrors, 1);
		goto buf_rel;
	}

	/* IP ヘッダの長さをチェックし、上位が ICMP 以外はオプションを消去する。*/
	if (hlen > IP4_HDR_SIZE && ip4h->proto != IPPROTO_ICMP) {
		memset((uint8_t*)ip4h + IP4_HDR_SIZE, 0, hlen - IP4_HDR_SIZE);
	}

	/* 送信元アドレスをチェックする。*/
	src = ntohl(ip4h->src);
	bc  = (addr & mask) | ~mask;

#ifdef SUPPORT_LOOP

	if (src == bc || src == IPV4_ADDR_BROADCAST || src == IPV4_ADDRANY) {
		NET_COUNT_IP4(net_count_ip4[NC_IP4_IN_ERR_ADDR], 1);
		NET_COUNT_MIB(ip_stats.ipInAddrErrors, 1);
		goto buf_rel;
	}

#else	/* of #ifdef SUPPORT_LOOP */

	if (src == ifp->in4_ifaddr.addr || src == bc || src == IPV4_ADDR_BROADCAST || src == IPV4_ADDRANY) {
		NET_COUNT_IP4(net_count_ip4[NC_IP4_IN_ERR_ADDR], 1);
		NET_COUNT_MIB(ip_stats.ipInAddrErrors, 1);
		goto buf_rel;
	}

#endif	/* of #ifdef SUPPORT_LOOP */

	/* あて先アドレスをチェックする。*/
	dst = ntohl(ip4h->dst);

//TODO: これ以下の addr
#ifdef DHCP_CFG

	/*
	 *  DHCP_CFG が定義されているときは、ローカルアドレスが未定義の
	 *  場合もデータグラムを受信する。
	 */

#if defined(ETHER_CFG_MULTICAST)
	if ((ifp->in4_ifaddr.addr != IPV4_ADDRANY) &&
		(!(dst == ifp->in4_ifaddr.addr || dst == bc ||
		   dst == IPV4_ADDR_BROADCAST  || dst == IPV4_ADDRANY ||
		  IN4_IS_ADDR_MULTICAST(dst)))) {
		NET_COUNT_IP4(net_count_ip4[NC_IP4_IN_ERR_ADDR], 1);
		NET_COUNT_MIB(ip_stats.ipInAddrErrors, 1);
		goto buf_rel;
	}
#else
	if ((ifp->in4_ifaddr.addr != IPV4_ADDRANY) &&
	    (!(dst == ifp->in4_ifaddr.addr || dst == bc ||
	       dst == IPV4_ADDR_BROADCAST  || dst == IPV4_ADDRANY))) {
		NET_COUNT_IP4(net_count_ip4[NC_IP4_IN_ERR_ADDR], 1);
		NET_COUNT_MIB(ip_stats.ipInAddrErrors, 1);
		goto buf_rel;
	}
#endif

#else	/* of #ifdef DHCP_CFG */

#if defined(ETHER_CFG_MULTICAST)
	if (!(dst == ifp->in4_ifaddr.addr || dst == bc ||
		  dst == IPV4_ADDR_BROADCAST || dst == IPV4_ADDRANY ||
		  IN4_IS_ADDR_MULTICAST(dst))) {
		NET_COUNT_IP4(net_count_ip4[NC_IP4_IN_ERR_ADDR], 1);
		NET_COUNT_MIB(ip_stats.ipInAddrErrors, 1);
		goto buf_rel;
	}
#else
	if (!(dst == ifp->in4_ifaddr.addr || dst == bc ||
	      dst == IPV4_ADDR_BROADCAST  || dst == IPV4_ADDRANY)) {
		NET_COUNT_IP4(net_count_ip4[NC_IP4_IN_ERR_ADDR], 1);
		NET_COUNT_MIB(ip_stats.ipInAddrErrors, 1);
		goto buf_rel;
	}
#endif

#endif	/* of #ifdef DHCP_CFG */

#ifdef IP4_CFG_FRAGMENT

	/* 分割されているかチェックする。*/
	if (ntohs(ip4h->flg_off) & (IP4_MF | IP4_OFFMASK)) {
		if ((input = ip_reass(ip4h, input)) == NULL)
			return;
	}

#else	/* of #ifdef IP4_CFG_FRAGMENT */

	/* 分割されているかチェックする。*/
	if (ntohs(ip4h->flg_off) & (IP4_MF | IP4_OFFMASK)) {
		T_IN4_ADDR	src;

		NET_COUNT_MIB(ip_stats.ipReasmReqds, 1);
		if ((ntohs(ip4h->flg_off) & IP4_OFFMASK) == 0) {
			NET_COUNT_MIB(ip_stats.ipReasmFails, 1);
		}
		src = ntohl(ip4h->src);
		syslog(LOG_WARNING, "[IP] flaged src: %s.", ip2str(NULL, &src));
		goto buf_rel;
	}

#endif	/* of #ifdef IP4_CFG_FRAGMENT */

	off  = (uint_t)(GET_IP4_SDU(input) - input->buf);

#if defined(SUPPORT_IPSEC)
	/* ここでipsec4_in_rejectを実行する */
	if ((ip4h->proto != IPPROTO_ESP) && ipsec4_in_reject (input)) {
		goto buf_rel;
	}
#endif /* of #if defined(SUPPORT_IPSEC) */

	/* プロトコルを選択する */
	switch (ip4h->proto) {

#if defined(SUPPORT_TCP)
	case IPPROTO_TCP:
		if (is_cTCPInput_joined()) {
			NET_COUNT_MIB(ip_stats.ipInDelivers, 1);
			cTCPInput_TCPInput(inputp, size, (int8_t*)&dst, (int8_t*)&src, 4);
			return;
		}
		break;
#endif	/* of #if defined(SUPPORT_TCP) */

#if defined(SUPPORT_UDP) && ( (TNUM_UDP4_CEPID > 0) || \
                             ((TNUM_UDP6_CEPID > 0) && defined(API_CFG_IP4MAPPED_ADDR)))
	case IPPROTO_UDP:
	//TODO: if (is_cUDPInput_joined()) {
		NET_COUNT_MIB(ip_stats.ipInDelivers, 1);
		// udp4_input(&input, &off, NULL);
		cUDPInput_UDPInput(inputp, size, (int8_t *)&dst, 4); // dstはホストオーダ順で入っている[0]=200 [1]=1 [2]=168 [3]=192//offmikan
		return;
		break;
#endif	/* of #if defined(SUPPORT_UDP) && TNUM_UDP4_CEPID > 0 */

	case IPPROTO_ICMP:
		//TODO: if (is_cICMP4_joined()) {
		NET_COUNT_MIB(ip_stats.ipInDelivers, 1);
		cICMP4_input(inputp, off);	//TODO: off = size ??
		return;
		break;

#if defined(SUPPORT_IGMP)
	case IPPROTO_IGMP:
		NET_COUNT_MIB(ip_stats.ipInDelivers, 1);
		igmp_input(&input, &off, NULL);
		return;
		break;
#endif /* of #ifdef UDP_CFG_EXTENTIONS */

#if defined(SUPPORT_IPSEC)
	case IPPROTO_ESP:
		NET_COUNT_MIB(ip_stats.ipInDelivers, 1);
		esp4_input(input, &off);
		return;
		break;
#endif /* of #if defined(SUPPORT_IPSEC) */

	default:
		NET_COUNT_IP4(net_count_ip4[NC_IP4_IN_ERR_PROTO], 1);
		NET_COUNT_MIB(ip_stats.ipInUnknownProtos, 1);

		/* ローカル IP アドレスに届いたデータグラムのみ ICMP エラーを通知する。*/
		if (dst == ifp->in4_ifaddr.addr) {
		//TODO: if ((dst == addr) && is_cICMP4Error_joined()) {
			T_IN4_ADDR	src;

			src = ntohl(ip4h->src);
			syslog(LOG_INFO, "[IP] unexp proto: %d, src=%s.", ip4h->proto, ip2str(NULL, &src));
			icmp_error(ICMP4_UNREACH_PROTOCOL, input);
			//TODO: cICMP4Error_error(inputp,size,ICMP4_UNREACH_PROTOCOL);
		}
		/*
		 *  icmp_error では、ネットワークバッファ input を返却しないので
		 *  開放してから終了する。
		 */
		break;
	}

buf_rel:
	NET_COUNT_IP4(net_count_ip4[NC_IP4_IN_ERR_PACKETS], 1);
	eIPv4Input_IPv4Input_inputp_dealloc((void*)inputp);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
