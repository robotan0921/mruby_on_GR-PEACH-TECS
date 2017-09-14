/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tNetworkTimer_template.c => src/tNetworkTimer.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * timeout          int32_t*         VAR_timeout
 *
 * 呼び口関数 #_TCPF_#
 * call port: cSemaphoreNetworkTimer signature: sSemaphore context:task
 *   ER             cSemaphoreNetworkTimer_signal( );
 *   ER             cSemaphoreNetworkTimer_wait( );
 *   ER             cSemaphoreNetworkTimer_waitPolling( );
 *   ER             cSemaphoreNetworkTimer_waitTimeout( TMO timeout );
 *   ER             cSemaphoreNetworkTimer_initialize( );
 *   ER             cSemaphoreNetworkTimer_refer( T_RSEM* pk_semaphoreStatus );
 * call port: ciSemaphoreNetworkTimer signature: siSemaphore context:non-task
 *   ER             ciSemaphoreNetworkTimer_signal( );
 * call port: cSemaphoreCalloutLock signature: sSemaphore context:task
 *   ER             cSemaphoreCalloutLock_signal( );
 *   ER             cSemaphoreCalloutLock_wait( );
 *   ER             cSemaphoreCalloutLock_waitPolling( );
 *   ER             cSemaphoreCalloutLock_waitTimeout( TMO timeout );
 *   ER             cSemaphoreCalloutLock_initialize( );
 *   ER             cSemaphoreCalloutLock_refer( T_RSEM* pk_semaphoreStatus );
 * call port: cCallTimerFunction signature: sCallTimerFunction context:task optional:true
 *   bool_t     is_cCallTimerFunction_joined(int subscript)        check if joined
 *   void           cCallTimerFunction_callFunction( subscript );
 *       subscript:  0...(NCP_cCallTimerFunction-1)
 * call port: cTCPTask signature: sTask context:task optional:true
 *   bool_t     is_cTCPTask_joined()                     check if joined
 *   ER             cTCPTask_activate( );
 *   ER_UINT        cTCPTask_cancelActivate( );
 *   ER             cTCPTask_getTaskState( STAT* p_tskstat );
 *   ER             cTCPTask_changePriority( PRI priority );
 *   ER             cTCPTask_getPriority( PRI* p_priority );
 *   ER             cTCPTask_refer( T_RTSK* pk_taskStatus );
 *   ER             cTCPTask_wakeup( );
 *   ER_UINT        cTCPTask_cancelWakeup( );
 *   ER             cTCPTask_releaseWait( );
 *   ER             cTCPTask_suspend( );
 *   ER             cTCPTask_resume( );
 *   ER             cTCPTask_raiseTerminate( );
 *   ER             cTCPTask_terminate( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tNetworkTimer_tecsgen.h"

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
#include <net/net_buf.h>
#include <net/net_timer.h>

#include <netinet/in.h>
#include <netinet/in_var.h>
#include <netinet/ip.h>
#include <netinet/ip_var.h>

static char const tinet_banner[] =
"\n"
"TINET+TECS\n"
"TINET %d.%d.%d (" __DATE__ ", " __TIME__ ")\n"
"Copyright (C) 2001-2012 by Dep. of Computer Science and Engineering\n"
"                    Tomakomai National College of Technology, JAPAN\n";


/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eNetworkTimer
 * entry port: eNetworkTimer
 * signature:  sNetworkTimer
 * context:    task
 * entry port array size:  NEP_eNetworkTimer
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eNetworkTimer_timeout
 * name:         eNetworkTimer_timeout
 * global_name:  tNetworkTimer_eNetworkTimer_timeout
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eNetworkTimer_timeout(int_t subscript, RELTIM timout)
{
	if(is_cCallTimerFunction_joined(subscript)) {
		VAR_timeout[subscript] = timout;
		return E_OK;
	}

	return E_ID;
}

/* #[<ENTRY_PORT>]# eTaskBody
 * entry port: eTaskBody
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTaskBody_main
 * name:         eTaskBody_main
 * global_name:  tNetworkTimer_eTaskBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTaskBody_main()
{
	ID				tskid;
	int_t			ix;

	get_tid(&tskid);
	syslog(LOG_NOTICE, tinet_banner,
	       (TINET_PRVER   >> 12) & UINT_C(0x0f),
	       (TINET_PRVER   >>  4) & UINT_C(0x0f),
	        TINET_PRVER          & UINT_C(0x0f));
	syslog(LOG_NOTICE, "[NET/TIMER:%d] started.", tskid);
	/* IP を初期化する。*/

#if defined(_IP6_CFG)
	ip6_init();
#endif

#if defined(_IP4_CFG)
	ip_init();
#endif

#ifdef SUPPORT_TCP

	/* TCP 出力タスクを起動する */
	if (is_cTCPTask_joined())
		cTCPTask_activate();

#endif	/* of #ifdef SUPPORT_TCP */

#if defined(SUPPORT_UDP) && defined(UDP_CFG_NON_BLOCKING)

	/* UDP 出力タスクを起動する */
	syscall(act_tsk(UDP_OUTPUT_TASK));
	//TODO: if (is_cUDPTask_joined()) cUDPTask_activate(); (UDP出力はタスク？？)

#endif	/* of #if defined(SUPPORT_UDP) && defined(UDP_CFG_NON_BLOCKING) */

	/* 接続されているが起動していないタイマを起動 */
	for(ix = NCP_cCallTimerFunction; ix -- > 0; ) {
		if(is_cCallTimerFunction_joined(ix) && VAR_timeout == -1)
		   cCallTimerFunction_callFunction(ix);
	}

	while (true) {
		/* タイムアウトしたエントリを呼出す。*/
		cSemaphoreNetworkTimer_wait();
		for (ix = NCP_cCallTimerFunction; ix -- > 0; ) {
			cSemaphoreCalloutLock_wait();
			if (is_cCallTimerFunction_joined(ix) && VAR_timeout[ix] == 0) {
				VAR_timeout[ix] = -1;
				cSemaphoreCalloutLock_signal();
				cCallTimerFunction_callFunction(ix);
			}
			else
				cSemaphoreCalloutLock_signal();
		}
	}
}

/* #[<ENTRY_PORT>]# eiHandlerBody
 * entry port: eiHandlerBody
 * signature:  siHandlerBody
 * context:    non-task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiHandlerBody_main
 * name:         eiHandlerBody_main
 * global_name:  tNetworkTimer_eiHandlerBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eiHandlerBody_main()
{
	/**
	*	ネットワークタイマハンドラ
	*    NET_TIMER_CYCLE (100ms) 毎に呼出される
	*	 (100ms周期で呼び出されるネットワークタイマ関数)
	**/

	int32_t ix;

	for (ix = N_CP_cCallTimerFunction; ix -- > 0; ) {
		if (is_cCallTimerFunction_joined(ix) && VAR_timeout[ix] > 0) {
			VAR_timeout[ix]--;
			if (VAR_timeout[ix] == 0)
			  ciSemaphoreNetworkTimer_signal();
		}
	}
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
