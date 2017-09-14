/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tRepSelector_template.c => src/tRepSelector.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * name             char*            ATTR_name
 *
 * 呼び口関数 #_TCPF_#
 * call port: cREP signature: sREP4 context:task
 *   T_IPV4EP       cREP_getEndpoint( subscript );
 *   ER             cREP_signal( subscript );
 *   ER             cREP_wait( subscript );
 *   ER             cREP_waitPolling( subscript );
 *   ER             cREP_waitTimeout( subscript, TMO timeout );
 *   ER             cREP_initialize( subscript );
 *   ER             cREP_refer( subscript, T_RSEM* pk_semaphoreStatus );
 *       subscript:  0...(NCP_cREP-1)
 *   [ref_desc]
 *      Descriptor( sREP4 ) cREP_refer_to_descriptor( int_t subscript );
 *      Descriptor( sREP4 ) cREP_ref_desc( int_t subscript )      (same as above; abbreviated version);
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tRepSelector_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eRepSelector
 * entry port: eRepSelector
 * signature:  sRepSelector
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eRepSelector_getRep
 * name:         eRepSelector_getRep
 * global_name:  tRepSelector_eRepSelector_getRep
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eRepSelector_getRep(CELLIDX idx, Descriptor( sREP4 )* desc, int_t i)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	*desc = cREP_refer_to_descriptor(i);
}

/* #[<ENTRY_FUNC>]# eRepSelector_getNRep
 * name:         eRepSelector_getNRep
 * global_name:  tRepSelector_eRepSelector_getNRep
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eRepSelector_getNRep(CELLIDX idx, int_t* n)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	*n = NCP_cREP;
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
