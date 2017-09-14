/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tUDPCEPwrapper4_template.c => src/tUDPCEPwrapper4.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * v4addr           T_IN4_ADDR       ATTR_v4addr
 * addr             T_IN4_ADDR       VAR_addr
 *
 * 呼び口関数 #_TCPF_#
 * call port: cAPI signature: sUDPCEPAPI context:task
 *   ER_UINT        cAPI_send( const int8_t* data, int32_t len, const int8_t* dstaddr, int32_t addrlen, uint16_t dstport, TMO tmout );
 *   ER_UINT        cAPI_receive( int8_t* data, int32_t len, TMO tmout );
 *   ER             cAPI_cancelSend( ER error );
 *   ER             cAPI_celcelReceive( ER error );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tUDPCEPwrapper4_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eAPI4
 * entry port: eAPI4
 * signature:  sUDPCEPAPI4
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eAPI4_send
 * name:         eAPI4_send
 * global_name:  tUDPCEPwrapper4_eAPI4_send
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER_UINT
eAPI4_send(CELLIDX idx, const int8_t* data, int32_t len, T_IN4_ADDR dstaddr, uint16_t dstport, TMO tmout)
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
	return cAPI_send(data, len, (int8_t*)&dstaddr, 4, dstport, tmout);
}

/* #[<ENTRY_FUNC>]# eAPI4_receive
 * name:         eAPI4_receive
 * global_name:  tUDPCEPwrapper4_eAPI4_receive
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER_UINT
eAPI4_receive(CELLIDX idx, int8_t* data, int32_t len, TMO tmout)
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
	return cAPI_receive(data, len, tmout);
}

/* #[<ENTRY_FUNC>]# eAPI4_cancelSend
 * name:         eAPI4_cancelSend
 * global_name:  tUDPCEPwrapper4_eAPI4_cancelSend
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eAPI4_cancelSend(CELLIDX idx, ER error)
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
	return cAPI_cancelSend(error);
}

/* #[<ENTRY_FUNC>]# eAPI4_cancelReceive
 * name:         eAPI4_cancelReceive
 * global_name:  tUDPCEPwrapper4_eAPI4_cancelReceive
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eAPI4_cancelReceive(CELLIDX idx, ER error)
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
	return cAPI_celcelReceive(error);
}

/* #[<ENTRY_PORT>]# eGetAddress4
 * entry port: eGetAddress4
 * signature:  sGetAddress
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eGetAddress4_getAddress
 * name:         eGetAddress4_getAddress
 * global_name:  tUDPCEPwrapper4_eGetAddress4_getAddress
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
int8_t*
eGetAddress4_getAddress(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return (int8_t*)&VAR_addr;
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
