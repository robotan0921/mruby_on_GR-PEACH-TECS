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
 *  @(#) $Id: nTECSInfo_tNamespaceInfo.c 2640 2017-06-03 11:27:12Z okuma-top $
 */

/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * name             char*            ATTR_name       
 *
 * 呼び口関数 #_TCPF_#
 * call port: cSignatureInfo signature: nTECSInfo_sSignatureInfo context:task optional:true
 *   bool_t     is_cSignatureInfo_joined(int subscript)        check if joined
 *   ER             cSignatureInfo_getName( subscript, char_t* name, int_t max_len );
 *   void           cSignatureInfo_getNameLength( subscript, uint16_t* len );
 *   void           cSignatureInfo_getNFunction( subscript, int32_t* num );
 *   void           cSignatureInfo_getFunctionInfo( subscript, int32_t ith, Descriptor( nTECSInfo_sFunctionInfo )* desc );
 *       subscript:  0...(NCP_cSignatureInfo-1)
 *   [ref_desc]
 *      Descriptor( nTECSInfo_sSignatureInfo ) cSignatureInfo_refer_to_descriptor( int_t subscript );
 *      Descriptor( nTECSInfo_sSignatureInfo ) cSignatureInfo_ref_desc( int_t subscript )      (same as above; abbreviated version);
 * call port: cCelltypeInfo signature: nTECSInfo_sCelltypeInfo context:task optional:true
 *   bool_t     is_cCelltypeInfo_joined(int subscript)        check if joined
 *   ER             cCelltypeInfo_getName( subscript, char_t* name, int_t max_len );
 *   void           cCelltypeInfo_getNameLength( subscript, uint16_t* len );
 *   void           cCelltypeInfo_getNAttr( subscript, int32_t* nAttr );
 *   void           cCelltypeInfo_getAttrInfo( subscript, int32_t ith, Descriptor( nTECSInfo_sAttrVarInfo )* desc );
 *   void           cCelltypeInfo_getNVar( subscript, int32_t* nVar );
 *   void           cCelltypeInfo_getVarInfo( subscript, int32_t ith, Descriptor( nTECSInfo_sAttrVarInfo )* desc );
 *   void           cCelltypeInfo_getNCall( subscript, int32_t* nCall );
 *   void           cCelltypeInfo_getCallInfo( subscript, int32_t ith, Descriptor( nTECSInfo_sCallInfo )* desc );
 *   void           cCelltypeInfo_getNEntry( subscript, int32_t* nEntry );
 *   void           cCelltypeInfo_getEntryInfo( subscript, int32_t ith, Descriptor( nTECSInfo_sEntryInfo )* desc );
 *   bool_t         cCelltypeInfo_isSingleton( subscript );
 *   bool_t         cCelltypeInfo_isIDX_is_ID( subscript );
 *   bool_t         cCelltypeInfo_hasCB( subscript );
 *   bool_t         cCelltypeInfo_hasINIB( subscript );
 *       subscript:  0...(NCP_cCelltypeInfo-1)
 *   [ref_desc]
 *      Descriptor( nTECSInfo_sCelltypeInfo ) cCelltypeInfo_refer_to_descriptor( int_t subscript );
 *      Descriptor( nTECSInfo_sCelltypeInfo ) cCelltypeInfo_ref_desc( int_t subscript )      (same as above; abbreviated version);
 * call port: cNamespaceInfo signature: nTECSInfo_sNamespaceInfo context:task optional:true
 *   bool_t     is_cNamespaceInfo_joined(int subscript)        check if joined
 *   ER             cNamespaceInfo_getName( subscript, char_t* name, int_t max_len );
 *   void           cNamespaceInfo_getNameLength( subscript, uint16_t* len );
 *   void           cNamespaceInfo_getNNamespace( subscript, int32_t* num );
 *   void           cNamespaceInfo_getNamespaceInfo( subscript, int32_t ith, Descriptor( nTECSInfo_sNamespaceInfo )* des );
 *   void           cNamespaceInfo_getNSignature( subscript, int32_t* num );
 *   void           cNamespaceInfo_getSignatureInfo( subscript, int32_t ith, Descriptor( nTECSInfo_sSignatureInfo )* des );
 *   void           cNamespaceInfo_getNCelltype( subscript, int32_t* num );
 *   void           cNamespaceInfo_getCelltypeInfo( subscript, int32_t ith, Descriptor( nTECSInfo_sCelltypeInfo )* des );
 *       subscript:  0...(NCP_cNamespaceInfo-1)
 *   [ref_desc]
 *      Descriptor( nTECSInfo_sNamespaceInfo ) cNamespaceInfo_refer_to_descriptor( int_t subscript );
 *      Descriptor( nTECSInfo_sNamespaceInfo ) cNamespaceInfo_ref_desc( int_t subscript )      (same as above; abbreviated version);
 *
 * #[</PREAMBLE>]# */

/* Put prototype declaration and/or variale definition here #_PAC_# */
#include "nTECSInfo_tNamespaceInfo_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* entry port function #_TEPF_# */
/* #[<ENTRY_PORT>]# eNamespaceInfo
 * entry port: eNamespaceInfo
 * signature:  nTECSInfo_sNamespaceInfo
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eNamespaceInfo_getName
 * name:         eNamespaceInfo_getName
 * global_name:  nTECSInfo_tNamespaceInfo_eNamespaceInfo_getName
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eNamespaceInfo_getName(CELLIDX idx, char_t* name, int_t max_len)
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

/* #[<ENTRY_FUNC>]# eNamespaceInfo_getNameLength
 * name:         eNamespaceInfo_getNameLength
 * global_name:  nTECSInfo_tNamespaceInfo_eNamespaceInfo_getNameLength
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eNamespaceInfo_getNameLength(CELLIDX idx, uint16_t* len)
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

/* #[<ENTRY_FUNC>]# eNamespaceInfo_getNNamespace
 * name:         eNamespaceInfo_getNNamespace
 * global_name:  nTECSInfo_tNamespaceInfo_eNamespaceInfo_getNNamespace
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eNamespaceInfo_getNNamespace(CELLIDX idx, int32_t* num)
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

/* #[<ENTRY_FUNC>]# eNamespaceInfo_getNamespaceInfo
 * name:         eNamespaceInfo_getNamespaceInfo
 * global_name:  nTECSInfo_tNamespaceInfo_eNamespaceInfo_getNamespaceInfo
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eNamespaceInfo_getNamespaceInfo(CELLIDX idx, int32_t ith, Descriptor( nTECSInfo_sNamespaceInfo )* des)
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

/* #[<ENTRY_FUNC>]# eNamespaceInfo_getNSignature
 * name:         eNamespaceInfo_getNSignature
 * global_name:  nTECSInfo_tNamespaceInfo_eNamespaceInfo_getNSignature
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eNamespaceInfo_getNSignature(CELLIDX idx, int32_t* num)
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

/* #[<ENTRY_FUNC>]# eNamespaceInfo_getSignatureInfo
 * name:         eNamespaceInfo_getSignatureInfo
 * global_name:  nTECSInfo_tNamespaceInfo_eNamespaceInfo_getSignatureInfo
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eNamespaceInfo_getSignatureInfo(CELLIDX idx, int32_t ith, Descriptor( nTECSInfo_sSignatureInfo )* des)
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

/* #[<ENTRY_FUNC>]# eNamespaceInfo_getNCelltype
 * name:         eNamespaceInfo_getNCelltype
 * global_name:  nTECSInfo_tNamespaceInfo_eNamespaceInfo_getNCelltype
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eNamespaceInfo_getNCelltype(CELLIDX idx, int32_t* num)
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

/* #[<ENTRY_FUNC>]# eNamespaceInfo_getCelltypeInfo
 * name:         eNamespaceInfo_getCelltypeInfo
 * global_name:  nTECSInfo_tNamespaceInfo_eNamespaceInfo_getCelltypeInfo
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eNamespaceInfo_getCelltypeInfo(CELLIDX idx, int32_t ith, Descriptor( nTECSInfo_sCelltypeInfo )* des)
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
