/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tCopySave_template.c => src/tCopySave.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cSemaphore signature: sSemaphore context:task
 *   ER             cSemaphore_signal( );
 *   ER             cSemaphore_wait( );
 *   ER             cSemaphore_waitPolling( );
 *   ER             cSemaphore_waitTimeout( TMO timeout );
 *   ER             cSemaphore_initialize( );
 *   ER             cSemaphore_refer( T_RSEM* pk_semaphoreStatus );
 * call port: cSemaphoreTcppost signature: sSemaphore context:task
 *   ER             cSemaphoreTcppost_signal( );
 *   ER             cSemaphoreTcppost_wait( );
 *   ER             cSemaphoreTcppost_waitPolling( );
 *   ER             cSemaphoreTcppost_waitTimeout( TMO timeout );
 *   ER             cSemaphoreTcppost_initialize( );
 *   ER             cSemaphoreTcppost_refer( T_RSEM* pk_semaphoreStatus );
 * call port: cSendFlag signature: sEventflag context:task
 *   ER             cSendFlag_set( FLGPTN setPattern );
 *   ER             cSendFlag_clear( FLGPTN clearPattern );
 *   ER             cSendFlag_wait( FLGPTN waitPattern, MODE waitMode, FLGPTN* p_flagPattern );
 *   ER             cSendFlag_waitPolling( FLGPTN waitPattern, MODE waitMode, FLGPTN* p_flagPattern );
 *   ER             cSendFlag_waitTimeout( FLGPTN waitPattern, MODE waitMode, FLGPTN* p_flagPattern, TMO timeout );
 *   ER             cSendFlag_initialize( );
 *   ER             cSendFlag_refer( T_RFLG* pk_eventflagStatus );
 * call port: cRcvFlag signature: sEventflag context:task
 *   ER             cRcvFlag_set( FLGPTN setPattern );
 *   ER             cRcvFlag_clear( FLGPTN clearPattern );
 *   ER             cRcvFlag_wait( FLGPTN waitPattern, MODE waitMode, FLGPTN* p_flagPattern );
 *   ER             cRcvFlag_waitPolling( FLGPTN waitPattern, MODE waitMode, FLGPTN* p_flagPattern );
 *   ER             cRcvFlag_waitTimeout( FLGPTN waitPattern, MODE waitMode, FLGPTN* p_flagPattern, TMO timeout );
 *   ER             cRcvFlag_initialize( );
 *   ER             cRcvFlag_refer( T_RFLG* pk_eventflagStatus );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tCopySave_tecsgen.h"

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
#include <net/if_arp.h>
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
/* #[<ENTRY_PORT>]# eCopySave
 * entry port: eCopySave
 * signature:  sCopySave
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eCopySave_tcpWriteRwbuf
 * name:         eCopySave_tcpWriteRwbuf
 * global_name:  tCopySave_eCopySave_tcpWriteRwbuf
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
/*
 *  tcp_write_rwbuf -- 受信ウィンドバッファにデータを書き込む。
 *
 *    注意:
 *	入力 input は、T_TCP_Q_HDR によりリンクされ、
 *	並べ替えが終了していなければならない。また、
 *	追加するデータは、受信ウィンドバッファに収まること。
 */
void
eCopySave_tcpWriteRwbuf(CELLIDX idx, T_TCP_CEP* cep, int8_t* inputp, int32_t size, uint8_t thoff, int8_t* rbuf, int32_t len)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	T_TCP_Q_HDR	*qhdr;
	T_NET_BUF 	*input = (T_NET_BUF*)inputp;
	uint_t		offset, inlen, last;

	/* 通信端点をロックする。*/
	cSemaphore_wait();

	qhdr  = (T_TCP_Q_HDR*)GET_TCP_HDR(input, thoff);

	/* 受信済みシーケンス番号を更新する。*/
	cep->rcv_nxt += qhdr->slen;

	last  = cep->rwbuf_count;
	inlen = qhdr->slen;

	/* 緊急データの SDU 補正を行う。*/
	if (qhdr->urp > 0 && inlen > 0) {
		inlen      -= qhdr->urp;
		qhdr->slen -= qhdr->urp;
		qhdr->urp   = 0;
	}

	/*
	 *  FIN フラグが付いたセグメントは inlen == 0 になることもある。
	 *  これは、アプリケーションに、相手からこれ以上データが送られて
	 *  こないことを知らせるためである。
	 */
	if (inlen > 0) {

		/* 書き込みポインタがラウンドするときの処理 */
		if (inlen > len - (cep->rbuf_wptr - (uint8_t*)rbuf)) {
			offset = (uint_t)(len - (cep->rbuf_wptr - (uint8_t*)rbuf));
			memcpy(cep->rbuf_wptr, (void*)(GET_TCP_SDU(input, thoff) + qhdr->soff), (size_t)offset);
			cep->rbuf_wptr   = (uint8_t*)rbuf;
			cep->rwbuf_count += offset;
			inlen           -= offset;
		}
		else
		  offset = 0;

		memcpy(cep->rbuf_wptr, (void*)(GET_TCP_SDU(input, thoff) + qhdr->soff + offset), (size_t)inlen);
		cep->rbuf_wptr  += inlen;
		cep->rwbuf_count += inlen;

	}

	/* 通信端点のロックを解除する。*/
	cSemaphore_signal();

	if (inlen == 0 && cep->rwbuf_count == 0) {
		/*
		 *  受信ウィンドバッファ内のデータ数が 0 で、
		 *  相手から FIN フラグが付いたセグメントを受信したときは、
		 *  通信端点をロックして、
		 *  受信ウィンドバッファキューのネットワークバッファを解放する。
		 */
		cSemaphore_wait();
		eCopySave_tcpFreeRwbufq(idx, cep);
		cSemaphore_signal();
	}

	/*
	 *  受信ウィンドバッファにデータが入るか、 inlen == 0 の時、入力タスクを起床する。
	 *  FIN フラグが付いたセグメントは inlen == 0 になることもある。
	 *  これは、アプリケーションに、相手からこれ以上データが送られて
	 *  こないことを知らせるためである。
	 */
	if ((last == 0 && cep->rwbuf_count > 0) || inlen == 0)
	  cRcvFlag_set(TCP_CEP_EVT_RWBUF_READY);
}

/* #[<ENTRY_FUNC>]# eCopySave_tcpReadSwbuf
 * name:         eCopySave_tcpReadSwbuf
 * global_name:  tCopySave_eCopySave_tcpReadSwbuf
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCopySave_tcpReadSwbuf(CELLIDX idx, T_TCP_CEP* cep, int8_t* outputp, int32_t size, uint32_t doff, int8_t* sbuf, int32_t buflen, int32_t hoff, int32_t len)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	uint8_t	*wptr, *rptr;
	T_NET_BUF *output = (T_NET_BUF *)outputp;

	/* SDU の大きさをチェックする。*///TCPヘッダはオプションがつくがIPヘッダは固定長
	if (output->off.tphdrlenall < GET_TCP_HDR_SIZE(output, hoff)) {
		len = output->off.tphdrlenall+len - GET_TCP_HDR_SIZE(output,hoff);
	}

	wptr = GET_TCP_SDU(output, hoff);

	/* 通信端点をロックする。*/
	cSemaphore_wait();

	rptr = cep->sbuf_rptr + doff;
	if (rptr - (uint8_t*)sbuf > buflen) {

		/* 転送開始が送信ウィンドバッファの終わりを超えるときの処理　*/
		rptr = (uint8_t*)cep->sbuf_rptr - (buflen - doff);
	}
	else if (len + (rptr - (uint8_t*)sbuf) > buflen) {
		uint_t sub;

		/* 転送範囲がラウンドするときの処理 */
		sub = (uint_t)(buflen - (rptr - (uint8_t*)sbuf));
		memcpy((void*)wptr, rptr, (size_t)sub);
		len  -= sub;
		wptr += sub;
		rptr  = (uint8_t*)sbuf;
	}
	memcpy((void*)wptr, rptr, (size_t)len);

	/* 通信端点のロックを解除する。*/
	cSemaphore_signal();

}

/* #[<ENTRY_FUNC>]# eCopySave_tcpWaitSwbuf
 * name:         eCopySave_tcpWaitSwbuf
 * global_name:  tCopySave_eCopySave_tcpWaitSwbuf
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eCopySave_tcpWaitSwbuf(CELLIDX idx, T_TCP_CEP* cep, uint32_t* flags, int32_t sbufSize, TMO tmout)
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
	ER	error;
	FLGPTN	flag;

	while (cep->swbuf_count >= sbufSize) {
		/*
		 *  送信ウィンドバッファの空きがなければ、出力をポストして、
		 *  送信ウィンドバッファが空くまで待つ。
		 */
		*flags |= TCP_CEP_FLG_POST_OUTPUT;
		cSemaphoreTcppost_signal();

		if ((error = cSendFlag_waitTimeout( TCP_CEP_EVT_SWBUF_READY, TWF_ORW,&flag,tmout )) != E_OK) {
			return error;
		}
		cSendFlag_clear((FLGPTN)(~TCP_CEP_EVT_SWBUF_READY));

		/*
		 *  送信できるか、CEP の FSM 状態を見る。
		 *  送信ウィンドバッファが空くまで待つ間に、送信不能になった場合は、
		 *  コネクションが切断されたことを意味している。
		 */
		if (!TCP_FSM_CAN_SEND_MORE(cep->fsm_state)) {
			return E_CLS;
		}
	}

	return E_OK;
}

/* #[<ENTRY_FUNC>]# eCopySave_tcpWriteSwbuf
 * name:         eCopySave_tcpWriteSwbuf
 * global_name:  tCopySave_eCopySave_tcpWriteSwbuf
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER_UINT
eCopySave_tcpWriteSwbuf(CELLIDX idx, T_TCP_CEP* cep, int8_t* data, int32_t datalen, int8_t* sbuf, int32_t buflen)
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
	uint_t	offset;

	/* 通信端点をロックする。*/
	cSemaphore_wait();

	/* len と送信ウィンドバッファの空きの小さい方を移すデータ数にする。*/
	if (datalen > (buflen - cep->swbuf_count))
		datalen = buflen - cep->swbuf_count;

	/* 書き込みポインタがラウンドするときの処理 */
	if (datalen > buflen - (cep->sbuf_wptr - (uint8_t*)sbuf)) {
		offset = (uint_t)(buflen - (cep->sbuf_wptr -(uint8_t*)sbuf));
		memcpy(cep->sbuf_wptr, data, (size_t)offset);
		cep->sbuf_wptr  = (uint8_t*)sbuf;
		cep->swbuf_count += offset;
	}
	else
	  offset = 0;

	memcpy(cep->sbuf_wptr, (void*)((uint8_t*)data + offset), (size_t)(datalen - offset));
	cep->sbuf_wptr  += datalen - offset;
	cep->swbuf_count += datalen - offset;

	/* 通信端点のロックを解除する。*/
	cSemaphore_signal();

	return (ER_UINT)datalen;
}

/* #[<ENTRY_FUNC>]# eCopySave_tcpIsSwbufFull
 * name:         eCopySave_tcpIsSwbufFull
 * global_name:  tCopySave_eCopySave_tcpIsSwbufFull
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eCopySave_tcpIsSwbufFull(CELLIDX idx, T_TCP_CEP* cep, int32_t sbufSize)
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

	return cep->swbuf_count >= sbufSize;
}

/* #[<ENTRY_FUNC>]# eCopySave_tcpReadRwbuf
 * name:         eCopySave_tcpReadRwbuf
 * global_name:  tCopySave_eCopySave_tcpReadRwbuf
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
uint32_t
eCopySave_tcpReadRwbuf(CELLIDX idx, T_TCP_CEP* cep, int8_t* data, int32_t datalen, int8_t* rbuf, int32_t buflen)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	uint_t	offset;

	/* 通信端点をロックする。*/
	cSemaphore_wait();

	/* len と受信ウィンドバッファのデータ数の小さい方を取り出すデータ数にする。*/
	if (datalen > cep->rwbuf_count)
		datalen = cep->rwbuf_count;

	/* 読み出しポインタがラウンドするときの処理 */
	if (datalen > buflen - (cep->rbuf_rptr - (uint8_t*)rbuf)) {
		offset = (uint_t)(buflen - (cep->rbuf_rptr -(uint8_t*)rbuf));
		memcpy(data, cep->rbuf_rptr, (size_t)offset);
		cep->rwbuf_count -= offset;
		cep->rbuf_rptr   = (uint8_t*)rbuf;
	}
	else
	  offset = 0;

	memcpy((void*)((uint8_t*)data + offset), cep->rbuf_rptr, (size_t)(datalen - offset));
	cep->rwbuf_count -= datalen - offset;
	cep->rbuf_rptr  += datalen - offset;

	/* 通信端点のロックを解除する。*/
	cSemaphore_signal();

	return datalen;
}

/* #[<ENTRY_FUNC>]# eCopySave_tcpDropSwbuf
 * name:         eCopySave_tcpDropSwbuf
 * global_name:  tCopySave_eCopySave_tcpDropSwbuf
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCopySave_tcpDropSwbuf(CELLIDX idx, T_TCP_CEP* cep, uint32_t len, const int8_t* sbuf, int32_t sbufSize, uint32_t* flags)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	uint_t	last;

	/* 通信端点をロックする。*/
	cSemaphore_wait();

	last = cep->swbuf_count;

	if (cep->sbuf_rptr + len > sbuf + sbufSize)
		/* ラウンドするときの計算 */
		cep->sbuf_rptr -= sbufSize - len;
	else
		cep->sbuf_rptr += len;
	cep->swbuf_count -= (uint16_t)len;

	/* 通信端点のロックを解除する。*/
	cSemaphore_signal();

	if (cep->swbuf_count > 0) {
		/* 送信ウィンドバッファにデータがあれば出力をポストする。*/
		*flags |= TCP_CEP_FLG_POST_OUTPUT;
		cSemaphoreTcppost_signal();
	}
}

/* #[<ENTRY_FUNC>]# eCopySave_tcpFreeRwbufq
 * name:         eCopySave_tcpFreeRwbufq
 * global_name:  tCopySave_eCopySave_tcpFreeRwbufq
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCopySave_tcpFreeRwbufq(CELLIDX idx, T_TCP_CEP* cep)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eCopySave_tcpFreeSwbufq
 * name:         eCopySave_tcpFreeSwbufq
 * global_name:  tCopySave_eCopySave_tcpFreeSwbufq
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCopySave_tcpFreeSwbufq(CELLIDX idx, T_TCP_CEP* cep)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
