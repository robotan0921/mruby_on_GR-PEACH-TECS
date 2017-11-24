/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tLED_template.c => src/tLED.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tLED_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eLED
 * entry port: eLED
 * signature:  sLED
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eLED_setColor
 * name:         eLED_setColor
 * global_name:  tLED_eLED_setColor
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eLED_setColor(CELLIDX idx, uint_t color)
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
	gr_peach_set_led(color, 1);

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eLED_off
 * name:         eLED_off
 * global_name:  tLED_eLED_off
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eLED_off(CELLIDX idx)
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
	gr_peach_set_led(GR_PEACH_LED_RED, 0);
	gr_peach_set_led(GR_PEACH_LED_GREEN, 0);
	gr_peach_set_led(GR_PEACH_LED_BLUE, 0);

	return(ercd);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
