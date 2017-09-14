/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tTCPCEP_template.c => src/tTCPCEP.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * sbufSizeInit     int32_t          ATTR_sbufSizeInit
 * rbufSizeInit     int32_t          ATTR_rbufSizeInit
 * ipLength         int8_t           ATTR_ipLength
 * offset           T_OFF_BUF        VAR_offset
 * myport           uint16_t         VAR_myport
 * dstport          uint16_t         VAR_dstport
 * sbufSize         int32_t          VAR_sbufSize
 * rbufSize         int32_t          VAR_rbufSize
 * sbuf             int8_t*          VAR_sbuf
 * rbuf             int8_t*          VAR_rbuf
 * flags            uint32_t         VAR_flags
 * cep              T_TCP_CEP        VAR_cep
 *
 * 呼び口関数 #_TCPF_#
 * require port: signature:sKernel context:task
 *   ER             getExtendedInformation( intptr_t* p_exinf );
 *   ER             sleep( );
 *   ER             sleepTimeout( TMO timeout );
 *   ER             delay( RELTIM delayTime );
 *   ER             exit( );
 *   ER             disableTerminate( );
 *   ER             enableTerminate( );
 *   bool_t         senseTerminate( );
 *   ER             setTime( SYSTIM systemTime );
 *   ER             getTime( SYSTIM* p_systemTime );
 *   ER             adjustTime( int32_t adjustTime );
 *   HRTCNT         fetchHighResolutionTimer( );
 *   ER             rotateReadyQueue( PRI taskPriority );
 *   ER             getTaskId( ID* p_taskId );
 *   ER             getLoad( PRI taskPriority, uint_t* p_load );
 *   ER             getNthTask( PRI taskPriority, uint_t nth, ID* p_taskID );
 *   ER             lockCpu( );
 *   ER             unlockCpu( );
 *   ER             disableDispatch( );
 *   ER             enableDispatch( );
 *   bool_t         senseContext( );
 *   bool_t         senseLock( );
 *   bool_t         senseDispatch( );
 *   bool_t         senseDispatchPendingState( );
 *   bool_t         senseKernel( );
 *   ER             exitKernel( );
 *   ER             changeInterruptPriorityMask( PRI interruptPriority );
 *   ER             getInterruptPriorityMask( PRI* p_interruptPriority );
 * call port: cCopySave signature: sCopySave context:task
 *   void           cCopySave_tcpWriteRwbuf( T_TCP_CEP* cep, int8_t* inputp, int32_t size, uint8_t thoff, int8_t* rbuf, int32_t len );
 *   void           cCopySave_tcpReadSwbuf( T_TCP_CEP* cep, int8_t* outputp, int32_t size, uint32_t doff, int8_t* sbuf, int32_t buflen, int32_t hoff, int32_t len );
 *   ER             cCopySave_tcpWaitSwbuf( T_TCP_CEP* cep, uint32_t* flags, int32_t sbufSize, TMO tmout );
 *   ER_UINT        cCopySave_tcpWriteSwbuf( T_TCP_CEP* cep, int8_t* data, int32_t datalen, int8_t* sbuf, int32_t buflen );
 *   ER             cCopySave_tcpIsSwbufFull( T_TCP_CEP* cep, int32_t sbufSize );
 *   uint32_t       cCopySave_tcpReadRwbuf( T_TCP_CEP* cep, int8_t* data, int32_t datalen, int8_t* rbuf, int32_t buflen );
 *   void           cCopySave_tcpDropSwbuf( T_TCP_CEP* cep, uint32_t len, const int8_t* sbuf, int32_t sbufSize, uint32_t* flags );
 *   void           cCopySave_tcpFreeRwbufq( T_TCP_CEP* cep );
 *   void           cCopySave_tcpFreeSwbufq( T_TCP_CEP* cep );
 * call port: cTCPOutput signature: sTCPOutput context:task
 *   ER             cTCPOutput_output( int8_t* outputp, int32_t size, const int8_t* dstaddr, const int8_t* srcaddr, int32_t addrlen );
 *   ER             cTCPOutput_getOffset( T_OFF_BUF* offset );
 *   T_IN4_ADDR     cTCPOutput_getIPv4Address( );
 *   ER             cTCPOutput_respond( int8_t* outputp, int32_t size, T_TCP_CEP* cep, T_TCP_SEQ ack, T_TCP_SEQ seq, uint32_t rbfree, uint8_t flags );
 *   ER             cTCPOutput_allocAndRespond( const int8_t* dstaddr, const int8_t* srcaddr, int32_t addrlen, uint16_t dstport, uint16_t srcport, T_TCP_SEQ ack, T_TCP_SEQ seq, uint32_t rbfree, uint8_t flags, T_OFF_BUF offset );
 * call port: cTCPFunctions signature: sTCPFunctions context:task
 *   T_TCP_SEQ      cTCPFunctions_getTcpIss( );
 *   void           cTCPFunctions_setTcpIss( T_TCP_SEQ iss );
 *   T_TCP_SEQ      cTCPFunctions_initTcpIss( );
 *   T_TCP_TIME     cTCPFunctions_tcpRexmtValue( T_TCP_TIME srtt, T_TCP_TIME rttvar );
 *   T_TCP_TIME     cTCPFunctions_tcpRangeSet( T_TCP_TIME value, T_TCP_TIME tvmin, T_TCP_TIME tvmax );
 * call port: cGetAddress signature: sGetAddress2 context:task
 *   int8_t*        cGetAddress_getMyAddress( );
 *   int8_t*        cGetAddress_getDstAddress( );
 *   void           cGetAddress_setMy4Address( T_IN4_ADDR addr );
 *   void           cGetAddress_setDst4Address( T_IN4_ADDR addr );
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
 * call port: cSemaphoreTcpcep signature: sSemaphore context:task
 *   ER             cSemaphoreTcpcep_signal( );
 *   ER             cSemaphoreTcpcep_wait( );
 *   ER             cSemaphoreTcpcep_waitPolling( );
 *   ER             cSemaphoreTcpcep_waitTimeout( TMO timeout );
 *   ER             cSemaphoreTcpcep_initialize( );
 *   ER             cSemaphoreTcpcep_refer( T_RSEM* pk_semaphoreStatus );
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
 * call port: cEstFlag signature: sEventflag context:task
 *   ER             cEstFlag_set( FLGPTN setPattern );
 *   ER             cEstFlag_clear( FLGPTN clearPattern );
 *   ER             cEstFlag_wait( FLGPTN waitPattern, MODE waitMode, FLGPTN* p_flagPattern );
 *   ER             cEstFlag_waitPolling( FLGPTN waitPattern, MODE waitMode, FLGPTN* p_flagPattern );
 *   ER             cEstFlag_waitTimeout( FLGPTN waitPattern, MODE waitMode, FLGPTN* p_flagPattern, TMO timeout );
 *   ER             cEstFlag_initialize( );
 *   ER             cEstFlag_refer( T_RFLG* pk_eventflagStatus );
 * call port: cREP4 signature: sREP4 context:task optional:true
 *   bool_t     is_cREP4_joined()                     check if joined
 *   T_IPV4EP       cREP4_getEndpoint( );
 *   ER             cREP4_signal( );
 *   ER             cREP4_wait( );
 *   ER             cREP4_waitPolling( );
 *   ER             cREP4_waitTimeout( TMO timeout );
 *   ER             cREP4_initialize( );
 *   ER             cREP4_refer( T_RSEM* pk_semaphoreStatus );
 * call port: cCallingSendTask signature: sTask context:task optional:true
 *   bool_t     is_cCallingSendTask_joined()                     check if joined
 *   ER             cCallingSendTask_activate( );
 *   ER_UINT        cCallingSendTask_cancelActivate( );
 *   ER             cCallingSendTask_getTaskState( STAT* p_tskstat );
 *   ER             cCallingSendTask_changePriority( PRI priority );
 *   ER             cCallingSendTask_getPriority( PRI* p_priority );
 *   ER             cCallingSendTask_refer( T_RTSK* pk_taskStatus );
 *   ER             cCallingSendTask_wakeup( );
 *   ER_UINT        cCallingSendTask_cancelWakeup( );
 *   ER             cCallingSendTask_releaseWait( );
 *   ER             cCallingSendTask_suspend( );
 *   ER             cCallingSendTask_resume( );
 *   ER             cCallingSendTask_raiseTerminate( );
 *   ER             cCallingSendTask_terminate( );
 * call port: cCallingReceiveTask signature: sTask context:task optional:true
 *   bool_t     is_cCallingReceiveTask_joined()                     check if joined
 *   ER             cCallingReceiveTask_activate( );
 *   ER_UINT        cCallingReceiveTask_cancelActivate( );
 *   ER             cCallingReceiveTask_getTaskState( STAT* p_tskstat );
 *   ER             cCallingReceiveTask_changePriority( PRI priority );
 *   ER             cCallingReceiveTask_getPriority( PRI* p_priority );
 *   ER             cCallingReceiveTask_refer( T_RTSK* pk_taskStatus );
 *   ER             cCallingReceiveTask_wakeup( );
 *   ER_UINT        cCallingReceiveTask_cancelWakeup( );
 *   ER             cCallingReceiveTask_releaseWait( );
 *   ER             cCallingReceiveTask_suspend( );
 *   ER             cCallingReceiveTask_resume( );
 *   ER             cCallingReceiveTask_raiseTerminate( );
 *   ER             cCallingReceiveTask_terminate( );
 * allocator port for call port:cTCPOutput func:output param: outputp
 *   ER             cTCPOutput_output_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cTCPOutput_output_outputp_dealloc( const void* buf );
 *   ER             cTCPOutput_output_outputp_reuse( void* buf );
 *   ER_UINT        cTCPOutput_output_outputp_bufferSize( const void* buf );
 *   uint32_t       cTCPOutput_output_outputp_bufferMaxSize( );
 * allocator port for call port:cTCPOutput func:respond param: outputp
 *   ER             cTCPOutput_respond_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cTCPOutput_respond_outputp_dealloc( const void* buf );
 *   ER             cTCPOutput_respond_outputp_reuse( void* buf );
 *   ER_UINT        cTCPOutput_respond_outputp_bufferSize( const void* buf );
 *   uint32_t       cTCPOutput_respond_outputp_bufferMaxSize( );
 * allocator port for call port:eCEPInput func:input param: inputp
 *   ER             eCEPInput_input_inputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             eCEPInput_input_inputp_dealloc( const void* buf );
 *   ER             eCEPInput_input_inputp_reuse( void* buf );
 *   ER_UINT        eCEPInput_input_inputp_bufferSize( const void* buf );
 *   uint32_t       eCEPInput_input_inputp_bufferMaxSize( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tTCPCEP_tecsgen.h"

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

#define T_TCP_IP4_Q_HDR T_IP4_TCP_Q_HDR 	// TEMP

//TODO:
#if 0
/* 動的結合 */
//本当はカーネルの機能に組み込むがmikan

extern ER		get_inf(intptr_t *p_exinf);

typedef struct tag_tTask_VCB {
    /* call port #_TCP_# */
    intptr_t cBody;
    intptr_t cExceptionBody;
    /* call port #_NEP_# */
    /* attribute #_AT_# */
    ID             id;
    intptr_t       sTask_DES;
    intptr_t       siTask_DES;
}  tTask_VCB;

static struct tag_sTask_VDES*
get_tTask_DES()
{
	intptr_t inf;
	tTask_VCB *vcb;

	get_inf(&inf);
	vcb = (tTask_VCB*)inf;

	return (struct tag_sTask_VDES*)(vcb->sTask_DES);
}


#define tTCPCEP_cCallingSendTask_bind(p_that) \
  (p_that)->cCallingSendTask = get_tTask_DES()
#define cCallingSendTask_bind() tTCPCEP_cCallingSendTask_bind(p_cellcb)

#define tTCPCEP_cCallingReceiveTask_bind(p_that) \
  (p_that)->cCallingReceiveTask = get_tTask_DES()
#define cCallingReceiveTask_bind() tTCPCEP_cCallingReceiveTask_bind(p_cellcb)
//mikanここまで

#define sREP4_entrypoint intptr_t//シグニチャ用につけられる
#define sREP4_cREP4_bind(des) ((p_cellcb)->cREP4 = (struct tag_sREP4_VDES *)(des))
#define sREP4_cREP4_unbind() ((p_cellcb)->cREP4 = NULL)
#define sTask_cCallingSendTask_bind(des) ((p_cellcb)->cCallingSendTask = (struct tag_sTask_VDES *)(des))
#define sTask_cCallingSendTask_unbind() ((p_cellcb)->cCallingSendTask = NULL)
#define sTask_cCallingReceiveTask_bind(des) ((p_cellcb)->cCallingReceiveTask = (struct tag_sTask_VDES *)(des))
#define sTask_cCallingReceiveTask_unbind() ((p_cellcb)->cCallingReceiveTask = NULL)
/* dynamic conecction */
#endif /* of #if 0 */

#define tTCPCEP_cCallingSendTask_bind(p_that)
#define cCallingSendTask_bind()

#define tTCPCEP_cCallingReceiveTask_bind(p_that)
#define cCallingReceiveTask_bind()
//mikanここまで

#define sREP4_entrypoint intptr_t//シグニチャ用につけられる
#define sREP4_cREP4_bind(des)
#define sREP4_cREP4_unbind()
#define sTask_cCallingSendTask_bind(des)
#define sTask_cCallingSendTask_unbind()
#define sTask_cCallingReceiveTask_bind(des)
#define sTask_cCallingReceiveTask_unbind()

/*
 *  関数
 *
 *	TODO: 関数名の先頭に tecs_ を使う
 */

static T_TCP_CEP *tecs_tcp_user_closed (CELLCB *p_cellcb);
static void 	 tecs_tcp_output (CELLCB *p_cellcb);
static void      tecs_tcp_alloc_auto_port (CELLCB *p_cellcb);
static ER        tecs_tcp_alloc_port (CELLCB *p_cellcb, uint16_t portno);
static T_TCP_CEP *tecs_tcp_timers (CELLCB *p_cellcb, int_t tix);
static ER 		 tecs_tcp_wait_rwbuf (CELLCB *p_cellcb, TMO tmout);
static uint8_t 	 tecs_tcp_move_ra2rw (CELLCB *p_cellcb, uint8_t flags);
static uint8_t 	 tecs_tcp_write_raque (CELLCB *p_cellcb, T_NET_BUF *input, uint_t thoff, uint8_t flags);
static T_TCP_TIME tecs_tcp_rexmt_val (CELLCB *p_cellcb);
static void 	 tecs_tcp_init_cep (CELLCB *p_cellcb);
static ER 		 tecs_tcp_lock_cep (CELLCB *p_cellcb, FN tfn);
static T_TCP_CEP *tecs_tcp_close (CELLCB *p_cellcb);
static void 	 tecs_tcp_free_reassq (CELLCB *p_cellcb);
static T_TCP_CEP *tecs_tcp_drop (CELLCB *p_cellcb, ER errno);
static ER        tecs_tcp_can_snd (CELLCB *p_cellcb, FN fncd);
static ER        tecs_tcp_can_rcv (CELLCB *p_cellcb, FN fncd);
static ER 		 tecs_tcp_can_send_more (CELLCB *p_cellcb, FN fncd, TMO tmout);
static ER 		 tecs_tcp_can_recv_more (ER *error, CELLCB *p_cellcb, FN fncd, TMO tmout);
static void 	 tecs_tcp_set_persist_timer (CELLCB *p_cellcb);

static ER 		tecs_send_segment(CELLCB *p_cellcb, bool_t *sendalot, uint_t doff, uint_t win, uint_t len, uint8_t flags);
static void 	tecs_set_rexmt_timer (CELLCB *p_cellcb, T_TCP_TIME rtt);
static uint8_t 	tecs_reassemble (CELLCB *p_cellcb, T_NET_BUF *input, uint_t thoff, uint8_t flags);
static ER 		tecs_listening (CELLCB *p_cellcb, T_NET_BUF *input, uint_t thoff, T_TCP_SEQ iss);
static bool_t 	tecs_update_wnd (CELLCB *p_cellcb, T_TCP_HDR *tcph);
static void 	tecs_proc_urg (CELLCB *p_cellcb, T_TCP_HDR *tcph);
static ER 		tecs_drop_after_ack (CELLCB *p_cellcb, T_NET_BUF *input, uint_t thoff);
static void 	tecs_close_connection (CELLCB *p_cellcb, bool_t *needoutput);
static void 	tecs_parse_option (CELLCB *p_cellcb, T_TCP_HDR *tcph, uint16_t mss);
static ER 		tecs_syn_sent (CELLCB *p_cellcb, T_TCP_HDR *tcph, T_TCP_CEP *cep);
static void 	tecs_trim_length (CELLCB *p_cellcb, T_TCP_HDR *tcph);
static ER 		tecs_proc_ack1 (CELLCB *p_cellcb, T_NET_BUF *input, uint_t thoff, bool_t *needoutput);
static ER 		tecs_proc_ack2 (CELLCB *p_cellcb, T_NET_BUF *input, uint_t thoff, bool_t *needoutput);

/*
 *  変数
 */

/* 出力時のフラグを FSM 状態により選択するための表 */

const static uint8_t tcp_outflags[] = {
	TCP_FLG_RST | TCP_FLG_ACK,	/*  0, クローズ						*/
	0,							/*  1, 受動オープン						*/
	TCP_FLG_SYN,				/*  2, 能動オープン、SYN 送信済み			*/
	TCP_FLG_SYN | TCP_FLG_ACK,	/*  3, SYM を受信し、SYN 送信済み		*/
	TCP_FLG_ACK,				/*  4, コネクション開設完了				*/
	TCP_FLG_ACK,				/*  5, FIN 受信、クローズ待ち				*/
	TCP_FLG_FIN | TCP_FLG_ACK,	/*  6, 終了して、FIN 送信済み			*/
	TCP_FLG_FIN | TCP_FLG_ACK,	/*  7, 終了、FIN 交換済み、ACK 待ち		*/
	TCP_FLG_FIN | TCP_FLG_ACK,	/*  8, FIN 受信、終了、ACK 待ち			*/
	TCP_FLG_ACK,				/*  9, 終了、FIN 伝達確認受信、FIN待ち	*/
	TCP_FLG_ACK,				/* 10, 終了、時間待ち					*/
};

/*
 *  局所変数
 */

static uint16_t tcp_port_auto = TCP_PORT_FIRST_AUTO;    /* 自動割り当て番号 */

/*
 *  バックオフ時間
 *
 *  再送を行うたびに、タイムアウトの時間を延長する。
 */

const static uint8_t tcp_back_off[] = {
	UINT_C(1), 		UINT_C(2), 		UINT_C(4), 		UINT_C(8),
	UINT_C(16), 	UINT_C(32), 	UINT_C(64), 	UINT_C(64),
	UINT_C(64), 	UINT_C(64), 	UINT_C(64), 	UINT_C(64),
	UINT_C(64)
};

#define TCP_TOTAL_BACK_OFF	511	/* バックオフ時間の合計 */


/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eTCPOutputStart
 * entry port: eTCPOutputStart
 * signature:  sTCPOutputStart
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTCPOutputStart_outputStart
 * name:         eTCPOutputStart_outputStart
 * global_name:  tTCPCEP_eTCPOutputStart_outputStart
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eTCPOutputStart_outputStart(CELLIDX idx)
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
#if 0
#ifdef TCP_CFG_SWBUF_CSAVE

	if ((cep->flags & TCP_CEP_FLG_WBCS_NBUF_REQ) != 0 &&
	    ((cep->flags & TCP_CEP_FLG_WBCS_MASK) == TCP_CEP_FLG_WBCS_FREE ||
	     (cep->flags & TCP_CEP_FLG_WBCS_MASK) == TCP_CEP_FLG_WBCS_NBUF_RSVD)) {
		tcptsk_alloc_swbufq(cep);
		sel_ix = ix;
	}

	if ((cep->flags & TCP_CEP_FLG_WBCS_MASK) == TCP_CEP_FLG_WBCS_ACKED &&
	    (cep->swbufq->flags & NB_FLG_NOREL_IFOUT) == 0) {
		tcptsk_free_swbufq(cep);
		sel_ix = ix;
	}

	/*
	 *  ネットワークインタフェースから送信が終わっていないときは、
	 *  送信を予約する。
	 */
	if (cep->flags & TCP_CEP_FLG_POST_OUTPUT &&
	   (cep->flags & TCP_CEP_FLG_WBCS_MASK) >= TCP_CEP_FLG_WBCS_SENT) {
		syscall(wai_sem(cep->semid_lock));
		if (cep->swbufq == NULL)
			cep->flags &= ~TCP_CEP_FLG_POST_OUTPUT;
		else if (cep->swbufq->flags & NB_FLG_NOREL_IFOUT) {
			cep->flags &= ~TCP_CEP_FLG_POST_OUTPUT;
			cep->flags |=  TCP_CEP_FLG_RESERVE_OUTPUT;
		}
		syscall(sig_sem(cep->semid_lock));
	}

	/*
	 *  送信予約中に、ネットワークインタフェースから送信が終了したら、
	 *  送信を開始する。ただし、完全に送信が終了したときは何もしない。
	 */
	if (cep->flags & TCP_CEP_FLG_RESERVE_OUTPUT) {
		syscall(wai_sem(cep->semid_lock));
		if (cep->swbufq != NULL && (cep->swbufq->flags & NB_FLG_NOREL_IFOUT) == 0) {
			cep->flags |=  TCP_CEP_FLG_POST_OUTPUT;
		}
		syscall(sig_sem(cep->semid_lock));
		cep->flags &= ~TCP_CEP_FLG_RESERVE_OUTPUT;
	}

#endif	/* of #ifdef TCP_CFG_SWBUF_CSAVE */
#endif 	/* of #if 0 */

	if (VAR_flags & TCP_CEP_FLG_POST_OUTPUT) {

		VAR_flags &= ~TCP_CEP_FLG_POST_OUTPUT;

#if 0
#ifdef TCP_CFG_NON_BLOCKING

		if (cep->snd_nblk_tfn == TFN_TCP_CON_CEP && cep->myaddr.portno == TCP_PORTANY) {
	 		ER	error;

			/*
			 *  tcp_con_cep のノンブロッキングコールで、
			 *  未割当のの場合は、ポート番号を割り当てる。
			 *  p_myaddr が NADR (-1) か、
			 *  自ポート番号が TCP_PORTANY なら、自動で割り当てる。
			 */
			if (cep->p_myaddr == NADR || cep->p_myaddr->portno == TCP_PORTANY)
				tcp_alloc_auto_port(cep);
			else if ((error = tcp_alloc_port(cep, cep->p_myaddr->portno)) != E_OK) {

				if (IS_PTR_DEFINED(cep->callback))
#ifdef TCP_CFG_NON_BLOCKING_COMPAT14
					(*cep->callback)(GET_TCP_CEPID(cep), cep->snd_nblk_tfn, (void*)error);
#else
					(*cep->callback)(GET_TCP_CEPID(cep), cep->snd_nblk_tfn, (void*)&error);
#endif
				else
					syslog(LOG_WARNING, "[TCP] no call back, CEP: %d.", GET_TCP_CEPID(cep));

				/* 記憶されているタスク ID と API 機能コードをクリアーする。*/
				cep->snd_tfn   = cep->snd_nblk_tfn = TFN_TCP_UNDEF;
				cep->snd_tskid = TA_NULL;
				continue;
			}
		}

#endif	/* of #ifdef TCP_CFG_NON_BLOCKING */
#endif 	/* of #if 0 */

		tecs_tcp_output(p_cellcb);

		if (VAR_flags & TCP_CEP_FLG_CLOSE_AFTER_OUTPUT) {
			/* コネクションを閉じる。*/
			tecs_tcp_close( p_cellcb );
			VAR_flags &= ~TCP_CEP_FLG_CLOSE_AFTER_OUTPUT;
		}

		if (VAR_flags & TCP_CEP_FLG_RESTORE_NEXT_OUTPUT) {
			/* snd_nxt を元に戻す。*/
			if (SEQ_GT(VAR_cep.snd_old_nxt, VAR_cep.snd_nxt))
				VAR_cep.snd_nxt = VAR_cep.snd_old_nxt;
			VAR_flags &= ~TCP_CEP_FLG_RESTORE_NEXT_OUTPUT;
		}
	}

	return E_OK;
}

/* #[<ENTRY_FUNC>]# eTCPOutputStart_timerFunction
 * name:         eTCPOutputStart_timerFunction
 * global_name:  tTCPCEP_eTCPOutputStart_timerFunction
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
/*
 *  tcp_slow_timo -- 500 [ms] 毎に呼出される TCP タイムアウト関数
 */

ER
eTCPOutputStart_timerFunction(CELLIDX idx)
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
	T_TCP_CEP	*cep = &VAR_cep;
	int_t		tix;

	if (!(VAR_cep.fsm_state == TCP_FSM_CLOSED || VAR_cep.fsm_state == TCP_FSM_LISTEN)) {
		for (tix = NUM_TCP_TIMERS; cep != NULL && tix -- > 0; ) {
			if (VAR_cep.timer[tix] != 0 && -- VAR_cep.timer[tix] == 0) {
				cep = tecs_tcp_timers(p_cellcb, tix);
			}
		}
		if (cep != NULL) {
			VAR_cep.idle ++;
			if (VAR_cep.rtt) {
				VAR_cep.rtt ++;
			}
		}
	}

	return(ercd);
}

/* #[<ENTRY_PORT>]# eCEPInput
 * entry port: eCEPInput
 * signature:  sTCPCEPInput
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eCEPInput_check
 * name:         eCEPInput_check
 * global_name:  tTCPCEP_eCEPInput_check
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
/*
 *  tcp_find_cep -- ポート番号から TCP 通信端点を得る。
 * 	(おそらくこの関数の一部)
 */

ER
eCEPInput_check(CELLIDX idx, const int8_t* dstaddr, const int8_t* srcaddr, int32_t len, uint16_t dstport, uint16_t srcport)
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
	/* このコンポーネントではv4かv6かわからない */
	if (ATTR_ipLength == len) {
		/*
		 *  状態が SYN 送信済み以後は、
		 *  IP アドレスとポート番号が一致する通信端点を探索する。
		 */
		if (VAR_cep.fsm_state >= TCP_FSM_SYN_SENT &&
		  	dstport == VAR_myport &&
			srcport == VAR_dstport){
			/* v4パケットの処理　*/
			if (ATTR_ipLength == 4) {
				if (*((T_IN4_ADDR *)srcaddr) == (*(T_IN4_ADDR *)cGetAddress_getDstAddress())) {
					T_IN4_ADDR myaddr = *(T_IN4_ADDR *)cGetAddress_getMyAddress();
					if ((myaddr == IPV4_ADDRANY) && (*(T_IN4_ADDR *)dstaddr == cTCPOutput_getIPv4Address()))
						return E_OK;
					else
					  	if ((*(T_IN4_ADDR *)dstaddr == myaddr))
							return E_OK;
				}
			}
		}

		/* 受動オープン中の場合の処理。*/
		if (VAR_cep.fsm_state == TCP_FSM_LISTEN &&
			dstport == VAR_myport) {
			/* v4パケットの処理　*/
			if (ATTR_ipLength == 4) {
				T_IN4_ADDR myaddr = *(T_IN4_ADDR *)cGetAddress_getMyAddress();
				if ((myaddr == IPV4_ADDRANY) && (*(T_IN4_ADDR *)dstaddr == cTCPOutput_getIPv4Address()))
					return E_OK;
				else
					if((*(T_IN4_ADDR *)dstaddr == myaddr))
						return E_OK;
			}
		}
	}

	return E_ID;
}

/* #[<ENTRY_FUNC>]# eCEPInput_input
 * name:         eCEPInput_input
 * global_name:  tTCPCEP_eCEPInput_input
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eCEPInput_input(CELLIDX idx, int8_t* inputp, int32_t size)
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
	T_NET_BUF 	*input 	= (T_NET_BUF *)inputp;
	int32_t 	offset 	= input->off.ifhdrlen + input->off.iphdrlenall;
	T_TCP_HDR 	*tcph 	= GET_TCP_HDR(input, offset);
	int32_t 	tcphlen = TCP_HDR_LEN(tcph->doff);
	T_TCP_SEQ 	iss 	= 0;

	ER			ret;
	bool_t		needoutput = false;
	int32_t		todrop, win;
	uint8_t		flags;
	T_TCP_CEP 	*cep = &VAR_cep;
	T_IP4_HDR 	*ip4h;
	T_IN4_ADDR 	dst;
	int32_t 	rbfree;


#if 0
#if defined(NUM_TCP_TW_CEP_ENTRY) && NUM_TCP_TW_CEP_ENTRY > 0

	/*
	 *  状態が Time Wait 中の CEP を探索する。
	 */
	twcep = tcp_find_twcep(input, *offp);
	if (twcep != NULL) {

		if (tcph->flags & TCP_FLG_RST)		/* RST フラグを受信したときは無視する。*/
			goto drop;
		else {

			/*
			 *    TCP 通信端点が Time Wait の時、相手ホストからセグメントが来たときは、
			 *    相手ホストの FIN に対する自ホストの ACK セグメントが途中で
			 *    損失したことを意味しているので、ACK セグメントを再送する。
			 */

			/* ホストオーダーからネットワークオーダーに戻す。*/
			HTONS(tcph->sport);
			HTONS(tcph->dport);

			tcp_respond(input, NULL, twcep->rcv_nxt, twcep->snd_una, twcep->rbufsz - twcep->rwbuf_count, TCP_FLG_ACK);
			}
		return IPPROTO_DONE;
		}
	else
		/* 標準の TCP 通信端点を得る。*/
		cep = tcp_find_cep(input, *offp);

#else	/* of #if defined(NUM_TCP_TW_CEP_ENTRY) && NUM_TCP_TW_CEP_ENTRY > 0 */

	/* TCP 通信端点を得る。*/
	cep = tcp_find_cep(input, *offp);

#endif	/* of #if defined(NUM_TCP_TW_CEP_ENTRY) && NUM_TCP_TW_CEP_ENTRY > 0 */
#endif /* of #if 0 */
#if 0
	/*
	 *  TCP 通信端点がない場合と CEP の状態がクローズなら破棄する。
	 */
	if (cep == NULL) {
		syslog(LOG_INFO, "[TCP] unexp port: %d.", tcph->dport);
		goto reset_drop;
		}
#endif /* of #if 0 */

#ifdef TCP_CFG_TRACE

	tcp_input_trace(input, cep);

#endif	/* of #ifdef TCP_CFG_TRACE */

	/* トランスポート層のヘッダ長を格納 */
	input->off.tphdrlenall = tcphlen;

	/*
	 *  CEP の状態がクローズなら破棄する。
	 */
	if (VAR_cep.fsm_state == TCP_FSM_CLOSED)
		goto drop;

	/* CEPのオフセット情報を設定する */
	if (VAR_offset.protocolflag == 0)
		VAR_offset = input->off;

	/*
	 *  コネクション開設済みでセグメントを受信したときは、
	 *  アイドル時間と生存確認タイマをリセットする。
	 */
	VAR_cep.idle = 0;
	if (TCP_FSM_HAVE_ESTABLISHED(VAR_cep.fsm_state)) {
		VAR_cep.timer[TCP_TIM_KEEP] = TCP_TVAL_KEEP_IDLE;
	}

	/* CEP の状態が LISTEN 以外の時は、オプションを処理する。*/
	if (VAR_cep.fsm_state != TCP_FSM_LISTEN)
		tecs_parse_option(p_cellcb, tcph, input->off.ipmss);

	/*
	 *  受信可能ウィンドサイズを計算する。
	 *
	 *  rcv_nxt:     受信を期待している最小の SEQ（これ以前は受信済み）
	 *  rcv_adv:     受信を期待している最大の SEQ
	 *  rbufsz:      受信ウィンドバッファサイズ
	 *  rwbuf_count:  受信ウィンドバッファにあるデータ量
	 *  tcph->sum:   今回受信した SDU サイズ
	 *
	 *  今回受信したセグメントを順序整列キューに連結する
	 *  可能性があるので tcph->sum を考慮する。
	 *
	 */
	win = VAR_rbufSize - (VAR_cep.rwbuf_count + tcph->sum);
	if (win < 0)
		win = 0;
	if (win > (int32_t)(VAR_cep.rcv_adv - VAR_cep.rcv_nxt))
		VAR_cep.rcv_wnd = win;
	else
		VAR_cep.rcv_wnd = VAR_cep.rcv_adv - VAR_cep.rcv_nxt;

	/* CEP の状態により処理を行う。*/

	if (VAR_cep.fsm_state == TCP_FSM_LISTEN) {		/* 受動オープン (LISTEN) の処理。*/
		// syslog(LOG_EMERG, "Debug: input when cep is LISTEN ");
		if ((ret = tecs_listening(p_cellcb, input, offset, iss)) == RET_RST_DROP)
			goto reset_drop;
		else if (ret == RET_DROP)
			goto drop;
		tecs_trim_length(p_cellcb, tcph);			/* 受信した SDU 長を調整する。*/

		if (tcph->flags & TCP_FLG_ACK) {	/* ACK フラグの処理 */
			if ((ret = tecs_proc_ack2(p_cellcb, input, offset, &needoutput)) == RET_DROP)
				goto drop;
			else if (ret == RET_RST_DROP) {
				cep = NULL;
				goto reset_drop;
			}
			else if (ret == RET_RETURN)
				return IPPROTO_DONE;
		}
	}
	else if (VAR_cep.fsm_state == TCP_FSM_SYN_SENT) {	/* 能動オープン、SYN 送信済み	*/
		if ((ret = tecs_syn_sent(p_cellcb, tcph, cep)) == RET_RST_DROP)
			goto reset_drop;
		else if (ret == RET_DROP)
			goto drop;
		tecs_trim_length(p_cellcb, tcph);			/* 受信した SDU 長を調整する。*/

		if (tcph->flags & TCP_FLG_ACK) {	/* ACK フラグの処理 */
			if ((ret = tecs_proc_ack2(p_cellcb, input, offset, &needoutput)) == RET_DROP)
				goto drop;
			else if (ret == RET_RST_DROP)
				goto reset_drop;
			else if (ret == RET_RETURN)
				return IPPROTO_DONE;
		}
	}
	else {
		if (VAR_cep.fsm_state == TCP_FSM_SYN_RECVD) {	/* SYN を受信、SYN 送信済み	*/
			// syslog(LOG_EMERG, "Debug: input when cep is SYN_RECVD ");
			/*
			 *  相手から受信確認が送られて来ても、
			 *
			 *    ACK <= 未確認の最小送信 SEQ (snd_una) &&
			 *           送信した最大     SEQ (snd_max) < ACK
			 *
			 *  なら、リセットを送ってセグメントを破棄する。
			 */
			if ((tcph->flags & TCP_FLG_ACK) &&
			    (SEQ_LE(tcph->ack, VAR_cep.snd_una) ||
			     SEQ_GT(tcph->ack, VAR_cep.snd_max)))
			     	goto reset_drop;
        }

		/*
		 *  RST フラグを受信したときの処理 (異常切断)
		 */
		if (tcph->flags & TCP_FLG_RST) {
			if (SEQ_GE(tcph->seq, VAR_cep.last_ack_sent) &&
			    SEQ_LT(tcph->seq, VAR_cep.last_ack_sent + VAR_cep.rcv_wnd)) {
				/*
				 *  受信したセグメントの SEQ が、最後に送信した ACK (last_ack_sent)
				 *  から、受信ウインドウサイズまでの間の処理
				 */
				switch (VAR_cep.fsm_state) {
					case TCP_FSM_SYN_RECVD:		/* SYN を受信し、SYN 送信済み		*/

						VAR_cep.net_error = EV_CNNRF;	/* 接続不能 */
						VAR_cep.error     = E_CLS;
						NET_COUNT_TCP(net_count_tcp[NC_TCP_RECV_RSTS], 1);
						NET_COUNT_MIB(tcp_stats.tcpAttemptFails, 1);
						cep = tecs_tcp_close(p_cellcb);
						break;

					case TCP_FSM_ESTABLISHED:	/* コネクション開設完了			*/
					case TCP_FSM_CLOSE_WAIT:	/* FIN 受信、クローズ待ち		*/
						NET_COUNT_MIB(tcp_stats.tcpEstabResets, 1);
						/* fallthrough */

					case TCP_FSM_FIN_WAIT_1:	/* 終了して、FIN 送信済み		*/
					case TCP_FSM_FIN_WAIT_2:	/* 終了、FIN 伝達確認受信、FIN待ち	*/

						VAR_cep.net_error = EV_CNRST;	/* 接続リセット */
						VAR_cep.error     = E_CLS;
						NET_COUNT_TCP(net_count_tcp[NC_TCP_RECV_RSTS], 1);
						/* no break; */

					case TCP_FSM_CLOSING:		/* 終了、FIN 交換済み、ACK 待ち	*/
					case TCP_FSM_LAST_ACK:		/* FIN 受信、終了、ACK 待ち	*/

						cep = tecs_tcp_close(cep);
						break;
				}
			}
			goto drop;
		}

		/*
		 *  CEP の状態が SYN を受信し、SYN 送信済みの場合は、
		 *  受信ウィンドに収まるようにデータを
		 *  調整する前に、この接続によるパケットかどうかを検証する。
		 *
		 *    受信した相手の SEQ < 相手の SEQ の初期値 (irs)
		 *
		 *  これは、"LAND" DoS 攻撃の防御である。
		 */
		if (VAR_cep.fsm_state == TCP_FSM_SYN_RECVD && SEQ_LT(tcph->seq, VAR_cep.irs)) {
			goto reset_drop;
		}

		/*
		 *  受信を期待している最小の SEQ (rcv_nxt) - 受信した相手の SEQ が
		 *  正なら、rcv_nxt 以前のデータはすでに受信しているので、その部分を
		 *  削除する。
		 *                           <---------- rcv_wnd --------->
		 *                           rcv_nxt                      rcv_nxt + rcv_wnd
		 *                           v                            v
		 *                      -----+----------------------------+-----
		 *                           |                            |
		 *                      -----+----------------------------+-----
		 *           +----------------------+
		 *           |***************|      |
		 *           +----------------------+
		 *           ^                      ^
		 *           seq                    seq + len
		 *           <---------------> 削除する。
		 */
		todrop = VAR_cep.rcv_nxt - tcph->seq;
		if (todrop > 0) {

			/*
			 *  SYN フラグがついているときは、その分 (1 オクテット)
			 *  SEQ を進め、緊急ポインタと削除する長さを調整する。
			 */
			if (tcph->flags & TCP_FLG_SYN) {
				tcph->flags &= ~TCP_FLG_SYN;
				tcph->seq ++;
				if (tcph->urp > 1)
					tcph->urp --;
				else
					tcph->flags &= ~TCP_FLG_URG;
				todrop --;
			}

			/*
			 *  削除する長さが SDU より長い、つまり、受信を期待している
			 *  最小の SEQ (rcv_nxt) に達していないか、
			 *  削除する長さが SDU と同じで、FIN フラグがついてなければ
			 *  全て削除する。
			 */
			if ( todrop >  tcph->sum ||		/* tcph->sum は TCP の SDU 長 */
			    (todrop == tcph->sum && (tcph->flags & TCP_FLG_FIN) == 0)) {
				tcph->flags &= ~TCP_FLG_FIN;
				VAR_flags |= TCP_CEP_FLG_ACK_NOW;
				todrop = tcph->sum;		/* tcph->sum は TCP の SDU 長 */
			}

			/*
			 *  SDU を前に詰める。
			 */
			if (todrop < tcph->sum) {		/* tcph->sum は TCP の SDU 長 */
				//CHECK: memcpy(GET_TCP_SDU(input, *offp),
				//CHECK:        GET_TCP_SDU(input, *offp) + todrop, (size_t)(tcph->sum - todrop));
				memcpy((uint8_t*)(input->buf + offset + tcphlen),
				       (uint8_t*)(input->buf + offset + tcphlen) + todrop, (size_t)(tcph->sum - todrop));
			}

			/*
			 *  SEQ と SDU 長を調整する。
			 */
			tcph->seq +=     todrop;
			tcph->sum -= (uint16_t)todrop;	/* tcph->sum は TCP の SDU 長 */

			/*
			 *  緊急ポインタを調整する。
			 */
			if (tcph->urp > todrop)
				tcph->urp -= (uint16_t)todrop;
			else {
				tcph->flags &= ~TCP_FLG_URG;
				tcph->urp = 0;
			}

			NET_COUNT_TCP(net_count_tcp[NC_TCP_RECV_DUP_SEGS], 1);
		}

		/*
		 *  もしユーザタスクが終了した後に、データを受信した
		 *  場合は、RST を送る。
		 */
		if (VAR_cep.fsm_state == TCP_FSM_LAST_ACK && tcph->sum > 0) {	/* tcph->sum は TCP の SDU 長 */
			cep = tecs_tcp_close(p_cellcb);
			goto reset_drop;
		}

		/*
		 *  受信セグメントが受信ウィンドを超える場合は、
		 *  超えた分を削る。
		 *
		 *       <---------- rcv_wnd --------->
		 *       rcv_nxt                      (rcv_nxt + rcv_wnd)
		 *       v                            v
		 *  -----+----------------------------+-----
		 *       |                            |
		 *  -----+----------------------------+-----
		 *                    +----------------------+
		 *                    |               |******|
		 *                    +----------------------+
		 *                    ^                      ^
		 *                    seq                    seq + len
		 *                                     <-----> 削除する。
		 */
		todrop = (tcph->seq + tcph->sum) - (VAR_cep.rcv_nxt + VAR_cep.rcv_wnd);	/* tcph->sum は TCP の SDU 長 */
		if (todrop > 0) {
			if (todrop > tcph->sum) {					/* tcph->sum は TCP の SDU 長 */
				/*
				 *  受信した SDU の全てが受信ウィンドを超える場合。
				 *
				 *  TIME_WAIT 中に、新たな接続要求を受信したら
				 *  古い接続を破棄し、新たな接続を開始する。
				 *  ただし、SEQ は前より進んでいなければならない。
				 */
				if ((tcph->flags & TCP_FLG_SYN) &&
				    VAR_cep.fsm_state == TCP_FSM_TIME_WAIT &&
				    SEQ_GT(tcph->seq, VAR_cep.rcv_nxt)) {
					iss = VAR_cep.snd_nxt + TCP_ISS_INCR();
					tecs_tcp_close(p_cellcb);
					delay(0);
					goto drop;
					//goto find_cep;//yabai mikan
				}

				/*
				 *  受信ウィンドが 0 で、受信した SEQ と
				 *  受信を期待している最小の SEQ が一致したときは
				 *  ACK を返す。それ以外はデータを破棄し、ACK を返す。
				 */
				if (VAR_cep.rcv_wnd == 0 && (tcph->seq == VAR_cep.rcv_nxt || tcph->sum == 0)) {
					VAR_flags |= TCP_CEP_FLG_ACK_NOW;
				}
				else if (tecs_drop_after_ack(p_cellcb, input, offset) == RET_RST_DROP)
					goto reset_drop;
				else {
					return IPPROTO_DONE;
				}
			}
			tcph->sum -= (uint16_t)todrop;	/* tcph->sum は TCP の SDU 長 */
			tcph->flags &= ~(TCP_FLG_PUSH | TCP_FLG_FIN);
		}

		/*
		 *  もし、SYN がセットされていれば、
		 *  エラーなので RST を送り、接続を破棄する。
		 */
		if (tcph->flags & TCP_FLG_SYN) {
			VAR_cep.net_error = EV_CNRST;
			cep = tecs_tcp_drop(p_cellcb, E_CLS);
			goto reset_drop;
		}

		/*
		 *  もし、ACK がセットされていない場合は、
		 *  状態が SYN 受信済みか
		 *  SYN を送信しようとしていれば、処理を続けるが、
		 *  それ以外はセグメントを破棄して終了する。
		 */
		if ((tcph->flags & TCP_FLG_ACK) == 0) {
			if (!(VAR_cep.fsm_state == TCP_FSM_SYN_RECVD || (VAR_flags & TCP_CEP_FLG_NEED_SYN)))
				goto drop;
		}
		else {
			/*
			 * ACK の処理
			 */
			ret = tecs_proc_ack1(p_cellcb, input, offset, &needoutput);
			if (ret == RET_DROP)
				goto drop;
			else if (ret == RET_RST_DROP)
				goto reset_drop;
			else if (ret == RET_RETURN)
				return IPPROTO_DONE;
		}
	}

/* step 6 */

	/* 送信ウィンドを更新する。*/
	if (tecs_update_wnd(p_cellcb, tcph) == true)
		needoutput = true;

	/* 緊急データを処理する。*/
	tecs_proc_urg(p_cellcb, tcph);

/* do data */

	/*
	 *  SDU があるか、FIN を未受信の状態で、最初に FIN を受信したとき、
	 *  受信セグメントキューに net_buf を追加する。
	 *  それ以外の場合は、セグメントを破棄する。
	 */
	flags = tcph->flags;
	if ((tcph->sum > 0 || (flags & TCP_FLG_FIN)) &&		/* tcph->sum は TCP の SDU 長 */
	    TCP_FSM_HAVE_RCVD_FIN(VAR_cep.fsm_state) == 0) {
		flags = tecs_reassemble(p_cellcb, input, offset, flags);
	}
	else {
		eCEPInput_input_inputp_dealloc(inputp);
		flags &= ~TCP_FLG_FIN;
	}

	/*
	 *  FIN を受信したらコネクションをクローズする。
	 */
	if (flags & TCP_FLG_FIN)
		tecs_close_connection(p_cellcb, &needoutput);

	/* 出力を行った後終了する。*/
	if (needoutput == true || (VAR_flags & TCP_CEP_FLG_ACK_NOW)) {
		/* 送信を指示する。*/
		VAR_flags |=  TCP_CEP_FLG_POST_OUTPUT;
		cSemaphoreTcppost_signal();
	}

	return IPPROTO_DONE;

reset_drop:
	/*
	 *  RST 送信処理
	 */
	if (input->off.protocolflag & FLAG_USE_IPV4) {
		//TODO:  ip4h =	GET_IP4_HDR(input, input->off.ifhdrlen);
		ip4h =	GET_IP4_HDR(input);
		dst = ntohl(ip4h->dst);
		if ((tcph->flags & TCP_FLG_RST) || IN_IS_NET_ADDR_MULTICAST(input))
			goto drop;
	}

	/* ホストオーダーからネットワークオーダーに戻す。*/

	HTONS(tcph->sport);
	HTONS(tcph->dport);

	if (cep == NULL)
		rbfree = 0;
	else
		rbfree = VAR_rbufSize - VAR_cep.rwbuf_count;

	if (tcph->flags & TCP_FLG_ACK)
		cTCPOutput_respond(inputp, size, cep, 0, tcph->ack, rbfree, TCP_FLG_RST);
	else {
		if (tcph->flags & TCP_FLG_SYN)
			tcph->sum ++;		/* tcph->sum は SDU 長 */
		cTCPOutput_respond(inputp, size, cep, tcph->seq + tcph->sum, 0, rbfree, TCP_FLG_RST | TCP_FLG_ACK);
	}

	/* input は tcp_respoond で返却される。*/
	NET_COUNT_TCP(net_count_tcp[NC_TCP_SEND_RSTS], 1);
	NET_COUNT_MIB(tcp_stats.tcpOutRsts, 1);
	return IPPROTO_DONE;

drop:
	NET_COUNT_TCP(net_count_tcp[NC_TCP_RECV_DROP_SEGS], 1);
	NET_COUNT_MIB(tcp_stats.tcpInErrs, 1);
	eCEPInput_input_inputp_dealloc(inputp);
	return IPPROTO_DONE;
}

/* #[<ENTRY_FUNC>]# eCEPInput_notify
 * name:         eCEPInput_notify
 * global_name:  tTCPCEP_eCEPInput_notify
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
/*
 *  tcp_notify -- ICMP エラーの処理
 */
void
eCEPInput_notify(CELLIDX idx, ER error)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	/*
	 *  コネクション開設済で、ホスト到達不能エラーの場合は、
	 *  再送により処理する。
	 */
	if (VAR_cep.fsm_state == TCP_FSM_ESTABLISHED &&
	    (error == EV_NURCH || error == EV_HURCH || error == EV_HDOWN))
		return;

	/*
	 *  コネクション開設中、同じエラーを何度か受信した場合は、
	 *  待ち状態を解除し、対応する関数にエラーを返させる。
	 */
	if (VAR_cep.fsm_state < TCP_FSM_ESTABLISHED && VAR_cep.rxtshift > 3 && VAR_cep.net_error != E_OK) {
		VAR_cep.error = E_CLS;
		tecs_tcp_close(p_cellcb);
	}
	else {
		VAR_cep.net_error = error;

		/* 送信を指示する。*/
		VAR_flags |=  TCP_CEP_FLG_POST_OUTPUT;
		cSemaphoreTcppost_signal();
	}
}

/* #[<ENTRY_PORT>]# eAPI
 * entry port: eAPI
 * signature:  sTCPCEPAPI
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eAPI_accept
 * name:         eAPI_accept
 * global_name:  tTCPCEP_eAPI_accept
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
/*
 *  tcp_acp_cep -- 接続要求待ち (受動オープン)【標準機能】
 */
ER
eAPI_accept(CELLIDX idx, Descriptor( sREP4 ) desc, uint16_t* dstport, TMO tmout)
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
    ER			error;
	FLGPTN		flag;
	T_IN4_ADDR 	my4addr;
	T_IPV4EP 	ep4;

#if 0
#if defined(SUPPORT_INET6) && defined(SUPPORT_INET4)

	/*
	 * API (tcp6_acp_cep と tcp_acp_cep) と、
	 * TCP通信端点のプロトコルが矛盾していればエラー
	 */

#if API_PROTO == API_PROTO_IPV6

	if (GET_TCP_CEP(cepid)->flags & TCP_CEP_FLG_IPV4)
		return E_ID;

#endif	/* of #if API_PROTO == API_PROTO_IPV6 */

#if API_PROTO == API_PROTO_IPV4

	if ((GET_TCP_CEP(cepid)->flags & TCP_CEP_FLG_IPV4) == 0)
		return E_ID;

#endif	/* of #if API_PROTO == API_PROTO_IPV4 */

#endif	/* of #if defined(SUPPORT_INET6) && defined(SUPPORT_INET4) */

	/* TCP 受付口をチェックする。*/
	if (!VALID_TCP_REPID(repid))
		return E_ID;

#ifdef TCP_CFG_NON_BLOCKING

	/* p_dstaddr が NULL ならエラー */
	if (p_dstaddr == NULL)
		return E_PAR;

#else	/* of #ifdef TCP_CFG_NON_BLOCKING */

	/* p_dstaddr が NULL か、tmout が TMO_NBLK ならエラー */
	if (p_dstaddr == NULL || tmout == TMO_NBLK)
		return E_PAR;

#endif	/* of #ifdef TCP_CFG_NON_BLOCKING */

#if (API_PROTO == API_PROTO_IPV6) && !defined(API_CFG_IP4MAPPED_ADDR)

	/*
	 * API が IPv6 で IPv4 射影アドレスが認められていないのにもかかわらず、
	 * IPv4 射影アドレスが指定されたらエラー
	 */
	if (in6_is_addr_ipv4mapped(&p_dstaddr->ipaddr))
		return E_PAR;

#endif	/* of #if (API_PROTO == API_PROTO_IPV6) && !defined(DAPI_CFG_IP4MAPPED_ADDR) */
#endif 	/* of #if 0 */

	/*
	 *  CEP をロックし、API 機能コードとタスク識別子を記録する。
	 *  すでに記録されていれば、ペンディング中なのでエラー
	 */
	if ((error = tecs_tcp_lock_cep(p_cellcb, TFN_TCP_ACP_CEP)) != E_OK)
		return error;

	/* CEP の FSM がクローズ状態でなければエラー。*/
	if (VAR_cep.fsm_state != TCP_FSM_CLOSED) {
		error = E_OBJ;
		goto err_ret;
	}
	cEstFlag_clear((FLGPTN)(~TCP_CEP_EVT_CLOSED));

	/* TCP 通信端点を初期化する。*/
	tecs_tcp_init_cep(p_cellcb);

	/* TCP 受付口を得る。*/
    cREP4_set_descriptor(desc);

#ifdef TCP_CFG_EXTENTIONS

	/* TCP 受付口をロックする。*/
	syscall(wai_sem(rep->semid_lock));

	/* TCP 受付口をチェックする。*/
	if (!VALID_TCP_REP(rep)) {
		syscall(sig_sem(rep->semid_lock));
		error = E_NOEXS;
		goto err_ret;
	}

#endif	/* of #ifdef TCP_CFG_EXTENTIONS */

	/* TCP 通信端点にTCP受付口を記録する。*/
#if 0
#if defined(_IP6_CFG) && defined(_IP4_CFG)

#if API_PROTO == API_PROTO_IPV6

	cep->rep = rep;

#else	/* of #if API_PROTO == API_PROTO_IPV6 */

	cep->rep4 = rep;

#endif	/*of #if API_PROTO == API_PROTO_IPV6 */

#else	/* of #if defined(_IP6_CFG) && defined(_IP4_CFG) */

	cep->rep = rep;

#endif	/* of #if defined(_IP6_CFG) && defined(_IP4_CFG) */

#ifdef TCP_CFG_EXTENTIONS

	/* TCP 受付口のロックを解除する。*/
	syscall(sig_sem(rep->semid_lock));

#endif	/* of #ifdef TCP_CFG_EXTENTIONS */
#endif 	/* of #if 0 */

	/* TCP 受付口のアドレスをコピーする。*/
	if(ATTR_ipLength == 4) {
		ep4 = cREP4_getEndpoint();
		cGetAddress_setMy4Address(ep4.ipaddr);
	}
	VAR_myport = ep4.portno;

#if 0
#if defined(_IP6_CFG) && defined(_IP4_CFG) && (API_PROTO == API_PROTO_IPV4)

	if (rep->myaddr.ipaddr == IPV4_ADDRANY)
		memcpy(&cep->myaddr.ipaddr, &in6_addr_unspecified,
		                      sizeof(in6_addr_unspecified));
	else
		in6_make_ipv4mapped(&cep->myaddr.ipaddr, rep->myaddr.ipaddr);
	cep->myaddr.portno = rep->myaddr.portno;

#else	/* of #if defined(_IP6_CFG) && defined(_IP4_CFG) && (API_PROTO == API_PROTO_IPV4) */

	cep->myaddr = rep->myaddr;

#endif	/* of #if defined(_IP6_CFG) && defined(_IP4_CFG) && (API_PROTO == API_PROTO_IPV4) */

#if API_PROTO == API_PROTO_IPV4

	/* TCP 通信端点のネットワーク層プロトコルを設定する。*/
	cep->flags |= TCP_CEP_FLG_IPV4;

#endif	/* of #if API_PROTO == API_PROTO_IPV4 */
#endif 	/* of #if 0*/

	/* 通信端点を設定する。*/
	VAR_cep.fsm_state = TCP_FSM_LISTEN;
#if 0
#ifdef TCP_CFG_NON_BLOCKING

	/* タイムアウトをチェックする。*/
	if (tmout == TMO_NBLK) {
		/* ノンブロッキングコール */

#if defined(_IP6_CFG) && defined(_IP4_CFG)

#if API_PROTO == API_PROTO_IPV4

		cep->p_dstaddr4   = p_dstaddr;
		cep->p_dstaddr    = NULL;

#else	/* of #if API_PROTO == API_PROTO_IPV4 */

		cep->p_dstaddr4   = NULL;
		cep->p_dstaddr    = p_dstaddr;

#endif	/* of #if API_PROTO == API_PROTO_IPV4 */

#else	/* of #if defined(_IP6_CFG) && defined(_IP4_CFG) */

		cep->p_dstaddr    = p_dstaddr;

#endif	/* of #if defined(_IP6_CFG) && defined(_IP4_CFG) */

		cep->rcv_nblk_tfn = TFN_TCP_ACP_CEP;
		return E_WBLK;
		}
	else {

#endif	/* of #ifdef TCP_CFG_NON_BLOCKING */
#endif 	/* of #if 0 */

		/*
		 *  FSM が ESTABLISHED になるまで待つ。
		 *  FSM が CLOSED になった場合は、エラーが発生したことを意味している。
		 */
		error = cEstFlag_waitTimeout((TCP_CEP_EVT_CLOSED | TCP_CEP_EVT_ESTABLISHED), TWF_ORW, &flag, tmout);
		if (error == E_OK) {
			if (VAR_cep.error != E_OK)
				error = VAR_cep.error;
			else if (VAR_cep.fsm_state == TCP_FSM_CLOSED)
				error = E_TMOUT;
		}

		cEstFlag_clear((FLGPTN)(~TCP_CEP_EVT_ESTABLISHED));

		if (error == E_OK) {
			/* 相手のアドレスをコピーする。*/
#if 0
#if defined(_IP6_CFG) && defined(_IP4_CFG) && (API_PROTO == API_PROTO_IPV4)
			p_dstaddr->ipaddr = ntohl(cep->dstaddr.ipaddr.s6_addr32[3]);
			p_dstaddr->portno = cep->dstaddr.portno;
#else
			*p_dstaddr = cep->dstaddr;
#endif
#endif 	/* of #if 0 */
		}
		else {
			/*
			 *  通信端点から受付口を解放し、
			 *  イベントフラグをクローズに設定する。
			 */
            cREP4_unjoin();
#if 0
#if defined(_IP6_CFG) && defined(_IP4_CFG)
			cep->rep4 = NULL;
#endif
#endif 	/* of #if 0 */

			VAR_cep.fsm_state = TCP_FSM_CLOSED;
			cEstFlag_set(TCP_CEP_EVT_CLOSED);
		}

		*dstport = VAR_dstport;
#if 0
#ifdef TCP_CFG_NON_BLOCKING

		}

#endif	/* of #ifdef TCP_CFG_NON_BLOCKING */
#endif 	/* of #if 0 */

err_ret:
	VAR_cep.rcv_tskid = TA_NULL;
	sTask_cCallingReceiveTask_unbind();
	VAR_cep.rcv_tfn   = TFN_TCP_UNDEF;
	return error;
}

/* #[<ENTRY_FUNC>]# eAPI_connect
 * name:         eAPI_connect
 * global_name:  tTCPCEP_eAPI_connect
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eAPI_connect(CELLIDX idx, const int8_t* myaddr, uint16_t myport, const int8_t* dstaddr, uint16_t dstport, int32_t addrlen, TMO tmout)
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
    ER          error;
    FLGPTN      flag;
    T_IN4_ADDR  my4addr = *myaddr, dst4addr = *dstaddr;

#if defined(SUPPORT_INET6) && defined(SUPPORT_INET4)

    /*
     * API (tcp6_acp_cep と tcp_acp_cep) と、
     * TCP通信端点のプロトコルが矛盾していればエラー
     */

#if API_PROTO == API_PROTO_IPV6

    if (GET_TCP_CEP(cepid)->flags & TCP_CEP_FLG_IPV4)
        return E_ID;

#endif  /* of #if API_PROTO == API_PROTO_IPV6 */

#if API_PROTO == API_PROTO_IPV4

    if ((GET_TCP_CEP(cepid)->flags & TCP_CEP_FLG_IPV4) == 0)
        return E_ID;

#endif  /* of #if API_PROTO == API_PROTO_IPV4 */

#endif  /* of #if defined(SUPPORT_INET6) && defined(SUPPORT_INET4) */

    /*
     *  あて先がマルチキャストアドレスならエラー
     */

#if defined(_IP6_CFG) && defined(_IP4_CFG) && (API_PROTO == API_PROTO_IPV4)

    if (IN4_IS_ADDR_MULTICAST(dstaddr))
        return E_PAR;

#else   /* of #if defined(_IP6_CFG) && defined(_IP4_CFG) && (API_PROTO == API_PROTO_IPV4) */

    if (IN_IS_ADDR_MULTICAST(dstaddr))
        return E_PAR;

#endif  /* of #if defined(_IP6_CFG) && defined(_IP4_CFG) && (API_PROTO == API_PROTO_IPV4) */

#if (API_PROTO == API_PROTO_IPV6) && !defined(API_CFG_IP4MAPPED_ADDR)

    /*
     * API が IPv6 で IPv4 射影アドレスが認められていないのにもかかわらず、
     * IPv4 射影アドレスが指定されたらエラー
     */
    if (in6_is_addr_ipv4mapped(&p_dstaddr->ipaddr))
        return E_PAR;

#endif  /* of #if (API_PROTO == API_PROTO_IPV6) && !defined(DAPI_CFG_IP4MAPPED_ADDR) */

#ifdef TCP_CFG_NON_BLOCKING

    /*
     *  p_dstaddr または p_myaddr が NULL ならエラー
     */
    if (myaddr == NULL || dstaddr == NULL)
        return E_PAR;

#else   /* of #ifdef TCP_CFG_NON_BLOCKING */

    /*
     *  p_dstaddr または p_myaddr が NULL 、
     *  tmout が TMO_NBLK ならエラー
     */
    if (myaddr == NULL || dstaddr == NULL || tmout == TMO_NBLK)
        return E_PAR;

#endif  /* of #ifdef TCP_CFG_NON_BLOCKING */

    /*
     *  CEP をロックし、API 機能コードとタスク識別子を記録する。
     *  すでに記録されていれば、ペンディング中なのでエラー
     */
    if ((error = tecs_tcp_lock_cep(p_cellcb, TFN_TCP_CON_CEP)) != E_OK)
        return error;

    /* CEP の FSM がクローズ状態でなければエラー。*/
    if (VAR_cep.fsm_state != TCP_FSM_CLOSED) {
        error = E_OBJ;
        goto err_ret;
    }
    cEstFlag_clear((FLGPTN)(~TCP_CEP_EVT_CLOSED));

    /* シーケンス番号を初期化する。*/
    if (cTCPFunctions_getTcpIss() == 0)
        cTCPFunctions_initTcpIss();

    /* 通信端点を初期化する。*/
    tecs_tcp_init_cep(p_cellcb);

    /*
     *  IP アドレスを設定する。
     *  p_myaddr が NADR (-1) ではなく、自 IP アドレスが ANY でなければ、
     *  指定された IP アドレスを割り当てる。
     */

#if defined(_IP6_CFG) && defined(_IP4_CFG) && (API_PROTO == API_PROTO_IPV4)

    if (p_myaddr != NADR && !IN4_IS_ADDR_ANY(&p_myaddr->ipaddr))
        in6_make_ipv4mapped(&cep->myaddr.ipaddr, p_myaddr->ipaddr);
    else
        in6_make_ipv4mapped(&cep->myaddr.ipaddr, IF_GET_IFNET()->in4_ifaddr.addr);

    in6_make_ipv4mapped(&cep->dstaddr.ipaddr, p_dstaddr->ipaddr);
    cep->dstaddr.portno = p_dstaddr->portno;

#else   /* of #if defined(_IP6_CFG) && defined(_IP4_CFG) && (API_PROTO == API_PROTO_IPV4) */

    if(ATTR_ipLength == 4) {
        if (my4addr != 0  && my4addr != IPV4_ADDRANY)
          cGetAddress_setMy4Address(my4addr);
        else
          cGetAddress_setMy4Address(cTCPOutput_getIPv4Address());
        cGetAddress_setDst4Address(dst4addr);
    }
    // if (p_myaddr != NADR && !IN_IS_ADDR_ANY(&p_myaddr->ipaddr))
    //     cep->myaddr.ipaddr = p_myaddr->ipaddr;
    // else {
    //     if (IN_ADDRWITHIFP(IF_GET_IFNET(), &cep->myaddr.ipaddr, &p_dstaddr->ipaddr) == NULL) {
    //         error = E_PAR;
    //         goto err_ret;
    //         }
    //     }

    // cep->dstaddr   = *p_dstaddr;

#endif  /* of #if defined(_IP6_CFG) && defined(_IP4_CFG) && (API_PROTO == API_PROTO_IPV4) */

#if API_PROTO == API_PROTO_IPV4

    /* TCP 通信端点のネットワーク層プロトコルを設定する。*/
    cep->flags |= TCP_CEP_FLG_IPV4;

#endif  /* of #if API_PROTO == API_PROTO_IPV4 */

    /* 通信端点を設定する。*/
    //NET_DEBUG_TCP5("tcp_con_cep3[c=%d,d=%lI.%d,s=%lI.%d]\n",
    VAR_cep.fsm_state = TCP_FSM_SYN_SENT;
    VAR_dstport       = dstport;
    VAR_cep.iss       = cTCPFunctions_getTcpIss();
    VAR_cep.timer[TCP_TIM_KEEP] = TCP_TVAL_KEEP_INIT;
    // tcp_iss += TCP_ISS_INCR() / 2;
    cTCPFunctions_setTcpIss(cTCPFunctions_getTcpIss() + (TCP_ISS_INCR() / 2));
    // init_send_seq(cep);
    VAR_cep.snd_una = VAR_cep.snd_nxt = VAR_cep.snd_max = VAR_cep.iss;

#ifdef TCP_CFG_NON_BLOCKING

    /* タイムアウトをチェックする。*/
    if (tmout == TMO_NBLK) {
        /* ノンブロッキングコール */

#if defined(_IP6_CFG) && defined(_IP4_CFG)

#if API_PROTO == API_PROTO_IPV4

        cep->p_dstaddr4   = p_dstaddr;
        cep->p_myaddr4    = p_myaddr;
        cep->p_dstaddr    = NULL;
        cep->p_myaddr     = NULL;

#else   /* of #if API_PROTO == API_PROTO_IPV4 */

        cep->p_dstaddr4   = NULL;
        cep->p_myaddr4    = NULL;
        cep->p_dstaddr    = p_dstaddr;
        cep->p_myaddr     = p_myaddr;

#endif  /* of #if API_PROTO == API_PROTO_IPV4 */

#else   /* of #if defined(_IP6_CFG) && defined(_IP4_CFG) */

        cep->p_dstaddr    = p_dstaddr;
        cep->p_myaddr     = p_myaddr;

#endif  /* of #if defined(_IP6_CFG) && defined(_IP4_CFG) */

        cep->snd_nblk_tfn = TFN_TCP_CON_CEP;

        /* コネクションの開設をポストする。*/
        cep->flags |= TCP_CEP_FLG_POST_OUTPUT;
        sig_sem(SEM_TCP_POST_OUTPUT);
        return E_WBLK;
        }
    else {

#endif  /* of #ifdef TCP_CFG_NON_BLOCKING */

        /*
         *  p_myaddr が NADR (-1) か、
         *  自ポート番号が TCP_PORTANY なら、自動で割り当てる。
         */
        // if (p_myaddr == NADR || p_myaddr->portno == TCP_PORTANY)
        //     tcp_alloc_auto_port(cep);
        // else if ((error = tcp_alloc_port(cep, p_myaddr->portno)) != E_OK)
        //     goto err_ret;
        if (myport == TCP_PORTANY)
            tecs_tcp_alloc_auto_port(p_cellcb);
        else if ((error = tecs_tcp_alloc_port(p_cellcb, myport)) != E_OK)
            goto err_ret;

        /* コネクションの開設をポストする。*/
        VAR_flags |= TCP_CEP_FLG_POST_OUTPUT;
        cSemaphoreTcppost_signal();

        /*
         *  イベントが ESTABLISHED になるまで待つ。
         *  イベントが CLOSED になった場合は、何らかのエラーが発生したか、
         *  接続要求が拒否されたことを意味している。
         */
        error = cEstFlag_waitTimeout((TCP_CEP_EVT_CLOSED | TCP_CEP_EVT_ESTABLISHED), TWF_ORW, &flag, tmout);
        if (error == E_OK) {
            if (VAR_cep.error != E_OK)
                error = VAR_cep.error;
            else if (VAR_cep.fsm_state == TCP_FSM_CLOSED)
                error = E_CLS;
        }

        cEstFlag_clear((FLGPTN)(~TCP_CEP_EVT_ESTABLISHED));

        if (error != E_OK) {
            /*
             *  通信端点から受付口を解放し、
             *  イベントフラグをクローズに設定する。
             */
            cREP4_unjoin();

#if defined(_IP6_CFG) && defined(_IP4_CFG)
            cep->rep4 = NULL;
#endif

            VAR_cep.fsm_state = TCP_FSM_CLOSED;
            cEstFlag_set(TCP_CEP_EVT_CLOSED);
        }

#ifdef TCP_CFG_NON_BLOCKING

    }

#endif  /* of #ifdef TCP_CFG_NON_BLOCKING */

err_ret:
    VAR_cep.snd_tskid = TA_NULL;
    sTask_cCallingSendTask_unbind();
    //TODO: cREP4_unjoin();
    VAR_cep.snd_tfn   = TFN_TCP_UNDEF;
    return error;
}

/* #[<ENTRY_FUNC>]# eAPI_send
 * name:         eAPI_send
 * global_name:  tTCPCEP_eAPI_send
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER_UINT
eAPI_send(CELLIDX idx, const int8_t* data, int32_t len, TMO tmout)
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
	ER_UINT		error;

#ifdef TCP_CFG_NON_BLOCKING

	/* data が NULL か、len < 0 ならエラー */
	if (data == NULL || len < 0)
		return E_PAR;

#else	/* of #ifdef TCP_CFG_NON_BLOCKING */

	/* data が NULL、len < 0 か、tmout が TMO_NBLK ならエラー */
	if (data == NULL || len < 0 || tmout == TMO_NBLK)
		return E_PAR;

#endif	/* of #ifdef TCP_CFG_NON_BLOCKING */

	/*
	 *  CEP をロックし、API 機能コードとタスク識別子を記録する。
	 *  すでに記録されていれば、ペンディング中なのでエラー
	 */
	if ((error = tecs_tcp_lock_cep(p_cellcb, TFN_TCP_SND_DAT)) != E_OK)
		return error;

	/* 送信できるか、通信端点の状態を見る。*/
	if ((error = tecs_tcp_can_send_more(p_cellcb, TFN_TCP_SND_DAT, tmout)) != E_OK)
		goto err_ret;
#if 0
#ifdef TCP_CFG_NON_BLOCKING

	/* タイムアウトをチェックする。*/
	if (tmout == TMO_NBLK) {		/* ノンブロッキングコール */

		/* 送信ウィンドバッファに空きがあればコールバック関数を呼び出す。*/
		if (!TCP_IS_SWBUF_FULL(cep)) {

		 	/* 送信ウィンドバッファにデータを書き込む。*/
			error = TCP_WRITE_SWBUF(cep, data, (uint_t)len);

			/* 出力をポストする。*/
			cep->flags |= TCP_CEP_FLG_POST_OUTPUT;
			sig_sem(SEM_TCP_POST_OUTPUT);

			/* コールバック関数を呼び出す。*/
#ifdef TCP_CFG_NON_BLOCKING_COMPAT14
			(*cep->callback)(GET_TCP_CEPID(cep), TFN_TCP_SND_DAT, (void*)error);
#else
			(*cep->callback)(GET_TCP_CEPID(cep), TFN_TCP_SND_DAT, (void*)&error);
#endif
			error = E_WBLK;
			goto err_ret;
			}
		else {
			cep->snd_data     = data;
			cep->snd_len      = len;
			cep->snd_nblk_tfn = TFN_TCP_SND_DAT;
			TCP_ALLOC_SWBUF(cep);

			return E_WBLK;
			}
		}
	else {		/* 非ノンブロッキングコール */

#endif	/* of #ifdef TCP_CFG_NON_BLOCKING */
#endif 	//* of #if 0 */

	 	/* 送信ウィンドバッファが空くのを待つ。*/
		if ((error = cCopySave_tcpWaitSwbuf(&VAR_cep, &VAR_flags, VAR_sbufSize, tmout)) != E_OK)
			goto err_ret;

	 	/* 送信ウィンドバッファにデータを書き込む。*/
		if ((error = cCopySave_tcpWriteSwbuf(&VAR_cep, data,len, VAR_sbuf, VAR_sbufSize)) > 0) {

			/* データを送信する。送信ウィンドバッファがフルのときは強制的に送信する。*/
			if (cCopySave_tcpIsSwbufFull(&VAR_cep, VAR_sbufSize))
				VAR_flags |= TCP_CEP_FLG_FORCE | TCP_CEP_FLG_FORCE_CLEAR;

			/* 出力をポストする。*/
			VAR_flags |= TCP_CEP_FLG_POST_OUTPUT;
			cSemaphoreTcppost_signal();
		}
#if 0
#ifdef TCP_CFG_NON_BLOCKING

	}

#endif	/* of #ifdef TCP_CFG_NON_BLOCKING */
#endif 	/* of #if 0 */

err_ret:
	VAR_cep.snd_tskid = TA_NULL;
	sTask_cCallingSendTask_unbind();
    //TODO: cREP4_unjoin();
	VAR_cep.snd_tfn   = TFN_TCP_UNDEF;
	return error;
}

/* #[<ENTRY_FUNC>]# eAPI_receive
 * name:         eAPI_receive
 * global_name:  tTCPCEP_eAPI_receive
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
/*
 *  tcp_rcv_dat -- パケットの受信【標準機能】
 */
ER_UINT
eAPI_receive(CELLIDX idx, int8_t* data, int32_t len, TMO tmout)
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
	ER_UINT		error;
#if 0
#ifdef TCP_CFG_NON_BLOCKING

	/* data が NULL か、len < 0 ならエラー */
	if (data == NULL || len < 0)
		return E_PAR;

#else	/* of #ifdef TCP_CFG_NON_BLOCKING */

	/* data が NULL、len < 0 か、tmout が TMO_NBLK ならエラー */
	if (data == NULL || len < 0 || tmout == TMO_NBLK)
		return E_PAR;

#endif	/* of #ifdef TCP_CFG_NON_BLOCKING */
#endif 	/* of #if 0 */

	/*
	 *  CEP をロックし、API 機能コードとタスク識別子を記録する。
	 *  すでに記録されていれば、ペンディング中なのでエラー
	 */
	if ((error = tecs_tcp_lock_cep(p_cellcb, TFN_TCP_RCV_DAT)) != E_OK)
		return error;

	/* 受信できるか、通信端点の状態を見る。*/
	if (tecs_tcp_can_recv_more(&error, p_cellcb, TFN_TCP_RCV_DAT, tmout) != E_OK)
		goto err_ret;
#if 0
#ifdef TCP_CFG_NON_BLOCKING

	/* タイムアウトをチェックする。*/
	if (tmout == TMO_NBLK) {		/* ノンブロッキングコール */

		/* 受信ウィンドバッファにデータがあればコールバック関数を呼び出す。*/
		if (cep->rwbuf_count > 0) {

			/* 受信ウィンドバッファからデータを取り出す。*/
			len = TCP_READ_RWBUF(cep, data, (uint_t)len);

			/* コールバック関数を呼び出す。*/
#ifdef TCP_CFG_NON_BLOCKING_COMPAT14
			(*cep->callback)(GET_TCP_CEPID(cep), TFN_TCP_RCV_DAT, (void*)(uint32_t)len);
#else
			(*cep->callback)(GET_TCP_CEPID(cep), TFN_TCP_RCV_DAT, (void*)&len);
#endif
			error = E_WBLK;
			goto err_ret;
			}
		else {
			cep->rcv_data     = data;
			cep->rcv_len      = len;
			cep->rcv_nblk_tfn = TFN_TCP_RCV_DAT;
			return E_WBLK;
			}
		}
	else {		/* 非ノンブロッキングコール */

#endif	/* of #ifdef TCP_CFG_NON_BLOCKING */
#endif 	/* of #if 0 */

		/* 受信ウィンドバッファにデータがなければ、入力があるまで待つ。*/
		if ((error = tecs_tcp_wait_rwbuf(p_cellcb, tmout)) != E_OK)
			goto err_ret;

		/* 受信ウィンドバッファからデータを取り出す。*/
		error = cCopySave_tcpReadRwbuf(&VAR_cep, data, len, VAR_rbuf, VAR_rbufSize);

		/* 相手にウィンドウサイズが変わったことを知らせるため出力をポストする。*/
		VAR_flags |= TCP_CEP_FLG_POST_OUTPUT;
		cSemaphoreTcppost_signal();
#if 0
#ifdef TCP_CFG_NON_BLOCKING

		}

#endif	/* of #ifdef TCP_CFG_NON_BLOCKING */
#endif 	/* of #if 0 */

err_ret:
	VAR_cep.rcv_tskid = TA_NULL;
    //TODO: cREP4_unjoin();
	sTask_cCallingReceiveTask_unbind();
	VAR_cep.rcv_tfn   = TFN_TCP_UNDEF;
	return error;
}

/* #[<ENTRY_FUNC>]# eAPI_cancel
 * name:         eAPI_cancel
 * global_name:  tTCPCEP_eAPI_cancel
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eAPI_cancel(CELLIDX idx, FN fncd)
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
    T_TCP_CEP   *cep;
    ER  error = E_OK;
    ER  snd_err, rcv_err;

    /* API 機能コードをチェックする。*/
    if (!VALID_TFN_TCP_CAN(fncd))
        return E_PAR;

    /* TCP 通信端点を得る。*/
    cep = &VAR_cep;

    /* TCP 通信端点をチェックする。*/
    //TODO: if (!VALID_TCP_CEP(cep))
    //     return E_NOEXS;

    if (fncd == TFN_TCP_ALL) {      /* TFN_TCP_ALL の処理 */
        snd_err = tecs_tcp_can_snd(p_cellcb, fncd);
        rcv_err = tecs_tcp_can_rcv(p_cellcb, fncd);

        /*
         *  snd_err と rcv_err のどちらも EV_NOPND
         *  なら、ペンディングしていないのでエラー
         */
        if (snd_err == EV_NOPND && rcv_err == EV_NOPND)
            error = E_OBJ;
        else {
            if (snd_err == EV_NOPND)
                snd_err = E_OK;
            if (rcv_err == EV_NOPND)
                rcv_err = E_OK;

            if (snd_err != E_OK)
                error = snd_err;
            else if (rcv_err != E_OK)
                error = rcv_err;
        }
    }

    else if (IS_TFN_TCP_RCV(fncd)) {    /* 受信処理のキャンセル */
        if ((error = tecs_tcp_can_rcv(p_cellcb, fncd)) == EV_NOPND)
            error = E_OBJ;
    }

    else {                  /* 送信処理のキャンセル */
        if ((error = tecs_tcp_can_snd(p_cellcb, fncd)) == EV_NOPND)
            error = E_OBJ;
    }

    return error;
}

/* #[<ENTRY_FUNC>]# eAPI_close
 * name:         eAPI_close
 * global_name:  tTCPCEP_eAPI_close
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eAPI_close(CELLIDX idx, TMO tmout)
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
    T_TCP_CEP   *cep;
    ER      error = E_OK;
    FLGPTN      flag;

#ifndef TCP_CFG_NON_BLOCKING

    /* tmout が TMO_NBLK ならエラー */
    if (tmout == TMO_NBLK)
        return E_PAR;

#endif  /* of #ifndef TCP_CFG_NON_BLOCKING */

    /*
     *  CEP をロックし、API 機能コードとタスク識別子を記録する。
     *  すでに記録されていれば、ペンディング中なのでエラー
     */
    if ((error = tecs_tcp_lock_cep(p_cellcb, TFN_TCP_CLS_CEP)) != E_OK)
        return error;

#ifdef TCP_CFG_NON_BLOCKING

    /* タイムアウトをチェックする。*/
    if (tmout == TMO_NBLK) {                /* ノンブロッキングコール */

        if (!IS_PTR_DEFINED(cep->callback))
            error = E_OBJ;
        else if (cep->fsm_state == TCP_FSM_CLOSED) {    /* すでにクローズされているとき */

#ifdef TCP_CFG_NON_BLOCKING_COMPAT14

            (*cep->callback)(GET_TCP_CEPID(cep), TFN_TCP_CLS_CEP, E_OK);
            error = E_WBLK;

#else   /* of #ifdef TCP_CFG_NON_BLOCKING_COMPAT14 */

            ER  error = E_OK;

            (*cep->callback)(GET_TCP_CEPID(cep), TFN_TCP_CLS_CEP, (void*)&error);
            error = E_WBLK;

#endif  /* of #ifdef TCP_CFG_NON_BLOCKING_COMPAT14 */

        }
        else {
            /* NBLK のAPI 機能コードを設定する。*/
            cep->rcv_nblk_tfn = TFN_TCP_CLS_CEP;

            if ((cep = tcp_user_closed(cep)) != NULL) { /* コネクションを切断する。*/
                /* 切断セグメント出力をポストする。*/
                cep->flags |= TCP_CEP_FLG_POST_OUTPUT;
                sig_sem(SEM_TCP_POST_OUTPUT);
                }

            /*  cep が NULL で戻ってきた場合は、
             *  既にコネクションが切断されていることを意味している。
             *  また、この場合コールバック関数が呼び出されている。
             */
            return E_WBLK;
            }
        }
    else {                          /* 非ノンブロッキングコール */

#endif  /* of #ifdef TCP_CFG_NON_BLOCKING */

        if ((cep = tecs_tcp_user_closed(p_cellcb)) == NULL) { /* コネクションを切断する。*/

            /*  cep が NULL で戻ってきた場合は、
             *  既にコネクションが切断されていることを意味している。
             */
            return error;
        }
        else {
            /* 切断セグメント出力をポストする。*/
            VAR_flags |= TCP_CEP_FLG_POST_OUTPUT;
            cSemaphoreTcppost_signal();

            /* イベントフラグが CLOSED になるまで待つ。*/
            error = cEstFlag_waitTimeout(TCP_CEP_EVT_CLOSED, TWF_ORW, &flag, tmout);
            if (error == E_OK && VAR_cep.error != E_OK)
                error = VAR_cep.error;

            if (error != E_OK) {
                if (error == E_RLWAI) {
                    /* tcp_cls_cep がキャンセルされたときは、RST を送信する。*/
                    // tcp_respond(NULL, cep, cep->rcv_nxt, cep->snd_una - 1,
                    //             cep->rbufsz - cep->rwbuf_count, TCP_FLG_RST);
                    cTCPOutput_allocAndRespond(cGetAddress_getDstAddress(),
                                               cGetAddress_getMyAddress(),
                                               ATTR_ipLength,
                                               VAR_dstport,
                                               VAR_myport,
                                               VAR_cep.rcv_nxt,
                                               VAR_cep.snd_una - 1,
                                               VAR_rbufSize - VAR_cep.rwbuf_count,
                                               TCP_FLG_RST,
                                               VAR_offset);

                }

                /* タイマーを停止する。*/
                //TODO: tecs_tcp_cancel_timers(cep);
                for (int_t ix = NUM_TCP_TIMERS; ix -- > 0; )
                    VAR_cep.timer[ix] = 0;

                /*
                 *  通信端点をロックし、
                 *  受信再構成キューのネットワークバッファを解放する。
                 */
                cSemaphore_wait();
                tecs_tcp_free_reassq(p_cellcb);
                cSemaphore_signal();

                /* 状態を未使用にする。*/
                VAR_cep.fsm_state = TCP_FSM_CLOSED;

                /*
                 * 以下に関係しないフラグをクリアーする。
                 * ・送受信ウィンドバッファの省コピー機能
                 * ・動的な通信端点の生成・削除機能
                 */
                //TODO: VAR_flags &= TCP_CEP_FLG_NOT_CLEAR;
                VAR_flags &= (TCP_CEP_FLG_WBCS_NBUF_REQ | TCP_CEP_FLG_WBCS_MASK |
                              TCP_CEP_FLG_DYNAMIC       | TCP_CEP_FLG_VALID);
                /*
                 *  通信端点をロックし、
                 *  送受信ウィンドバッファキューのネットワークバッファを解放する。
                 */
                VAR_cep.rwbuf_count = 0;
                cSemaphore_wait();
                cCopySave_tcpFreeRwbufq(&VAR_cep);
                cCopySave_tcpFreeSwbufq(&VAR_cep);
                cSemaphore_signal();

                cEstFlag_set(TCP_CEP_EVT_CLOSED);
            }
        }

#ifdef TCP_CFG_NON_BLOCKING

    }

#endif  /* of #ifdef TCP_CFG_NON_BLOCKING */

    VAR_cep.rcv_tskid = TA_NULL;
    sTask_cCallingReceiveTask_unbind();
    //TODO: cREP4_unjoin();
    VAR_cep.rcv_tfn   = TFN_TCP_UNDEF;
    return error;
}

/* #[<ENTRY_FUNC>]# eAPI_shutdown
 * name:         eAPI_shutdown
 * global_name:  tTCPCEP_eAPI_shutdown
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
/*
 *  tcp_sht_cep  -- データ送信の終了【標準機能】
 */
ER
eAPI_shutdown(CELLIDX idx)
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
	T_TCP_CEP	*cep 	= &VAR_cep;
	ER 			error 	= E_OK;

	/*
	 *  CEP をロックし、API 機能コードとタスク識別子を記録する。
	 *  すでに記録されていれば、ペンディング中なのでエラー
	 */
	if ((error = tecs_tcp_lock_cep(p_cellcb, TFN_TCP_SHT_CEP)) != E_OK)
		return error;

	/* TCP 通信端点のコネクションが確立状態でなければエラー */
	if (!TCP_FSM_HAVE_ESTABLISHED(VAR_cep.fsm_state)) {
		if ((error = VAR_cep.error) == E_OK)
			error = E_OBJ;
	}

	else if ((cep = tecs_tcp_user_closed(p_cellcb)) != NULL) {		/* コネクションを切断する。*/

		/* 切断セグメント出力をポストする。*/
		VAR_flags |= TCP_CEP_FLG_POST_OUTPUT;
		cSemaphoreTcpcep_signal();
	}

	VAR_cep.snd_tskid = TA_NULL;
	VAR_cep.snd_tfn   = TFN_TCP_UNDEF;
	return error;
}

/* #[<ENTRY_PORT>]# eInitializeRoutineBody
 * entry port: eInitializeRoutineBody
 * signature:  sRoutineBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eInitializeRoutineBody_main
 * name:         eInitializeRoutineBody_main
 * global_name:  tTCPCEP_eInitializeRoutineBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eInitializeRoutineBody_main(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	VAR_offset.protocolflag = 0;
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/

/*
 *  tecs_tcp_user_closed -- ユーザからのコネクションの開放
 */

static T_TCP_CEP *
tecs_tcp_user_closed (CELLCB *p_cellcb)
{
	T_TCP_CEP *cep = &VAR_cep;

	switch (VAR_cep.fsm_state) {

	case TCP_FSM_CLOSED:		/* クローズ	*/
	case TCP_FSM_LISTEN:		/* 受動オープン	*/
		VAR_cep.fsm_state = TCP_FSM_CLOSED;
		cep = tecs_tcp_close(p_cellcb);
		break;

	case TCP_FSM_SYN_SENT:		/* 能動オープン、SYN 送信済み	*/
	case TCP_FSM_SYN_RECVD:		/* SYN を受信し、SYN 送信済み	*/
		VAR_flags |= TCP_CEP_FLG_NEED_FIN;
		break;

	case TCP_FSM_ESTABLISHED:	/* コネクション開設完了	*/
		VAR_cep.fsm_state = TCP_FSM_FIN_WAIT_1;
		break;

	case TCP_FSM_CLOSE_WAIT:	/* 相手から FIN 受信、APP の終了待ち */
		VAR_cep.fsm_state = TCP_FSM_LAST_ACK;
		break;
	}

	if (cep != NULL && VAR_cep.fsm_state == TCP_FSM_FIN_WAIT_2)
		VAR_cep.timer[TCP_TIM_2MSL] = TCP_TVAL_KEEP_COUNT * TCP_TVAL_KEEP_INTERVAL;
	return cep;
}
/*
 *  tecs_tcp_output -- TCP 出力処理
 */

static void
tecs_tcp_output (CELLCB *p_cellcb)
{
	bool_t	sendalot = true, idle;
	ER	    error = E_OK;
	int32_t	len;
	uint_t	doff, win;
	uint8_t	flags;

	/*
	 *  snd_una: 未確認の最小送信 SEQ	 または、確認された最大送信 SEQ
	 *  snd_max: 送信した最大 SEQ
	 */
	idle = (VAR_cep.snd_max == VAR_cep.snd_una);

	/*
	 *  idle:   アイドル時間
	 *  rxtcur: 現在の再送タイムアウト
	 */
	if (idle && VAR_cep.idle >= VAR_cep.rxtcur)

		/*
		 *  snd_cwnd: 輻輳ウィンドサイズ
		 *  maxseg  : 相手の最大受信セグメントサイズ
		 *
		 *  長時間アイドルだったのでスロースタート制御に設定する。
		 */
		VAR_cep.snd_cwnd = VAR_cep.maxseg;

	while (error == E_OK && sendalot) {
		sendalot = false;

		/*
		 *  snd_nxt: 次に送信する SEQ、この時点では、前回送信した SEQ
		 *  snd_una: 未確認の最小送信 SEQ、または確認された最大送信 SEQ
		 *
		 *  doff: 送信を開始するオフセット。
		 *                                    swbuf_count (送信バッファにあるオクテット数)
		 *    0                               V
		 *    +-------------------------------------------+
		 *    |                    sbuf                   |
		 *    +-------------------------------------------+
		 *    ^               ^
		 *    |<------------->snd_nxt (前回送信した SEQ)
		 *    |       doff
		 *    snd_una (まだ確認されていない)
		 */
		doff = (uint_t)(VAR_cep.snd_nxt - VAR_cep.snd_una);

		/*
		 *  snd_wnd:  相手の受信可能ウィンドサイズ
		 *  snd_cwnd: 輻輳ウィンドサイズ
		 *
		 *  win: どちらか小さいウィンドサイズに設定する。
		 */
		win = VAR_cep.snd_wnd < VAR_cep.snd_cwnd ? VAR_cep.snd_wnd : VAR_cep.snd_cwnd;

		/* 出力フラグの設定 */
		flags = tcp_outflags[VAR_cep.fsm_state];
		if (VAR_flags & TCP_CEP_FLG_NEED_FIN)
			flags |= TCP_FLG_FIN;
		if (VAR_flags & TCP_CEP_FLG_NEED_SYN)
			flags |= TCP_FLG_SYN;
		if (VAR_flags & TCP_CEP_FLG_FORCE) {

			/*
			 *  もし、送信ウインドサイズ (win) が 0 なら 1 オクテット送信する。
			 *  そうでなければ、持続タイムアウトをキャンセルし、
			 *  再送信回数 (rxtshift) を 0 にする。
			 */
			if (win == 0) {

				/*
				 *  doff:        送信するオクテット数。
				 *  swbuf_count: 送信バッファの使用中サイズ
				 *
				 *  送信バッファに残っているオクテットが、これから
				 *  送信しようとしているオクテット数より多ければ
				 *  FIN フラグをクリアする。
				 */
				if (doff < VAR_cep.swbuf_count)
					flags &=~TCP_FLG_FIN;
				win = 1;
			}
			else {
				/*
				 *  TCP_TIM_PERSIST: 持続タイマ
				 *  rxtshift:        再送信回数の log(2)
				 */
				VAR_cep.timer[TCP_TIM_PERSIST] = 0;
				VAR_cep.rxtshift = 0;
			}
		 }

		/*
		 *  len: 今回送信するオクテット数
		 *        swbuf_count (送信バッファにあるオクテット数)
		 *                                    |
		 *    0                               V
		 *    +-------------------------------------------+
		 *    |                    sbuf       |           |
		 *    +-------------------------------------------+
		 *    ^               ^<------------->
		 *    |               |      len
		 *    |<------------->snd_nxt (前回送信した SEQ)
		 *    |       doff
		 *    snd_una (まだ確認されていない)
		 */
		if (VAR_cep.swbuf_count < win)
			len = (int32_t)VAR_cep.swbuf_count - doff;
		else
			len = (int32_t)win - doff;

		/*
		 *  すでに送信されていれば、SYN ビットをオフする。
		 *  しかし、以下の条件では送信を控える。
		 *
		 *    ・状態が SYN 送信。
		 *    ・セグメントがデータを含んでいる。
		 */
		if ((flags & TCP_FLG_SYN) && SEQ_GT(VAR_cep.snd_nxt, VAR_cep.snd_una)) {
			flags &= ~TCP_FLG_SYN;
			doff --;		/* -1 は SYN フラグ分 */
			len ++;			/* +1 は SYN フラグ分 */
			if (len > 0 && VAR_cep.fsm_state == TCP_FSM_SYN_SENT)
				break;
		}

		if (flags & TCP_FLG_SYN) {
			len = 0;
			flags &= ~TCP_FLG_FIN;
		}

		if (len < 0) {

			/*
			 *  len が 0 以下なら、0 に設定する。
			 *  もし、送信ウィンドウサイズが 0 なら、
			 *  再送信タイマをキャンセルし、
			 *  前回送信した SEQ (snd_nxt) を
			 *  確認された最大送信 SEQ (snd_una) に戻す。
			 *  そして、持続タイマーが止まっていれば、再設定する。
			 */
			len = 0;
			if (win == 0) {
				VAR_cep.timer[TCP_TIM_REXMT] = 0;
				VAR_cep.rxtshift = 0;
				VAR_cep.snd_nxt  = VAR_cep.snd_una;
				if (VAR_cep.timer[TCP_TIM_PERSIST] == 0)
					tecs_tcp_set_persist_timer( p_cellcb );
			}
		}


		/*
		 *  今回送信するオクテット数 (len) は、
		 *  相手の最大受信セグメントサイズ (maxseg) を超えないようにする。
		 */
		if (len > VAR_cep.maxseg) {
			len = VAR_cep.maxseg;
			sendalot = true;
		}

		/*
         *        swbuf_count (送信バッファにあるオクテット数)
         *                                           |
		 *    0                                      V
		 *    +-------------------------------------------+
		 *    |                    sbuf       |           |
		 *    +-------------------------------------------+
		 *    ^               ^<------------->
		 *    |               |      len
		 *    |<------------->snd_nxt (前回送信した SEQ)
		 *    |       doff
		 *    snd_una (まだ確認されていない)
		 *
		 *  今回送信後も、送信バッファにデータが残っていれば
		 *  FIN フラグをクリアする。
		 */
		if (SEQ_LT(VAR_cep.snd_nxt + len, VAR_cep.snd_una + VAR_cep.swbuf_count))
			flags &= ~TCP_FLG_FIN;

		/*
		 *  ここから win は、受信ウィンドウサイズ。
		 *  受信バッファの空き容量
		 */
		win = VAR_rbufSize - VAR_cep.rwbuf_count;

		/*
		 *  愚かなウィンドウ・シンドロームの回避処理 (送信側)
		 *
		 *  以下の条件で、送信を行う。
		 *
		 *    ・フルサイズ (maxseg) のセグメントを送ることができる。
		 *    ・相手の最大の受信ウィンドウサイズの 1/2 のデータを
		 *      送ることができる。
		 *    ・送信バッファを空にでき、アイドルか非遅延オプションが有効なとき。
		 */
		if (len) {

			/*
			 *  今回送信するオクテット数 (len) が
			 *  相手の最大受信セグメントサイズ (maxseg) に
			 *  一致するときは送信する。
			 */
			if (len == VAR_cep.maxseg) {
				error = tecs_send_segment(p_cellcb, &sendalot, doff, win, (uint_t)len, flags);
				continue;
			}

			/*
			 *  今回の送信で、送信バッファを空にでき、
			 *  アイドルか非 PUSH オプションが有効なとき。
			 */
			if ((idle || (VAR_flags & TCP_CEP_FLG_NO_DELAY)) &&
			    (VAR_flags & TCP_CEP_FLG_NO_PUSH) == 0 &&
			    len + doff >= VAR_cep.swbuf_count) {
				error = tecs_send_segment(p_cellcb, &sendalot, doff, win, (uint_t)len, flags);
				continue;
			}

			/*
			 *  max_sndwnd: 今までの最大送信ウィンドサイズ
			 *  snd_nxt:    次に送信する SEQ
			 *  snd_max:    送信した最大 SEQ
			 *
			 *  次の条件では送信を行う。
			 *
			 *    ・強制送信フラグがセットされている。
			 *    ・データ長が相手の最大の受信ウィンドウサイズの 1/2 以上で、
			 *      相手の最大の受信ウィンドウサイズが 0 より大きい。
			 *    ・次に送信する SEQ が送信した最大 SEQ より小さい、
			 *      つまり、再送するとき。
			 */
			if ((VAR_flags & TCP_CEP_FLG_FORCE) ||
			    (len >= VAR_cep.max_sndwnd / 2 && VAR_cep.max_sndwnd > 0) ||
			    SEQ_LT(VAR_cep.snd_nxt, VAR_cep.snd_max)) {
				error = tecs_send_segment(p_cellcb, &sendalot, doff, win, (uint_t)len, flags);
				continue;
			}
		}


		/*
		 *  愚かなウィンドウ・シンドロームの回避処理 (受信側)
		 *
		 *  ウィンドウサイズがフルサイズの 2 倍のセグメント、あるいは
		 *  受信バッファ容量の 1/2 の、いずれか小さいほうの
		 *  サイズで増加される場合は、ウィンドウサイズの更新を行う。
		 */
		if (win > 0) {
			long adv;

			/*
			 *  win:              受信バッファの空き容量
			 *  MAX_TCP_WIN_SIZE: TCP ヘッダの win フィールドに設定できる最大値
			 *  rcv_adv:          受信を期待している最大の SEQ
			 *  rcv_nxt:          受信を期待している最小の SEQ
			 */
			if (win < MAX_TCP_WIN_SIZE)
				adv = win - (VAR_cep.rcv_adv - VAR_cep.rcv_nxt);
			else
				adv = MAX_TCP_WIN_SIZE - (VAR_cep.rcv_adv - VAR_cep.rcv_nxt);

			if (adv     >= (long)(VAR_cep.maxseg * 2) ||
			    adv * 2 >= (long) VAR_rbufSize) {
				error = tecs_send_segment(p_cellcb, &sendalot, doff, win, (uint_t)len, flags);
				continue;
			}
		}

		/*
		 *  ACK を送信する。
		 */
		if (VAR_flags & TCP_CEP_FLG_ACK_NOW) {
			error = tecs_send_segment(p_cellcb, &sendalot, doff, win, (uint_t)len, flags);
			continue;
		}

		if ( (flags & TCP_FLG_RST) ||
		    ((flags & TCP_FLG_SYN) && (VAR_flags & TCP_CEP_FLG_NEED_SYN) == 0)) {
			error = tecs_send_segment(p_cellcb, &sendalot, doff, win, (uint_t)len, flags);
			continue;
		}

#ifdef TCP_CFG_EXTENTIONS

		if (SEQ_GT(VAR_cep.snd_up, VAR_cep.snd_una)) {
			error = tecs_send_segment(p_cellcb, &sendalot, doff, win, (uint_t)len, flags);
			continue;
		}

#endif	/* of #ifdef TCP_CFG_EXTENTIONS */

		/*
		 *  snd_nxt: 次に送信する SEQ
		 *  snd_una: 未確認の最小送信 SEQ、または確認された最大送信 SEQ
		 *
		 *  相手から FIN を受信し、まだ FIN を送信していないか、
		 *  送るデータがないときは、FIN を相手に届けるため、
		 *  セグメントを送信する。
		 */
		if ((flags & TCP_FLG_FIN) &&
		    ((VAR_flags & TCP_CEP_FLG_SENT_FIN) == 0 || VAR_cep.snd_nxt == VAR_cep.snd_una)) {
			error = tecs_send_segment(p_cellcb, &sendalot, doff, win, (uint_t)len, flags);
			continue;
		}

		/*
		 *  送信すべきデータがあり、再送タイマと持続タイマが切れているときは
		 *  持続タイマを設定する。
		 */
		if (VAR_cep.swbuf_count && VAR_cep.timer[TCP_TIM_REXMT	] == 0 &&
		                           VAR_cep.timer[TCP_TIM_PERSIST] == 0) {
			VAR_cep.rxtshift = 0;
			tecs_tcp_set_persist_timer( p_cellcb );
			break;
		}

	}
}

/*
 *  tecs_tcp_alloc_auto_port -- 自動割り当てポート番号を設定する。
 */

static void
tecs_tcp_alloc_auto_port (CELLCB *p_cellcb)
{
    int_t       ix;
    uint16_t    portno;
    CELLCB      *p_cb;

    while (true) {
        portno = tcp_port_auto ++;
        if (tcp_port_auto > TCP_PORT_LAST_AUTO)
            tcp_port_auto = TCP_PORT_FIRST_AUTO;

#if defined(TNUM_TCP6_REPID)
#if TNUM_TCP6_REPID > 0

        for (ix = tmax_tcp6_repid; ix -- > 0; ) {

#ifdef TCP_CFG_EXTENTIONS

            if (VALID_TCP_REP(&tcp6_rep[ix]) && tcp6_rep[ix].myaddr.portno == portno) {
                portno = TCP_PORTANY;
                break;
            }

#else   /* of #ifdef TCP_CFG_EXTENTIONS */

            if (tcp6_rep[ix].myaddr.portno == portno) {
                portno = TCP_PORTANY;
                break;
            }

#endif  /* of #ifdef TCP_CFG_EXTENTIONS */

        }

#endif  /* of #if TNUM_TCP6_REPID > 0 */
#endif  /* of #if defined(TNUM_TCP6_REPID) */

#if defined(TNUM_TCP4_REPID)
#if TNUM_TCP4_REPID > 0

        for (ix = tmax_tcp4_repid; ix -- > 0; ) {

#ifdef TCP_CFG_EXTENTIONS

            if (VALID_TCP_REP(&tcp4_rep[ix]) && tcp4_rep[ix].myaddr.portno == portno) {
                portno = TCP_PORTANY;
                break;
            }

#else   /* of #ifdef TCP_CFG_EXTENTIONS */

            if (tcp4_rep[ix].myaddr.portno == portno) {
                portno = TCP_PORTANY;
                break;
            }

#endif  /* of #ifdef TCP_CFG_EXTENTIONS */

        }

#endif  /* of #if TNUM_TCP4_REPID > 0 */
#endif  /* of #if defined(TNUM_TCP4_REPID) */

        if (portno != TCP_PORTANY) {

            syscall(wai_sem(SEM_TCP_CEP));
            cSemaphoreTcpcep_wait();
            FOREACH_CELL(ix, p_cb)
            if (((tTCPCEP_VAR_flags(p_cb) & TCP_CEP_FLG_VALID) != 0) &&
                 (tTCPCEP_VAR_myport(p_cb) == portno)) {
                portno = TCP_PORTANY;
                break;
            }
            END_FOREACH_CELL

            if (portno != TCP_PORTANY) {
                VAR_myport = portno;
                cSemaphoreTcpcep_signal();
                return;
            }
            cSemaphoreTcpcep_signal();
        }
    }
}

/*
 *  tecs_tcp_alloc_port -- 指定されたポート番号を設定する。
 */

static ER
tecs_tcp_alloc_port (CELLCB *p_cellcb, uint16_t portno)
{
    int_t   ix;
    CELLCB *p_cb;

    cSemaphoreTcpcep_wait();

    FOREACH_CELL(ix, p_cb)
    if (((tTCPCEP_VAR_flags(p_cb) & TCP_CEP_FLG_VALID) != 0) &&
         (tTCPCEP_VAR_myport(p_cb) == portno)) {
        cSemaphoreTcpcep_signal();
        return E_PAR;
    }
    END_FOREACH_CELL

    VAR_myport = portno;
    cSemaphoreTcpcep_signal();
    return E_OK;
}

/*
 *  tecs_tcp_close -- コネクションを開放する。
 */

static T_TCP_CEP *
tecs_tcp_close (CELLCB *p_cellcb)
{
	/* タイマーを停止する。*/
	int_t ix;
	for (ix = NUM_TCP_TIMERS; ix -- > 0; )
		VAR_cep.timer[ix] = 0;

	/*
	 *  通信端点をロックし、
	 *  受信再構成キューのネットワークバッファを解放する。
	 */
	cSemaphore_wait();
	tecs_tcp_free_reassq( p_cellcb );
	cSemaphore_signal();

	/* 状態を未使用にする。*/
	VAR_cep.fsm_state = TCP_FSM_CLOSED;

	/*
	 * 以下に関係しないフラグをクリアーする。
	 * ・送受信ウィンドバッファの省コピー機能
	 * ・動的な通信端点の生成・削除機能
	 * ・通信端点のネットワーク層プロトコル
	 */
	//VAR_flags &= TCP_CEP_FLG_NOT_CLEAR;
	VAR_flags &= (TCP_CEP_FLG_WBCS_NBUF_REQ | TCP_CEP_FLG_WBCS_MASK |
	              TCP_CEP_FLG_DYNAMIC       | TCP_CEP_FLG_VALID);

#if 0
#ifdef TCP_CFG_NON_BLOCKING

	if (VAR_cep.snd_nblk_tfn != TFN_TCP_UNDEF || VAR_cep.rcv_nblk_tfn != TFN_TCP_UNDEF) {
		/* ノンブロッキングコール */

#ifdef TCP_CFG_NON_BLOCKING_COMPAT14

		if (!IS_PTR_DEFINED(VAR_cep.callback))
			syslog(LOG_WARNING, "[TCP] no call back, CEP: %d.", GET_TCP_CEPID(cep));
		else {
			if (VAR_cep.rcv_nblk_tfn != TFN_TCP_UNDEF) {
				ER_UINT len;

				switch (VAR_cep.rcv_nblk_tfn) {

				case TFN_TCP_ACP_CEP:
					/* TCP 通信端点からTCP 受付口を解放する。*/
					//cep->rep = NULL;

#if defined(_IP6_CFG) && defined(_IP4_CFG)
					//cep->rep4 = NULL;
#endif

					(*VAR_cep.callback)(GET_TCP_CEPID(VAR_cep), VAR_cep.rcv_nblk_tfn, (void*)E_CLS);
					break;

				case TFN_TCP_RCV_BUF:

					/* 受信ウィンドバッファの空アドレスを獲得する。*/
					len = TCP_GET_RWBUF_ADDR(VAR_cep, VAR_cep.rcv_p_buf);

					/* 異常切断等のエラーを設定する。*/
					if (VAR_cep.error == E_TMOUT)
						len = E_CLS;
					else if (VAR_cep.error < 0)
						len = VAR_cep.error;

					(*VAR_cep.callback)(GET_TCP_CEPID(VAR_cep), VAR_cep.rcv_nblk_tfn, (void*)(uint32_t)len);
					break;

				case TFN_TCP_RCV_DAT:

					/* 受信ウィンドバッファからデータを取り出す。*/
					len = TCP_READ_RWBUF(VAR_cep, VAR_cep.rcv_data, (uint_t)VAR_cep.rcv_len);

					/* 異常切断等のエラーを設定する。*/
					if (VAR_cep.error == E_TMOUT)
						len = E_CLS;
					else if (VAR_cep.error != E_OK)
						len = VAR_cep.error;

					(*VAR_cep.callback)(GET_TCP_CEPID(VAR_cep), VAR_cep.rcv_nblk_tfn, (void*)(uint32_t)len);
					break;

				case TFN_TCP_CLS_CEP:

					if (VAR_cep.error == E_TMOUT)
						(*VAR_cep.callback)(GET_TCP_CEPID(VAR_cep), VAR_cep.rcv_nblk_tfn, (void*)E_CLS);
					else
						(*VAR_cep.callback)(GET_TCP_CEPID(VAR_cep), VAR_cep.rcv_nblk_tfn, (void*)VAR_cep.error);
					break;

				default:
					syslog(LOG_WARNING, "[TCP] unexp TFN: %s.", in_strtfn((FN)VAR_cep.rcv_nblk_tfn));
					break;
				}

				/* 記憶されているタスク ID と API 機能コードをクリアーする。*/
				VAR_cep.snd_tskid = TA_NULL;
				VAR_cep.rcv_tskid = TA_NULL;
				sTask_cCallingReceiveTask_unbind();
				sTask_cCallingSendTask_unbind();
				VAR_cep.rcv_tfn   = TFN_TCP_UNDEF;
				//TODO: CHECK!!
				VAR_cep.rcv_nblk_tfn = TFN_TCP_UNDEF;
				VAR_cep.rcv_tfn = TFN_TCP_UNDEF;
			}

			if (VAR_cep.snd_nblk_tfn != TFN_TCP_UNDEF) {

				switch (VAR_cep.snd_nblk_tfn) {

				case TFN_TCP_CON_CEP:
					/* TCP 通信端点から TCP 受付口を解放する。*/
					//cep->rep = NULL;

#if defined(_IP6_CFG) && defined(_IP4_CFG)
					//cep->rep4 = NULL;
#endif

					(*VAR_cep.callback)(GET_TCP_CEPID(VAR_cep), VAR_cep.snd_nblk_tfn, (void*)E_CLS);
					break;

				case TFN_TCP_SND_DAT:
				case TFN_TCP_GET_BUF:
					if (VAR_cep.error == E_TMOUT)
						(*VAR_cep.callback)(GET_TCP_CEPID(VAR_cep), VAR_cep.snd_nblk_tfn, (void*)E_CLS);
					else
						(*VAR_cep.callback)(GET_TCP_CEPID(vAR_cep), VAR_cep.snd_nblk_tfn, (void*)VAR_cep.error);
					break;

				default:
					syslog(LOG_WARNING, "[TCP] unexp TFN: %s.", in_strtfn((FN)VAR_cep.snd_nblk_tfn));
					break;
				}

				/* 記憶されているタスク ID と API 機能コードをクリアーする。*/
				VAR_cep.snd_tskid = TA_NULL;
				VAR_cep.rcv_tskid = TA_NULL;
				sTask_cCallingReceiveTask_unbind();
				sTask_cCallingSendTask_unbind();
				VAR_cep.rcv_tfn   = TFN_TCP_UNDEF;
				//TODO: CHECK!!
				VAR_cep.rcv_nblk_tfn = TFN_TCP_UNDEF;
				VAR_cep.rcv_tfn = TFN_TCP_UNDEF;
			}
		}

#else	/* of #ifdef TCP_CFG_NON_BLOCKING_COMPAT14 */

		if (!IS_PTR_DEFINED(VAR_cep.callback))
			syslog(LOG_WARNING, "[TCP] no call back, CEP: %d.", GET_TCP_CEPID(VAR_cep));
		else {
			if (VAR_cep.rcv_nblk_tfn != TFN_TCP_UNDEF) {
				ER_UINT len;

				switch (VAR_cep.rcv_nblk_tfn) {

				case TFN_TCP_ACP_CEP:

					/* TCP 通信端点からTCP 受付口を解放する。*/
					//cep->rep = NULL;

#if defined(_IP6_CFG) && defined(_IP4_CFG)
					//cep->rep4 = NULL;
#endif

					/* 接続エラーを設定する。*/
					len      = E_CLS;
					(*VAR_cep.callback)(GET_TCP_CEPID(VAR_cep), VAR_cep.rcv_nblk_tfn, (void*)&len);
					break;

				case TFN_TCP_RCV_BUF:

					/* 受信ウィンドバッファの空アドレスを獲得する。*/
					len = TCP_GET_RWBUF_ADDR(VAR_cep, VAR_cep.rcv_p_buf);

					/* 異常切断等のエラーを設定する。*/
					if (VAR_cep.error == E_TMOUT)
						len = E_CLS;
					else if (VAR_cep.error < 0)
						len = VAR_cep.error;

					(*VAR_cep.callback)(GET_TCP_CEPID(VAR_cep), VAR_cep.rcv_nblk_tfn, (void*)&len);
					break;

				case TFN_TCP_RCV_DAT:

					/* 受信ウィンドバッファからデータを取り出す。*/
					len = TCP_READ_RWBUF(VAR_cep, VAR_cep.rcv_data, (uint_t)VAR_cep.rcv_len);

					/* 異常切断等のエラーを設定する。*/
					if (VAR_cep.error == E_TMOUT)
						len = E_CLS;
					else if (VAR_cep.error != E_OK)
						len = VAR_cep.error;

					(*VAR_cep.callback)(GET_TCP_CEPID(VAR_cep), VAR_cep.rcv_nblk_tfn, (void*)&len);
					break;

				case TFN_TCP_CLS_CEP:
					if (VAR_cep.error == E_TMOUT)
						len = E_CLS;
					else
						len = VAR_cep.error;
					(*VAR_cep.callback)(GET_TCP_CEPID(VAR_cep), VAR_cep.rcv_nblk_tfn, (void*)&len);
					break;

				default:
					syslog(LOG_WARNING, "[TCP] unexp TFN: %s.", in_strtfn((FN)VAR_cep.rcv_nblk_tfn));
					break;
				}

				/* 記憶されているタスク ID と API 機能コードをクリアーする。*/
				VAR_cep.snd_tskid = TA_NULL;
				VAR_cep.rcv_tskid = TA_NULL;
				sTask_cCallingReceiveTask_unbind();
				sTask_cCallingSendTask_unbind();
				VAR_cep.rcv_tfn   = TFN_TCP_UNDEF;
				//TODO: CHECK!!
				VAR_cep.rcv_nblk_tfn = TFN_TCP_UNDEF;
				VAR_cep.rcv_tfn = TFN_TCP_UNDEF;
			}

			if (VAR_cep.snd_nblk_tfn != TFN_TCP_UNDEF) {
				ER_UINT len;

				switch (VAR_cep.snd_nblk_tfn) {

				case TFN_TCP_CON_CEP:

					/* TCP 通信端点からTCP 受付口を解放する。*/
					//cep->rep = NULL;

#if defined(_IP6_CFG) && defined(_IP4_CFG)
					//cep->rep4 = NULL;
#endif

					/* 接続エラーを設定する。*/
					len      = E_CLS;
					(*VAR_cep.callback)(GET_TCP_CEPID(VAR_cep), VAR_cep.snd_nblk_tfn, (void*)&len);
					break;

				case TFN_TCP_SND_DAT:
				case TFN_TCP_GET_BUF:
					if (VAR_cep.error == E_TMOUT)
						len = E_CLS;
					else
						len = VAR_cep.error;
					(*VAR_cep.callback)(GET_TCP_CEPID(VAR_cep), VAR_cep.rcv_nblk_tfn, (void*)&len);
					break;

				default:
					syslog(LOG_WARNING, "[TCP] unexp TFN: %s.", in_strtfn((FN)VAR_cep.snd_nblk_tfn));
					break;
				}

				/* 記憶されているタスク ID と API 機能コードをクリアーする。*/
				VAR_cep.snd_tskid = TA_NULL;
				VAR_cep.rcv_tskid = TA_NULL;
				sTask_cCallingReceiveTask_unbind();
				sTask_cCallingSendTask_unbind();
				VAR_cep.rcv_tfn   = TFN_TCP_UNDEF;
				//TODO: CHECK!!
				VAR_cep.rcv_nblk_tfn = TFN_TCP_UNDEF;
				VAR_cep.rcv_tfn = TFN_TCP_UNDEF;
			}
		}

#endif	/* of #ifdef TCP_CFG_NON_BLOCKING_COMPAT14 */

		/*
		 *  通信端点をロックし、
		 *  送受信ウィンドバッファキューのネットワークバッファを解放する。
		 */
		cSemaphore_wait();
		cCopySave_tcpFreeRwbufq(&VAR_cep);
		cCopySave_tcpFreeSwbufq(&VAR_cep);
		cSemaphore_signal();

		/* 未使用になったことを知らせる。*/
		cEstFlag_set(TCP_CEP_EVT_CLOSED);
	}
	else {	/* 非ノンブロッキングコール */

#endif	/* of #ifdef TCP_CFG_NON_BLOCKING */
#endif
		/* 記憶されているタスク ID と API 機能コードをクリアーする。*/
		VAR_cep.snd_tskid = TA_NULL;
		VAR_cep.rcv_tskid = TA_NULL;
		//TODO: sTask_cCallingReceiveTask_unbind();
		//TODO: sTask_cCallingSendTask_unbind();
		VAR_cep.rcv_tfn   = TFN_TCP_UNDEF;
		VAR_cep.rcv_tfn   = TFN_TCP_UNDEF;

		/*
		 *  通信端点をロックし、
		 *  送受信ウィンドバッファキューのネットワークバッファを解放する。
		 */
		cSemaphore_wait();
		cCopySave_tcpFreeRwbufq(&VAR_cep);
		cCopySave_tcpFreeSwbufq(&VAR_cep);
		cSemaphore_signal();

		/* 未使用になったことを知らせる。*/
		cEstFlag_set(TCP_CEP_EVT_CLOSED);

		/*
		 * 入出力タスクを起床して、
		 * 送受信不可になったことを知らせる。
		 */
		//TODO: CHECK!! syscall(set_flg(cep->snd_flgid, TCP_CEP_EVT_SWBUF_READY));
		//TODO: CHECK!! syscall(set_flg(cep->rcv_flgid, TCP_CEP_EVT_RWBUF_READY));
		cSendFlag_set(TCP_CEP_EVT_SWBUF_READY);
		cRcvFlag_set(TCP_CEP_EVT_RWBUF_READY);
#if 0
#ifdef TCP_CFG_NON_BLOCKING

	}

#endif	/* of #ifdef TCP_CFG_NON_BLOCKING */
#endif
	return NULL;
}

/*
 *  tecs_tcp_free_reassq -- 受信再構成キューのネットワークバッファを解放する。
 *
 *    注意:
 *      必要であれば、この関数を呼び出す前に、通信端点をロックし、
 *      戻った後、解除する必要がある。
 */

static void
tecs_tcp_free_reassq (CELLCB *p_cellcb)
{
	T_NET_BUF	*q, *nq;
	T_TCP_IP4_Q_HDR *ip4qhdr;

	if (VAR_offset.protocolflag & FLAG_USE_IPV4) {
		for (q = VAR_cep.reassq; q != NULL; q = nq) {
			//TODO: ip4qhdr = ((T_TCP_IP4_Q_HDR*)GET_IP4_HDR(q,q->off.ifhdrlen));
			ip4qhdr = ((T_TCP_IP4_Q_HDR*)GET_IP4_HDR(q));
			// nq = GET_TCP_Q_HDR(q, ip4qhdr->thoff)->next;
			eCEPInput_input_inputp_dealloc(q);
		}
	}
	VAR_cep.reassq  = NULL;
}


/*
 *  tecs_tcp_drop -- TCP 接続を破棄する。
 */

static T_TCP_CEP *
tecs_tcp_drop (CELLCB *p_cellcb, ER errno)
{
    T_TCP_CEP *cep = &VAR_cep;

#ifdef SUPPORT_MIB

    if ((VAR_cep.fsm_state == TCP_FSM_SYN_SENT) || (VAR_cep.fsm_state == TCP_FSM_SYN_RECVD)) {
        NET_COUNT_MIB(tcp_stats.tcpAttemptFails, 1);
    }

#endif  /* of #ifdef SUPPORT_MIB */

    VAR_cep.error = errno;
    if (TCP_FSM_HAVE_RCVD_SYN(VAR_cep.fsm_state)) {
        VAR_cep.fsm_state = TCP_FSM_CLOSED;

        /* 送信と、送信後コネクションの切断を指示する。*/
        VAR_flags |=  TCP_CEP_FLG_POST_OUTPUT | TCP_CEP_FLG_CLOSE_AFTER_OUTPUT;
        cSemaphoreTcppost_signal();
    }
    else {
        cep = tecs_tcp_close(p_cellcb);
    }

    return cep;
}

/*
 *  tecs_tcp_can_snd -- ペンディングしている送信のキャンセル
 */

static ER
tecs_tcp_can_snd (CELLCB *p_cellcb, FN fncd)
{
    ER  error = E_OK;
    T_TCP_CEP *cep = &VAR_cep;

    /* 通信端点をロックする。*/
    cSemaphore_wait();

    /*
     *  snd_tskid が TA_NULL なら、
     *  ペンディングしていないのでエラー
     */
    if (VAR_cep.snd_tskid == TA_NULL)
        error = EV_NOPND;

    /* ペンディング中の API 機能コードと一致しなければエラー */
    else if (fncd != TFN_TCP_ALL && fncd != VAR_cep.snd_tfn)
        error = E_OBJ;

    /* 処理をキャンセルする。*/
    else {

        /* 受信再構成キューのネットワークバッファを解放する。*/
        tecs_tcp_free_reassq(p_cellcb);

        /* 受信ウィンドバッファキューのネットワークバッファを解放する。*/
        cep->rwbuf_count = 0;
        // TCP_FREE_RWBUFQ(cep);
        cCopySave_tcpFreeRwbufq(cep);

        /* 送信ウィンドバッファキューのネットワークバッファを解放する。*/
        // TCP_FREE_SWBUFQ(cep);
        cCopySave_tcpFreeSwbufq(cep);

#ifdef TCP_CFG_NON_BLOCKING

        if (cep->snd_nblk_tfn != TFN_TCP_UNDEF) {   /* ノンブロッキングコール */

            switch (cep->snd_nblk_tfn) {

            case TFN_TCP_CON_CEP:
                /*
                 *  通信端点から受付口を解放し、
                 *  イベントフラグをクローズに設定する。
                 */
                cep->rep = NULL;

#if defined(_IP6_CFG) && defined(_IP4_CFG)
                cep->rep4 = NULL;
#endif

                cep->fsm_state = TCP_FSM_CLOSED;
                syscall(set_flg(cep->est_flgid, TCP_CEP_EVT_CLOSED));
                break;

            case TFN_TCP_SND_DAT:
            case TFN_TCP_GET_BUF:
            case TFN_TCP_SND_OOB:
                break;
            }

            if (IS_PTR_DEFINED(cep->callback)) {

#ifdef TCP_CFG_NON_BLOCKING_COMPAT14

                (*cep->callback)(GET_TCP_CEPID(cep), cep->snd_nblk_tfn, (void*)E_RLWAI);

#else   /* of #ifdef TCP_CFG_NON_BLOCKING_COMPAT14 */

                ER  error = E_RLWAI;

                (*cep->callback)(GET_TCP_CEPID(cep), cep->snd_nblk_tfn, (void*)&error);

#endif  /* of #ifdef TCP_CFG_NON_BLOCKING_COMPAT14 */

            }
            else
                error = E_OBJ;
            cep->snd_nblk_tfn = TFN_TCP_UNDEF;
            }
        else

#endif  /* of #ifdef TCP_CFG_NON_BLOCKING */

            // error = rel_wai(cep->snd_tskid);
            error = cCallingSendTask_releaseWait();

        VAR_cep.snd_tskid = TA_NULL;
        sTask_cCallingSendTask_unbind();
        //TODO: cREP4_unjoin();
        VAR_cep.snd_tfn   = TFN_TCP_UNDEF;
    }

    /* 通信端点のロックを解除する。*/
    cSemaphore_signal();

    return error;
}

/*
 *  tecs_tcp_can_rcv -- ペンディングしている受信のキャンセル
 */

static ER
tecs_tcp_can_rcv (CELLCB *p_cellcb, FN fncd)
{
    ER  error = E_OK;
    T_TCP_CEP *cep = &VAR_cep;

    /* 通信端点をロックする。*/
    cSemaphore_wait();

    /*
     *  rcv_tskid が TA_NULL なら、
     *  ペンディングしていないのでエラー
     */
    if (VAR_cep.rcv_tskid == TA_NULL)
        error = EV_NOPND;

    /* ペンディング中の API 機能コードと一致しなければエラー */
    else if (fncd != TFN_TCP_ALL && fncd != VAR_cep.rcv_tfn)
        error = E_OBJ;

    /* 処理をキャンセルする。*/
    else {

        /* 受信再構成キューのネットワークバッファを解放する。*/
        tcp_free_reassq(p_cellcb);

        /* 受信ウィンドバッファキューのネットワークバッファを解放する。*/
        VAR_cep.rwbuf_count = 0;
        // TCP_FREE_RWBUFQ(cep);
        cCopySave_tcpFreeRwbufq(cep);

        /* 送信ウィンドバッファキューのネットワークバッファを解放する。*/
        // TCP_FREE_SWBUFQ(cep);
        cCopySave_tcpFreeSwbufq(cep);

#ifdef TCP_CFG_NON_BLOCKING

        if (cep->rcv_nblk_tfn != TFN_TCP_UNDEF) {   /* ノンブロッキングコール */

            switch (cep->rcv_nblk_tfn) {

            case TFN_TCP_ACP_CEP:
                /*
                 *  通信端点から受付口を解放し、
                 *  イベントフラグをクローズに設定する。
                 */
                cep->rep = NULL;

#if defined(_IP6_CFG) && defined(_IP4_CFG)
                cep->rep4 = NULL;
#endif

                cep->fsm_state = TCP_FSM_CLOSED;
                syscall(set_flg(cep->est_flgid, TCP_CEP_EVT_CLOSED));
                break;

            case TFN_TCP_RCV_DAT:
            case TFN_TCP_RCV_BUF:
                break;

            case TFN_TCP_CLS_CEP:
                cep->fsm_state = TCP_FSM_CLOSED;
                tcp_respond(NULL, cep, cep->rcv_nxt, cep->snd_una - 1,
                            cep->rbufsz - cep->rwbuf_count, TCP_FLG_RST);
                syscall(set_flg(cep->est_flgid, TCP_CEP_EVT_CLOSED));
                break;
            }

            if (IS_PTR_DEFINED(cep->callback)) {

#ifdef TCP_CFG_NON_BLOCKING_COMPAT14

                (*cep->callback)(GET_TCP_CEPID(cep), cep->rcv_nblk_tfn, (void*)E_RLWAI);

#else   /* of #ifdef TCP_CFG_NON_BLOCKING_COMPAT14 */

                ER  error = E_RLWAI;

                (*cep->callback)(GET_TCP_CEPID(cep), cep->rcv_nblk_tfn, (void*)&error);

#endif  /* of #ifdef TCP_CFG_NON_BLOCKING_COMPAT14 */

            }
            else
                error = E_OBJ;
            cep->rcv_nblk_tfn = TFN_TCP_UNDEF;
        }
        else

#endif  /* of #ifdef TCP_CFG_NON_BLOCKING */

            // error = rel_wai(cep->rcv_tskid);
            error = cCallingReceiveTask_releaseWait();

        cep->rcv_tskid = TA_NULL;
        sTask_cCallingReceiveTask_unbind();
        //TODO: cREP4_unjoin();
        cep->rcv_tfn   = TFN_TCP_UNDEF;
    }

    /* 通信端点のロックを解除する。*/
    cSemaphore_signal();

    return error;
}

/*
 *  tecs_tcp_can_send_more -- 送信できるか、通信端点の状態を見る。
 */

static ER
tecs_tcp_can_send_more (CELLCB *p_cellcb, FN fncd, TMO tmout)
{
	ER	error;

	/* 送信できるか、CEP の FSM 状態を見る。*/
	if (!TCP_FSM_CAN_SEND_MORE(VAR_cep.fsm_state)) {
		if ((error = VAR_cep.error) == E_OK)
			error = E_OBJ;
#if 0
#ifdef TCP_CFG_NON_BLOCKING

		/* タイムアウトをチェックする。*/
		if (tmout == TMO_NBLK) {	/* ノンブロッキングコール */

			if (!IS_PTR_DEFINED(cep->callback))
				error = E_OBJ;
			else {
				/* コールバック関数を呼び出す。*/
#ifdef TCP_CFG_NON_BLOCKING_COMPAT14
				(*cep->callback)(GET_TCP_CEPID(cep), fncd, (void*)error);
#else
				(*cep->callback)(GET_TCP_CEPID(cep), fncd, (void*)&error);
#endif
				error = E_WBLK;
				}
			}

#endif	/* of #ifdef TCP_CFG_NON_BLOCKING */
#endif 	/* of #if 0 */
	}
	else {

#ifdef TCP_CFG_SWBUF_CSAVE

		error = E_OK;

#else	/* of #ifdef TCP_CFG_SWBUF_CSAVE */

		if (!IS_PTR_DEFINED(VAR_sbuf)) {
#if 0
#ifdef TCP_CFG_NON_BLOCKING

			/* タイムアウトをチェックする。*/
			if (tmout == TMO_NBLK) {	/* ノンブロッキングコール */
				if (!IS_PTR_DEFINED(cep->callback))
					error = E_OBJ;
				else {
					error = E_OBJ;

					/* コールバック関数を呼び出す。*/
#ifdef TCP_CFG_NON_BLOCKING_COMPAT14
					(*cep->callback)(GET_TCP_CEPID(cep), fncd, (void*)error);
#else
					(*cep->callback)(GET_TCP_CEPID(cep), fncd, (void*)&error);
#endif
					error = E_WBLK;
					}
				}
			else

#endif	/* of #ifdef TCP_CFG_NON_BLOCKING */
#endif 	/* of #if 0 */

			error = E_OBJ;
		}
		else
			error = E_OK;

#endif	/* of #ifdef TCP_CFG_SWBUF_CSAVE */

	}

	return error;
}

/*
 *  tecs_tcp_can_recv_more -- 受信できるか、通信端点の状態を見る。
 *
 *  注意: 戻り値
 *
 *	E_OK	受信可能
 *	E_OBJ	相手から切断されたか、エラーが発生した。
 */

static ER
tecs_tcp_can_recv_more (ER *error, CELLCB *p_cellcb, FN fncd, TMO tmout)
{
	/*
	 *  受信できるか、fsm_state を見る。受信できない場合は
	 *  長さ 0、またはエラーを返す。
	 */
	if (!TCP_FSM_CAN_RECV_MORE(VAR_cep.fsm_state) &&
	    VAR_cep.rwbuf_count == 0 && VAR_cep.reassq == NULL) {
		*error = VAR_cep.error;
#if 0
#ifdef TCP_CFG_NON_BLOCKING

		/* タイムアウトをチェックする。*/
		if (tmout == TMO_NBLK) {	/* ノンブロッキングコール */

			if (!IS_PTR_DEFINED(cep->callback))
				*error = E_OBJ;
			else {
				/* コールバック関数を呼び出す。*/
#ifdef TCP_CFG_NON_BLOCKING_COMPAT14
				(*cep->callback)(GET_TCP_CEPID(cep), fncd, (void*)*error);
#else
				(*cep->callback)(GET_TCP_CEPID(cep), fncd, (void*)error);
#endif
				*error = E_WBLK;
				}
			}

#endif	/* of #ifdef TCP_CFG_NON_BLOCKING */
#endif 	/* of #if 0 */

		/*
		 *  通信端点をロックして、
		 *  受信ウィンドバッファキューのネットワークバッファを解放する。
		 */
		cSemaphore_wait();
		cCopySave_tcpFreeRwbufq(&VAR_cep);
		cSemaphore_signal();

		return E_OBJ;
	}
	else {

#ifndef TCP_CFG_RWBUF_CSAVE

		if (!IS_PTR_DEFINED(VAR_rbuf)) {
#if 0
#ifdef TCP_CFG_NON_BLOCKING

			/* タイムアウトをチェックする。*/
			if (tmout == TMO_NBLK) {	/* ノンブロッキングコール */
				if (!IS_PTR_DEFINED(cep->callback))
					*error = E_OBJ;
				else {
					*error = E_OBJ;

					/* コールバック関数を呼び出す。*/
#ifdef TCP_CFG_NON_BLOCKING_COMPAT14
					(*cep->callback)(GET_TCP_CEPID(cep), fncd, (void*)*error);
#else
					(*cep->callback)(GET_TCP_CEPID(cep), fncd, (void*)error);
#endif
					*error = E_WBLK;
					}
				}
			else

#endif	/* of #ifdef TCP_CFG_NON_BLOCKING */
#endif 	/* of #if 0 */

				*error = E_OBJ;

			return E_OBJ;
		}

#endif	/* of #ifndef TCP_CFG_RWBUF_CSAVE */

		return E_OK;
	}
}

/*
 *  tecs_tcp_set_persist_timer -- 持続タイマの設定
 */

static void
tecs_tcp_set_persist_timer (CELLCB *p_cellcb)
{
    T_TCP_TIME time;

    /*
     *  srtt:   平滑化された RTT
     *  rttvar: 平滑化された分散
     */
    time = ((VAR_cep.srtt >> 2) + VAR_cep.rttvar) >> 1;

    /*
     *  再送タイマも設定されていれば回復不能エラー
     */
    if (VAR_cep.timer[TCP_TIM_REXMT])
        /* %%% panic("tcp_output REXMT"); %%% */;

    /*
     *  持続タイマを設定する。
     */
    VAR_cep.timer[TCP_TIM_PERSIST] = cTCPFunctions_tcpRangeSet((T_TCP_TIME)(time * tcp_back_off[VAR_cep.rxtshift]),
                                                                           (T_TCP_TIME)TCP_TVAL_MIN_PERSIST,
                                                                           (T_TCP_TIME)TCP_TVAL_MAX_PERSIST);
                                        // tcp_range_set((T_TCP_TIME)(time * tcp_back_off[cep->rxtshift]),
                                        //         (T_TCP_TIME)TCP_TVAL_MIN_PERSIST,
                                        //         (T_TCP_TIME)TCP_TVAL_MAX_PERSIST);
    /*
     *  再送回数を更新する。
     */
    if (VAR_cep.rxtshift < TCP_MAX_REXMT_SHIFT)
        VAR_cep.rxtshift ++;
}

/*
 *  tecs_tcp_wait_rwbuf -- 受信ウィンドバッファにデータが入るのを待つ。
 */

static ER
tecs_tcp_wait_rwbuf (CELLCB *p_cellcb, TMO tmout)
{
	ER	error;
	FLGPTN	flag;

	if (VAR_cep.rwbuf_count == 0) {
		/* 受信ウィンドバッファにデータがなければ、入力があるまで待つ。*/
		while (VAR_cep.rwbuf_count == 0) {
			if ((error = cRcvFlag_waitTimeout(TCP_CEP_EVT_RWBUF_READY, TWF_ORW, &flag, tmout)) != E_OK) {
				return error;
				}
			cRcvFlag_clear((FLGPTN)(~TCP_CEP_EVT_RWBUF_READY));

			/*
			 *  受信できるか、fsm_state を見る。受信できない状態で、
			 *  受信ウィンドバッファに文字がない場合は終了する。
			 */
			if (!TCP_FSM_CAN_RECV_MORE(VAR_cep.fsm_state) &&
			    VAR_cep.rwbuf_count == 0 && VAR_cep.reassq == NULL) {

				/*
				 *  通信端点をロックして、
				 *  受信ウィンドバッファキューのネットワークバッファを解放する。
				 */
				cSemaphore_wait();
				cCopySave_tcpFreeRwbufq(&VAR_cep);
				cSemaphore_signal();

				return VAR_cep.error;
			}
		}
	}
	else {
		cRcvFlag_clear((FLGPTN)(~TCP_CEP_EVT_RWBUF_READY));
	}

	return E_OK;
}

/*
 *  tecs_tcp_move_ra2rw -- 受信再構成キューで再構成したセグメントを受信ウィンドバッファに書き込む。
 */

static uint8_t
tecs_tcp_move_ra2rw (CELLCB *p_cellcb, uint8_t flags)
{
	T_NET_BUF	*q;
	T_TCP_Q_HDR	*qhdr;
	T_TCP_IP4_Q_HDR *ip4qhdr;

	/*
	 *  受信データを受信ウィンドバッファに書き込み、
	 *  rcv_nxt を完了した SEQ だけ進める。
	 */
	if (TCP_FSM_HAVE_ESTABLISHED(VAR_cep.fsm_state)) {
		if (VAR_offset.protocolflag & FLAG_USE_IPV4) {
			while (VAR_cep.reassq != NULL) {
				q = VAR_cep.reassq;
				qhdr = GET_TCP_Q_HDR(q, GET_IP_TCP_Q_HDR_OFFSET(q));
				if (qhdr->seq != VAR_cep.rcv_nxt)
					break;

				/* 次のセグメントに進む。*/
				VAR_cep.reassq = qhdr->next;

				/* FIN フラグのみ残す。*/
				flags &= TCP_FLG_FIN;

				/* データを受信ウィンドバッファに書き込む。*/
				// TCP_WRITE_RWBUF(cep, q, (uint_t)(GET_IP_TCP_Q_HDR_OFFSET(q)));
				cCopySave_tcpWriteRwbuf(&VAR_cep, (int8_t*)q,
								q->len + sizeof(T_NET_BUF) - 4 + VAR_offset.ifalign,
								(uint_t)(ip4qhdr->thoff), VAR_rbuf, VAR_rbufSize);
				//TODO: eCEPInput_input_inputp_dealloc(q);
			}
		}
	}
	if (VAR_cep.reassq != NULL) {
		VAR_flags |= TCP_CEP_FLG_ACK_NOW;
		flags &= ~TCP_FLG_FIN;
	}
	return flags;
}

/*
 *  tecs_tcp_write_raque -- 受信セグメントを再構成して、受信再構成キューに繋ぐ。
 */

static uint8_t
tecs_tcp_write_raque (CELLCB *p_cellcb, T_NET_BUF *input, uint_t thoff, uint8_t flags)
{
	T_NET_BUF	*new;
	T_NET_BUF	*p, *q, *nq;
	T_TCP_Q_HDR	*qhdr, *inqhdr = GET_TCP_Q_HDR(input, thoff);
	int32_t		len, tempoff, poff;
	T_TCP_IP4_Q_HDR *ip4qhdr;

	if(input->off.protocolflag & FLAG_USE_IPV4){
		/*  TCP ヘッダの位置を保存する。*/
		// SET_IP_TCP_Q_HDR_OFFSET(input, thoff);
		ip4qhdr = (T_TCP_IP4_Q_HDR *)(input->buf + input->off.ifhdrlen);
		ip4qhdr->thoff = thoff;
	}
	/*
	 *  MAX_TCP_REALLOC_SIZE 以下の場合は、新たにネットワークバッファを
	 *  割当てて、データをコピーする。
	 *  このとき、IP のオプション（拡張ヘッダ）と TCP のオプションは削除する。
	 */
	// len  = IF_IP_TCP_HDR_SIZE(input) + inqhdr->slen;
	len = input->off.iphdrlen + input->off.ifhdrlen + TCP_HDR_SIZE + inqhdr->slen;


	if (len <= MAX_TCP_REALLOC_SIZE) {

		/*
		 *  ネットワークバッファが確保できないときは割当てない。
		 */
        if (eCEPInput_input_inputp_alloc(&new, (uint_t)len, TMO_TCP_GET_NET_BUF) != E_OK)
			new = NULL;
	}
	else
		new = NULL;

	/*
	 *    inqhdr->seq
	 *    |
	 *    |<------- inqhdr->slen ------->|
	 *    v                              v
	 *    +------------------------------+
	 *    |             input            |
	 *    +------------------------------+
	 *        ^                  ^
	 *        |<----- slen ----->|
	 *        |
	 *        soff
	 *
	 */
	inqhdr->soff = 0;

	/*
	 *  今回追加するセグメントより前(p)と後(q)のセグメントを探す。
	 *
	 *    +-------------------------+
	 *    |            p            |
	 *    +-------------------------+
	 *    ^              +---------------------------+
	 *    p->seq         |            input          |
	 *                   +---------------------------+
	 *                   ^                      +-------------------------+
	 *                   inqhdr->seq            |            q            |
	 *                                          +-------------------------+
	 *                                          ^
	 *                                          q->seq
	 */
	for (q = VAR_cep.reassq, p = NULL; q != NULL; ) {
		if (q->off.protocolflag & FLAG_USE_IPV4) {
			/*  TCP ヘッダの位置を保存する。*/
			ip4qhdr = (T_TCP_IP4_Q_HDR *)(q->buf + q->off.ifhdrlen);
			tempoff = ip4qhdr->thoff;
		}
		qhdr = GET_TCP_Q_HDR(q, tempoff);
		if (SEQ_GT(qhdr->seq, inqhdr->seq))
			break;
		p = q;
		poff = tempoff;
		q = qhdr->next;
	}

	/*
	 *  前(p)のセグメントがあれば、既に、今回と同じセグメントが
	 *  あることもある。その場合は、その部分または全てを破棄する。
	 *
	 *    qhdr->seq
	 *    |
	 *    |<----- qhdr->slen ------>|
	 *    v                         v
	 *    +-------------------------+
	 *    |            p            |
	 *    +-------------------------+
	 *                    <--len -->
	 *                   +---------------------------+
	 *                   |            input          |
	 *                   +---------------------------+
	 *                   ^
	 *                   inqhdr->seq
	 */
	if (p != NULL) {
		qhdr = GET_TCP_Q_HDR(p, poff);
		len = qhdr->seq + qhdr->slen - inqhdr->seq;
		if (len > 0) {

			/*
			 *  len が正であれば、前(p) のセグメントと今回の
			 *  セグメントが重なっている。
			 */
			if (len >= inqhdr->slen) {

				/*
				 *  len が今回のセグメントと同じなら
				 *  まったく同じセグメントなので何もしない。
				 */
				if (new != NULL) {
					eCEPInput_input_inputp_dealloc(new);
				}

				eCEPInput_input_inputp_dealloc(input);
				return flags;
			}

			/*
			 *  追加するセグメントの SDU を len 分前に詰める。
			 */
			inqhdr->seq  += len;
			inqhdr->soff += (uint16_t)len;
			inqhdr->slen -= (uint16_t)len;
		}
	}

	/*
	 *  キューにつなぐ前に、新しいネットワークバッファにデータを移す。
	 *  TCP のオプションは削除する。
	 */
	if (new != NULL) {
		memcpy(new->buf, input->buf, (size_t)(thoff + TCP_HDR_SIZE));
		memcpy((uint8_t*)GET_TCP_HDR(new, thoff) + TCP_HDR_SIZE,
		                 GET_TCP_SDU(input, thoff), (size_t)(inqhdr->slen));
        eCEPInput_input_inputp_dealloc(input);
		input = new;
		inqhdr = GET_TCP_Q_HDR(input, thoff);
		inqhdr->doff = (uint8_t)TCP_MAKE_DATA_OFF(TCP_HDR_SIZE);
	}

	/*
	 *  重なる後(q)のセグメントを調整する。
	 *
	 *    inqhdr->seq
	 *    |
	 *    |<----- inqhdr->slen ---->|
	 *    v                         v
	 *    +-------------------------+
	 *    |          input          |
	 *    +-------------------------+
	 *                    <--len -->
	 *                   +---------------------------+
	 *                   |              q            |
	 *                   +---------------------------+
	 *                   ^
	 *                   qhdr->seq
	 */
	while (q != NULL) {
		qhdr = GET_TCP_Q_HDR(q, tempoff);
		len = inqhdr->seq + inqhdr->slen - qhdr->seq;
		if (len <= 0)
			/* len が負なら重なっていない。*/
			break;
		else if (len < qhdr->slen) {

			/*
			 *  後ろで重なっているセグメントの SDU を len 分前に詰める。
			 *
			 *    inqhdr->seq
			 *    |
			 *    |<----- inqhdr->slen ---->|
			 *    v                         v
			 *    +-------------------------+
			 *    |          input          |
			 *    +-------------------------+
			 *                    <--len -->
			 *            +------+---------------------------+
			 *            |      |              q            |
			 *            +------+---------------------------+
			 *                   ^--------->
			 *                   qhdr->seq
			 *                   qhdr->soff
			 */
			qhdr->seq  += len;
			qhdr->soff += (uint16_t)len;
			qhdr->slen -= (uint16_t)len;
			break;
		}
		nq = qhdr->next;
		if (p)
			GET_TCP_Q_HDR(p, poff)->next = nq;
		else
			VAR_cep.reassq = nq;
		eCEPInput_input_inputp_dealloc(q);
		q = nq;
	}

	if (p == NULL) {
		inqhdr->next = VAR_cep.reassq;
		VAR_cep.reassq = input;
	}
	else {
		inqhdr->next = GET_TCP_Q_HDR(p, poff)->next;
		GET_TCP_Q_HDR(p, poff)->next = input;
	}

	return tecs_tcp_move_ra2rw(p_cellcb, flags);
}


/*
 *  tecs_tcp_rexmt_val -- 再送タイムアウト値を返す。
 */

static T_TCP_TIME
tecs_tcp_rexmt_val (CELLCB *p_cellcb)
{
	T_TCP_TIME val;

	val = ((VAR_cep.srtt >> (TCP_SRTT_SHIFT - TCP_DELTA_SHIFT)) + VAR_cep.rttvar) >> TCP_DELTA_SHIFT;
	if (val < TCP_TVAL_MIN)
		return TCP_TVAL_MIN;
	else
	  return val;
}

/*
 *  tecs_tcp_init_cep -- 通信端点を初期化する。
 */

static void
tecs_tcp_init_cep (CELLCB *p_cellcb)
{
#if 0
#ifdef TCP_CFG_RWBUF_CSAVE
	/*
	 * 受信ウィンドバッファの省コピー機能を有効にした場合、
	 * 受信ウィンドバッファが全て解放されないことがあるので、
	 * ここで解放する。
	 */
	if (cep->rwbufq != NULL) {
		cep->rwbuf_count = 0;
		TCP_FREE_RWBUFQ(cep);
		}
#endif	/* of #ifdef TCP_CFG_RWBUF_CSAVE */
#endif

	// memset((uint8_t*)cep + offsetof(T_TCP_CEP, timer), 0,
	       // sizeof(T_TCP_CEP) - offsetof(T_TCP_CEP, timer));
	for (int_t ix = 0; ix < NUM_TCP_TIMERS; ix++)
		VAR_cep.timer[ix] = 0;
	VAR_cep.reassq 			= 0;	/* 受信再構成キュー			*/
	VAR_cep.snd_una 		= 0;	/* 未確認の最小送信 SEQ つまり	*/
									/* 確認された最大送信 SEQ		*/
	VAR_cep.snd_max 		= 0;	/* 送信した最大 SEQ			*/
	VAR_cep.snd_nxt 		= 0;	/* 次に送信する SEQ			*/
	VAR_cep.snd_old_nxt 	= 0;	/* 元の snd_nxt				*/
	VAR_cep.snd_wl1 		= 0;	/* 前回ウィンドを更新した SEQ	 	*/
	VAR_cep.snd_wl2 		= 0;	/* 前回ウィンドを更新した ACK 	*/
	VAR_cep.iss 			= 0;	/* 自分の SEQ の初期値		*/
	VAR_cep.irs 			= 0;	/* 相手の SEQ の初期値		*/
	VAR_cep.rcv_nxt 		= 0;	/* 受信を期待している最小の SEQ	*/
	VAR_cep.rcv_adv 		= 0;	/* 受信を期待している最大の SEQ	*/
	VAR_cep.rcv_wnd 		= 0;	/* 受信可能なウィンドサイズ		*/
	VAR_cep.rtseq 			= 0;	/* 時間計測を始めた SEQ		*/
	VAR_cep.last_ack_sent 	= 0;	/* 最後に送信した ACK			*/
	VAR_cep.idle 			= 0;	/* アイドル時間				*/
	VAR_cep.error 			= 0;	/* 非同期に発生したエラー		*/
	VAR_cep.net_error 		= 0;	/* ネットワークのエラー状態		*/
	VAR_cep.snd_wnd 		= 0;	/* 相手の受信可能ウィンドサイズ	*/
	VAR_cep.max_sndwnd 		= 0;	/* 今までの最大送信ウィンドサイズ	*/
	VAR_cep.rtt 			= 0;	/* 往復時間					*/
	VAR_cep.swbuf_count 	= 0;	/* 送信ウィンドバッファの使用中サイズ	*/
	VAR_cep.rwbuf_count 	= 0;	/* 受信ウィンドバッファの使用中サイズ	*/
	VAR_cep.rcv_buf_len 	= 0;	/* tcp_rcv_buf の割当て長		*/
	VAR_cep.get_buf_len 	= 0;	/* tcp_rcv_buf の割当て長		*/
	VAR_cep.rxtshift 		= 0;	/* 再送信回数の log(2)		*/
	VAR_cep.fsm_state 		= 0;	/* FSM 状態					*/
	VAR_cep.dupacks 		= 0;	/* 再送 ACK 数				*/

	VAR_cep.sbuf_rptr = VAR_cep.sbuf_wptr = VAR_sbuf;
	VAR_cep.rbuf_rptr = VAR_cep.rbuf_wptr = VAR_rbuf;

	if (ATTR_ipLength == 4)
		VAR_cep.maxseg	= TCP_MSS;		/* 送信最大セグメントサイズ		*/
	else
		VAR_cep.maxseg  = TCP6_MSS;
	//CEHCK cep->maxseg	= DEF_TCP_SND_SEG;		/* 送信最大セグメントサイズ		*/
	VAR_cep.srtt	= TCP_TVAL_SRTT_BASE;		/* 滑らかな移動平均			*/
	VAR_cep.rttvar	= ((TCP_TVAL_RTO_BASE - TCP_TVAL_SRTT_BASE) << TCP_RTTVAR_SHIFT) / 4;
							/* 滑らかな分散				*/
	VAR_cep.rxtcur	= TCP_TVAL_RTO_BASE;		/* 現在の再送値				*/
	VAR_cep.snd_cwnd	=  MAX_TCP_WIN_SIZE;		/* 輻輳ウィンドサイズ			*/
	VAR_cep.snd_ssthresh= MAX_TCP_WIN_SIZE;		/* 輻輳ウィンドサイズ(snd_cwnd)の	制限値	*/

	/*
	 * 以下に関係しないフラグをクリアーする。
	 * ・送受信ウィンドバッファの省コピー機能
	 * ・動的な通信端点の生成・削除機能
	 * ・通信端点のネットワーク層プロトコル
	 */
	VAR_flags &= (TCP_CEP_FLG_WBCS_NBUF_REQ | TCP_CEP_FLG_WBCS_MASK |
	              TCP_CEP_FLG_DYNAMIC       | TCP_CEP_FLG_VALID);

	/* セマフォを初期化する。*/
	cSemaphore_signal();

	/* フラグを初期化する。*/
	cSendFlag_set(TCP_CEP_EVT_SWBUF_READY);
	cRcvFlag_clear(TCP_CEP_EVT_RWBUF_READY);
}

/*
 *  tecs_tcp_lock_cep -- TCP 通信端点をロックする。
 */

static ER
tecs_tcp_lock_cep (CELLCB *p_cellcb, FN tfn)
{
	ER error = E_OK;

	/* TCP 通信端点をロックする。*/
	cSemaphore_wait();

	/* TCP 通信端点をチェックする。*/
	//TEMP if (!VALID_TCP_CEP {
	if (!(VAR_flags & TCP_CEP_FLG_VALID) != 0) {
		cSemaphore_signal();
		return E_NOEXS;
	}

	/*
	 *  API 機能コードとタスク識別子を記録する。
	 *  すでに記録されていれば、ペンディング中なのでエラー
	 */
	if (IS_TFN_TCP_RCV(tfn)) {
		if (VAR_cep.rcv_tfn != TFN_TCP_UNDEF ||
		    (tfn == TFN_TCP_ACP_CEP && VAR_cep.snd_tfn == TFN_TCP_CON_CEP))
			error = E_OBJ;
		else {
			getTaskId(&(VAR_cep.rcv_tskid));
			cCallingReceiveTask_bind();
			VAR_cep.rcv_tfn = tfn;
		}
	}
	else {
		if (VAR_cep.snd_tfn != TFN_TCP_UNDEF ||
		    (tfn == TFN_TCP_CON_CEP && VAR_cep.rcv_tfn == TFN_TCP_ACP_CEP) ||
		    (tfn == TFN_TCP_CON_CEP && VAR_cep.rcv_tfn == TFN_TCP_CLS_CEP))
			error = E_OBJ;
		else {
			getTaskId(&(VAR_cep.snd_tskid));
			cCallingSendTask_bind();
			VAR_cep.snd_tfn = tfn;
		}
	}

	/* 通信端点のロックを解除する。*/
	cSemaphore_signal();

	return error;
}

/*
 *  tecs_tcp_timers -- タイムアウト処理
 */

static T_TCP_CEP *
tecs_tcp_timers (CELLCB *p_cellcb, int_t tix)
{
	uint16_t 	win;
	T_TCP_CEP 	*cep = &VAR_cep;

	switch (tix) {

	/*
	 *  再送タイマ
	 */
	case TCP_TIM_REXMT:

		/*
		 *  最大再送回数 (TCP_MAX_REXMT_SHIFT、標準 12 回) になったときは、
		 *  コネクションを切断する。
		 */
		if (++ VAR_cep.rxtshift > TCP_MAX_REXMT_SHIFT) {
			VAR_cep.rxtshift  = TCP_MAX_REXMT_SHIFT;
			VAR_cep.net_error = EV_REXMTMO;
			cep = tecs_tcp_drop(p_cellcb, E_CLS);
			break;
		}

		/*
		 *  再送タイムアウトを計算する。
		 */
		VAR_cep.rxtcur = cTCPFunctions_tcpRangeSet((T_TCP_TIME)(tecs_tcp_rexmt_val(p_cellcb) * tcp_back_off[VAR_cep.rxtshift]),
		                            			   (T_TCP_TIME)TCP_TVAL_MIN,
		                            			   (T_TCP_TIME)TCP_TVAL_MAX_REXMT);
		VAR_cep.timer[TCP_TIM_REXMT] = VAR_cep.rxtcur;

		/*
		 *  srtt:   平滑化された RTT
		 *  rttvar: 平滑化された分散
		 *
		 *  再送回数が最大再送回数の 1/4 になったときは、
		 *  平滑化された分散 (rttvar) に srtt を加算し、
		 *  平滑化された RTT を 0 にする。
		 *
		 */
		if (VAR_cep.rxtshift > TCP_MAX_REXMT_SHIFT / 4) {
			VAR_cep.rttvar += (VAR_cep.srtt >> TCP_SRTT_SHIFT);
			VAR_cep.srtt    = 0;
		}

		/*
		 *  snd_nxt: 次に送信する SEQ、この時点では、前回送信した SEQ
		 *  snd_una: 未確認の最小送信 SEQ	 または、確認された最大送信 SEQ
		 *
		 *  前回送信した SEQ (snd_nxt) を
		 *  確認された最大送信 SEQ (snd_una) まで戻す。
		 */
		VAR_cep.snd_nxt = VAR_cep.snd_una;
		VAR_flags  |= TCP_CEP_FLG_ACK_NOW;

		/*
		 *  rtt: 往復時間の計測を中止する。
		 */
		VAR_cep.rtt     = 0;

		/*
		 *  送信ウインドの設定
		 *
		 *  snd_wnd:  相手の受信可能ウィンドサイズ
		 *  snd_cwnd: 輻輳ウィンドサイズ
		 *  maxseg  : 相手の最大受信セグメントサイズ
		 *
		 *  相手の受信可能ウィンドサイズ (snd_wnd) か、
		 *  輻輳ウィンドサイズ (snd_cwnd) の
		 *  どちらか小さいサイズの 1/2 を、更に
		 *  相手の最大受信セグメントサイズ (maxseg) で割った値。
		 *  ただし、2 以上
		 */
		if (VAR_cep.snd_wnd < VAR_cep.snd_cwnd)
			win = VAR_cep.snd_wnd / 2 / VAR_cep.maxseg;
		else
			win = VAR_cep.snd_cwnd / 2 / VAR_cep.maxseg;

		if (win < 2)
			win = 2;

		/*
		 *  輻輳ウィンドサイズ (snd_cwnd) は
		 *  相手の受信可能ウィンドサイズ (snd_wnd) に、
		 *  輻輳ウィンドサイズのしきい値 (snd_ssthresh) は
		 *  相手の受信可能ウィンドサイズ (snd_wnd) の win 倍に
		 *  設定する。
		 */
		VAR_cep.snd_cwnd     = VAR_cep.maxseg;
		VAR_cep.snd_ssthresh = win * VAR_cep.maxseg;
		VAR_cep.dupacks      = 0;

		/* 出力をポストする。*/
		VAR_flags |= TCP_CEP_FLG_POST_OUTPUT;
		cSemaphoreTcppost_signal();
		break;

	/*
	 *  持続タイマ
	 */
	case TCP_TIM_PERSIST:

		/*
		 *  最大再送回数 (TCP_MAX_REXMT_SHIFT、標準 12 回) を超えていて、
		 *  アイドル時間が、保留タイマの標準値 (TCP_TVAL_KEEP_IDLE、
		 *  標準 2 * 60 * 60 秒) 以上か、
		 *  再送タイムアウト値 * バックオフ時間の合計以上なら
		 *  コネクションを切断する。
		 */
		if (VAR_cep.rxtshift > TCP_MAX_REXMT_SHIFT &&
		    (VAR_cep.idle >= TCP_TVAL_KEEP_IDLE ||
		     VAR_cep.idle >= tecs_tcp_rexmt_val(cep) * TCP_TOTAL_BACK_OFF)) {
			VAR_cep.net_error = EV_REXMTMO;
			cep = tecs_tcp_drop(p_cellcb, E_CLS);
			break;
		}

		/* 持続タイマを再設定し、出力をポストする。*/
		tecs_tcp_set_persist_timer(p_cellcb);

		VAR_flags |= TCP_CEP_FLG_FORCE | TCP_CEP_FLG_FORCE_CLEAR | TCP_CEP_FLG_POST_OUTPUT;
		cSemaphoreTcppost_signal();
		break;

	/*
	 *  保留 (keep alive) タイマ
	 */
	case TCP_TIM_KEEP:

		/*
		 *  コネクションが開設されるまでにタイムアウトしたら
		 *  コネクションの開設を中止する。
		 */
		if (VAR_cep.fsm_state < TCP_FSM_ESTABLISHED) {
			VAR_cep.net_error = EV_REXMTMO;
			cep = tecs_tcp_drop(p_cellcb, E_CLS);
			break;
		}

#ifdef TCP_CFG_ALWAYS_KEEP

		else if (VAR_cep.fsm_state < TCP_FSM_CLOSING) {
			if (VAR_cep.idle >= TCP_TVAL_KEEP_IDLE +
			                 TCP_TVAL_KEEP_COUNT * TCP_TVAL_KEEP_INTERVAL) {
				VAR_cep.net_error = EV_REXMTMO;
				cep = tecs_tcp_drop(p_cellcb, E_CLS);
				break;
			}
			else {
				int32_t size;
				cTCPOutput_respond(NULL, size, &VAR_cep, VAR_cep.rcv_nxt, VAR_cep.snd_una - 1, VAR_rbufSize - VAR_cep.rwbuf_count, 0);
			}
			VAR_cep.timer[TCP_TIM_KEEP] = TCP_TVAL_KEEP_INTERVAL;
		}
		else
			VAR_cep.timer[TCP_TIM_KEEP] = TCP_TVAL_KEEP_IDLE;

#else	/* of #ifdef TCP_CFG_ALWAYS_KEEP */

		VAR_cep.timer[TCP_TIM_KEEP] = TCP_TVAL_KEEP_IDLE;

#endif	/* of #ifdef TCP_CFG_ALWAYS_KEEP */

		break;

	/*
	 *  2MSL タイマ
	 */
	case TCP_TIM_2MSL:

		if (VAR_cep.fsm_state != TCP_FSM_TIME_WAIT &&
		    VAR_cep.idle  <= TCP_TVAL_KEEP_COUNT * TCP_TVAL_KEEP_INTERVAL)
			VAR_cep.timer[TCP_TIM_2MSL] = TCP_TVAL_KEEP_INTERVAL;
		else
			cep = tecs_tcp_close(p_cellcb);
		break;
	}

	return cep;
}

/*
 *  tecs_send_segment -- TCP 出力処理
 */

static ER
tecs_send_segment (CELLCB *p_cellcb, bool_t *sendalot, uint_t doff, uint_t win, uint_t len, uint8_t flags)
{
	T_NET_BUF	*output;
	T_TCP_HDR	*tcph;
	uint_t		optlen;
	ER			error;
	int32_t 	offset;
	int32_t 	addrlen;

#ifdef TCP_CFG_OPT_MSS

	uint8_t		*optp;

	if (flags & TCP_FLG_SYN)
		optlen = TCP_OPT_LEN_MAXSEG;
	else
		optlen = 0;

#else/* of #ifdef TCP_CFG_OPT_MSS */

	optlen = 0;

#endif/* of #ifdef TCP_CFG_OPT_MSS */

	if (VAR_offset.protocolflag == 0) {

		VAR_offset.protocolflag |= FLAG_USE_TCP;

		if (ATTR_ipLength == 4)
			VAR_offset.protocolflag |= FLAG_USE_IPV4;
		else
			VAR_offset.protocolflag |= FLAG_USE_IPV6;

		cTCPOutput_getOffset(&VAR_offset);
	}

	offset = VAR_offset.ifhdrlen + VAR_offset.iphdrlen;

	//Debug:
	// switch (VAR_cep.fsm_state) {
	//    case TCP_FSM_SYN_RECVD:
	//        syslog(LOG_EMERG,"TCP CEP OUTPUT now. CEP mode is SYN_RECVD");
	//        break;

	//    case TCP_FSM_ESTABLISHED:
	//        syslog(LOG_EMERG,"TCP CEP OUTPUT now. CEP mode is ESTABLISHED");
	//        break;
	// }
	//Debug:

	/*
	 *  セグメント長を、相手の最大受信セグメント長に調整する。
	 *  もし、超えている場合は、超えた分を後で送信する。
	 *  このため、FIN ビットをクリアする。
	 *
	 *  オリジナルでは、t_maxopd を制限長にしているが、
	 *  本実装では、相手の最大受信セグメントにする。
	 */
	if (len + optlen > VAR_cep.maxseg) {
		flags &= ~TCP_FLG_FIN;
		len = VAR_cep.maxseg - optlen;
		*sendalot = true;
	}

	/*
	 *  送信バッファが空になるときは PUSH フラグを設定する。
	 */
	if (len && doff + len >= VAR_cep.swbuf_count)
		flags |= TCP_FLG_PUSH;

	/* データ長を 4 オクテット境界に調整する。*/
	int32_t align = (len + optlen + TCP_HDR_SIZE + 3) >> 2 << 2;
	int32_t size;


#if defined(TCP_CFG_SWBUF_CSAVE_ONLY)

	if (len > 0 && ((VAR_flags & TCP_CEP_FLG_WBCS_MASK) == TCP_CEP_FLG_WBCS_SEND_READY ||
	                (VAR_flags & TCP_CEP_FLG_WBCS_MASK) == TCP_CEP_FLG_WBCS_SENT)) {

		/*
		 *  送信ウインドバッファが開放されないようにして、
		 *  ネットワークバッファを出力に移す。
		 */
		VAR_cep.swbufq->flags |= NB_FLG_NOREL_IFOUT;
		output = VAR_cep.swbufq;
	}
	else {

		/*
		 *  ACK 完了状態で、この関数が呼び出されることもある。
		 *  この時は、len を 0 にして、処理を継続する。
		 */
		len = 0;
		if ((error = cTCPOutput_output_outputp_alloc((void**)&output, align + offset, TMO_TCP_GET_NET_BUF)) != E_OK) {
			if (VAR_cep.timer[TCP_TIM_REXMT] == 0)
				VAR_cep.timer[TCP_TIM_REXMT] = VAR_cep.rxtcur;
			goto err_ret;
		}
	}

#elif defined(TCP_CFG_SWBUF_CSAVE)	/* of #if defined(TCP_CFG_SWBUF_CSAVE_ONLY) */

	if (IS_PTR_DEFINED(VAR_sbuf)) {
		if ((error = cTCPOutput_output_outputp_alloc((void**)&output, align + offset, TMO_TCP_GET_NET_BUF)) != E_OK) {
			if (VAR_cep.timer[TCP_TIM_REXMT] == 0)
				VAR_cep.timer[TCP_TIM_REXMT] = VAR_cep.rxtcur;
			goto err_ret;
		}
	}
	else if (len > 0 && ((VAR_flags & TCP_CEP_FLG_WBCS_MASK) == TCP_CEP_FLG_WBCS_SEND_READY ||
	                     (VAR_flags & TCP_CEP_FLG_WBCS_MASK) == TCP_CEP_FLG_WBCS_SENT)) {

		/*
		 *  送信ウインドバッファが開放されないようにして、
		 *  ネットワークバッファを出力に移す。
		 */
		VAR_cep.swbufq->flags |= NB_FLG_NOREL_IFOUT;
		output = VAR_cep.swbufq;
	}
	else {

		/*
		 *  ACK 完了状態で、この関数が呼び出されることもある。
		 *  この時は、len を 0 にして、処理を継続する。
		 */
		len = 0;
		if ((error = cTCPOutput_output_outputp_alloc((void**)&output, align + offset, TMO_TCP_GET_NET_BUF)) != E_OK) {
			if (VAR_cep.timer[TCP_TIM_REXMT] == 0)
				VAR_cep.timer[TCP_TIM_REXMT] = VAR_cep.rxtcur;
			goto err_ret;
		}
	}

#else	/* of #if defined(TCP_CFG_SWBUF_CSAVE_ONLY) */

	if ((error = cTCPOutput_output_outputp_alloc((void**)&output, align + offset, TMO_TCP_GET_NET_BUF)) != E_OK) {
		if (VAR_cep.timer[TCP_TIM_REXMT] == 0)
			VAR_cep.timer[TCP_TIM_REXMT] = VAR_cep.rxtcur;
		goto err_ret;
	}

#endif	/* of #if defined(TCP_CFG_SWBUF_CSAVE_ONLY) */

	output->off 			= VAR_offset;
	output->off.tphdrlenall = TCP_HDR_SIZE + optlen;
	output->off.iphdrlenall = VAR_offset.iphdrlen;

	tcph = GET_TCP_HDR(output, offset);

	/* TCP ヘッダに情報を設定する。*/
	tcph->sport	= htons(VAR_myport);
	tcph->dport	= htons(VAR_dstport);
	tcph->doff	= TCP_MAKE_DATA_OFF(TCP_HDR_SIZE + optlen);
	tcph->sum	= tcph->flags = 0;

	/* ネットワークバッファ長を調整する。*/
    output->len = (uint16_t)(offset + TCP_HDR_SIZE + optlen + len - output->off.ifalign);   /* output->len の長さが足りないので怪しい */
    size = output->len + sizeof(T_NET_BUF) - 4;

	/*
	 *  TCP オプションの設定を行う。
	 *  本実装では、最大セグメントサイズのみ設定する。
	 */
	if (flags & TCP_FLG_SYN) {
		VAR_cep.snd_nxt = VAR_cep.iss;

#ifdef TCP_CFG_OPT_MSS

		optp = GET_TCP_OPT(output, offset);
		*optp ++ = TCP_OPT_MAXSEG;
		*optp ++ = TCP_OPT_LEN_MAXSEG;
		*(uint16_t*)optp = htons(DEF_TCP_RCV_SEG);

#endif/* of #ifdef TCP_CFG_OPT_MSS */

	}

	/* TCP SDU に送信データをコピーする。*/

	if (len > 0) {
		if (SEQ_LT(VAR_cep.snd_nxt, VAR_cep.snd_max)) {
			NET_COUNT_TCP(net_count_tcp[NC_TCP_SEND_REXMIT_SEGS], 1);
			NET_COUNT_MIB(tcp_stats.tcpRetransSegs, 1);
		}
		//TCP_READ_SWBUF(cep, output, len, doff);
		cCopySave_tcpReadSwbuf(&VAR_cep, output, size, doff, VAR_sbuf, VAR_sbufSize, offset, len);
	}
	else {
		if (VAR_flags & TCP_CEP_FLG_ACK_NOW)
			NET_COUNT_TCP(net_count_tcp[NC_TCP_SEND_ACKS], 1);
		if (flags & (TCP_FLG_FIN | TCP_FLG_SYN | TCP_FLG_RST))
			NET_COUNT_TCP(net_count_tcp[NC_TCP_SEND_CNTL_SEGS],  1);


#ifdef TCP_CFG_EXTENTIONS

		if (SEQ_LT(VAR_cep.snd_up, VAR_cep.snd_una))
			NET_COUNT_TCP(net_count_tcp[NC_TCP_SEND_URG_SEGS], 1);

#endif	/* of #ifdef TCP_CFG_EXTENTIONS */

	}

	/*
	 * snd_max: 送信した最大 SEQ
	 * snd_nxt: 次に送信する SEQ
	 *
	 *  相手から FIN を受信し、まだ FIN を送信していないか、
	 *  送るデータがないときは、FIN を相手に届けるため、
	 *  セグメントを送信するが、SEQ は進めない。
	 */
	if ((flags & TCP_FLG_FIN) && (VAR_flags & TCP_CEP_FLG_SENT_FIN) &&
	    VAR_cep.snd_nxt == VAR_cep.snd_max) {
		VAR_cep.snd_nxt --;
	}

	/*
	 *  SEQ、ACK、フラグの設定。
	 */
	if (len > 0 || (flags & (TCP_FLG_SYN | TCP_FLG_FIN)) || VAR_cep.timer[TCP_TIM_PERSIST] != 0)
		tcph->seq = htonl(VAR_cep.snd_nxt);
	else
		tcph->seq = htonl(VAR_cep.snd_max);

	/*
	 *  rcv_nxt: 受信を期待している最小の SEQ
	 */
	tcph->ack   = htonl(VAR_cep.rcv_nxt);
	tcph->flags = flags;

	/*
	 *  受信ウィンドの計算
	 *
	 *  rbufsz: 受信用バッファサイズ
	 *  maxseg: 相手の最大受信セグメントサイズ
	 */
	if (win < (VAR_rbufSize / 4) && win < VAR_cep.maxseg)
		win = 0;

	/*
	 *  rcv_nxt: 受信を期待している最小の SEQ
	 *  rcv_adv: 受信を期待している最大の SEQ
	 */
	if ((int32_t)win < (int32_t)(VAR_cep.rcv_adv - VAR_cep.rcv_nxt))
		win = (uint_t)(VAR_cep.rcv_adv - VAR_cep.rcv_nxt);

	tcph->win = htons(win);

#ifdef TCP_CFG_EXTENTIONS

	/*
	 *  緊急ポインタの設定
	 */
	if (SEQ_GT(VAR_cep.snd_up, VAR_cep.snd_nxt)) {
		if (TCP_CFG_URG_OFFSET)
			tcph->urp    = htons((uint16_t)(VAR_cep.snd_up - VAR_cep.snd_nxt));
		else
			tcph->urp    = htons((uint16_t)(VAR_cep.snd_up - VAR_cep.snd_nxt - 1));
		tcph->flags |= TCP_FLG_URG;
	}
	else
		VAR_cep.snd_up  = VAR_cep.snd_una;

#endif	/* of #ifdef TCP_CFG_EXTENTIONS */

	/*
	 *  チェックサムを設定する。
	 */
	tcph->sum = 0;
	//?? tcph->sum = IN_CKSUM(output, IPPROTO_TCP, hdr_offset, GET_TCP_HDR_SIZE(output, hdr_offset) + len);

	/*
	 *  タイマの調整
	 */
	if ((VAR_flags & TCP_CEP_FLG_FORCE) == 0 || VAR_cep.timer[TCP_TIM_PERSIST] == 0) {
		T_TCP_SEQ startseq = VAR_cep.snd_nxt;

		/*
		 *  次に送信する SEQ (snd_nxt) を今回送信するデータ数分進める。
		 */
		if (flags & TCP_FLG_SYN)
			VAR_cep.snd_nxt ++;
		if (flags & TCP_FLG_FIN) {
			VAR_flags |= TCP_CEP_FLG_SENT_FIN;
			VAR_cep.snd_nxt ++;
		}

		VAR_cep.snd_nxt += len;

		/*
		 *  次に送信する SEQ (snd_nxt) が
		 *  送信した最大 SEQ (snd_max) より進んでいれば、
		 *  送信した最大 SEQ (snd_max) を更新する。
		 */
		if (SEQ_GT(VAR_cep.snd_nxt, VAR_cep.snd_max)) {
			VAR_cep.snd_max = VAR_cep.snd_nxt;
			/*
			 *  もし、往復時間計測を行っていなければ、
			 *  この送信に時間を合わせる。
			 */
			if (VAR_cep.rtt == 0) {
				VAR_cep.rtt   = 1;
				VAR_cep.rtseq = startseq;	/* 更新前の cep->snd_nxt */
			}
		}

		/*
		 *  もし設定されていないか、ACK または保留が発生していなければ、
		 *  再送タイマを設定する。設定する初期値は、
		 * 「滑らかな往復時間 + 2 × 往復時間変動」である。
		 *  再送時間のバックオフに使われるシフトカウントも初期化する。
		 */
		if (VAR_cep.timer[TCP_TIM_REXMT] == 0 && VAR_cep.snd_nxt != VAR_cep.snd_una) {
			VAR_cep.timer[TCP_TIM_REXMT] = VAR_cep.rxtcur;
			if (VAR_cep.timer[TCP_TIM_PERSIST] != 0) {
				VAR_cep.timer[TCP_TIM_PERSIST] = 0;
				VAR_cep.rxtshift = 0;
			}
		}
	}

	/*
	 *  次に送信する SEQ (snd_nxt) + 今回送信するデータ数 (len) が
	 *  送信した最大 SEQ (snd_max) より進んでいれば、
	 *  送信した最大 SEQ (snd_max) を更新する。
	 */
	else if (SEQ_GT(VAR_cep.snd_nxt + len, VAR_cep.snd_max))
		VAR_cep.snd_max = VAR_cep.snd_nxt + len;

#ifdef TCP_CFG_SWBUF_CSAVE

	if ((VAR_flags & TCP_CEP_FLG_WBCS_MASK) == TCP_CEP_FLG_WBCS_SEND_READY)
		VAR_flags = (VAR_flags & ~TCP_CEP_FLG_WBCS_MASK) | TCP_CEP_FLG_WBCS_SENT;

#endif	/* of #ifdef TCP_CFG_SWBUF_CSAVE */

#ifdef TCP_CFG_TRACE

	//?? tecs_tcp_output_trace(output, cep);

#endif	/* of #ifdef TCP_CFG_TRACE */

	/* ネットワーク層 (IP) の出力関数を呼び出す。*/
	if ((error = cTCPOutput_output(output, size, cGetAddress_getDstAddress(), cGetAddress_getMyAddress(), ATTR_ipLength)) != E_OK)
		goto err_ret;

	/*
	 *  相手に伝えたウィンドウサイズ (win) が 0 以上で、
	 *  受信を期待している最小の SEQ (rcv_nxt) + win が
	 *  受信を期待している最大の SEQ (rcv_adv) より進んでいれば
	 *  受信を期待している最大の SEQ を更新する。
	 */
	if (win > 0 && SEQ_GT(VAR_cep.rcv_nxt + win, VAR_cep.rcv_adv)) {
		VAR_cep.rcv_adv = VAR_cep.rcv_nxt + win;
	}

	/*
	 *  最後に送信した ACK (last_ack_sent) を更新する。
	 */
	VAR_cep.last_ack_sent = VAR_cep.rcv_nxt;

	/*
	 *  フラグの設定を行う。
	 */
	VAR_flags &= ~(TCP_CEP_FLG_ACK_NOW | TCP_CEP_FLG_DEL_ACK);
	if (VAR_flags & TCP_CEP_FLG_FORCE_CLEAR)
		VAR_flags &= ~(TCP_CEP_FLG_FORCE | TCP_CEP_FLG_FORCE_CLEAR);

	return E_OK;

err_ret:
	/*
	 * 以下に関係しないフラグをクリアーする。
	 * ・送受信ウィンドバッファの省コピー機能
	 * ・動的な通信端点の生成・削除機能
	 */
	// VAR_flags &= TCP_CEP_FLG_NOT_CLEAR;
    VAR_flags &= (TCP_CEP_FLG_WBCS_NBUF_REQ | TCP_CEP_FLG_WBCS_MASK |
                  TCP_CEP_FLG_DYNAMIC       | TCP_CEP_FLG_VALID);

	return error;
}

/*
 *  tecs_set_rexmt_timer -- 新しい往復時間を収集し、再送タイマを更新する。
 */

static void
tecs_set_rexmt_timer (CELLCB *p_cellcb, T_TCP_TIME rtt)
{
	T_TCP_TIME delta;

	NET_COUNT_TCP(net_count_tcp[NC_TCP_RTT_UPDATES], 1);
	if (VAR_cep.srtt != 0) {
		/*
		 *  srtt: 平滑化された RTT
		 *
		 *  計測された RTT (rtt) と現在の平滑化された RTT (srtt) の差 (delta) を求める。
		 *
		 *  delta は 2 ビット左シフト ( 4 倍) した値で保持する。
		 *  srtt  は 5 ビット左シフト (32 倍) した値で保持されている。
		 *
		 *    delta = rtt / 8 - srtt / 8
		 *
		 *  新しい srtt は
		 *
		 *    srtt = rtt / 8 + srtt * 7 / 8
		 *         = srtt + (rtt / 8 - srtt / 8)
		 *
		 *  で計算する。
		 *  このため、rtt を 2 ビット左シフトし、srtt を (5 - 2) ビット右シフトして delta を求める。
		 */
		delta = ((rtt - 1) << TCP_DELTA_SHIFT) - (VAR_cep.srtt >> (TCP_SRTT_SHIFT - TCP_DELTA_SHIFT));
		VAR_cep.srtt += delta;
		if (VAR_cep.srtt <= 0)
			VAR_cep.srtt = 1;

		/*
		 *  delta の絶対値 | delta | を求める。
		 */
		if (delta < 0)
			delta = - delta;

		/*
		 *  rttvar: 平滑化された分散
		 *
		 *  rttvar は 4 ビット左シフト (16 倍) した値で保持されている。
		 *
		 *    delta = |delta| / 4 - rttvar / 4
		 *
		 *  新しい rttvar は
		 *
		 *    rttvar = |delta|/ 4 + rttvar * 3 /4
		 *           = rttvar + (|delta| / 4 - rttvar / 4)
		 *
		 *  で計算する。
		 */
		delta -= VAR_cep.rttvar >> (TCP_RTTVAR_SHIFT - TCP_DELTA_SHIFT);
		VAR_cep.rttvar += delta;
		if (VAR_cep.rttvar <= 0)
			VAR_cep.rttvar = 1;
	}
	else {
		/*
		 *  まだ srtt の設定が行われていないときは、今回計測された RTT を使用する。
		 *  平滑化された RTT (srtt) には、RTT を 5 ビット左シフト (32倍) した値。
		 *  平滑化された分散 (rttvar) には、RTT の 1/2 を 4 ビット左シフト (16倍) した値。
		 */
		VAR_cep.srtt   = rtt <<  TCP_SRTT_SHIFT;
		VAR_cep.rttvar = rtt << (TCP_RTTVAR_SHIFT - 1);
	}

	/*
	 *  rtt の測定を終了し、再送回数をリセットする。
	 */
	VAR_cep.rtt = VAR_cep.rxtshift = 0;

	/*
	 *  RTT に許される最小値 と rtt + 2 の大きな値の方を再送タイムアウトの最小値にする。
	 */
	if (rtt + 2 < TCP_TVAL_MIN)
		VAR_cep.rxtcur = cTCPFunctions_tcpRangeSet(
									cTCPFunctions_tcpRexmtValue(VAR_cep.srtt, VAR_cep.rttvar),
		                            (T_TCP_TIME)TCP_TVAL_MIN,
		                            (T_TCP_TIME)TCP_TVAL_MAX_REXMT);
	else
		VAR_cep.rxtcur = cTCPFunctions_tcpRangeSet(
									cTCPFunctions_tcpRexmtValue(VAR_cep.srtt, VAR_cep.rttvar),
		                           	(T_TCP_TIME)(rtt + 2),
		                            (T_TCP_TIME)TCP_TVAL_MAX_REXMT);
}

/*
 *  tecs_reassemble -- 受信セグメントを再構成する。順番通りに受信したときの処理
 */

static uint8_t
tecs_reassemble (CELLCB *p_cellcb, T_NET_BUF *input, uint_t thoff, uint8_t flags)
{
	T_TCP_Q_HDR *qhdr;
	T_TCP_HDR	*tcph;
	int32_t 	offset;

	tcph = GET_TCP_HDR(input, thoff);
	if (tcph->sum > VAR_rbufSize - VAR_cep.rwbuf_count) {
		/*
		 *  受信ウィンドバッファに空きがないときは破棄する。
		 */
		NET_COUNT_TCP(net_count_tcp[NC_TCP_RECV_DROP_SEGS], 1);
		eCEPInput_input_inputp_dealloc(input);
		VAR_flags |= TCP_CEP_FLG_ACK_NOW;
		flags &= ~TCP_FLG_FIN;
	}
	else if (tcph->seq == VAR_cep.rcv_nxt &&
	         VAR_cep.reassq == NULL &&
	         VAR_cep.fsm_state == TCP_FSM_ESTABLISHED) {
		/*
		 *  順番通りにセグメントを受信した時の処理
		 *  受信セグメントの並べ替えは不要なので
		 *  そのまま受信ウィンドバッファに書き込む。
		 */

#ifdef TCP_CFG_DELAY_ACK

		VAR_flags |= TCP_CEP_FLG_DEL_ACK;

#else/* of #ifdef TCP_CFG_DELAY_ACK */

		VAR_flags |= TCP_CEP_FLG_ACK_NOW;

#endif/* of #ifdef TCP_CFG_DELAY_ACK */

		qhdr = GET_TCP_Q_HDR(input, thoff);

		/*  TCP ヘッダの位置を保存する。*/
		// SET_IP_TCP_Q_HDR_OFFSET(input, thoff);
		if (input->off.protocolflag & FLAG_USE_IPV4) {
			/*  TCP ヘッダの位置を保存する。*/
			T_TCP_IP4_Q_HDR *ip4qhdr = (T_TCP_IP4_Q_HDR*)(input->buf + input->off.ifhdrlen);
			ip4qhdr->thoff = thoff;
		}

		/* SDU のオフセット（元はウィンドサイズ）をリセットする。*/
		qhdr->soff = 0;

		/* データを受信ウィンドバッファに書き込む。*/
		// TCP_WRITE_RWBUF(cep, input, thoff);
		cCopySave_tcpWriteRwbuf(&VAR_cep, (int8_t*)input,
					input->len + sizeof(T_NET_BUF) - 4 + input->off.ifalign,
					thoff, VAR_rbuf, VAR_rbufSize);
		eCEPInput_input_inputp_dealloc(input);
	}
	else {
		flags = tecs_tcp_write_raque(p_cellcb, input, thoff, flags);
		VAR_flags |= TCP_CEP_FLG_ACK_NOW;
	}
	return flags;
}

/*
 *  tecs_listening -- 受動オープンして，状態が LISTEN の処理
 *
 *    戻り値:
 *      RET_OK		正常
 *	RET_DROP	エラー、セグメントを破棄する。
 *	RET_RST_DROP	エラー、RST を送信し、セグメントを破棄する。
 */

static ER
tecs_listening (CELLCB *p_cellcb, T_NET_BUF *input, uint_t thoff, T_TCP_SEQ iss)
{
	T_TCP_HDR	*tcph;
	T_TCP_SEQ 	*tcp_iss;

	tcph = GET_TCP_HDR(input, thoff);

	/*
	 *  フラグに RST がセットされていれば破棄する。
	 */
	if (tcph->flags & TCP_FLG_RST)
		return RET_DROP;

	/*
	 *  フラグに ACK がセットさてれいれば、
	 *  リセットを送って破棄する。
	 */
	if (tcph->flags & TCP_FLG_ACK)
		return RET_RST_DROP;

	/*
	 *  フラグに SYN がセットされていなければれば破棄する。
	 */
	if ((tcph->flags & TCP_FLG_SYN) == 0)
		return RET_DROP;

	if (input->off.protocolflag & FLAG_USE_IPV4) {
		/*
		 *  次のときは破棄する。
		 *    ・ポート番号が同一で、送受信 IP アドレス が同一。
		 *    ・マルチキャストアドレス
		 */
		//TODO: T_IP4_HDR *ip4h = GET_IP4_HDR(input, input->off.ifhdrlen);
		T_IP4_HDR *ip4h = GET_IP4_HDR(input);

		if (tcph->dport == tcph->sport && ip4h->dst == ip4h->src)
		  return RET_DROP;

		if (IN4_IS_NET_ADDR_MULTICAST(&ip4h->dst))
		  return RET_DROP;

		T_IN4_ADDR *dst = (T_IN4_ADDR *)cGetAddress_getDstAddress();

		/* 相手のアドレスを記録する。*/
		// IN_COPY_TO_HOST(&cep->dstaddr.ipaddr, input);
		//TODO: IN4_COPY_TO_HOST(dst, &ip4h->src);
		*(dst)=ntohl(*(&ip4h->src));
	}

	/*相手先のポートを記録する*/
	VAR_dstport = tcph->sport;

	/* オプションを処理する。*/
	tecs_parse_option(p_cellcb, tcph, input->off.ipmss);

	/* シーケンス番号を初期化する。*/
	tcp_iss = cTCPFunctions_getTcpIss();
	if (tcp_iss == 0)
		tcp_iss = cTCPFunctions_initTcpIss();

	/* 自分のシーケンス番号の初期値を記録する。*/
	if (iss != 0)
		VAR_cep.iss = iss;
	else
		VAR_cep.iss = tcp_iss;

	// tcp_iss += TCP_ISS_INCR() / 4;
	cTCPFunctions_setTcpIss(tcp_iss + TCP_ISS_INCR() / 4);

	/* 相手のシーケンス番号の初期値を記録する。*/
	VAR_cep.irs = tcph->seq;

	/* 送受信シーケンス番号を初期化する。*/
	// init_send_seq(cep);
	// init_receive_seq(cep);
	VAR_cep.snd_una = VAR_cep.snd_nxt = VAR_cep.snd_max = VAR_cep.iss;
	VAR_cep.rcv_adv = VAR_cep.rcv_nxt = VAR_cep.irs + 1;

	/* 送信ウインドサイズを設定する。*/
	VAR_cep.snd_wnd = tcph->win;

	/* 最終設定 */
	VAR_flags    |= TCP_CEP_FLG_ACK_NOW;
	VAR_cep.fsm_state = TCP_FSM_SYN_RECVD;
	VAR_cep.timer[TCP_TIM_KEEP] = TCP_TVAL_KEEP_INIT;

	return RET_OK;
}

/*
 *  tecs_update_wnd -- ウィンドサイズを更新する。
 *
 *    戻り値: 送信が必要なら true を返す。
 */

static bool_t
tecs_update_wnd (CELLCB *p_cellcb, T_TCP_HDR *tcph)
{
	/*
	 *  更新条件
	 *
	 *    ACK フラグがセットされている &&
	 *    (前回ウィンドを更新した SEQ (snd_wl1) が SEQ より前 ||
	 *     前回ウィンドを更新した SEQ (snd_wl1) が SEQ と同じ &&
	 *     (前回ウィンドを更新した ACK (snd_wl2) が ACK より前 ||
	 *      (前回ウィンドを更新した ACK (snd_wl2) が ACK と同じ &&
	 *       WIN が相手の受信可能ウィンドサイズ (snd_wnd) より大きい
	 *       )
	 *      )
	 *     )
	 */
	if ((tcph->flags & TCP_FLG_ACK) &&
	    (SEQ_LT(VAR_cep.snd_wl1, tcph->seq) ||
	     (VAR_cep.snd_wl1 == tcph->seq &&
	      (SEQ_LT(VAR_cep.snd_wl2, tcph->ack) ||
	       (VAR_cep.snd_wl2 == tcph->ack && tcph->win > VAR_cep.snd_wnd))))) {

		VAR_cep.snd_wnd = tcph->win;
		VAR_cep.snd_wl1 = tcph->seq;
		VAR_cep.snd_wl2 = tcph->ack;

		if (VAR_cep.snd_wnd > VAR_cep.max_sndwnd)
			/* 今までの最大送信ウィンドサイズを更新する。*/
			VAR_cep.max_sndwnd = VAR_cep.snd_wnd;

#ifdef TCP_CFG_SWBUF_CSAVE

		if ((VAR_flags & TCP_CEP_FLG_WBCS_MASK) == TCP_CEP_FLG_WBCS_WOPEN_PEND) {

			/*
			 *  送信ウィンドバッファ用のネットワークバッファ割り当て中で、
			 *  相手の受信ウィンドが空くのを待っているときの処理
			 */
			if (VAR_cep.snd_wnd > 0) {

				/*
				 *  相手の受信ウィンドが空いたときは、
				 *  送信ウィンドバッファ用のネットワークバッファ割り当てを再開する。
				 */
				VAR_flags = (VAR_flags & ~TCP_CEP_FLG_WBCS_MASK)
				                         |  TCP_CEP_FLG_WBCS_FREE |  TCP_CEP_FLG_POST_OUTPUT;
				cSemaphoreTcppost_signal();
			}
		}

#endif	/* of #ifdef TCP_CFG_SWBUF_CSAVE */

		return true;
	}
	else
		return false;
}

/*
 *  tecs_proc_urg -- 緊急データつきのセグメントの処理
 */

static void
tecs_proc_urg (CELLCB *p_cellcb, T_TCP_HDR *tcph)
{
	tcph->urp = 0;
}

/*
 *  tecs_drop_after_ack -- 受信セグメントを破棄した後、ACK を返す (注意: 名前とは合っていない)。
 *
 *    戻り値:
 *      RET_RETURN		正常、リターンする。
 *		RET_RST_DROP	エラー、RST を送信し、セグメントを破棄する。
 */

static ER
tecs_drop_after_ack (CELLCB *p_cellcb, T_NET_BUF *input, uint_t thoff)
{
	T_TCP_HDR *tcph = GET_TCP_HDR(input, thoff);

	/*
	 *    SYN 受信状態で、ACK が送達確認されていない最小送信 SEQ (snd_una) より
	 *    前の値か、送信された最大 SEQ (snd_max) より後の値の場合は、相手に RST を
	 *    送って終了する。これは、"LAND" DoS 攻撃への防御であり、偽造された SYN
	 *    セグメントを送信しつづけるポート間での ACK ストームを防ぐ。
	 */
	if (VAR_cep.fsm_state == TCP_FSM_SYN_RECVD && (tcph->flags & TCP_FLG_ACK) &&
	    (SEQ_GT(VAR_cep.snd_una, tcph->ack) ||
	     SEQ_GT(tcph->ack, VAR_cep.snd_max)))
		return RET_RST_DROP;

	eCEPInput_input_inputp_dealloc(input);

	/* 送信を指示する。*/
	VAR_flags |=  TCP_CEP_FLG_ACK_NOW | TCP_CEP_FLG_POST_OUTPUT;
	cSemaphoreTcppost_signal();
	return RET_RETURN;
}

/*
 *  tecs_close_connection -- コネクション開放処理、相手から FIN を受信した。
 */

static void
tecs_close_connection (CELLCB *p_cellcb, bool_t *needoutput)
{
	if (TCP_FSM_HAVE_RCVD_FIN(VAR_cep.fsm_state) == 0) {

#ifdef TCP_CFG_DELAY_ACK

		if (VAR_flags & TCP_CEP_FLG_NEED_SYN)
			VAR_flags |= TCP_CEP_FLG_DEL_ACK;
		else
			VAR_flags |= TCP_CEP_FLG_ACK_NOW;

#else/* of #ifdef TCP_CFG_DELAY_ACK */

		VAR_flags |= TCP_CEP_FLG_ACK_NOW;

#endif/* of #ifdef TCP_CFG_DELAY_ACK */

		VAR_cep.rcv_nxt ++;
	}

	switch (VAR_cep.fsm_state) {
	case TCP_FSM_SYN_RECVD:		/* SYN を受信し、SYN 送信済み	*/
	case TCP_FSM_ESTABLISHED:	/* コネクション開設完了		*/
		VAR_cep.fsm_state = TCP_FSM_CLOSE_WAIT;
		break;

	case TCP_FSM_FIN_WAIT_1:	/* APP が終了、FIN 送信済み、ACK 待ち */
		VAR_cep.fsm_state = TCP_FSM_CLOSING;
		break;

	case TCP_FSM_FIN_WAIT_2:	/* 相手からの FIN 待ち */
		VAR_cep.fsm_state = TCP_FSM_TIME_WAIT;
		for (int_t ix = NUM_TCP_TIMERS; ix -- > 0; )
			VAR_cep.timer[ix] = 0;
		VAR_cep.timer[TCP_TIM_2MSL] = 2 * TCP_TVAL_MSL;

		/*
		 *  FIN WAIT 2 状態では、
		 *  受信は可能であるが、すでに送信は終了している。
		 *  相手の送信も終了したので、入力タスクのみ起床する。
		 */
		cSendFlag_set(TCP_CEP_EVT_SWBUF_READY);
#if 0
#if defined(NUM_TCP_TW_CEP_ENTRY) && NUM_TCP_TW_CEP_ENTRY > 0

		/* 相手からの FIN に対して応答を返す。*/
		tcp_respond(NULL, cep, cep->rcv_nxt, cep->snd_una,
		            cep->rbufsz - cep->rwbuf_count, TCP_FLG_ACK);
		cep->flags &= ~TCP_CEP_FLG_ACK_NOW;
		*needoutput = false;

		/*
		 *  必要な情報を Time Wait 用 TCP 通信端点に移して、
		 *  標準の TCP 通信端点を開放する。
		 */
		tcp_move_twcep(cep);

#endif	/* of #if defined(NUM_TCP_TW_CEP_ENTRY) && NUM_TCP_TW_CEP_ENTRY > 0 */
#endif 	/* of #if 0 */
		break;

	case TCP_FSM_TIME_WAIT:		/* 相手からの FIN 受信済み、時間待ち */
		VAR_cep.timer[TCP_TIM_2MSL] = 2 * TCP_TVAL_MSL;
		break;
	}
}

/*
 *  tecs_parse_option -- TCP ヘッダのオプションを解析する。
 */

static void
tecs_parse_option (CELLCB *p_cellcb, T_TCP_HDR *tcph, uint16_t mss)
{
	uint8_t	*opt, type = 0;
	uint32_t len, ol, ssize;

	opt = (uint8_t*)tcph + TCP_HDR_SIZE;
	len = (uint_t)(TCP_HDR_LEN(tcph->doff) - TCP_HDR_SIZE);
	while (len > 0 && (type = *opt) != TCP_OPT_EOL) {
		if (type == TCP_OPT_NOP)
			ol = 1u;
		else {
			if (len < 2)
			  break;
			ol = *(opt + 1);
			if (ol < 2 || ol > len)
			  break;
		}
		switch (type) {
		case TCP_OPT_NOP:
			break;
		case TCP_OPT_MAXSEG:
			if ((ol == TCP_OPT_LEN_MAXSEG) && (tcph->flags & TCP_FLG_SYN)) {
				ssize = ntohs(*(uint16_t*)(opt + 2));
				if (ssize > mss)
					VAR_cep.maxseg = mss;
				else if (ssize < TCP_MINMSS)
					VAR_cep.maxseg = TCP_MINMSS;
				else
					VAR_cep.maxseg = ssize;
			}
			syslog(LOG_EMERG, "max seg was changed = %d", VAR_cep.maxseg);
			break;

		case TCP_OPT_WINDOW:
		case TCP_OPT_SACK_PERM:
		case TCP_OPT_TIMESTAMP:
		case TCP_OPT_CC:
		case TCP_OPT_CCNEW:
		case TCP_OPT_CCECHO:
			syslog(LOG_INFO, "[TCP] unsup opt: %d.", type);
			break;

		  default:
			syslog(LOG_NOTICE, "[TCP] unexp opt: %d.", type);
			break;
		}
		opt += ol;
		len -= ol;
	}
}

/*
 *  tecs_syn_sent -- 能動オープンして、状態が SYN 送信済の処理
 *
 *    戻り値:
 *      RET_OK			正常
 *		RET_DROP		エラー、セグメントを破棄する。
 *		RET_RST_DROP	エラー、RST を送信し、セグメントを破棄する。
 */

static ER
tecs_syn_sent (CELLCB *p_cellcb, T_TCP_HDR *tcph, T_TCP_CEP *cep)
{
	ER error = RET_OK;

	/*
	 *  相手から受信確認が送られて来ても、
	 *
	 *    ACK <= iss && 送信した最大 SEQ (snd_max) < ACK
	 *
	 *  なら、リセットを送ってセグメントを破棄する。
	 */
	if ((tcph->flags & TCP_FLG_ACK) &&
	    (SEQ_LE(tcph->ack, VAR_cep.iss) || SEQ_GT(tcph->ack, VAR_cep.snd_max)))
		return RET_RST_DROP;

	/*
	 *  RST/ACK フラグの応答があれば、ポートが開いていない
	 *  ことを意味している。
	 */
	if (tcph->flags & TCP_FLG_RST) {
		if (tcph->flags & TCP_FLG_ACK) {
			VAR_cep.net_error = EV_CNNRF;
			cep = tecs_tcp_drop(p_cellcb, E_CLS);
		}
		return RET_DROP;
	}

	/*
	 *  SYN フラグがなければセグメントを破棄する。
	 */
	if ((tcph->flags & TCP_FLG_SYN) == 0)
		return RET_DROP;

	VAR_cep.snd_wnd = tcph->win;	/* snd_wnd: 相手の受信可能ウィンドサイズ	*/
	VAR_cep.irs     = tcph->seq;	/* irs:     相手のシーケンス番号の初期値	*/
	VAR_cep.rcv_adv = VAR_cep.rcv_nxt = VAR_cep.irs + 1;	/* 送受信シーケンス番号を初期化する。		*/

	if (tcph->flags & TCP_FLG_ACK) {
		/*
		 *  ACK フラグがあるときの処理
		 *
		 *  受信を期待している最大の SEQ (rcv_adv) を
		 *  受信可能なウィンドサイズ (rcv_wnd) 分進める。
		 */
		VAR_cep.rcv_adv += VAR_cep.rcv_wnd;	/* rcv_adv: 受信を期待している最大の SEQ	*/
						/* rcv_wnd: 受信可能なウィンドサイズ		*/

		/* 未確認の最小送信 SEQ (snd_una) を SYN 分 (1 オクテット) 進める。*/
		VAR_cep.snd_una ++;

#ifdef TCP_CFG_DELAY_ACK

		if (tcph->sum != 0)		/* tcph->sum は SDU 長 */
			VAR_flags |= TCP_CEP_FLG_DEL_ACK;
		else
			VAR_flags |= TCP_CEP_FLG_ACK_NOW;

#else/* of #ifdef TCP_CFG_DELAY_ACK */

		VAR_flags |= TCP_CEP_FLG_ACK_NOW;

#endif/* of #ifdef TCP_CFG_DELAY_ACK */

		if (VAR_flags & TCP_CEP_FLG_NEED_FIN) {
			/*
			 *  CEP で FIN 送信が要求されていれば、
			 *  切断処理を開始し、
			 *  CEP の状態を FIN Wait 1 にする。
			 */
			VAR_cep.fsm_state = TCP_FSM_FIN_WAIT_1;
			VAR_flags  &= ~TCP_CEP_FLG_NEED_FIN;
			tcph->flags &= ~TCP_FLG_SYN;
		}
		else {
			/*
			 *  相手から ACK が応答されたので、
			 *  CEP の状態を コネクション開設完了状態にする。
			 */
			VAR_cep.timer[TCP_TIM_KEEP] = TCP_TVAL_KEEP_IDLE;
			VAR_cep.fsm_state  = TCP_FSM_ESTABLISHED;
			NET_COUNT_MIB(tcp_stats.tcpActiveOpens, 1);
			cEstFlag_set(TCP_CEP_EVT_ESTABLISHED);
#if 0
#ifdef TCP_CFG_NON_BLOCKING

			if (cep.snd_nblk_tfn == TFN_TCP_CON_CEP) {

				/* 相手のアドレスをコピーする。*/
				*cep->p_dstaddr = cep->dstaddr;

				if (IS_PTR_DEFINED(cep->callback)) {

#ifdef TCP_CFG_NON_BLOCKING_COMPAT14

					NET_COUNT_TCP(net_count_tcp[NC_TCP_CONNECTS], 1);
					(*cep->callback)(GET_TCP_CEPID(cep), cep->snd_nblk_tfn, E_OK);

#else	/* of #ifdef TCP_CFG_NON_BLOCKING_COMPAT14 */

					ER	error = E_OK;

					NET_COUNT_TCP(net_count_tcp[NC_TCP_CONNECTS], 1);
					(*cep->callback)(GET_TCP_CEPID(cep), cep->snd_nblk_tfn, (void*)&error);

#endif	/* of #ifdef TCP_CFG_NON_BLOCKING_COMPAT14 */

					}
				else {
					syslog(LOG_WARNING, "[TCP] no call back, CEP: %d.", GET_TCP_CEPID(cep));
					error = RET_RST_DROP;
					}
				cep->p_dstaddr = NULL;
				cep->snd_tskid = TA_NULL;
				cep->snd_tfn   = cep->snd_nblk_tfn = TFN_TCP_UNDEF;
				}
			else

#endif	/* of #ifdef TCP_CFG_NON_BLOCKING */
#endif 	/* of #if 0 */
				NET_COUNT_TCP(net_count_tcp[NC_TCP_CONNECTS], 1);
		}
	}
	else {
		/* ACK フラグがないときは、ACK を送って、CEP の状態を SYN 受信済みにする。*/
		VAR_flags |= TCP_CEP_FLG_ACK_NOW;
		VAR_cep.timer[TCP_TIM_REXMT] = 0;
		VAR_cep.fsm_state  = TCP_FSM_SYN_RECVD;
	}

	return error;
}

/*
 *  tecs_trim_length -- 受信した SDU 長を調整する。
 */

static void
tecs_trim_length (CELLCB *p_cellcb, T_TCP_HDR *tcph)
{
	tcph->seq ++;
	if (tcph->sum > VAR_cep.rcv_wnd) {		/* 注意: tcph->sum は SDU 長 */
		/*
		 *  SDU 長が受信ウィンドサイズより大きいときは、受信ウィンドサイズ以降は
		 *  破棄し、FIN に応答しないことで、破棄したデータを再送させる。
		 */
		tcph->sum    = (uint16_t)VAR_cep.rcv_wnd;
		tcph->flags &= ~TCP_FLG_FIN;
	}
	VAR_cep.snd_wl1 = tcph->seq - 1;		/* cep->snd_wl1: ウィンド更新 SEQ 番号	*/

#ifdef TCP_CFG_EXTENTIONS
	VAR_cep.rcv_up  = tcph->seq;		/* cep->rcv_up : 受信した緊急ポインタ	*/
#endif
}

/*
 *  tecs_proc_ack1 -- ACK の処理 (1)
 *
 *    戻り値:
 *      RET_OK			正常
 *      RET_RETURN		正常、リターンする。
 *		RET_DROP		エラー、セグメントを破棄する。
 *		RET_RST_DROP	エラー、RST を送信し、セグメントを破棄する。
 *
 */

static ER
tecs_proc_ack1 (CELLCB *p_cellcb, T_NET_BUF *input, uint_t thoff, bool_t *needoutput)
{
	T_TCP_HDR *tcph = GET_TCP_HDR(input, thoff);

	switch (VAR_cep.fsm_state) {
	case TCP_FSM_SYN_RECVD:		/* SYN を受信し、SYN 送信済み	*/

		/* 状態を変更する。*/
		if (VAR_flags & TCP_CEP_FLG_NEED_FIN) {
			VAR_cep.fsm_state  = TCP_FSM_FIN_WAIT_1;
			VAR_flags &= ~TCP_CEP_FLG_NEED_FIN;
		}
		else {
			VAR_cep.timer[TCP_TIM_KEEP] = TCP_TVAL_KEEP_IDLE;
			VAR_cep.fsm_state  = TCP_FSM_ESTABLISHED;

			/* TCP 通信端点からTCP 受付口を解放する。*/
			//TODO: sREP4_cREP4_unbind();
			// cep->rep = NULL;

#if defined(_IP6_CFG) && defined(_IP4_CFG)
			// cep->rep4 = NULL;
#endif

			cEstFlag_set(TCP_CEP_EVT_ESTABLISHED);
#if 0
#ifdef TCP_CFG_NON_BLOCKING

			if (cep->rcv_nblk_tfn == TFN_TCP_ACP_CEP) {

				/* 相手のアドレスをコピーする。*/

#if defined(_IP6_CFG) && defined(_IP4_CFG)

				if (cep->flags & TCP_CEP_FLG_IPV4) {
					(*cep->p_dstaddr4).ipaddr = ntohl(cep->dstaddr.ipaddr.s6_addr32[3]);
					(*cep->p_dstaddr4).portno = cep->dstaddr.portno;
					}
				else
					*cep->p_dstaddr = cep->dstaddr;

#else	/* of #if defined(_IP6_CFG) && defined(_IP4_CFG) */

				*cep->p_dstaddr = cep->dstaddr;

#endif	/* of #if defined(_IP6_CFG) && defined(_IP4_CFG) */

				if (IS_PTR_DEFINED(cep->callback)) {

#ifdef TCP_CFG_NON_BLOCKING_COMPAT14

					NET_COUNT_MIB(tcp_stats.tcpPassiveOpens, 1);
					NET_COUNT_TCP(net_count_tcp[NC_TCP_ACCEPTS], 1);
					(*cep->callback)(GET_TCP_CEPID(cep), cep->rcv_nblk_tfn, E_OK);

#else	/* of #ifdef TCP_CFG_NON_BLOCKING_COMPAT14 */

					ER	error = E_OK;

					NET_COUNT_MIB(tcp_stats.tcpPassiveOpens, 1);
					NET_COUNT_TCP(net_count_tcp[NC_TCP_ACCEPTS], 1);
					(*cep->callback)(GET_TCP_CEPID(cep), cep->rcv_nblk_tfn, (void*)&error);

#endif	/* of #ifdef TCP_CFG_NON_BLOCKING_COMPAT14 */

					cep->p_dstaddr = NULL;
					cep->rcv_tskid = TA_NULL;
					cep->rcv_tfn   = cep->rcv_nblk_tfn = TFN_TCP_UNDEF;
					}
				else {
					syslog(LOG_WARNING, "[TCP] no call back, CEP: %d.", GET_TCP_CEPID(cep));
					cep->p_dstaddr = NULL;
					cep->rcv_tskid = TA_NULL;
					cep->rcv_tfn   = cep->rcv_nblk_tfn = TFN_TCP_UNDEF;
					return RET_RST_DROP;
					}
				}

			if (cep->snd_nblk_tfn == TFN_TCP_CON_CEP) {

				/* 相手のアドレスをコピーする。*/
				*cep->p_dstaddr = cep->dstaddr;

				if (IS_PTR_DEFINED(cep->callback)) {

#ifdef TCP_CFG_NON_BLOCKING_COMPAT14

					NET_COUNT_MIB(tcp_stats.tcpActiveOpens, 1);
					NET_COUNT_TCP(net_count_tcp[NC_TCP_CONNECTS], 1);
					(*cep->callback)(GET_TCP_CEPID(cep), cep->snd_nblk_tfn, E_OK);

#else	/* of #ifdef TCP_CFG_NON_BLOCKING_COMPAT14 */

					ER	error = E_OK;

					NET_COUNT_MIB(tcp_stats.tcpActiveOpens, 1);
					NET_COUNT_TCP(net_count_tcp[NC_TCP_CONNECTS], 1);
					(*cep->callback)(GET_TCP_CEPID(cep), cep->snd_nblk_tfn, (void*)&error);

#endif	/* of #ifdef TCP_CFG_NON_BLOCKING_COMPAT14 */

					cep->p_dstaddr = NULL;
					cep->snd_tskid = TA_NULL;
					cep->snd_tfn   = cep->snd_nblk_tfn = TFN_TCP_UNDEF;
					}
				else {
					syslog(LOG_WARNING, "[TCP] no call back, CEP: %d.", GET_TCP_CEPID(cep));
					cep->p_dstaddr = NULL;
					cep->snd_tskid = TA_NULL;
					cep->snd_tfn   = cep->snd_nblk_tfn = TFN_TCP_UNDEF;
					return RET_RST_DROP;
					}
				}

#endif	/* of #ifdef TCP_CFG_NON_BLOCKING */
#endif 	/* of #if 0 */
			if (VAR_cep.rcv_tfn == TFN_TCP_ACP_CEP) {
				NET_COUNT_MIB(tcp_stats.tcpPassiveOpens, 1);
				NET_COUNT_TCP(net_count_tcp[NC_TCP_ACCEPTS], 1);
			}

			if (VAR_cep.snd_tfn == TFN_TCP_CON_CEP) {
				NET_COUNT_MIB(tcp_stats.tcpActiveOpens, 1);
				NET_COUNT_TCP(net_count_tcp[NC_TCP_CONNECTS], 1);
			}
		}

		/*
		 *  SDU がなく FIN がついていなければ、tcp_move_ra2rw() を呼出す。
		 */
		if (tcph->sum == 0 && (tcph->flags & TCP_FLG_FIN) == 0)		/* tcph->sum は SDU 長 */
			tcph->flags = tecs_tcp_move_ra2rw(p_cellcb, tcph->flags);

		VAR_cep.snd_wl1 = tcph->seq - 1;	/* snd_wl1: ウィンド更新 SEQ */

		/* break; 下に落ちる。*/

	case TCP_FSM_ESTABLISHED:	/* コネクション開設完了		*/
	case TCP_FSM_FIN_WAIT_1:	/* 終了して、FIN 送信済み		*/
	case TCP_FSM_FIN_WAIT_2:	/* 終了、FIN 伝達確認受信、FIN待ち*/
	case TCP_FSM_CLOSE_WAIT:	/* FIN 受信、クローズ待ち		*/
	case TCP_FSM_CLOSING:		/* 終了、FIN 交換済み、ACK 待ち	*/
	case TCP_FSM_LAST_ACK:		/* FIN 受信、終了、ACK 待ち	*/
	case TCP_FSM_TIME_WAIT:		/* 終了、時間待ち		*/

		if (SEQ_LE(tcph->ack, VAR_cep.snd_una)) {

			/*
			 *  受信確認 ACK が 未確認の最小送信 SEQ (snd_una) と同じか以前のときの処理
			 *  つまり、多重に ACK を受信したことを意味している。
			 */

			if (tcph->sum == 0 && tcph->win == VAR_cep.snd_wnd) {	/* tcph->sum は SDU 長 */

				/*
				 *  SDU がなく、相手のウィンドサイズが変更されていなければ、
				 *  すでに送信したセグメントの中で、ACK (tcph->ack) と
				 *  同じ SEQ から始まるセグメントが、途中で消失した可能性がある。
				 *  この場合は、高速再転送と高速リカバリを行う。
				 */
				NET_COUNT_TCP(net_count_tcp[NC_TCP_RECV_DUP_ACKS], 1);

				if (VAR_cep.timer[TCP_TIM_REXMT] == 0 || tcph->ack != VAR_cep.snd_una) {

					/*
					 *  再送タイマがセットされていないとき、
					 *  または、ACK (tcph->ack) と未確認の最小送信 SEQが
					 *  一致しないときは、多重 ACK 数を 0 にする。
					 */
					VAR_cep.dupacks = 0;
				}

				else if (++ VAR_cep.dupacks == MAX_TCP_REXMT_THRESH) {

					/*
					 *  多重 ACK 数がしきい値 (標準 3) になったら
					 *  高速再転送処理を開始する。
					 */
					uint_t		win;

					/*
					 *  輻輳ウィンドサイズ(snd_cwnd)のしきい値を設定する。
					 *
					 *    相手の受信可能ウィンドサイズ (snd_wnd) か
					 *    輻輳ウィンドサイズ (snd_cwnd) の 1/2。
					 *    ただし、2 * maxseg 以上。
					 *
					 */
					if (VAR_cep.snd_wnd < VAR_cep.snd_cwnd)
						win = VAR_cep.snd_wnd / 2 / VAR_cep.maxseg;
					else
						win = VAR_cep.snd_cwnd / 2 / VAR_cep.maxseg;
					if (win < 2)
						win = 2;
					VAR_cep.snd_ssthresh = win * VAR_cep.maxseg;

					/* 再送タイマと往復時間をリセットする。*/
					VAR_cep.timer[TCP_TIM_REXMT] = 0;
					VAR_cep.rtt = 0;

					/* 消失したセグメントを送信する。*/
					VAR_cep.snd_old_nxt = VAR_cep.snd_nxt;
					VAR_cep.snd_nxt     = tcph->ack;
					VAR_cep.snd_cwnd    = VAR_cep.maxseg;

					/*
					 *  snd_nxt を元に戻すように設定して
					 *  送信を指示する。
					 */
					VAR_flags |=  TCP_CEP_FLG_POST_OUTPUT |
					              TCP_CEP_FLG_FORCE       |
					              TCP_CEP_FLG_FORCE_CLEAR |
					              TCP_CEP_FLG_RESTORE_NEXT_OUTPUT;
					cSemaphoreTcppost_signal();

					/* 輻輳ウィンドサイズを更新する。*/
					VAR_cep.snd_cwnd = (uint16_t)(VAR_cep.snd_ssthresh
					                   + VAR_cep.maxseg * VAR_cep.dupacks);

					return RET_DROP;
				}

				else if (VAR_cep.dupacks > MAX_TCP_REXMT_THRESH) {

					/*
					 *  多重 ACK 数がしきい値 (標準 3) を超えたら
					 *  輻輳ウィンドサイズを増加しながら再送する。
					 */
					VAR_cep.snd_cwnd += VAR_cep.maxseg;

					/* 送信を指示する。*/
					VAR_flags |=  TCP_CEP_FLG_POST_OUTPUT;
					cSemaphoreTcppost_signal();

					return RET_DROP;
				}
			}
			else
				VAR_cep.dupacks = 0;
			break;
		}

		/*
		 *  受信確認 ACK が 未確認の最小送信 SEQ (snd_una) 以降のときの処理
		 */
		if (VAR_cep.dupacks >= MAX_TCP_REXMT_THRESH && VAR_cep.snd_cwnd > VAR_cep.snd_ssthresh)
		 	/*
			 *  高速再転送を行っていたときは、輻輳ウィンドサイズをしきい値まで戻す。
			 */
			VAR_cep.snd_cwnd = (uint16_t)VAR_cep.snd_ssthresh;

		VAR_cep.dupacks = 0;

		if (SEQ_GT(tcph->ack, VAR_cep.snd_max))
			/*
			 *  受信した ACK が送信した最大 SEQ を超えていたときの処理
			 */
			return tecs_drop_after_ack(p_cellcb, input, thoff);

		if (VAR_flags & TCP_CEP_FLG_NEED_SYN) {
			/*
			 *  SYN 送信要求を取り消して、未確認の最小送信 SEQ を進める。
			 */
			VAR_flags &= ~TCP_CEP_FLG_NEED_SYN;
			VAR_cep.snd_una ++;
		}

		return tecs_proc_ack2(p_cellcb, input, thoff, needoutput);
		break;
	}
	return RET_OK;
}

/*
 *  tecs_proc_ack2 -- ACK の処理 (2)
 *
 *    戻り値
 *
 *      RET_OK			正常
 *      RET_RETURN		正常、リターンする。
 *		RET_DROP		エラー、セグメントを破棄する。
 *		RET_RST_DROP	エラー、RST を送信し、セグメントを破棄する。
 */

static ER
tecs_proc_ack2 (CELLCB *p_cellcb, T_NET_BUF *input, uint_t thoff, bool_t *needoutput)
{
	T_TCP_HDR	*tcph;
	ER			ret = RET_OK;
	uint32_t	acked;
	bool_t		ourfinisacked = false;
	int_t 		ix;

	tcph = GET_TCP_HDR(input, thoff);

	/*
	 *  相手に受信確認された ACK から、まだ確認されていない
	 *  最小送信 SEQ (snd_una) を引くと、送信ウィンドバッファから
	 *  削除してよいオクテット数 (acked) になる。
	 */
	acked = tcph->ack - VAR_cep.snd_una;
	NET_COUNT_TCP(net_count_tcp[NC_TCP_RECV_ACKS], 1);

	/*
	 *  往復時間計測 (rtt) が設定されていて、計測開始 SEQ より
	 *  後の ACK を受信したら、タイマバックオフをキャンセルし、
	 *  再送タイマを再設定する。
	 */
	if (VAR_cep.rtt && SEQ_GT(tcph->ack, VAR_cep.rtseq)) {
		tecs_set_rexmt_timer(p_cellcb, VAR_cep.rtt);
	}

	/*
	 *  全ての未確認データが ACK されたら、再送タイマを停止し、
	 *  再開を記憶する (さらに出力か持続)。
	 *  もし、ACK すべき、さらに多くのデータがあるなら、再送タイマに
	 *  現在の再送タイムアウトを設定する。
	 */
	if (tcph->ack == VAR_cep.snd_max) {	/* VAR_cep.snd_max: 送信した最大 SEQ */

#ifdef TCP_CFG_SWBUF_CSAVE

		/*
		 * 送信ウィンドバッファの省コピー機能が有効の場合は、
		 * 送信済みで、ACKが完了するまで再送タイマを変更しない。
		 */
		if ((VAR_flags & TCP_CEP_FLG_WBCS_MASK) == TCP_CEP_FLG_WBCS_ACKED)
			VAR_cep.timer[TCP_TIM_REXMT] = 0;

#else	/* of #ifdef TCP_CFG_SWBUF_CSAVE */

		VAR_cep.timer[TCP_TIM_REXMT] = 0;

#endif	/* of #ifdef TCP_CFG_SWBUF_CSAVE */

		*needoutput = true;
	}
	else if (VAR_cep.timer[TCP_TIM_PERSIST] == 0) {
	 	VAR_cep.timer[TCP_TIM_REXMT] = VAR_cep.rxtcur;	/* VAR_cep.rxtcur: 現在の再送タイムアウト */
	}

	/* 相手が受信確認したデータがあるときの処理 */
	if (acked) {
		uint32_t cw   = VAR_cep.snd_cwnd;	/* VAR_cep.snd_cwnd: 輻輳ウィンドサイズ	*/
		uint32_t incr = VAR_cep.maxseg;		/* VAR_cep.maxseg:   最大セグメントサイズ	*/

		/*
		 *  新たに相手が受信確認したデータがあったときは、
		 *  輻輳ウィンドサイズを大きくする。
		 *  輻輳ウィンドサイズ (snd_cwnd) が
		 *  輻輳ウィンドサイズのしきい値 (snd_ssthresh) より大きいときは
		 *  輻輳回避制御を行い。
		 *
		 *    snd_cwnd = snd_cwnd + maxseg * maxseg / snd_cwnd;
		 *
		 *  等しいか小さいときは、スロースタート制御を行う。
		 *
		 *    snd_cwnd = snd_cwnd + maxseg
		 *
		 */
		if (cw > VAR_cep.snd_ssthresh)
			/* 輻輳回避制御 */
			incr = incr * incr / cw;

		if (cw + incr < MAX_TCP_WIN_SIZE)
			VAR_cep.snd_cwnd = (uint16_t)(cw + incr);
		else
			VAR_cep.snd_cwnd = MAX_TCP_WIN_SIZE;

		/*
		 *  送信ウィンドバッファから、相手が受信確認したデータ数 (acked) のデータを削除する。
		 */
		if (acked > VAR_cep.swbuf_count) {
			VAR_cep.snd_wnd -= VAR_cep.swbuf_count;
			cCopySave_tcpDropSwbuf(&VAR_cep, (uint_t)VAR_cep.swbuf_count,
									VAR_sbuf, VAR_sbufSize, &VAR_flags);
			// TCP_DROP_SWBUF(cep, (uint_t)cep->swbuf_count);
			ourfinisacked = true;
		}
		else {
			VAR_cep.snd_wnd -= (uint16_t)acked;
			cCopySave_tcpDropSwbuf(&VAR_cep, (uint_t)acked,
									VAR_sbuf, VAR_sbufSize, &VAR_flags);
			// TCP_DROP_SWBUF(cep, (uint_t)acked);
			ourfinisacked = false;
		}

		/* 送信ウィンドバッファに空きができたことを知らせる。*/
		cSendFlag_set(TCP_CEP_EVT_SWBUF_READY);

		/*
		 *  送達確認されていない最小送信 SEQ (snd_una) を
		 *  今回送達確認された ACK まで進め、
		 *  次の送信データの SEQ (snd_nxt) も、新しい
		 *  送達確認されていない最小送信 SEQ (snd_una)
		 *  まで進める。
		 */
		VAR_cep.snd_una += acked;
		if (SEQ_LT(VAR_cep.snd_nxt, VAR_cep.snd_una))
			VAR_cep.snd_nxt = VAR_cep.snd_una;

		/*
		 *  状態により分岐
		 */
		switch (VAR_cep.fsm_state) {
		case TCP_FSM_FIN_WAIT_1:	/* APP が終了、FIN 送信済み、ACK 待ち */
			if (ourfinisacked) {
				VAR_cep.fsm_state = TCP_FSM_FIN_WAIT_2;
				VAR_cep.timer[TCP_TIM_2MSL] = TCP_TVAL_KEEP_COUNT * TCP_TVAL_KEEP_INTERVAL;
				}
			break;
		case TCP_FSM_CLOSING:		/* 同時クローズ、FIN 交換済み、ACK 待ち */
			if (ourfinisacked) {
				/*
				 *  送信した FIN が確認されていれば状態を変更し、
				 *  すべてのタイマをリセットした後、2MSL タイマを設定する。
				 */
				VAR_cep.fsm_state = TCP_FSM_TIME_WAIT;
				// tcp_cancel_timers(cep);
				for(ix = NUM_TCP_TIMERS; ix -- > 0; )
					VAR_cep.timer[ix] = 0;
				VAR_cep.timer[TCP_TIM_2MSL] = 2 * TCP_TVAL_MSL;
			}
			break;
		case TCP_FSM_LAST_ACK:		/* APP が終了、ACK 待ち */
			if (ourfinisacked) {
				/*
				 *  送信した FIN が確認されていれば、cep をクローズし、
				 *  セグメントを破棄する。
				 */
				tecs_tcp_close(p_cellcb);
				ret = RET_DROP;
			}
			break;
		case TCP_FSM_TIME_WAIT:		/* 相手からの FIN 受信済み、時間待ち */
			/*
			 *  相手から FIN が再送された。もう一度2MSL タイマを設定し、
			 *  ACK 送信後、セグメントを破棄する。
			 */
			VAR_cep.timer[TCP_TIM_2MSL] = 2 * TCP_TVAL_MSL;
			return tecs_drop_after_ack(p_cellcb, input, thoff);
		}
	}

	return ret;
}
