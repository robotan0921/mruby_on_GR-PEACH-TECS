/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tUDPCEP_template.c => src/tUDPCEP.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * port             uint16_t         ATTR_port
 * ipLength         int8_t           ATTR_ipLength
 * myport           uint16_t         VAR_myport
 * offset           T_OFF_BUF        VAR_offset
 * flags            uint16_t         VAR_flags
 * sendTaskID       ID               VAR_sendTaskID
 * receiveTaskID    ID               VAR_receiveTaskID
 * cb_netbuf        T_NET_BUF*       VAR_cb_netbuf
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
 * call port: cUDPOutput signature: sUDPOutput context:task
 *   ER             cUDPOutput_UDPOutput( const int8_t* outputp, int32_t size, const int8_t* dstaddr, const int8_t* srcaddr, int32_t addrlen, uint16_t dstport, uint16_t myport, T_OFF_BUF offset, TMO tmout );
 *   ER             cUDPOutput_getOffset( T_OFF_BUF* offset );
 * call port: cGetAddress signature: sGetAddress context:task
 *   int8_t*        cGetAddress_getAddress( );
 * call port: cDataqueue signature: sDataqueue context:task
 *   ER             cDataqueue_send( intptr_t data );
 *   ER             cDataqueue_sendPolling( intptr_t data );
 *   ER             cDataqueue_sendTimeout( intptr_t data, TMO timeout );
 *   ER             cDataqueue_sendForce( intptr_t data );
 *   ER             cDataqueue_receive( intptr_t* p_data );
 *   ER             cDataqueue_receivePolling( intptr_t* p_Data );
 *   ER             cDataqueue_receiveTimeout( intptr_t* p_data, TMO timeout );
 *   ER             cDataqueue_initialize( );
 *   ER             cDataqueue_refer( T_RDTQ* pk_dataqueueStatus );
 * call port: cSemaphore signature: sSemaphore context:task
 *   ER             cSemaphore_signal( );
 *   ER             cSemaphore_wait( );
 *   ER             cSemaphore_waitPolling( );
 *   ER             cSemaphore_waitTimeout( TMO timeout );
 *   ER             cSemaphore_initialize( );
 *   ER             cSemaphore_refer( T_RSEM* pk_semaphoreStatus );
 * call port: cSemaphoreAllCEP signature: sSemaphore context:task
 *   ER             cSemaphoreAllCEP_signal( );
 *   ER             cSemaphoreAllCEP_wait( );
 *   ER             cSemaphoreAllCEP_waitPolling( );
 *   ER             cSemaphoreAllCEP_waitTimeout( TMO timeout );
 *   ER             cSemaphoreAllCEP_initialize( );
 *   ER             cSemaphoreAllCEP_refer( T_RSEM* pk_semaphoreStatus );
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
 * allocator port for call port:eInput func:sendData param: input
 *   ER             eInput_sendData_input_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             eInput_sendData_input_dealloc( const void* buf );
 *   ER             eInput_sendData_input_reuse( void* buf );
 *   ER_UINT        eInput_sendData_input_bufferSize( const void* buf );
 *   uint32_t       eInput_sendData_input_bufferMaxSize( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tUDPCEP_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

#include <string.h>

#ifdef TARGET_KERNEL_ASP

#include <kernel.h>
#include <sil.h>
#include "tinet_cfg.h"

#endif	/* of #ifdef TARGET_KERNEL_ASP */

#ifdef TARGET_KERNEL_JSP

#include <s_services.h>
#include <t_services.h>
#include "tinet_id.h"

#endif	/* of #ifdef TARGET_KERNEL_JSP */

#include <tinet_defs.h>
#include <tinet_config.h>

#include <net/if.h>
#include <net/if_ppp.h>
#include <net/if_loop.h>
#include <net/ethernet.h>
#include <net/net.h>
#include <net/net_buf.h>
#include <net/net_count.h>
#include <net/ppp_ipcp.h>

#include <netinet/in.h>
#include <netinet/in_var.h>
#include <netinet/in_itron.h>
#include <netinet/ip.h>
#include <netinet/ip_var.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <netinet/udp_var.h>
#include <netinet/ip_igmp.h>

static uint16_t udp_port_auto = UDP_PORT_FIRST_AUTO;
static ER udp_alloc_auto_port (CELLCB *p_cellcb);

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eInput
 * entry port: eInput
 * signature:  sUDPCEPInput
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eInput_receiveTaskID
 * name:         eInput_receiveTaskID
 * global_name:  tUDPCEP_eInput_receiveTaskID
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ID
eInput_receiveTaskID(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return VAR_receiveTaskID;

}

/* #[<ENTRY_FUNC>]# eInput_check
 * name:         eInput_check
 * global_name:  tUDPCEP_eInput_check
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eInput_check(CELLIDX idx, const int8_t* dstaddr, int32_t len, uint16_t dstport)
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
	// v4とv6でCEPを共通にする可能性を考慮してIF分

	if (ATTR_ipLength == len) {
		if (dstport == VAR_myport) {
			if (len == 4) {
				if (*((T_IN4_ADDR *)dstaddr) == (*(T_IN4_ADDR *)cGetAddress_getAddress()))
					return E_OK;
				if (*((T_IN4_ADDR *)dstaddr) == IPV4_ADDR_BROADCAST)
					return E_OK;
			}
		}
	}

	return E_ID;
}

/* #[<ENTRY_FUNC>]# eInput_sendData
 * name:         eInput_sendData
 * global_name:  tUDPCEP_eInput_sendData
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eInput_sendData(CELLIDX idx, int8_t* input, int32_t size)
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
	ercd = cDataqueue_sendPolling((intptr_t)input);

	return(ercd);
}

/* #[<ENTRY_PORT>]# eAPI
 * entry port: eAPI
 * signature:  sUDPCEPAPI
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eAPI_send
 * name:         eAPI_send
 * global_name:  tUDPCEP_eAPI_send
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER_UINT
eAPI_send(CELLIDX idx, const int8_t* data, int32_t len, const int8_t* dstaddr, int32_t addrlen, uint16_t dstport, TMO tmout)
{
	ER		error = E_OK;
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		return(E_ID);
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */

	/* p_dstaddr または data が NULL か、tmout が TMO_NBLK ならエラー */
	if (dstaddr == NULL || data == NULL || tmout == TMO_NBLK)
		return E_PAR;

	int ip_hdr_size,if_mtu;
	// 利用する下位プロトコルを決定する offmikan
	VAR_offset.protocolflag = FLAG_USE_UDP;
	if (ATTR_ipLength == 4)
		VAR_offset.protocolflag |= FLAG_USE_IPV4;
	else if (ATTR_ipLength == 6)
		VAR_offset.protocolflag |= FLAG_USE_IPV6;
	else
		return E_ID;

	if ((error = cUDPOutput_getOffset(&VAR_offset)) != E_OK)
		return error;
	if (VAR_offset.protocolflag & FLAG_USE_ETHER)
		if_mtu = ETHER_MTU;

	/* データ長をチェックする。*/
	if (len < 0 || len + VAR_offset.iphdrlen + UDP_HDR_SIZE > if_mtu)
		return E_PAR;

#if (API_PROTO == API_PROTO_IPV6) && !defined(API_CFG_IP4MAPPED_ADDR)

	/*
	 * API が IPv6 で IPv4 射影アドレスが認められていないのにもかかわらず、
	 * IPv4 射影アドレスが指定されたらエラー
	 */
	if (in6_is_addr_ipv4mapped(&p_dstaddr->ipaddr))
		return E_PAR;

#endif	/* of #if (API_PROTO == API_PROTO_IPV6) && !defined(DAPI_CFG_IP4MAPPED_ADDR) */

	/*
	 *  自ポート番号が UDP_PORTANY なら、自動で割り当てる。
	 */
	if (VAR_myport == UDP_PORTANY) {
		if ((error = udp_alloc_auto_port(idx)) != E_OK)
			return error;
	}

	/* 通信端点をロックする。*/
	cSemaphore_wait();

	if (VAR_sendTaskID != TA_NULL) {

		/* 非ノンブロッキングコールでペンディング中 */
		error = E_QOVR;

		/* 通信端点をロックを解除する。*/
		cSemaphore_signal();
	}
	else {
		/* 現在のタスク識別子を記録する。*/
		getTaskId(&VAR_sendTaskID);

#ifdef UDP_CFG_EXTENTIONS

		/* 待ち中に発生したエラー情報をリセットする。*/
		VAR_cep.error = E_OK;

#endif	/* of #ifdef UDP_CFG_EXTENTIONS */

		/* 通信端点をロックを解除する。*/
		cSemaphore_signal();

		/* パケットを送信する。*/
		//Debug: error = UDP_SEND_DATA(cep, p_dstaddr, data, len, tmout);
		error = cUDPOutput_UDPOutput(data, len, dstaddr, cGetAddress_getAddress(),
									addrlen, dstport, VAR_myport, VAR_offset, tmout);
		VAR_sendTaskID = TA_NULL;

#ifdef UDP_CFG_EXTENTIONS

		/* 待ち中に発生したエラー情報を返す。*/
		if (error == E_RLWAI)
			error = VAR_cep.error;

#endif	/* of #ifdef UDP_CFG_EXTENTIONS */
		}

	return error;
}

/* #[<ENTRY_FUNC>]# eAPI_receive
 * name:         eAPI_receive
 * global_name:  tUDPCEP_eAPI_receive
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
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
	T_NET_BUF	*input;
	T_UDP_HDR	*udph;
	ER_UINT		error;
	uint_t		ulen, uhoff;

	/* p_dstaddr または data が NULL 、len < 0 か、tmout が TMO_NBLK ならエラー */
	// TODO:mikan とりあえずノンブロッキングコールには対応しない
	if (data == NULL || len < 0 || tmout == TMO_NBLK)
		return E_PAR;

	/* 通信端点をロックする。*/
	cSemaphore_wait();

	if (VAR_receiveTaskID != TA_NULL) {

		/* 非ノンブロッキングコールでペンディング中 */
		error = E_QOVR;

		/* 通信端点をロックを解除する。*/
		cSemaphore_signal();
	}
	else {

		/* 現在のタスク識別子を記録する。*/
		getTaskId(&VAR_receiveTaskID);

#ifdef UDP_CFG_EXTENTIONS

		/* 待ち中に発生したエラー情報をリセットする。*/
		VAR_cep.error = E_OK;

#endif	/* of #ifdef UDP_CFG_EXTENTIONS */

		/* 通信端点をロックを解除する。*/
		cSemaphore_signal();

		/* 入力があるまで待つ。*/
		if (VAR_cb_netbuf != NULL) {

			/*
			 *  ここにくる場合は、コールバック関数の中から
			 *  udp_rcv_dat を呼び出していることになり、
			 *  すでに入力済みである。
			 */
			input = VAR_cb_netbuf;
			VAR_cb_netbuf = NULL;
		}
		else if ((error = cDataqueue_receiveTimeout((intptr_t*)&input, tmout)) != E_OK) {

#ifdef UDP_CFG_EXTENTIONS

			/* 待ち中に発生したエラー情報を返す。*/
			if (error == E_RLWAI)
				error = VAR_cep.error;

#endif	/* of #ifdef UDP_CFG_EXTENTIONS */

			VAR_receiveTaskID = TA_NULL;
			return error;
		}

		/* p_dstaddr を設定する。*/
		//TODO: udph = GET_UDP_HDR(input,input->off.ifhdrlen+input->off.iphdrlenall);
		uhoff = (uint_t)GET_UDP_HDR_OFFSET(input);
		udph = GET_UDP_HDR(input, uhoff);
		//TODO: mikan 宛先IPとポート番号は未実装
		//TODO: p_dstaddr->portno = ntohs(udph->sport);
		//TODO: IN_COPY_TO_HOST(&p_dstaddr->ipaddr, input);

		/* データをバッファに移す。*/
		ulen = ntohs(udph->ulen);
		if (ulen - UDP_HDR_SIZE > len)
			error = E_BOVR;
		else {
			len   = (uint32_t)(ulen - UDP_HDR_SIZE);
			error = (ER_UINT)(ulen - UDP_HDR_SIZE);
		}

		memcpy(data, GET_UDP_SDU(input, uhoff), (size_t)len);
		//TODO: memcpy(data, (uint8_t *)(udph+UDP_HDR_SIZE), (size_t)len);

		eInput_sendData_input_dealloc((void*)input);

		VAR_receiveTaskID = TA_NULL;
	}

	return error;
}

/* #[<ENTRY_FUNC>]# eAPI_cancelSend
 * name:         eAPI_cancelSend
 * global_name:  tUDPCEP_eAPI_cancelSend
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eAPI_cancelSend(CELLIDX idx, ER error)
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
	if (VAR_sendTaskID != TA_NULL) {	/* 非ノンブロッキングコールでペンディング中 */

#ifdef UDP_CFG_EXTENTIONS

		/* 待ち中に発生したエラー情報を設定する。*/
		VAR_cep.error = error;

#endif	/* of #ifdef UDP_CFG_EXTENTIONS */

		ercd = cCallingSendTask_releaseWait();
		VAR_sendTaskID = TA_NULL;
	}
	else					/* どちらでもないならペンディングしていない */
		ercd = EV_NOPND;

	return(ercd);
}

/* #[<ENTRY_FUNC>]# eAPI_celcelReceive
 * name:         eAPI_celcelReceive
 * global_name:  tUDPCEP_eAPI_celcelReceive
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eAPI_celcelReceive(CELLIDX idx, ER error)
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
	if (VAR_receiveTaskID != TA_NULL) {	/* 非ノンブロッキングコールでペンディング中 */

#ifdef UDP_CFG_EXTENTIONS

		/* 待ち中に発生したエラー情報を設定する。*/
		VAR_cep->error = error;

#endif	/* of #ifdef UDP_CFG_EXTENTIONS */

		ercd = cCallingReceiveTask_releaseWait();
		VAR_receiveTaskID = TA_NULL;
	}
	else					/* どちらでもないならペンディングしていない */
		ercd = EV_NOPND;

	return(ercd);
}

/* #[<ENTRY_PORT>]# eCallback
 * entry port: eCallback
 * signature:  sUDPCallback
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eCallback_callback
 * name:         eCallback_callback
 * global_name:  tUDPCEP_eCallback_callback
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eCallback_callback(CELLIDX idx, FN fncd, ER_UINT error)
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

/*
 *  udp_alloc_auto_port -- 自動割り当てポート番号を設定する。
 */

static ER
udp_alloc_auto_port (CELLCB *p_cellcb)
{
	CELLCB	*p_cb = p_cellcb;
	int_t	ix;
	uint16_t	portno, portno_start;

	portno_start = udp_port_auto;
	do {
		portno = udp_port_auto ++;
		if (udp_port_auto > UDP_PORT_LAST_AUTO)
			udp_port_auto = UDP_PORT_FIRST_AUTO;

		cSemaphoreAllCEP_wait();
		// for (ix = TMAX_UDP_CEPID; ix -- > 0; ) {
FOREACH_CELL(ix, p_cellcb)
			if (VAR_myport == portno) {
				portno = UDP_PORTANY;
				break;
			}
END_FOREACH_CELL
		// }
		p_cellcb = p_cb;

		if (portno != UDP_PORTANY) {
			VAR_myport = portno;
			cSemaphoreAllCEP_signal();
			return E_OK;
		}
		cSemaphoreAllCEP_signal();

	} while (portno_start != udp_port_auto);

	return E_NOID;
}
