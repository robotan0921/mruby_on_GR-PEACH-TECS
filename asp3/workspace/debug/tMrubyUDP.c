/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tMrubyUDP_template.c => src/tMrubyUDP.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cAPI signature: sUDPCEPAPI4 context:task
 *   ER_UINT        cAPI_send( const int8_t* data, int32_t len, T_IN4_ADDR dstaddr, uint16_t dstport, TMO tmout );
 *   ER_UINT        cAPI_receive( int8_t* data, int32_t len, TMO tmout );
 *   ER             cAPI_cancelSend( ER error );
 *   ER             cAPI_cancelReceive( ER error );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tMrubyUDP_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

#include "t_syslog.h"

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eMrubyUDP
 * entry port: eMrubyUDP
 * signature:  sMrubyUDP
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eMrubyUDP_send
 * name:         eMrubyUDP_send
 * global_name:  tMrubyUDP_eMrubyUDP_send
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER_UINT
eMrubyUDP_send(CELLIDX idx, const char_t* data, int32_t len, uint32_t dstaddr, uint16_t dstport, TMO tmout)
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
	syslog(LOG_NOTICE, "==eMrubyUDP_send==");
	syslog(LOG_NOTICE, "data = %s", data);
	syslog(LOG_NOTICE, "len = %d", len);
	syslog(LOG_NOTICE, "dstaddr = %d", dstaddr);
	syslog(LOG_NOTICE, "dstport = %d", dstport);
	syslog(LOG_NOTICE, "tmout = %d", tmout);
	return cAPI_send(data, len, dstaddr, dstport, tmout);
}

/* #[<ENTRY_FUNC>]# eMrubyUDP_receive
 * name:         eMrubyUDP_receive
 * global_name:  tMrubyUDP_eMrubyUDP_receive
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER_UINT
eMrubyUDP_receive(CELLIDX idx, char_t* data, int32_t len, TMO tmout)
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
	// data = "Hello, world!";
	strncpy(data, "Hello, world!\n", len);
	data[len-1] = '\0';
	syslog(LOG_NOTICE, "==eMrubyUDP_receive==");
	syslog(LOG_NOTICE, "data = %s", data);
	syslog(LOG_NOTICE, "len = %d", len);
	syslog(LOG_NOTICE, "tmout = %d", tmout);
	return ercd;
	// return cAPI_receive(data, len, tmout);
}

/* #[<ENTRY_FUNC>]# eMrubyUDP_cancelSend
 * name:         eMrubyUDP_cancelSend
 * global_name:  tMrubyUDP_eMrubyUDP_cancelSend
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eMrubyUDP_cancelSend(CELLIDX idx, ER error)
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

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eMrubyUDP_cancelReceive
 * name:         eMrubyUDP_cancelReceive
 * global_name:  tMrubyUDP_eMrubyUDP_cancelReceive
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eMrubyUDP_cancelReceive(CELLIDX idx, ER error)
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

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eMrubyUDP_make_ipv4_addr
 * name:         eMrubyUDP_make_ipv4_addr
 * global_name:  tMrubyUDP_eMrubyUDP_make_ipv4_addr
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
uint32_t
eMrubyUDP_make_ipv4_addr(CELLIDX idx, uint32_t a, uint32_t b, uint32_t c, uint32_t d)
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
	uint32_t addr = MAKE_IPV4_ADDR(a, b, c, d);
	syslog(LOG_NOTICE, "addr = %d", addr);
	return addr;
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
