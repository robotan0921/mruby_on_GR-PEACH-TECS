/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tTCPInput_template.c => src/tTCPInput.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cCEPInput signature: sTCPCEPInput context:task
 *   ER             cCEPInput_check( subscript, const int8_t* dstaddr, const int8_t* srcaddr, int32_t len, uint16_t dstport, uint16_t srcport );
 *   ER             cCEPInput_input( subscript, int8_t* inputp, int32_t size );
 *   void           cCEPInput_notify( subscript, ER error );
 *       subscript:  0...(NCP_cCEPInput-1)
 * call port: cTCPRespond signature: sTCPOutput context:task
 *   ER             cTCPRespond_output( int8_t* outputp, int32_t size, const int8_t* dstaddr, const int8_t* srcaddr, int32_t addrlen );
 *   ER             cTCPRespond_getOffset( T_OFF_BUF* offset );
 *   T_IN4_ADDR     cTCPRespond_getIPv4Address( );
 *   ER             cTCPRespond_respond( int8_t* outputp, int32_t size, T_TCP_CEP* cep, T_TCP_SEQ ack, T_TCP_SEQ seq, uint32_t rbfree, uint8_t flags );
 *   ER             cTCPRespond_allocAndRespond( const int8_t* dstaddr, const int8_t* srcaddr, int32_t addrlen, uint16_t dstport, uint16_t srcport, T_TCP_SEQ ack, T_TCP_SEQ seq, uint32_t rbfree, uint8_t flags, T_OFF_BUF offset );
 * call port: cIPv4CheckSum signature: sIPv4CheckSum context:task optional:true
 *   bool_t     is_cIPv4CheckSum_joined()                     check if joined
 *   uint16_t       cIPv4CheckSum_ipv4CheckSum( int8_t* data, int32_t size, uint32_t offset, uint8_t proto );
 * allocator port for call port:cCEPInput func:input param: inputp
 *   ER             cCEPInput_input_inputp_alloc( subscript, void** buf, const int32_t minlen, TMO tmout );
 *   ER             cCEPInput_input_inputp_dealloc( subscript, const void* buf );
 *   ER             cCEPInput_input_inputp_reuse( subscript, void* buf );
 *   ER_UINT        cCEPInput_input_inputp_bufferSize( subscript, const void* buf );
 *   uint32_t       cCEPInput_input_inputp_bufferMaxSize( subscript );
 *       subscript:  0...(NCP_cCEPInput_input_inputp-1)
 * allocator port for call port:cTCPRespond func:output param: outputp
 *   ER             cTCPRespond_output_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cTCPRespond_output_outputp_dealloc( const void* buf );
 *   ER             cTCPRespond_output_outputp_reuse( void* buf );
 *   ER_UINT        cTCPRespond_output_outputp_bufferSize( const void* buf );
 *   uint32_t       cTCPRespond_output_outputp_bufferMaxSize( );
 * allocator port for call port:cTCPRespond func:respond param: outputp
 *   ER             cTCPRespond_respond_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cTCPRespond_respond_outputp_dealloc( const void* buf );
 *   ER             cTCPRespond_respond_outputp_reuse( void* buf );
 *   ER_UINT        cTCPRespond_respond_outputp_bufferSize( const void* buf );
 *   uint32_t       cTCPRespond_respond_outputp_bufferMaxSize( );
 * allocator port for call port:eInput func:TCPInput param: inputp
 *   ER             eInput_TCPInput_inputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             eInput_TCPInput_inputp_dealloc( const void* buf );
 *   ER             eInput_TCPInput_inputp_reuse( void* buf );
 *   ER_UINT        eInput_TCPInput_inputp_bufferSize( const void* buf );
 *   uint32_t       eInput_TCPInput_inputp_bufferMaxSize( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tTCPInput_tecsgen.h"

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
#include <netinet/ip_icmp.h>
#include <netinet/tcp.h>
#include <netinet/tcp_var.h>
#include <netinet/tcp_fsm.h>
#include <netinet/tcp_seq.h>
#include <netinet/tcp_timer.h>

/*
 *  戻り値
 *
 *  RET_OK			正常
 *	RET_DROP		エラー、セグメントを破棄する。
 *	RET_RST_DROP	エラー、RST を送信し、セグメントを破棄する。
 */

#define RET_OK			(0)
#define RET_NEED_OUTPUT	(1)
#define RET_RETURN		(2)
#define RET_DROP		(-1)
#define RET_RST_DROP	(-2)

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eInput
 * entry port: eInput
 * signature:  sTCPInput
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eInput_TCPInput
 * name:         eInput_TCPInput
 * global_name:  tTCPInput_eInput_TCPInput
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
uint32_t
eInput_TCPInput(int8_t* inputp, int32_t size, const int8_t* dstaddr, const int8_t* srcaddr, int32_t addrlen)
{
	ER 			error;
	T_NET_BUF	*input = (T_NET_BUF*)inputp;
	T_TCP_HDR	*tcph;
	int32_t		rbfree;
	uint16_t	seglen;
	int32_t 	offset;
	uint32_t 	ix;

#if defined(NUM_TCP_TW_CEP_ENTRY) && NUM_TCP_TW_CEP_ENTRY > 0
	T_TCP_TWCEP	*twcep;
#endif	/* of #if defined(NUM_TCP_TW_CEP_ENTRY) && NUM_TCP_TW_CEP_ENTRY > 0 */

	NET_COUNT_TCP(net_count_tcp[NC_TCP_RECV_OCTETS],
	              input->len - GET_IF_IP_HDR_SIZE(input));
	NET_COUNT_TCP(net_count_tcp[NC_TCP_RECV_SEGS], 1);
	NET_COUNT_MIB(tcp_stats.tcpInSegs, 1);

	/* プロトコルフラグにTCPをセット */
	input->off.protocolflag |= FLAG_USE_TCP;
	input->off.tphdrlen = TCP_HDR_SIZE;
	offset = input->off.ifhdrlen + input->off.iphdrlenall;

	/* ヘッダ長をチェックする。*/
	if (input->len < IF_IP_TCP_HDR_SIZE(input)) {
		NET_COUNT_TCP(net_count_tcp[NC_TCP_RECV_BAD_HEADERS], 1);
		goto drop;
	}

	tcph = GET_TCP_HDR(input, offset);

	//TODO: seglen  = input->len - (offset - input->off.ifalign);				/* TCP のセグメント長 */
	seglen  = input->len - offset;				/* TCP のセグメント長 */

	if ((input->off.protocolflag & FLAG_USE_IPV4) && is_cIPv4CheckSum_joined()) {
		if (cIPv4CheckSum_ipv4CheckSum(inputp, size, offset, IPPROTO_TCP) != 0) {
			syslog(LOG_EMERG, "TCP packets are Droped when check sum!" );
			goto drop;
		}
	}

	/* TCP ヘッダ長をチェックする。*/
	if (TCP_HDR_LEN(tcph->doff) < TCP_HDR_SIZE || TCP_HDR_LEN(tcph->doff) > seglen) {
		NET_COUNT_TCP(net_count_tcp[NC_TCP_RECV_BAD_HEADERS], 1);
		syslog(LOG_EMERG, "TCP packets are Droped when length!");
		goto drop;
	}
	tcph->sum = seglen - TCP_HDR_LEN(tcph->doff);		/* ここから tcph->sum は TCP の SDU 長 */

	/*
	 *  SYN と FIN の両ビットがセットされていれば破棄する。nmap 等の対策
	 *  ただし、RFC1644 T/TCP 拡張機能と競合する。
	 */
	if ((tcph->flags & (TCP_FLG_SYN | TCP_FLG_FIN)) == (TCP_FLG_SYN | TCP_FLG_FIN)) {
		syslog(LOG_EMERG, "TCP packets are Droped about flag!");
		goto drop;
	}

	/* ネットワークオーダーからホストオーダーに変換する。*/

	NTOHL(tcph->seq);
	NTOHL(tcph->ack);
	NTOHS(tcph->win);
	NTOHS(tcph->urp);
	NTOHS(tcph->sport);
	NTOHS(tcph->dport);

	/* TCPCEPのファインド */
	for (ix = 0; ix < N_CP_cCEPInput; ix++) {
		if (cCEPInput_check(ix, dstaddr, srcaddr, addrlen, tcph->dport, tcph->sport) == E_OK) {
			// syslog(LOG_EMERG, "Debug: CEP FIND! seq :%d  ack:%d .", tcph->seq, tcph->ack);
			// syslog(LOG_EMERG, "Debug: sport :%d  dport:%d .", tcph->sport, tcph->dport);
			// syslog(LOG_EMERG, "Debug: flags :0x%x  doff :0x%x .", tcph->flags, tcph->doff);
			error = cCEPInput_input(ix, inputp, size);
			// syslog(LOG_EMERG, "Debug: ********success!*********");
			return error;
		}
	}

	/* CEPがなかった処理 */
	syslog(LOG_EMERG, "CEP Lost... seq :%d  ack:%d .", tcph->seq, tcph->ack);

//reset_drop:
	/*
	 *  RST 送信処理
	 */

	if ((tcph->flags & TCP_FLG_RST) || IN_IS_NET_ADDR_MULTICAST(input))
		goto drop;

	/* ホストオーダーからネットワークオーダーに戻す。*/

	HTONS(tcph->sport);
	HTONS(tcph->dport);

	//if (cep == NULL)
		rbfree = 0;
	//else
		//rbfree = cep->rbufsz - cep->rwbuf_count;

	if (tcph->flags & TCP_FLG_ACK)
		//TODO: tcp_respond(input, cep, 0, tcph->ack, rbfree, TCP_FLG_RST);
		cTCPRespond_respond(inputp, size, NULL, 0, tcph->ack, rbfree, TCP_FLG_RST);
	else {
		if (tcph->flags & TCP_FLG_SYN)
			tcph->sum ++;		/* tcph->sum は SDU 長 */
		//TODO: tcp_respond(input, cep, tcph->seq + tcph->sum, 0, rbfree, TCP_FLG_RST | TCP_FLG_ACK);
		cTCPRespond_respond(inputp, size, NULL, tcph->seq + tcph->sum, 0, rbfree, TCP_FLG_RST | TCP_FLG_ACK);
	}

	/* input は tcp_respoond で返却される。*/
	NET_COUNT_TCP(net_count_tcp[NC_TCP_SEND_RSTS], 1);
	NET_COUNT_MIB(tcp_stats.tcpOutRsts, 1);
	return IPPROTO_DONE;

drop:
	NET_COUNT_TCP(net_count_tcp[NC_TCP_RECV_DROP_SEGS], 1);
	NET_COUNT_MIB(tcp_stats.tcpInErrs, 1);
	eInput_TCPInput_inputp_dealloc(inputp);
	return IPPROTO_DONE;
}

/* #[<ENTRY_FUNC>]# eInput_TCPNotify
 * name:         eInput_TCPNotify
 * global_name:  tTCPInput_eInput_TCPNotify
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eInput_TCPNotify(const int8_t* inputp, int32_t size, ER error)
{
	T_NET_BUF *input = (T_NET_BUF *)inputp;
	T_IP4_HDR *ip4h;
	T_TCP_HDR *tcph;
	int addrlen,ix;
	T_IN4_ADDR dst, src;
	int8_t *dstaddr, *srcaddr;

	if(input->off.protocolflag & FLAG_USE_IPV4) {
		ip4h  	= GET_IP4_HDR(input);
		//TODO: ip4h  	= GET_IP4_HDR(input,input->off.ifhdrlen);
		addrlen = 4;
		dst 	= ntohl(ip4h->dst);
		src 	= ntohl(ip4h->src);
		dstaddr = &dst;
		srcaddr = &src;
	}
	else {
	}

	tcph = GET_TCP_HDR(input, input->off.ifhdrlen + input->off.iphdrlenall);

	/*TCPCEPのファインド*/
	//for(ix = 0; ix < N_CP_cCEPInput; ix++) {
	//	if(cCEPInput_check(ix, dstaddr, srcaddr, addrlen, tcph->dport, tcph->sport) == E_OK) {
	//		cCEPInput_notify(ix,error);
	//		return;
	//	}
	//}
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
