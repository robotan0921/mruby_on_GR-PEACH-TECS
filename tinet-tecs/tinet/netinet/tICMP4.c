/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tICMP4_template.c => src/tICMP4.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cTCPInput signature: sTCPInput context:task optional:true
 *   bool_t     is_cTCPInput_joined()                     check if joined
 *   uint32_t       cTCPInput_TCPInput( int8_t* inputp, int32_t size, const int8_t* dstaddr, const int8_t* srcaddr, int32_t addrlen );
 *   void           cTCPInput_TCPNotify( const int8_t* inputp, int32_t size, ER error );
 * call port: cIPv4Reply signature: sIPv4Output context:task
 *   ER             cIPv4Reply_IPv4Output( int8_t* outputp, int32_t size, TMO tmout );
 *   T_IN4_ADDR     cIPv4Reply_getIPv4Address( );
 *   void           cIPv4Reply_setHeader( int8_t* outputp, int32_t size, T_IN4_ADDR dstaddr, T_IN4_ADDR srcaddr );
 *   ER             cIPv4Reply_IPv4Reply( int8_t* outputp, int32_t size, TMO tmout );
 * call port: cIPv4Functions signature: sIPv4Functions context:task
 *   uint16_t       cIPv4Functions_checkSum( const int8_t* data, uint32_t len );
 *   T_IN4_ADDR     cIPv4Functions_getIPv4Address( );
 *   T_IN4_ADDR     cIPv4Functions_getIPv4Mask( );
 * allocator port for call port:cTCPInput func:TCPInput param: inputp
 *   ER             cTCPInput_TCPInput_inputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cTCPInput_TCPInput_inputp_dealloc( const void* buf );
 *   ER             cTCPInput_TCPInput_inputp_reuse( void* buf );
 *   ER_UINT        cTCPInput_TCPInput_inputp_bufferSize( const void* buf );
 *   uint32_t       cTCPInput_TCPInput_inputp_bufferMaxSize( );
 * allocator port for call port:cIPv4Reply func:IPv4Output param: outputp
 *   ER             cIPv4Reply_IPv4Output_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cIPv4Reply_IPv4Output_outputp_dealloc( const void* buf );
 *   ER             cIPv4Reply_IPv4Output_outputp_reuse( void* buf );
 *   ER_UINT        cIPv4Reply_IPv4Output_outputp_bufferSize( const void* buf );
 *   uint32_t       cIPv4Reply_IPv4Output_outputp_bufferMaxSize( );
 * allocator port for call port:cIPv4Reply func:IPv4Reply param: outputp
 *   ER             cIPv4Reply_IPv4Reply_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cIPv4Reply_IPv4Reply_outputp_dealloc( const void* buf );
 *   ER             cIPv4Reply_IPv4Reply_outputp_reuse( void* buf );
 *   ER_UINT        cIPv4Reply_IPv4Reply_outputp_bufferSize( const void* buf );
 *   uint32_t       cIPv4Reply_IPv4Reply_outputp_bufferMaxSize( );
 * allocator port for call port:eICMP4 func:input param: inputp
 *   ER             eICMP4_input_inputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             eICMP4_input_inputp_dealloc( const void* buf );
 *   ER             eICMP4_input_inputp_reuse( void* buf );
 *   ER_UINT        eICMP4_input_inputp_bufferSize( const void* buf );
 *   uint32_t       eICMP4_input_inputp_bufferMaxSize( );
 * allocator port for call port:eICMP4Error func:error param: inputp
 *   ER             eICMP4Error_error_inputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             eICMP4Error_error_inputp_dealloc( const void* buf );
 *   ER             eICMP4Error_error_inputp_reuse( void* buf );
 *   ER_UINT        eICMP4Error_error_inputp_bufferSize( const void* buf );
 *   uint32_t       eICMP4Error_error_inputp_bufferMaxSize( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tICMP4_tecsgen.h"

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
#include <net/net_var.h>
#include <net/net_timer.h>
#include <net/net_count.h>

#include <netinet/in.h>
#include <netinet/in_var.h>
#include <netinet/ip.h>
#include <netinet/ip_var.h>
#include <netinet/ip_icmp.h>
#include <netinet/icmp_var.h>
#include <netinet/tcp.h>
#include <netinet/tcp_var.h>
#include <netinet/udp_var.h>

#include <net/if_var.h>

static void icmp_echo (CELLCB *p_cellcb, T_NET_BUF *input, int32_t size);
static void icmp_unreach (CELLCB *p_cellcb, T_NET_BUF *input, uint_t ihoff);
static void icmp_redirect (T_NET_BUF *input, uint_t ihoff);

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eICMP4
 * entry port: eICMP4
 * signature:  sICMP4Input
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eICMP4_input
 * name:         eICMP4_input
 * global_name:  tICMP4_eICMP4_input
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
/*
 *  icmp_input -- ICMP の入力関数
 *
 *    input には IF ヘッダと IP ヘッダも含まれている。
 */

uint32_t
eICMP4_input(CELLIDX idx, int8_t* inputp, int32_t size)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	T_NET_BUF *input = (T_NET_BUF*)inputp;
	T_ICMP4_HDR	*icmp4h;
	T_IP4_HDR *iph = GET_IP4_HDR(input);
	//TODO: T_IP4_HDR *iph = GET_IP4_HDR(input,input->off.ifhdrlen);
	T_IN4_ADDR	addr;
	uint32_t	len, align, hlen;

	// int32_t icmpoff = size;	//TODO
	// int32_t icmpoff = GET_IP4_HDR_SIZE(input);
	int32_t icmpoff = input->off.ifhdrlen + GET_IP4_HDR_SIZE(input);

	NET_COUNT_ICMP4(net_count_icmp4.in_octets,
	               input->len - GET_IF_IP4_HDR_SIZE(input));
	NET_COUNT_ICMP4(net_count_icmp4.in_packets, 1);

	/* ICMP ヘッダの長さをチェックする。*/
	if (input->len < icmpoff + ICMP4_HDR_SIZE - input->off.ifalign) {
	// if (input->len < IF_IP4_ICMP4_HDR_SIZE) {
		NET_COUNT_ICMP4(net_count_icmp4.in_err_packets, 1);
		NET_COUNT_MIB(icmp_stats.icmpInErrors, 1);
		goto buf_rel;
	}

	//icmp4h = (T_ICMP4_HDR *)(input->buf + *offp);
	icmp4h = (T_ICMP4_HDR *)(input->buf + icmpoff);

	/* 4 オクテット境界のデータ長 */
	//len   = input->len - *offp;
	len   = input->len - icmpoff;
	align = (len + 3) >> 2 << 2;

	/* 4 オクテット境界までパディングで埋める。*/
	if (align > len)
		memset((uint8_t*)input->buf + input->len, 0, (size_t)(align - len));

	/* チェックサムを計算する。*/
	// if (in_cksum(icmp4h, align) != 0) {
	if (cIPv4Functions_checkSum(icmp4h, align) != 0) {
		NET_COUNT_ICMP4(net_count_icmp4.in_err_packets, 1);
		goto buf_rel;
	}

	/* メッセージの型により分岐する。*/
	switch (icmp4h->type) {
	case ICMP4_ECHO_REQUEST:
		//icmp_echo(input, *offp);
		icmp_echo(p_cellcb, input, size);
		return IPPROTO_DONE;
		break;
	case ICMP4_ECHO_REPLY:

#if defined(SUPPORT_INET4) && defined(ICMP_CFG_CALLBACK_ECHO_REPLY)

		//icmp_echo_reply(input, *offp);
		icmp_echo_reply(input, icmpoff);

#endif	/* of #if defined(SUPPORT_INET4) && defined(ICMP_CFG_CALLBACK_ECHO_REPLY) */

		break;
	case ICMP4_UNREACH:
		//icmp_unreach(input, *offp);
		icmp_unreach(p_cellcb, input, size);
		break;
	case ICMP4_REDIRECT:

#if defined(NUM_REDIRECT_ROUTE_ENTRY)
#if NUM_REDIRECT_ROUTE_ENTRY > 0

		addr = ntohl(icmp4h->data.addr);
		syslog(LOG_INFO, "[ICMP] redirect, addr: %s.", ip2str(NULL, &addr));
		//icmp_redirect(input, *offp);
		icmp_redirect(p_cellcb, input);

#else	/* of #if NUM_REDIRECT_ROUTE_ENTRY > 0 */

		addr = ntohl(icmp4h->data.addr);
		syslog(LOG_INFO, "[ICMP] redirect ignored, addr: %s.", ip2str(NULL, &addr));

#endif	/* of #if NUM_REDIRECT_ROUTE_ENTRY > 0 */
#else	/* of #if defined(NUM_REDIRECT_ROUTE_ENTRY) */

		addr = ntohl(icmp4h->data.addr);
		syslog(LOG_INFO, "[ICMP] redirect ignored, addr: %s.", ip2str(NULL, &addr));

#endif	/* of #if defined(NUM_REDIRECT_ROUTE_ENTRY) */

		break;
	default:
		syslog(LOG_INFO, "[ICMP] unknown type: %d.", icmp4h->type);
		NET_COUNT_ICMP4(net_count_icmp4.in_err_packets, 1);
		break;
	}

buf_rel:
	eICMP4_input_inputp_dealloc((void*)inputp);
	return IPPROTO_DONE;
}

/* #[<ENTRY_PORT>]# eICMP4Error
 * entry port: eICMP4Error
 * signature:  sICMP4Error
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eICMP4Error_error
 * name:         eICMP4Error_error
 * global_name:  tICMP4_eICMP4Error_error
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eICMP4Error_error(CELLIDX idx, int8_t* inputp, int32_t size, uint8_t code)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	T_IP4_HDR	*ip4h, *sip4h;
	T_ICMP4_HDR	*icmp4h;
	T_NET_BUF	*output;
	T_NET_BUF 	*input = (T_NET_BUF*)inputp;
	T_IN4_ADDR	saddr;
	uint_t		len, ip4hl, align, slen;

	ip4h  = GET_IP4_HDR(input);
	//TODO: ip4h  = GET_IP4_HDR(input, input->off.ifhdrlen);
	ip4hl = GET_IP4_HDR_SIZE(input);

	/* 送信用の IP データグラムを獲得する。*/
	if (input->len - ip4hl < 8)
		len = input->len - ip4hl;
	else
		len = 8;

	/* 4 オクテット境界のデータ長 */
	align = (len + ICMP4_HDR_SIZE + ip4hl + 3) >> 2 << 2;
	// align = (len + 3) >> 2 << 2;

	slen = align + input->off.ifhdrlen + IP4_HDR_SIZE;

	// saddr = ntohl(ip4h->src);
	// if (in4_get_datagram(&output, (uint_t)(ICMP4_HDR_SIZE + ip4hl + len), 0,
	//                      &saddr, NULL, IPPROTO_ICMP, IP4_DEFTTL,
	//                      NBA_SEARCH_ASCENT, TMO_ICMP_OUTPUT) != E_OK)
	// 	return;
	if(cIPv4Reply_IPv4Reply_outputp_alloc((void**)&output,slen,TMO_ICMP_OUTPUT) != E_OK)
		return;

	/* オフセット情報hをコピーする */
	output->off = input->off;
	output->off.iphdrlenall = IP4_HDR_SIZE;

	sip4h = output->buf + output->off.ifhdrlen;

	/* IP ヘッダを設定する --------------------- */
	sip4h->vhl	= IP4_MAKE_VHL(IPV4_VERSION, IP4_HDR_SIZE >> 2);
	sip4h->len	= htons(slen);
	sip4h->proto	= IPPROTO_ICMP;
	sip4h->ttl	= IP4_DEFTTL;
	sip4h->type	= 0;
	sip4h->id	= ip4h->flg_off = ip4h->sum = 0;

	/* IP アドレスを設定する。*/
	sip4h->dst	= ip4h->src;
	sip4h->src = htonl(cIPv4Functions_getIPv4Address());
	/* IPheader ここまで--------------------- */

	/* ICMP ヘッダを設定する。*/
	icmp4h		= GET_ICMP4_HDR(output, output->off.ifhdrlen+IP4_HDR_SIZE);
	// icmp4h		= GET_ICMP4_HDR(output, IF_IP4_ICMP4_HDR_OFFSET);
	icmp4h->type	= ICMP4_UNREACH;
	icmp4h->code	= code;
	icmp4h->data.addr= 0;

	/* エラーが発生した IP ヘッダと データ 8 オクテットをコピーする。*/
	// memcpy(GET_ICMP4_SDU(output, IF_IP4_ICMP4_HDR_OFFSET),
	//        GET_IP4_HDR(input), (size_t)(ip4hl + len));
	memcpy(GET_ICMP4_SDU(output, output->off.ifhdrlen+IP4_HDR_SIZE),
	       ip4h, (size_t)(ip4hl + len));



	/* 4 オクテット境界までパディングで埋める。*/
	if (align > len)
		// memset((uint8_t*)GET_ICMP4_SDU(output, IF_IP4_ICMP4_HDR_OFFSET) + ip4hl + len,
		//        0, (size_t)(align - len));
		memset((uint8_t*)GET_ICMP4_SDU(output, output->off.ifhdrlen + IP4_HDR_SIZE) + ip4hl + len,
		       0, (size_t)(align - len));

	/* チェックサムを計算する。*/
	icmp4h->sum = 0;
	// icmp4h->sum = in_cksum(icmp4h, (uint_t)(ICMP4_HDR_SIZE + ip4hl + align));
	icmp4h->sum = cIPv4Functions_checkSum(icmp4h, (uint_t)(ICMP4_HDR_SIZE + ip4hl + align));

	/* 送信する。*/
	NET_COUNT_ICMP4(net_count_icmp4.out_octets,
	               output->len - GET_IF_IP4_HDR_SIZE(output));
	NET_COUNT_ICMP4(net_count_icmp4.out_packets, 1);
	NET_COUNT_MIB(icmp_stats.icmpOutMsgs, 1);
	NET_COUNT_MIB(icmp_stats.icmpOutDestUnreachs, 1);
	// ip_output(output, TMO_ICMP_OUTPUT);
	cIPv4Reply_IPv4Reply((int8_t*)output, output->len+output->off.ifalign + sizeof(T_NET_BUF) - 4, TMO_ICMP_OUTPUT);

	/* メモリを解放 */
	eICMP4Error_error_inputp_dealloc((void*)inputp);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/

/*
 *  icmp_echo -- エコー要求を受信したときの処理
 *
 *    input には IF ヘッダと IP ヘッダも含まれている。
 */

static void
icmp_echo (CELLCB *p_cellcb, T_NET_BUF *input, int32_t size)
{
	T_IP4_HDR	*ip4h;
	T_ICMP4_HDR	*icmp4h;
	T_IFNET		*ifp = IF_GET_IFNET();
	T_IN4_ADDR srcaddr, dstaddr;
	int32_t icmpoff;

	NET_COUNT_MIB(icmp_stats.icmpInEchos, 1);

	/* IPv4 アドレスが未定義の時は応答しない。*/
	if (!IN4_IS_ADDR_ANY(&ifp->in4_ifaddr.addr)) {

		/*
		 *  メッセージの型をエコー要求 (8) から
		 *  エコー応答 (0) に変更して送り返す。
		 */
		icmpoff = input->off.ifhdrlen + GET_IP4_HDR_SIZE(input);

		// icmp4h = GET_ICMP4_HDR(input, ihoff);
		icmp4h = GET_ICMP4_HDR(input, icmpoff);
		icmp4h->type = ICMP4_ECHO_REPLY;

		/*
		 *  宛先アドレスは受信したメッセージの送信元アドレス。
		 *  送信元アドレスは自 IPv4 アドレス。
		 */
		ip4h      = GET_IP4_HDR(input);
		//TODO: ip4h      = GET_IP4_HDR(input,input->off.ifhdrlen);
		srcaddr   = ip4h->src;
		ip4h->src = ip4h->dst;
		dstaddr   = ntohl(ip4h->dst);
		ip4h->dst = srcaddr;
		srcaddr   = ntohl(srcaddr);

		// ip4h->dst = ip4h->src;
		// ip4h->src = htonl(ifp->in4_ifaddr.addr);

		/* チェックサムを計算する。*/
		icmp4h->sum = 0;
		icmp4h->sum = cIPv4Functions_checkSum(icmp4h, (uint_t)(((input->len - GET_IF_IP4_HDR_SIZE(input)) + 3) >> 2 << 2));
		//TODO: icmp4h->sum = cIPv4Functions_checkSum(icmp4h, (uint_t)(((input->len - icmpoff)) + 3) >> 2 << 2);
		// icmp4h->sum = cIPv4Functions_checkSum(icmp4h, (uint_t)(((input->len + input->off.ifalign - icmpoff)) + 3) >> 2 << 2);

		/* 送信する。*/
		NET_COUNT_ICMP4(net_count_icmp4.out_octets,
		               input->len - GET_IF_IP4_HDR_SIZE(input));
		NET_COUNT_ICMP4(net_count_icmp4.out_packets, 1);
		NET_COUNT_MIB(icmp_stats.icmpOutMsgs, 1);
		NET_COUNT_MIB(icmp_stats.icmpOutEchoReps, 1);
		// ip_output(input, TMO_ICMP_OUTPUT);
		cIPv4Reply_IPv4Reply((int8_t*)input, size, TMO_ICMP_OUTPUT);
	}
}

/*
 *  icmp_unreach -- ICMP4_UNREACH を受信したときの処理
 */

static const int8_t code2error[] = {
	EV_HURCH,	/* ICMP4_UNREACH_NET			 	0 */
	EV_HURCH,	/* ICMP4_UNREACH_HOST			 	1 */
	EV_CNNRF,	/* ICMP4_UNREACH_PROTOCOL		 	2 */
	EV_CNNRF,	/* ICMP4_UNREACH_PORT			 	3 */
	EV_MSIZE,	/* ICMP4_UNREACH_FLAG			 	4 */
	EV_HURCH,	/* ICMP4_UNREACH_SRC_FAIL		 	5 */
	EV_HURCH,	/* ICMP4_UNREACH_NET_UNKNOWN	 	6 */
	EV_HURCH,	/* ICMP4_UNREACH_HOST_UNKNOWN	 	7 */
	EV_HURCH,	/* ICMP4_UNREACH_ISOLATED		 	8 */
	EV_HURCH,	/* ICMP4_UNREACH_NET_PROHIB		 	9 */
	EV_HURCH,	/* ICMP4_UNREACH_HOST_PROHIB	 	10 */
	EV_HURCH,	/* ICMP4_UNREACH_TOS_NET		 	11 */
	EV_HURCH,	/* ICMP4_UNREACH_TOS_HOST		 	12 */
	EV_HURCH,	/* ICMP4_UNREACH_FILTER_PROHIB	 	13 */
	EV_HURCH,	/* ICMP4_UNREACH_HOST_PRECEDENCE 	14 */
	EV_HURCH,	/* ICMP4_UNREACH_PRECEDENCE_CUTOFF	15 */
};

static void
icmp_unreach (CELLCB *p_cellcb, T_NET_BUF *input, uint_t ihoff)
{
	T_IP4_HDR	*ip4h;
	uint8_t		code;
	ER 		error;

	NET_COUNT_MIB(icmp_stats.icmpInDestUnreachs, 1);

	ip4h   = (T_IP4_HDR*)GET_ICMP4_SDU(input, ihoff);

	int32_t icmpoff = input->off.ifhdrlen + GET_IP4_HDR_SIZE(input);

	code  = GET_ICMP4_HDR(input, ihoff)->code;
	error = code2error[code];

	/* 最終ヘッダが TCP/UDP のみ対応する。*/
	if (ip4h->proto == IPPROTO_TCP || ip4h->proto == IPPROTO_UDP) {

		memcpy(GET_IP4_HDR(input), ip4h, input->len - (IP4_HDR_SIZE + ICMP4_HDR_SIZE));
		input->len -= IP4_HDR_SIZE + ICMP4_HDR_SIZE;

#if defined(SUPPORT_TCP)

		if (ip4h->proto == IPPROTO_TCP)
			// tcp_notify(input, error);
			cTCPInput_TCPNotify(input, input->len + sizeof(T_NET_BUF), error);

#endif	/* of #if defined(SUPPORT_TCP) */

#if defined(SUPPORT_UDP) && TNUM_UDP4_CEPID > 0

		if (ip4h->proto == IPPROTO_UDP)
			udp4_notify(input, error);
			//TODO:

#endif	/* of #if defined(SUPPORT_UDP) && TNUM_UDP4_CEPID > 0 */

	}
	else
		syslog(LOG_NOTICE, "[ICMP] error, code: %d.", code);
}

#if defined(NUM_REDIRECT_ROUTE_ENTRY)
#if NUM_REDIRECT_ROUTE_ENTRY > 0

/*
 *  icmp_redirect -- 向け直しメッセージを受信したときの処理
 *
 *    input には IF ヘッダと IP ヘッダも含まれている。
 */

static void
icmp_redirect (T_NET_BUF *input, uint_t ihoff)
{
	T_IP4_HDR	*ip4h, *sip4h;
	T_ICMP4_HDR	*icmp4h;

	ip4h   = GET_IP4_HDR(input);
	icmp4h = GET_ICMP4_HDR(input, ihoff);
	sip4h  = (T_IP4_HDR *)GET_ICMP4_SDU(input, ihoff);

	/*
	 *  内容チェック、以下の場合はエラー
	 *
	 *    ・ICMP コードが、ICMP4_REDIRECT_PORT_AND_HOST (3) 以上
	 *    ・データグラム長が、ICMP の最小長より短い (IP ヘッダ + ICMP ヘッダ + IP ヘッダ + 8)
	 *    ・データグラム長が、ICMP の最大長より短い
	 *    ・
	 */
	if (icmp4h->code > ICMP4_REDIRECT_PORT_AND_HOST ||
	    ip4h->len < GET_IP4_ICMP4_HDR_SIZE(input) + 8 + IP4_HDR_SIZE ||
	    ip4h->len < GET_IP4_ICMP4_HDR_SIZE(input) + 8 + (IP4_VHL_HL(sip4h->vhl) << 2)) {
		NET_COUNT_ICMP4(net_count_icmp4.in_err_packets, 1);
		return;
		}

	in4_rtredirect(icmp4h->data.addr, sip4h->dst, IN_RTF_REDIRECT, TMO_IN_REDIRECT);
}

#endif	/* of #if NUM_REDIRECT_ROUTE_ENTRY > 0 */
#endif	/* of #if defined(NUM_REDIRECT_ROUTE_ENTRY) */