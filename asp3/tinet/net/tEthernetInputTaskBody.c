/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tEthernetInputTaskBody_template.c => src/tEthernetInputTaskBody.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cSemaphoreReceive signature: sSemaphore context:task
 *   ER             cSemaphoreReceive_signal( );
 *   ER             cSemaphoreReceive_wait( );
 *   ER             cSemaphoreReceive_waitPolling( );
 *   ER             cSemaphoreReceive_waitTimeout( TMO timeout );
 *   ER             cSemaphoreReceive_initialize( );
 *   ER             cSemaphoreReceive_refer( T_RSEM* pk_semaphoreStatus );
 * call port: cNicDriver signature: sNicDriver context:task
 *   void           cNicDriver_init( );
 *   void           cNicDriver_start( int8_t* outputp, int32_t size, uint8_t align );
 *   T_NET_BUF*     cNicDriver_read( int8_t** inputp, int32_t* size, uint8_t align );
 *   void           cNicDriver_probe( uint8_t* macaddress );
 *   void           cNicDriver_reset( );
 * call port: cTaskEthernetOutput signature: sTask context:task optional:true
 *   bool_t     is_cTaskEthernetOutput_joined()                     check if joined
 *   ER             cTaskEthernetOutput_activate( );
 *   ER_UINT        cTaskEthernetOutput_cancelActivate( );
 *   ER             cTaskEthernetOutput_getTaskState( STAT* p_tskstat );
 *   ER             cTaskEthernetOutput_changePriority( PRI priority );
 *   ER             cTaskEthernetOutput_getPriority( PRI* p_priority );
 *   ER             cTaskEthernetOutput_refer( T_RTSK* pk_taskStatus );
 *   ER             cTaskEthernetOutput_wakeup( );
 *   ER_UINT        cTaskEthernetOutput_cancelWakeup( );
 *   ER             cTaskEthernetOutput_releaseWait( );
 *   ER             cTaskEthernetOutput_suspend( );
 *   ER             cTaskEthernetOutput_resume( );
 *   ER             cTaskEthernetOutput_raiseTerminate( );
 *   ER             cTaskEthernetOutput_terminate( );
 * call port: cTaskNetworkTimer signature: sTask context:task
 *   ER             cTaskNetworkTimer_activate( );
 *   ER_UINT        cTaskNetworkTimer_cancelActivate( );
 *   ER             cTaskNetworkTimer_getTaskState( STAT* p_tskstat );
 *   ER             cTaskNetworkTimer_changePriority( PRI priority );
 *   ER             cTaskNetworkTimer_getPriority( PRI* p_priority );
 *   ER             cTaskNetworkTimer_refer( T_RTSK* pk_taskStatus );
 *   ER             cTaskNetworkTimer_wakeup( );
 *   ER_UINT        cTaskNetworkTimer_cancelWakeup( );
 *   ER             cTaskNetworkTimer_releaseWait( );
 *   ER             cTaskNetworkTimer_suspend( );
 *   ER             cTaskNetworkTimer_resume( );
 *   ER             cTaskNetworkTimer_raiseTerminate( );
 *   ER             cTaskNetworkTimer_terminate( );
 * call port: cArpInput signature: sArpInput context:task optional:true
 *   bool_t     is_cArpInput_joined()                     check if joined
 *   void           cArpInput_arpInitialize( );
 *   void           cArpInput_arpInput( int8_t* inputp, int32_t size, const uint8_t* macaddress );
 * call port: cIPv4Input signature: sIPv4Input context:task optional:true
 *   bool_t     is_cIPv4Input_joined()                     check if joined
 *   void           cIPv4Input_IPv4Input( int8_t* inputp, int32_t size );
 * allocator port for call port:cNicDriver func:start param: outputp
 *   ER             cNicDriver_start_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cNicDriver_start_outputp_dealloc( const void* buf );
 *   ER             cNicDriver_start_outputp_reuse( void* buf );
 *   ER_UINT        cNicDriver_start_outputp_bufferSize( const void* buf );
 *   uint32_t       cNicDriver_start_outputp_bufferMaxSize( );
 * allocator port for call port:cNicDriver func:read param: inputp
 *   ER             cNicDriver_read_inputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cNicDriver_read_inputp_dealloc( const void* buf );
 *   ER             cNicDriver_read_inputp_reuse( void* buf );
 *   ER_UINT        cNicDriver_read_inputp_bufferSize( const void* buf );
 *   uint32_t       cNicDriver_read_inputp_bufferMaxSize( );
 * allocator port for call port:cArpInput func:arpInput param: inputp
 *   ER             cArpInput_arpInput_inputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cArpInput_arpInput_inputp_dealloc( const void* buf );
 *   ER             cArpInput_arpInput_inputp_reuse( void* buf );
 *   ER_UINT        cArpInput_arpInput_inputp_bufferSize( const void* buf );
 *   uint32_t       cArpInput_arpInput_inputp_bufferMaxSize( );
 * allocator port for call port:cIPv4Input func:IPv4Input param: inputp
 *   ER             cIPv4Input_IPv4Input_inputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cIPv4Input_IPv4Input_inputp_dealloc( const void* buf );
 *   ER             cIPv4Input_IPv4Input_inputp_reuse( void* buf );
 *   ER_UINT        cIPv4Input_IPv4Input_inputp_bufferSize( const void* buf );
 *   uint32_t       cIPv4Input_IPv4Input_inputp_bufferMaxSize( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tEthernetInputTaskBody_tecsgen.h"

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
#include <net/ethernet.h>
#include <net/if_llc.h>
#include <net/if_arp.h>
#include <net/net.h>
#include <net/net_var.h>
#include <net/net_buf.h>
#include <net/net_timer.h>
#include <net/net_count.h>

#include <netinet/in.h>
#include <netinet/in_var.h>
#include <netinet/if_ether.h>

#include <netinet6/if6_ether.h>
#include <netinet6/nd6.h>

#include <net/if_var.h>

extern T_IFNET ether_ifnet;

#ifdef SUPPORT_MIB
extern T_IF_STATS if_stats;
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eTaskBody
 * entry port: eTaskBody
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTaskBody_main
 * name:         eTaskBody_main
 * global_name:  tEthernetInputTaskBody_eTaskBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTaskBody_main(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	T_IF_SOFTC	*ic;
	T_NET_BUF	*input;
	T_ETHER_HDR	*eth;
	ID			tskid;
	uint16_t	proto;
	uint8_t		rcount = 0;
	int32_t 	size;
	uint8_t 	macaddress[6];
	T_OFF_BUF 	etheroff = {0, 0, 0, ETHER_HDR_SIZE, ETHER_MTU, NETBUFFER_ALIGN, FLAG_USE_ETHER, 0, 0};

	/* ネットワークインタフェース管理を初期化する。*/
	ifinit();

	/* イーサネットネットワークインタフェース管理を初期化する。*/

#if defined(_IP4_CFG)

	ether_ifnet.in4_ifaddr.addr = IPV4_ADDR_LOCAL;		/* IPv4 アドレス		*/
	ether_ifnet.in4_ifaddr.mask = IPV4_ADDR_LOCAL_MASK;	/* サブネットマスク		*/

#endif	/* of #if defined(_IP4_CFG) */

	/* NIC を初期化する。*/
	cNicDriver_init();
	cNicDriver_probe(macaddress);

	/* Ethernet 出力タスクを起動する */
	if(is_cTaskEthernetOutput_joined())
		cTaskEthernetOutput_activate();

	/* ネットワークタイマタスクを起動する */
	cTaskNetworkTimer_activate();

	get_tid(&tskid);
	syslog(LOG_NOTICE, "[ETHER INPUT:%2d] started on MAC Addr: %s.",
	                   tskid, mac2str(NULL, macaddress));

#if defined(_IP4_CFG)

	/* ARP を初期化する。*/
	if(is_cArpInput_joined())
		cArpInput_arpInitialize();

#endif	/* of #if defined(_IP4_CFG) */

	/* 乱数生成を初期化する。*/
	net_srand(0);
	//TODO: netSrand(0);

	while (true) {
		cSemaphoreReceive_wait();
		if ((input = cNicDriver_read((int8_t**)&input, (int32_t*)&size, NETBUFFER_ALIGN)) != NULL) {
			NET_COUNT_ETHER(net_count_ether.in_octets,  input->len);
			NET_COUNT_MIB(if_stats.ifInOctets, input->len + 8);
			NET_COUNT_ETHER(net_count_ether.in_packets, 1);
			input->off = etheroff;
			eth = GET_ETHER_HDR(input);
			proto = ntohs(eth->type);

			/* 乱数生成を初期化する。*/
			if (rcount == 0) {

#ifdef ETHER_CFG_COLLECT_ADDR
				memcpy(ether_collect_addr.lladdr, eth->shost,
				sizeof(ether_collect_addr.lladdr));
#endif	/* of #ifdef ETHER_CFG_COLLECT_ADDR */

				net_srand(0);
				//TODO: netSrand(0);
			}
			rcount ++;


#ifdef SUPPORT_MIB
			if ((*eth->dhost & ETHER_MCAST_ADDR) == 0) {
				NET_COUNT_MIB(if_stats.ifInUcastPkts, 1);
			}
			else {
				NET_COUNT_MIB(if_stats.ifInNUcastPkts, 1);
			}
#endif	/* of #ifdef SUPPORT_MIB */

#if defined(_IP4_CFG) && defined(ETHER_CFG_ACCEPT_ALL)

			if ((*eth->dhost & ETHER_MCAST_ADDR) && *eth->dhost != 0xff) {

#ifdef ETHER_CFG_MCAST_WARNING

				if (proto <= 1500)
					proto = ntohs(*(uint16_t*)&(GET_8022SNAP_HDR(input)->type));
				syslog(LOG_WARNING, "[ETHER] mcast addr  from: %s, to: %s, proto: 0x%04x.",
				                    mac2str(NULL, eth->shost), mac2str(NULL, eth->dhost), proto);

#endif	/* of #ifdef ETHER_CFG_MCAST_WARNING */

				NET_COUNT_ETHER(net_count_ether.in_err_packets, 1);
				NET_COUNT_MIB(if_stats.ifInErrors, 1);
				cNicDriver_read_inputp_dealloc((void *)input);
				continue;
			}

#endif	/* of #if defined(_IP4_CFG) && defined(ETHER_CFG_ACCEPT_ALL) */

			switch(proto) {

#if defined(_IP4_CFG)

			case ETHER_TYPE_IP:		/* IP	*/
				if (is_cIPv4Input_joined()) {
					cIPv4Input_IPv4Input((int8_t*)input, size);
					break;
				}

			case ETHER_TYPE_ARP:		/* ARP	*/
				if (is_cArpInput_joined()) {
					cArpInput_arpInput((int8_t*)input, size, macaddress);
					break;
				}

#endif	/* of #if defined(_IP4_CFG) */

#if defined(_IP6_CFG)

			case ETHER_TYPE_IPV6:		/* IPv6	*/
				ip6_input(input);
				break;

#endif	/* of #if defined(_IP6_CFG) */

			default:

#ifdef ETHER_CFG_UNEXP_WARNING

#ifdef ETHER_CFG_802_WARNING

				if (proto <= 1500)
					ieee_802_input(input);
				else
					syslog(LOG_NOTICE, "[ETHER] unexp proto from: %s, proto: 0x%04x.",
					                   mac2str(NULL, GET_ETHER_HDR(input)->shost), proto);

#else	/* of #ifdef ETHER_CFG_802_WARNING */

				syslog(LOG_INFO, "[ETHER] unexp proto from: %s, proto: 0x%04x.",
				                   mac2str(NULL, GET_ETHER_HDR(input)->shost), proto);

#endif	/* of #ifdef ETHER_CFG_802_WARNING */

#endif	/* of #ifdef ETHER_CFG_UNEXP_WARNING */

				NET_COUNT_ETHER(net_count_ether.in_err_packets, 1);
				NET_COUNT_MIB(if_stats.ifUnknownProtos, 1);
				cNicDriver_read_inputp_dealloc((void *)input);
				break;
			}
		}
	}
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
