/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tIPv4RoutingTable_template.c => src/tIPv4RoutingTable.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * numStaticEntry   int32_t          ATTR_numStaticEntry
 * numRedirectEntry int32_t          ATTR_numRedirectEntry
 * timeout          int32_t          ATTR_timeout
 * staticRoutingTable const T_IN4_RTENTRY*  ATTR_staticRoutingTable
 * routingTable     T_IN4_RTENTRY*   VAR_routingTable
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
 * call port: cNetworkTimer signature: sNetworkTimer context:task
 *   ER             cNetworkTimer_timeout( RELTIM timout );
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
#include "tIPv4RoutingTable_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

#include <string.h>

#ifdef TARGET_KERNEL_ASP

#include <kernel.h>
#include <sil.h>
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
#include <net/if_loop.h>
#include <net/if_ppp.h>
#include <net/ethernet.h>
//#include <net/ppp_ipcp.h>
#include <net/net.h>
#include <net/net_buf.h>
#include <net/net_timer.h>

#include <netinet/in.h>
#include <netinet/in_var.h>
#include <netinet/ip.h>
#include <netinet/ip_var.h>
#include <netinet/udp_var.h>
#include <netinet/ip_igmp.h>

#include <net/if_var.h>

extern T_IN4_RTENTRY routing4_tbl[];
T_IN4_RTENTRY *tecs_in_rtnewentry (uint8_t flags, uint32_t tmo);

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eRoutingTable
 * entry port: eRoutingTable
 * signature:  sIPv4RoutingTable
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eRoutingTable_routeAlloc
 * name:         eRoutingTable_routeAlloc
 * global_name:  tIPv4RoutingTable_eRoutingTable_routeAlloc
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
T_IN4_ADDR
eRoutingTable_routeAlloc(T_IN4_ADDR dst)
{
	int_t ix;

#ifdef ETHER_CFG_MULTICAST
	if(IN4_IS_ADDR_MULTICAST(dst))
		return dst;
#endif /* of #ifdef ETHER_CFG_MULTICAST */
#if 0
	for (ix = NUM_IN4_ROUTE_ENTRY; ix --; )
		if ((routing4_tbl[ix].flags & IN_RTF_DEFINED) &&
		    (dst & routing4_tbl[ix].mask) == routing4_tbl[ix].target) {
			if (routing4_tbl[ix].gateway == 0)
				return dst;
			else
				return routing4_tbl[ix].gateway;
		}

	return dst;
#endif 	/* of #if 0 */
#if 1 /* TODO */
	for (ix = ATTR_numStaticEntry; ix --; ) {
		if ((ATTR_staticRoutingTable[ix].flags & IN_RTF_DEFINED) &&
		    (dst & ATTR_staticRoutingTable[ix].mask) == ATTR_staticRoutingTable[ix].target) {
			if (ATTR_staticRoutingTable[ix].gateway == 0)
				return dst;
			else {
				return ATTR_staticRoutingTable[ix].gateway;
			}
		}
	}

	for (ix = ATTR_numRedirectEntry; ix --; )
	  	if ((VAR_routingTable[ix].flags & IN_RTF_DEFINED) &&
		  (dst & VAR_routingTable[ix].mask) == VAR_routingTable[ix].target) {
			if (VAR_routingTable[ix].gateway == 0)
				return dst;
			else
				return VAR_routingTable[ix].gateway;
		}
	return dst;
#endif
}

/* #[<ENTRY_FUNC>]# eRoutingTable_redirect
 * name:         eRoutingTable_redirect
 * global_name:  tIPv4RoutingTable_eRoutingTable_redirect
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eRoutingTable_redirect(T_IN4_ADDR gateway, T_IN4_ADDR target, uint8_t flags, uint32_t tmo)
{
	T_IN4_RTENTRY	*frt;

	frt = tecs_in_rtnewentry(flags, tmo);	//TODO: 関数を定義しなおす
	frt->gateway    = gateway;
	frt->target     = target;
	frt->mask       = 0xffffffff;
}

/* #[<ENTRY_PORT>]# eRoutingTableTimer
 * entry port: eRoutingTableTimer
 * signature:  sCallTimerFunction
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eRoutingTableTimer_callFunction
 * name:         eRoutingTableTimer_callFunction
 * global_name:  tIPv4RoutingTable_eRoutingTableTimer_callFunction
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eRoutingTableTimer_callFunction()
{
	SYSTIM	now;
	int_t	ix;

	/* expire の単位は [s]。*/
	getTime(&now);
	now /= SYSTIM_HZ;

	cSemaphore_wait();
	for (ix = NUM_IN4_STATIC_ROUTE_ENTRY; ix < NUM_IN4_ROUTE_ENTRY; ix ++)
	//TODO: ATTR とか VAR とか
		if ((routing4_tbl[ix].flags & IN_RTF_DEFINED) &&
		    (int_t)(routing4_tbl[ix].expire - now) <= 0)
			routing4_tbl[ix].flags = 0;
	cSemaphore_signal();
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/

/*
 *  in_rtnewentry -- 新しいエントリを獲得する。
 */

T_IN4_RTENTRY *
tecs_in_rtnewentry (uint8_t flags, uint32_t tmo)
{
	SYSTIM now;
	T_IN4_RTENTRY	*rt, *frt = NULL;
	int_t ix;

	/* 空きエントリを探す。*/
	for (ix = NUM_IN4_STATIC_ROUTE_ENTRY; ix < NUM_IN4_ROUTE_ENTRY; ix ++) {
	//TODO: ATTR とか VAR とか
		rt = &routing4_tbl[ix];
		if ((routing4_tbl[ix].flags & IN_RTF_DEFINED) == 0) {
			frt = rt;
			break;
		}
	}

	/* expire の単位は [s]。*/
	getTime(&now);
	now /= SYSTIM_HZ;

	if (frt == NULL) {
		/* 空きがなければ、有効時間がもっとも短いエントリを空きにする。*/
		T_IN4_RTENTRY	*srt = NULL;
		int_t		diff, sdiff = INT_MAX;

		cSemaphore_wait();
		for (ix = NUM_IN4_STATIC_ROUTE_ENTRY; ix < NUM_IN4_ROUTE_ENTRY; ix ++) {
			rt = &routing4_tbl[ix];
			diff = (int_t)(rt->expire - now);
			if (diff <= 0) {	/* rt->expire <= now */
				/* 既に、有効時間が過ぎている。*/
				frt = rt;
				break;
			}
			else if (diff < sdiff) {
				srt = rt;
				sdiff = diff;
			}
		}
		if (frt == NULL)
			frt = srt;
		frt->flags = 0;
		cSemaphore_signal();
	}

	frt->flags  = (uint8_t)(flags | IN_RTF_DEFINED);
	frt->expire = now + tmo / SYSTIM_HZ;

	return frt;
}