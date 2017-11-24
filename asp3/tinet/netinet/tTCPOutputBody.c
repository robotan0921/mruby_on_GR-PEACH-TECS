/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tTCPOutputBody_template.c => src/tTCPOutputBody.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cIPv4Output signature: sIPv4Output context:task optional:true
 *   bool_t     is_cIPv4Output_joined()                     check if joined
 *   ER             cIPv4Output_IPv4Output( int8_t* outputp, int32_t size, TMO tmout );
 *   ER             cIPv4Output_getOffset( T_OFF_BUF* offset );
 *   T_IN4_ADDR     cIPv4Output_getIPv4Address( );
 *   void           cIPv4Output_setHeader( int8_t* outputp, int32_t size, T_IN4_ADDR dstaddr, T_IN4_ADDR srcaddr );
 *   ER             cIPv4Output_IPv4Reply( int8_t* outputp, int32_t size, TMO tmout );
 * call port: cIPv4CheckSum signature: sIPv4CheckSum context:task optional:true
 *   bool_t     is_cIPv4CheckSum_joined()                     check if joined
 *   uint16_t       cIPv4CheckSum_ipv4CheckSum( int8_t* data, int32_t size, uint32_t offset, uint8_t proto );
 * call port: cTCPOutputStart signature: sTCPOutputStart context:task
 *   ER             cTCPOutputStart_outputStart( subscript );
 *   ER             cTCPOutputStart_timerFunction( subscript );
 *       subscript:  0...(NCP_cTCPOutputStart-1)
 * call port: cSemaphore signature: sSemaphore context:task
 *   ER             cSemaphore_signal( );
 *   ER             cSemaphore_wait( );
 *   ER             cSemaphore_waitPolling( );
 *   ER             cSemaphore_waitTimeout( TMO timeout );
 *   ER             cSemaphore_initialize( );
 *   ER             cSemaphore_refer( T_RSEM* pk_semaphoreStatus );
 * call port: cTCPFunctions signature: sTCPFunctions context:task
 *   T_TCP_SEQ      cTCPFunctions_getTcpIss( );
 *   void           cTCPFunctions_setTcpIss( T_TCP_SEQ iss );
 *   T_TCP_SEQ      cTCPFunctions_initTcpIss( );
 *   T_TCP_TIME     cTCPFunctions_tcpRexmtValue( T_TCP_TIME srtt, T_TCP_TIME rttvar );
 *   T_TCP_TIME     cTCPFunctions_tcpRangeSet( T_TCP_TIME value, T_TCP_TIME tvmin, T_TCP_TIME tvmax );
 * call port: cNetworkTimer signature: sNetworkTimer context:task
 *   ER             cNetworkTimer_timeout( RELTIM timout );
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
 * allocator port for call port:eTCPOutput func:output param: outputp
 *   ER             eTCPOutput_output_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             eTCPOutput_output_outputp_dealloc( const void* buf );
 *   ER             eTCPOutput_output_outputp_reuse( void* buf );
 *   ER_UINT        eTCPOutput_output_outputp_bufferSize( const void* buf );
 *   uint32_t       eTCPOutput_output_outputp_bufferMaxSize( );
 * allocator port for call port:eTCPOutput func:respond param: outputp
 *   ER             eTCPOutput_respond_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             eTCPOutput_respond_outputp_dealloc( const void* buf );
 *   ER             eTCPOutput_respond_outputp_reuse( void* buf );
 *   ER_UINT        eTCPOutput_respond_outputp_bufferSize( const void* buf );
 *   uint32_t       eTCPOutput_respond_outputp_bufferMaxSize( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tTCPOutputBody_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

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
#include <netinet/tcp.h>
#include <netinet/tcp_var.h>
#include <netinet/tcp_fsm.h>
#include <netinet/tcp_seq.h>
#include <netinet/tcp_timer.h>

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eTaskBody
 * entry port: eTaskBody
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTaskBody_main
 * name:         eTaskBody_main
 * global_name:  tTCPOutputBody_eTaskBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTaskBody_main(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	static int_t last_ix = 0;

	T_TCP_CEP	*cep;
	ID			tskid;
 	int_t		ix, sel_ix;

	get_tid(&tskid);
	syslog(LOG_NOTICE, "[TCP OUTPUT:%d] started.", tskid);

	// tcp_init();
	cNetworkTimer_timeout(5);

#ifdef _IP6_CFG

	/* IPv6 のステートレス・アドレス自動設定を実行する。*/
	in6_if_up(IF_GET_IFNET());

#endif	/* of #ifdef _IP6_CFG */

	while (true) {

		/* 出力がポストされるまで待つ。*/
		cSemaphoreTcppost_wait();

		if (++ last_ix == NCP_cTCPOutputStart)
			last_ix = 0;
		sel_ix = ix = last_ix;
		do {
			if(cTCPOutputStart_outputStart(ix) == E_OK)
				sel_ix = ix;

			if (++ ix == NCP_cTCPOutputStart)
				ix = 0;
		} while (ix != last_ix);

		/* 次回は、処理した通信端点を後回しにする。*/
		last_ix = sel_ix;
	}
}

/* #[<ENTRY_PORT>]# eTCPOutput
 * entry port: eTCPOutput
 * signature:  sTCPOutput
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTCPOutput_output
 * name:         eTCPOutput_output
 * global_name:  tTCPOutputBody_eTCPOutput_output
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eTCPOutput_output(CELLIDX idx, int8_t* outputp, int32_t size, const int8_t* dstaddr, const int8_t* srcaddr, int32_t addrlen)
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

	if ((is_cIPv4Output_joined()) && (output->off.protocolflag & FLAG_USE_IPV4)) {
		T_IN4_ADDR dst = *((T_IN4_ADDR*)dstaddr);
		T_IN4_ADDR src = *((T_IN4_ADDR*)srcaddr);

		cIPv4Output_setHeader(output, size, dst, src);

		T_TCP_HDR *tcph = GET_TCP_HDR(output, output->off.ifhdrlen + output->off.iphdrlenall);
		tcph->sum 		= cIPv4CheckSum_ipv4CheckSum(outputp, size, output->off.ifhdrlen + output->off.iphdrlenall, IPPROTO_TCP);

		return cIPv4Output_IPv4Output(outputp, size, TMO_TCP_OUTPUT);
	}

	return E_ID;
}

/* #[<ENTRY_FUNC>]# eTCPOutput_getOffset
 * name:         eTCPOutput_getOffset
 * global_name:  tTCPOutputBody_eTCPOutput_getOffset
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eTCPOutput_getOffset(CELLIDX idx, T_OFF_BUF* offset)
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
	offset->tphdrlen = TCP_HDR_SIZE;

	if((is_cIPv4Output_joined()) && (offset->protocolflag & FLAG_USE_IPV4))
		return cIPv4Output_getOffset(offset);

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eTCPOutput_getIPv4Address
 * name:         eTCPOutput_getIPv4Address
 * global_name:  tTCPOutputBody_eTCPOutput_getIPv4Address
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
T_IN4_ADDR
eTCPOutput_getIPv4Address(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	if(is_cIPv4Output_joined())
		return cIPv4Output_getIPv4Address();
}

/* #[<ENTRY_FUNC>]# eTCPOutput_respond
 * name:         eTCPOutput_respond
 * global_name:  tTCPOutputBody_eTCPOutput_respond
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eTCPOutput_respond(CELLIDX idx, int8_t* outputp, int32_t size, T_TCP_CEP* cep, T_TCP_SEQ ack, T_TCP_SEQ seq, uint32_t rbfree, uint8_t flags)
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
	T_NET_BUF 	*output = (T_NET_BUF*)outputp;
	T_TCP_HDR	*tcph;
	uint_t		win = 0;
	uint_t		hdr_offset;

	if ((flags & TCP_FLG_RST) == 0)
		win = rbfree;
//TODO:
	/*
	 *  output が NULL でなければ、これは入力したセグメントの
	 *  net_buf で、そのまま再利用する。
	 */
	if (output != NULL) {
		uint16_t	portno;

		/*
		 * IPv4 では、IP ヘッダのオプションを削除する。
		 * IPv6 では、拡張ヘッダを削除する。
		 */
		if (IP_REMOVE_OPTIONS(output) != E_OK) {
			syscall(rel_net_buf(output));
			return;
		}

		/* IP アドレスを交換する。*/
		ip_exchg_addr(output);

#if defined(_IP6_CFG)

		/* トラヒッククラスとフローラベルをクリアする。*/
		SET_IP_CF(output, 0);

#endif	/* of #if defined(_IP6_CFG) */

		/* TCP SDU 長を 0 にする。*/
		SET_IP_SDU_SIZE(output, TCP_HDR_SIZE);

		tcph = GET_TCP_HDR(output, IF_IP_TCP_HDR_OFFSET(output));
		//TODO: tcph = GET_TCP_HDR(output, output->off.ifhdrlen + output->off.iphdrlen);

		/* ポート番号を交換する。*/
		portno 		= tcph->sport;
		tcph->sport = tcph->dport;
		tcph->dport = portno;

		/* TCP ヘッダに情報を設定する。*/
		tcph->doff = TCP_MAKE_DATA_OFF(TCP_HDR_SIZE);
		output->off.tphdrlenall = TCP_HDR_SIZE;
	}

	/* cep が NULL であれば、何もしないで終了する。*/
	else if (cep == NULL)
		return;
	else {
		if (tcpn_get_segment(&output, cep, 0,
		                    0, (uint_t)net_buf_max_siz(),
		                    NBA_SEARCH_ASCENT, TMO_TCP_GET_NET_BUF) != E_OK)
			return;
		tcph = GET_TCP_HDR(output, IF_IP_TCP_HDR_OFFSET(output));
		flags |= TCP_FLG_ACK;
	}

	tcph->seq   = htonl(seq);
	tcph->ack   = htonl(ack);
	tcph->win   = htons(win);
	tcph->flags = flags;
	tcph->urp   = tcph->sum = 0;

	/*
	 *  チェックサムを設定する。
	 */
	if (output->off.protocolflag & FLAG_USE_IPV4) {
		hdr_offset = IF_IP_TCP_HDR_OFFSET(output);
		// tcph->sum = IN_CKSUM(output, IPPROTO_TCP, hdr_offset,
		//                      (uint_t)GET_TCP_HDR_SIZE(output, hdr_offset));
		tcph->sum = cIPv4CheckSum_ipv4CheckSum(outputp,size, output->off.ifhdrlen + output->off.iphdrlen, IPPROTO_TCP);

		/* ネットワークバッファ長を調整する。*/
		output->len = (uint16_t)GET_IF_IP_TCP_HDR_SIZE(output, hdr_offset);
		// output->len = output->off.ifhdrlen - output->off.ifalign + GET_IP4_HDR_SIZE(output) + GET_TCP_HDR_SIZE2(output, output->off.ifhdrlen + output->off.iphdrlen);

#ifdef TCP_CFG_TRACE

		tcp_output_trace(output, cep);

#endif	/* of #ifdef TCP_CFG_TRACE */

		/* ネットワーク層 (IP) の出力関数を呼び出す。*/
		// IP_OUTPUT(output, TMO_TCP_OUTPUT);
		if (is_cIPv4Output_joined())
			return cIPv4Output_IPv4Reply(outputp, size, TMO_TCP_OUTPUT);
	}
	return E_ID;
}

/* #[<ENTRY_FUNC>]# eTCPOutput_allocAndRespond
 * name:         eTCPOutput_allocAndRespond
 * global_name:  tTCPOutputBody_eTCPOutput_allocAndRespond
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eTCPOutput_allocAndRespond(CELLIDX idx, const int8_t* dstaddr, const int8_t* srcaddr, int32_t addrlen, uint16_t dstport, uint16_t srcport, T_TCP_SEQ ack, T_TCP_SEQ seq, uint32_t rbfree, uint8_t flags, T_OFF_BUF offset)
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
	//TODO: 使われていないので，とりあえず後回し
	return(ercd);
}

/* #[<ENTRY_PORT>]# eCallTimerFunction
 * entry port: eCallTimerFunction
 * signature:  sCallTimerFunction
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eCallTimerFunction_callFunction
 * name:         eCallTimerFunction_callFunction
 * global_name:  tTCPOutputBody_eCallTimerFunction_callFunction
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCallTimerFunction_callFunction(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	int_t cix;

	for (cix = NCP_cTCPOutputStart; cix -- > 0; ) {
		cTCPOutputStart_timerFunction( cix );
	}

	int_t iss = cTCPFunctions_getTcpIss();

	if (iss != 0) {
		// cTCPFunctions_setTcpIss(iss + ((T_TCP_SEQ)122*1024 + (((T_TCP_SEQ)netRand() >> 14) & 0x3ffff)) / TCP_SLOW_HZ);
		cTCPFunctions_setTcpIss(iss + ((T_TCP_SEQ)122*1024 + (((T_TCP_SEQ)net_rand() >> 14) & 0x3ffff)) / TCP_SLOW_HZ);
	}

	cNetworkTimer_timeout(5);	/* 500ms間隔で呼び出されるタイマ関数 */
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
