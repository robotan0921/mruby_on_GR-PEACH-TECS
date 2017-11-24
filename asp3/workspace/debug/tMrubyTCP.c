/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tMrubyTCP_template.c => src/tMrubyTCP.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cAPI signature: sTCPCEPAPI4 context:task
 *   ER             cAPI_accept( Descriptor( sREP4 ) desc, T_IPV4EP* dstep4, TMO tmout );
 *   ER             cAPI_connect( T_IN4_ADDR myaddr, uint16_t myport, T_IN4_ADDR dstaddr, uint16_t dstport, TMO tmout );
 *   ER_UINT        cAPI_send( const int8_t* data, int32_t len, TMO tmout );
 *   ER_UINT        cAPI_receive( int8_t* data, int32_t len, TMO tmout );
 *   ER             cAPI_cancel( FN fncd );
 *   ER             cAPI_close( TMO tmout );
 *   ER             cAPI_shutdown( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tMrubyTCP_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eMrubyTCP
 * entry port: eMrubyTCP
 * signature:  sMrubyTCP
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eMrubyTCP_accept
 * name:         eMrubyTCP_accept
 * global_name:  tMrubyTCP_eMrubyTCP_accept
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eMrubyTCP_accept(CELLIDX idx, uint16_t descid, uint32_t* ipaddr, uint16_t* portno, TMO tmout)
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
	T_IPV4EP dstep4;
    Descriptor(sREP4) desc;
    cRepSelector_getRep(&desc, descid);

	ercd = cAPI_accept(desc, &dstep4, tmout);

	*ipaddr = dstep4.ipaddr;
	*portno = dstep4.portno;

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eMrubyTCP_connect
 * name:         eMrubyTCP_connect
 * global_name:  tMrubyTCP_eMrubyTCP_connect
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eMrubyTCP_connect(CELLIDX idx, T_IN4_ADDR myaddr, uint16_t myport, T_IN4_ADDR dstaddr, uint16_t dstport, TMO tmout)
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

/* #[<ENTRY_FUNC>]# eMrubyTCP_send
 * name:         eMrubyTCP_send
 * global_name:  tMrubyTCP_eMrubyTCP_send
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER_UINT
eMrubyTCP_send(CELLIDX idx, const char_t* data, int32_t len, TMO tmout)
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

	return cAPI_send(data, len, tmout);
}

/* #[<ENTRY_FUNC>]# eMrubyTCP_receive
 * name:         eMrubyTCP_receive
 * global_name:  tMrubyTCP_eMrubyTCP_receive
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER_UINT
eMrubyTCP_receive(CELLIDX idx, char_t* data, int32_t len, TMO tmout)
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

/* #[<ENTRY_FUNC>]# eMrubyTCP_cancel
 * name:         eMrubyTCP_cancel
 * global_name:  tMrubyTCP_eMrubyTCP_cancel
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eMrubyTCP_cancel(CELLIDX idx, FN fncd)
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

/* #[<ENTRY_FUNC>]# eMrubyTCP_close
 * name:         eMrubyTCP_close
 * global_name:  tMrubyTCP_eMrubyTCP_close
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eMrubyTCP_close(CELLIDX idx, TMO tmout)
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

/* #[<ENTRY_FUNC>]# eMrubyTCP_shutdown
 * name:         eMrubyTCP_shutdown
 * global_name:  tMrubyTCP_eMrubyTCP_shutdown
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eMrubyTCP_shutdown(CELLIDX idx)
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

/* #[<ENTRY_FUNC>]# eMrubyTCP_make_ipv4_addr
 * name:         eMrubyTCP_make_ipv4_addr
 * global_name:  tMrubyTCP_eMrubyTCP_make_ipv4_addr
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
uint32_t
eMrubyTCP_make_ipv4_addr(CELLIDX idx, uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	uint32_t addr = MAKE_IPV4_ADDR(a, b, c, d);
	return addr;
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
