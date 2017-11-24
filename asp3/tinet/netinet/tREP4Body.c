/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tREP4Body_template.c => src/tREP4Body.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * repatr           ATR              ATTR_repatr
 * myaddr           T_IN4_ADDR       ATTR_myaddr
 * myport           uint16_t         ATTR_myport
 *
 * 呼び口関数 #_TCPF_#
 * call port: cSemaphore signature: sSemaphore context:task
 *   ER             cSemaphore_signal( );
 *   ER             cSemaphore_wait( );
 *   ER             cSemaphore_waitPolling( );
 *   ER             cSemaphore_waitTimeout( TMO timeout );
 *   ER             cSemaphore_initialize( );
 *   ER             cSemaphore_refer( T_RSEM* pk_semaphoreStatus );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tREP4Body_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eREP4
 * entry port: eREP4
 * signature:  sREP4
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eREP4_getEndpoint
 * name:         eREP4_getEndpoint
 * global_name:  tREP4Body_eREP4_getEndpoint
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
T_IPV4EP
eREP4_getEndpoint(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	T_IPV4EP ep4;

	ep4.ipaddr = ATTR_myaddr;
	ep4.portno = ATTR_myport;

	return ep4;
}

/* #[<ENTRY_FUNC>]# eREP4_signal
 * name:         eREP4_signal
 * global_name:  tREP4Body_eREP4_signal
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eREP4_signal(CELLIDX idx)
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

	return cSemaphore_signal();
}

/* #[<ENTRY_FUNC>]# eREP4_wait
 * name:         eREP4_wait
 * global_name:  tREP4Body_eREP4_wait
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eREP4_wait(CELLIDX idx)
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

	return cSemaphore_wait();
}

/* #[<ENTRY_FUNC>]# eREP4_waitPolling
 * name:         eREP4_waitPolling
 * global_name:  tREP4Body_eREP4_waitPolling
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eREP4_waitPolling(CELLIDX idx)
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

	return cSemaphore_waitPolling();
}

/* #[<ENTRY_FUNC>]# eREP4_waitTimeout
 * name:         eREP4_waitTimeout
 * global_name:  tREP4Body_eREP4_waitTimeout
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eREP4_waitTimeout(CELLIDX idx, TMO timeout)
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

	return cSemaphore_waitTimeout(timeout);
}

/* #[<ENTRY_FUNC>]# eREP4_initialize
 * name:         eREP4_initialize
 * global_name:  tREP4Body_eREP4_initialize
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eREP4_initialize(CELLIDX idx)
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

	return cSemaphore_initialize();
}

/* #[<ENTRY_FUNC>]# eREP4_refer
 * name:         eREP4_refer
 * global_name:  tREP4Body_eREP4_refer
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eREP4_refer(CELLIDX idx, T_RSEM* pk_semaphoreStatus)
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

	return cSemaphore_refer(pk_semaphoreStatus);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
