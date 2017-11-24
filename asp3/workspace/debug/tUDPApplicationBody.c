/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tUDPApplicationBody_template.c => src/tUDPApplicationBody.c
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
 * call port: cUDPAPI4 signature: sUDPCEPAPI4 context:task
 *   ER_UINT        cUDPAPI4_send( const int8_t* data, int32_t len, T_IN4_ADDR dstaddr, uint16_t dstport, TMO tmout );
 *   ER_UINT        cUDPAPI4_receive( int8_t* data, int32_t len, TMO tmout );
 *   ER             cUDPAPI4_cancelSend( ER error );
 *   ER             cUDPAPI4_cancelReceive( ER error );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tUDPApplicationBody_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

#define BUF_SIZE	2048
static char	udp_buf[BUF_SIZE];

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eTaskBody
 * entry port: eTaskBody
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTaskBody_main
 * name:         eTaskBody_main
 * global_name:  tUDPApplicationBody_eTaskBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTaskBody_main()
{
	ID		tskid;
	ER_UINT len;
	ER		error = E_OK;

	getTaskId(&tskid);
	syslog(LOG_EMERG, "[UDP] Application started!! [ID:%d]", tskid);

	T_IN4_ADDR	myaddr  = UDPV4ADDR_000;
	uint16_t 	myport 	= UDPPORT_000;
	T_IN4_ADDR	dstaddr = MAKE_IPV4_ADDR(192,168,1,56);
	uint16_t 	dstport = 50000;

	for (int i = 5; i > 0; i--) {
		syslog(LOG_EMERG, "[%d]", i);
		delay(1000);
	}

#if 1
	while (1) {
		if ((len = cUDPAPI4_receive(udp_buf, sizeof(udp_buf), TMO_FEVR)) >= 0) {
			udp_buf[len] = '\0';
			syslog(LOG_EMERG, "[RECEIVE] <-- %s.%d\n"
			                   "msg: %s", ip2str(NULL, &myaddr), myport, udp_buf);
			if (len > 0) {
				len = cUDPAPI4_send(udp_buf, len, dstaddr, dstport, TMO_FEVR);
				if (len >= 0)
					syslog(LOG_EMERG, "[SEND] --> %s.%d\n"
			                   "msg: %s", ip2str(NULL, &dstaddr), dstport, udp_buf);
				else
					syslog(LOG_EMERG, "[SEND] error: %s", itron_strerror(len));
			}
		}
		else {
			syslog(LOG_EMERG, "[RECEIVE] error: %s", itron_strerror(len));
		}
	}
#else
	while (1) {
		for (int i = 10; i > 0; i--) {
			udp_buf[i] = i;
		}
		len = cUDPAPI4_send(udp_buf, len, dstaddr, dstport, TMO_FEVR);
		if (len >= 0)
			syslog(LOG_EMERG, "[send] len: %d", (uint16_t)len);
		else
			syslog(LOG_EMERG, "[send] error: %s", itron_strerror(len));
	}
#endif

	// return len >= 0 || len == E_TMOUT ? E_OK : len;
	syslog(LOG_EMERG, "[UDP] Application ended!! [ID:%d]", tskid);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
