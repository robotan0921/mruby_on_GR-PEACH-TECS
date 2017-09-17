/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tApplicationBody_template.c => src/tApplicationBody.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
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
 * call port: cTCPAPI4 signature: sTCPCEPAPI4 context:task
 *   ER             cTCPAPI4_accept( Descriptor( sREP4 ) desc, T_IPV4EP* dstep4, TMO tmout );
 *   ER             cTCPAPI4_connect( T_IN4_ADDR myaddr, uint16_t myport, T_IN4_ADDR dstaddr, uint16_t dstport, TMO tmout );
 *   ER_UINT        cTCPAPI4_send( const int8_t* data, int32_t len, TMO tmout );
 *   ER_UINT        cTCPAPI4_receive( int8_t* data, int32_t len, TMO tmout );
 *   ER             cTCPAPI4_cancel( FN fncd );
 *   ER             cTCPAPI4_close( TMO tmout );
 *   ER             cTCPAPI4_shutdown( );
 * call port: cREP4_000 signature: sREP4 context:task
 *   T_IPV4EP       cREP4_000_getEndpoint( );
 *   ER             cREP4_000_signal( );
 *   ER             cREP4_000_wait( );
 *   ER             cREP4_000_waitPolling( );
 *   ER             cREP4_000_waitTimeout( TMO timeout );
 *   ER             cREP4_000_initialize( );
 *   ER             cREP4_000_refer( T_RSEM* pk_semaphoreStatus );
 * call port: cRepSelector signature: sRepSelector context:task
 *   void           cRepSelector_getRep( Descriptor( sREP4 )* desc, int_t i );
 *   void           cRepSelector_getNRep( int_t* n );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tApplicationBody_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

//dynamic-------
// #define cREP4_000_callport (intptr_t)tApplicationBody_SINGLE_CELL_CB.cREP4_000
// #define cREP4_001_callport (intptr_t)tApplicationBody_SINGLE_CELL_CB.cREP4_001
//-------dynamic

#define NUM_SEND_DATA 300
#define COUNT 10000
#define HIST 10000

#define TCP_REPID	1
#define TCP_CEPID	1

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eTaskBody
 * entry port: eTaskBody
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTaskBody_main
 * name:         eTaskBody_main
 * global_name:  tApplicationBody_eTaskBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTaskBody_main()
{
	ID		tskid;
	ER_UINT		rlen, slen;
	ER		error = E_OK;
	uint32_t i;
	int8_t data[NUM_SEND_DATA];
	T_IPV4EP dstep4;
    Descriptor(sREP4) desc;

	getTaskId(&tskid);
	syslog(LOG_EMERG, "Application started!! [ID:%d]", tskid);

	for(i = 0; i < NUM_SEND_DATA; i++)
		data[i] = 10;

	T_IN4_ADDR myaddr  = MYIP4ADDRESS;
	// T_IN4_ADDR dstaddr = MAKE_IPV4_ADDR(192,168,1,56);

    cRepSelector_getRep(&desc, 0);
	error = cTCPAPI4_accept(desc, &dstep4, TMO_FEVR);

	while((rlen = cTCPAPI4_receive(data, 100, TMO_FEVR)) > 0) {
		for(i = 0; i < 30; i++) {
			data[i] ++;		/* 受信データに+1して送信する */
		}
		data[20] = '\0';
		cTCPAPI4_send(data, rlen, TMO_FEVR);
	}

	syslog(LOG_EMERG, "Application ended!! [ID:%d]", tskid);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
