/*
 *   Copyright (C) 2008-2017 by TOPPERS Project
 *
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 * 
 *  @(#) $Id: nTECSInfo_tCelltypeInfo.c 2640 2017-06-03 11:27:12Z okuma-top $
 */

/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * name             char_t*          ATTR_name       
 * bSingleton       bool_t           ATTR_bSingleton 
 * bIDX_is_ID       bool_t           ATTR_bIDX_is_ID 
 * b_hasCB          bool_t           ATTR_b_hasCB    
 * b_hasINIB        bool_t           ATTR_b_hasINIB  
 *
 * 呼び口関数 #_TCPF_#
 * call port: cEntryInfo signature: nTECSInfo_sEntryInfo context:task optional:true
 *   bool_t     is_cEntryInfo_joined(int subscript)        check if joined
 *   ER             cEntryInfo_getName( subscript, char_t* name, int_t max_len );
 *   void           cEntryInfo_getNameLength( subscript, uint16_t* len );
 *   void           cEntryInfo_getSignatureInfo( subscript, Descriptor( nTECSInfo_sSignatureInfo )* desc );
 *   void           cEntryInfo_getArraySize( subscript, uint32_t* array_size );
 *   bool_t         cEntryInfo_isInline( subscript );
 *       subscript:  0...(NCP_cEntryInfo-1)
 *   [ref_desc]
 *      Descriptor( nTECSInfo_sEntryInfo ) cEntryInfo_refer_to_descriptor( int_t subscript );
 *      Descriptor( nTECSInfo_sEntryInfo ) cEntryInfo_ref_desc( int_t subscript )      (same as above; abbreviated version);
 * call port: cCallInfo signature: nTECSInfo_sCallInfo context:task optional:true
 *   bool_t     is_cCallInfo_joined(int subscript)        check if joined
 *   ER             cCallInfo_getName( subscript, char_t* name, int_t max_len );
 *   void           cCallInfo_getNameLength( subscript, uint16_t* len );
 *   void           cCallInfo_getSignatureInfo( subscript, Descriptor( nTECSInfo_sSignatureInfo )* desc );
 *   void           cCallInfo_getArraySize( subscript, uint32_t* array_size );
 *   bool_t         cCallInfo_isOptional( subscript );
 *   bool_t         cCallInfo_isDynamic( subscript );
 *   bool_t         cCallInfo_isRefDesc( subscript );
 *   bool_t         cCallInfo_isOmit( subscript );
 *       subscript:  0...(NCP_cCallInfo-1)
 *   [ref_desc]
 *      Descriptor( nTECSInfo_sCallInfo ) cCallInfo_refer_to_descriptor( int_t subscript );
 *      Descriptor( nTECSInfo_sCallInfo ) cCallInfo_ref_desc( int_t subscript )      (same as above; abbreviated version);
 * call port: cAttrInfo signature: nTECSInfo_sVarDeclInfo context:task optional:true
 *   bool_t     is_cAttrInfo_joined(int subscript)        check if joined
 *   ER             cAttrInfo_getName( subscript, char_t* name, int_t max_len );
 *   void           cAttrInfo_getOffset( subscript, uint32_t* offset );
 *   void           cAttrInfo_getTypeInfo( subscript, Descriptor( nTECSInfo_sTypeInfo )* desc );
 *   void           cAttrInfo_getSizeIsExpr( subscript, uint32_t* expr_str, int32_t max_len );
 *   ER             cAttrInfo_getSizeIs( subscript, uint32_t* size, const void* p_cb );
 *   bool_t         cAttrInfo_isInCB( subscript );
 *       subscript:  0...(NCP_cAttrInfo-1)
 *   [ref_desc]
 *      Descriptor( nTECSInfo_sVarDeclInfo ) cAttrInfo_refer_to_descriptor( int_t subscript );
 *      Descriptor( nTECSInfo_sVarDeclInfo ) cAttrInfo_ref_desc( int_t subscript )      (same as above; abbreviated version);
 * call port: cVarInfo signature: nTECSInfo_sVarDeclInfo context:task optional:true
 *   bool_t     is_cVarInfo_joined(int subscript)        check if joined
 *   ER             cVarInfo_getName( subscript, char_t* name, int_t max_len );
 *   void           cVarInfo_getOffset( subscript, uint32_t* offset );
 *   void           cVarInfo_getTypeInfo( subscript, Descriptor( nTECSInfo_sTypeInfo )* desc );
 *   void           cVarInfo_getSizeIsExpr( subscript, uint32_t* expr_str, int32_t max_len );
 *   ER             cVarInfo_getSizeIs( subscript, uint32_t* size, const void* p_cb );
 *   bool_t         cVarInfo_isInCB( subscript );
 *       subscript:  0...(NCP_cVarInfo-1)
 *   [ref_desc]
 *      Descriptor( nTECSInfo_sVarDeclInfo ) cVarInfo_refer_to_descriptor( int_t subscript );
 *      Descriptor( nTECSInfo_sVarDeclInfo ) cVarInfo_ref_desc( int_t subscript )      (same as above; abbreviated version);
 *
 * #[</PREAMBLE>]# */

/* Put prototype declaration and/or variale definition here #_PAC_# */
#include "nTECSInfo_tCelltypeInfo_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* entry port function #_TEPF_# */
/* #[<ENTRY_PORT>]# eCelltypeInfo
 * entry port: eCelltypeInfo
 * signature:  nTECSInfo_sCelltypeInfo
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eCelltypeInfo_getName
 * name:         eCelltypeInfo_getName
 * global_name:  nTECSInfo_tCelltypeInfo_eCelltypeInfo_getName
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eCelltypeInfo_getName(CELLIDX idx, char_t* name, int_t max_len)
{
	ER		ercd = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eCelltypeInfo_getNameLength
 * name:         eCelltypeInfo_getNameLength
 * global_name:  nTECSInfo_tCelltypeInfo_eCelltypeInfo_getNameLength
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCelltypeInfo_getNameLength(CELLIDX idx, uint16_t* len)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eCelltypeInfo_getNAttr
 * name:         eCelltypeInfo_getNAttr
 * global_name:  nTECSInfo_tCelltypeInfo_eCelltypeInfo_getNAttr
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCelltypeInfo_getNAttr(CELLIDX idx, int32_t* nAttr)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eCelltypeInfo_getAttrInfo
 * name:         eCelltypeInfo_getAttrInfo
 * global_name:  nTECSInfo_tCelltypeInfo_eCelltypeInfo_getAttrInfo
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCelltypeInfo_getAttrInfo(CELLIDX idx, int32_t ith, Descriptor( nTECSInfo_sVarDeclInfo )* desc)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eCelltypeInfo_getNVar
 * name:         eCelltypeInfo_getNVar
 * global_name:  nTECSInfo_tCelltypeInfo_eCelltypeInfo_getNVar
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCelltypeInfo_getNVar(CELLIDX idx, int32_t* nVar)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eCelltypeInfo_getVarInfo
 * name:         eCelltypeInfo_getVarInfo
 * global_name:  nTECSInfo_tCelltypeInfo_eCelltypeInfo_getVarInfo
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCelltypeInfo_getVarInfo(CELLIDX idx, int32_t ith, Descriptor( nTECSInfo_sVarDeclInfo )* desc)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eCelltypeInfo_getNCall
 * name:         eCelltypeInfo_getNCall
 * global_name:  nTECSInfo_tCelltypeInfo_eCelltypeInfo_getNCall
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCelltypeInfo_getNCall(CELLIDX idx, int32_t* nCall)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eCelltypeInfo_getCallInfo
 * name:         eCelltypeInfo_getCallInfo
 * global_name:  nTECSInfo_tCelltypeInfo_eCelltypeInfo_getCallInfo
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCelltypeInfo_getCallInfo(CELLIDX idx, int32_t ith, Descriptor( nTECSInfo_sCallInfo )* desc)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eCelltypeInfo_getNEntry
 * name:         eCelltypeInfo_getNEntry
 * global_name:  nTECSInfo_tCelltypeInfo_eCelltypeInfo_getNEntry
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCelltypeInfo_getNEntry(CELLIDX idx, int32_t* nEntry)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eCelltypeInfo_getEntryInfo
 * name:         eCelltypeInfo_getEntryInfo
 * global_name:  nTECSInfo_tCelltypeInfo_eCelltypeInfo_getEntryInfo
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCelltypeInfo_getEntryInfo(CELLIDX idx, int32_t ith, Descriptor( nTECSInfo_sEntryInfo )* desc)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eCelltypeInfo_isSingleton
 * name:         eCelltypeInfo_isSingleton
 * global_name:  nTECSInfo_tCelltypeInfo_eCelltypeInfo_isSingleton
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
bool_t
eCelltypeInfo_isSingleton(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eCelltypeInfo_isIDX_is_ID
 * name:         eCelltypeInfo_isIDX_is_ID
 * global_name:  nTECSInfo_tCelltypeInfo_eCelltypeInfo_isIDX_is_ID
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
bool_t
eCelltypeInfo_isIDX_is_ID(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eCelltypeInfo_hasCB
 * name:         eCelltypeInfo_hasCB
 * global_name:  nTECSInfo_tCelltypeInfo_eCelltypeInfo_hasCB
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
bool_t
eCelltypeInfo_hasCB(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eCelltypeInfo_hasINIB
 * name:         eCelltypeInfo_hasINIB
 * global_name:  nTECSInfo_tCelltypeInfo_eCelltypeInfo_hasINIB
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
bool_t
eCelltypeInfo_hasINIB(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
