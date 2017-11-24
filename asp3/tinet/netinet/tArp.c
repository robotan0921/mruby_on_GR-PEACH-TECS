/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tArp_template.c => src/tArp.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * arpEntry         int32_t          ATTR_arpEntry
 * arp_cache        T_ARP_ENTRY*     VAR_arp_cache
 *
 * 呼び口関数 #_TCPF_#
 * call port: cEthernetRawOutput signature: sEthernetRawOutput context:task
 *   ER             cEthernetRawOutput_ethernetRawOutput( int8_t* outputp, int32_t size, TMO tmout );
 * call port: cNetworkTimer signature: sNetworkTimer context:task
 *   ER             cNetworkTimer_timeout( RELTIM timout );
 * call port: cArpSemaphore signature: sSemaphore context:task
 *   ER             cArpSemaphore_signal( );
 *   ER             cArpSemaphore_wait( );
 *   ER             cArpSemaphore_waitPolling( );
 *   ER             cArpSemaphore_waitTimeout( TMO timeout );
 *   ER             cArpSemaphore_initialize( );
 *   ER             cArpSemaphore_refer( T_RSEM* pk_semaphoreStatus );
 * allocator port for call port:cEthernetRawOutput func:ethernetRawOutput param: outputp
 *   ER             cEthernetRawOutput_ethernetRawOutput_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cEthernetRawOutput_ethernetRawOutput_outputp_dealloc( const void* buf );
 *   ER             cEthernetRawOutput_ethernetRawOutput_outputp_reuse( void* buf );
 *   ER_UINT        cEthernetRawOutput_ethernetRawOutput_outputp_bufferSize( const void* buf );
 *   uint32_t       cEthernetRawOutput_ethernetRawOutput_outputp_bufferMaxSize( );
 * allocator port for call port:eArpInput func:arpInput param: inputp
 *   ER             eArpInput_arpInput_inputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             eArpInput_arpInput_inputp_dealloc( const void* buf );
 *   ER             eArpInput_arpInput_inputp_reuse( void* buf );
 *   ER_UINT        eArpInput_arpInput_inputp_bufferSize( const void* buf );
 *   uint32_t       eArpInput_arpInput_inputp_bufferMaxSize( );
 * allocator port for call port:eArpOutput func:arpResolve param: outputp
 *   ER             eArpOutput_arpResolve_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             eArpOutput_arpResolve_outputp_dealloc( const void* buf );
 *   ER             eArpOutput_arpResolve_outputp_reuse( void* buf );
 *   ER_UINT        eArpOutput_arpResolve_outputp_bufferSize( const void* buf );
 *   uint32_t       eArpOutput_arpResolve_outputp_bufferMaxSize( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tArp_tecsgen.h"

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
#include <net/if_arp.h>
#include <net/net.h>
#include <net/net_buf.h>
#include <net/net_var.h>
#include <net/net_timer.h>
#include <net/net_count.h>

#include <netinet/in.h>
#include <netinet/in_var.h>
#include <netinet/ip.h>
#include <netinet/if_ether.h>

#include <net/if_var.h>

static void tecs_in_arpinput (CELLCB *p_cellcb, const uint8_t *macaddress, T_NET_BUF *input);
static T_ARP_ENTRY *tecs_arp_lookup (CELLCB *p_cellcb, T_IN4_ADDR addr, bool_t create);
static ER tecs_arp_request (CELLCB *p_cellcb,const uint8_t *macaddress, T_IN4_ADDR dst);

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eArpInput
 * entry port: eArpInput
 * signature:  sArpInput
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eArpInput_arpInitialize
 * name:         eArpInput_arpInitialize
 * global_name:  tArp_eArpInput_arpInitialize
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eArpInput_arpInitialize(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	cNetworkTimer_timeout(ARP_TIMER_TMO);
}

/* #[<ENTRY_FUNC>]# eArpInput_arpInput
 * name:         eArpInput_arpInput
 * global_name:  tArp_eArpInput_arpInput
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eArpInput_arpInput(CELLIDX idx, int8_t* inputp, int32_t size, const uint8_t* macaddress)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	T_ARP_HDR *arph;
	T_NET_BUF *input = (T_NET_BUF*)inputp;

	NET_COUNT_ARP(net_count_arp.in_octets , input->len - IF_HDR_SIZE);
	NET_COUNT_ARP(net_count_arp.in_packets, 1);

	/* ARP ヘッダの長さをチェックする。*/
	if (input->len < IF_ARP_HDR_SIZE)
		goto buf_rel;

	arph = GET_ARP_HDR(input);

	/*
	 *  物理アドレスフォーマットが Ehternet 以外
	 *  または、プロトコルが IP 以外はエラー。
	 */
	if (ntohs(arph->hrd_addr) != ARPHRD_ETHER ||
	    ntohs(arph->proto)    != ETHER_TYPE_IP)
		goto buf_rel;

	/* ARP ヘッダ + Ether ARP ヘッダの長さをチェックする。*/
	if (input->len < IF_ARP_ETHER_HDR_SIZE)
		goto buf_rel;

	tecs_in_arpinput(p_cellcb, macaddress, input);
	return;

buf_rel:
	NET_COUNT_ARP(net_count_arp.in_err_packets, 1);
	eArpInput_arpInput_inputp_dealloc((void *)inputp);
}

/* #[<ENTRY_PORT>]# eArpOutput
 * entry port: eArpOutput
 * signature:  sArpOutput
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eArpOutput_arpResolve
 * name:         eArpOutput_arpResolve
 * global_name:  tArp_eArpOutput_arpResolve
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eArpOutput_arpResolve(CELLIDX idx, int8_t* outputp, int32_t size, T_IN4_ADDR dstaddr, const uint8_t* macaddress, TMO tmout)
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
	T_ARP_ENTRY	*ent;
	T_ETHER_HDR	*eth;
	T_NET_BUF 	*output = (T_NET_BUF *)outputp;
	T_IFNET		*ifp = IF_GET_IFNET();

	T_IN4_ADDR 	src  = cFunctions_getIPv4Address();
	T_IN4_ADDR 	mask = cFunctions_getIPv4Mask();

	eth = GET_ETHER_HDR(output);

	/*
	 *  次の場合は、イーサネットのブロードキャストアドレスを返す。
	 *
	 *    ・全ビットが 1
	 *    ・ホスト部の全ビットが 1 で、ネットワーク部がローカルアドレス
	 */
	if (dstaddr == IPV4_ADDR_BROADCAST ||
	    dstaddr == (( src & mask ) | ~mask )) {
		memcpy(eth->dhost, ether_broad_cast_addr, ETHER_ADDR_LEN);
		return cEthernetRawOutput_ethernetRawOutput(output, size, tmout);
	}

	/* 送信先 GW の IP アドレスが ARP キャッシュにあるか調べる。*/
	cArpSemaphore_wait();
	ent = tecs_arp_lookup(p_cellcb, dstaddr, true);
	if (ent->expire) {
		memcpy(eth->dhost, ent->mac_addr, ETHER_ADDR_LEN);
		cArpSemaphore_signal();
		return cEthernetRawOutput_ethernetRawOutput(output, size, tmout);
	}
	else {
	 	/* 送信がペンデングされているフレームがあれば捨てる。*/
		if (ent->hold) {
			NET_COUNT_IP4(net_count_ip4[NC_IP4_OUT_ERR_PACKETS], 1);
			eArpOutput_arpResolve_outputp_dealloc((void*)ent->hold);
		}

		/*
		 *  送信をペンディングする。
		 *  IF でネットワークバッファを開放しないフラグが設定されているときは、
		 *  送信をペンディングしない。
		 */
		if ((output->flags & NB_FLG_NOREL_IFOUT) == 0)
			ent->hold = output;
		else {
			output->flags &= (uint8_t)~NB_FLG_NOREL_IFOUT;
			ent->hold = NULL;
		}

		cArpSemaphore_signal();

		/* アドレス解決要求を送信する。*/
		return tecs_arp_request(p_cellcb, macaddress, dstaddr);
	}
}

/* #[<ENTRY_PORT>]# eArpTimer
 * entry port: eArpTimer
 * signature:  sCallTimerFunction
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eArpTimer_callFunction
 * name:         eArpTimer_callFunction
 * global_name:  tArp_eArpTimer_callFunction
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eArpTimer_callFunction(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	int32_t ix;
	cArpSemaphore_wait();

	for (ix = ATTR_arpEntry;ix-- > 0; ) {
		if (VAR_arp_cache[ix].expire) {
			VAR_arp_cache[ix].expire -= 600;
			if (VAR_arp_cache[ix].expire == 0) {
				if(VAR_arp_cache[ix].hold){
					//MIBをやってmikan
					eArpInput_arpInput_inputp_dealloc((void*)VAR_arp_cache[ix].hold);
				}
				memset(&VAR_arp_cache[ix],0,sizeof(T_ARP_ENTRY));
			}
		}
	}

	cArpSemaphore_signal();
	cNetworkTimer_timeout(600); 	/* 60s間隔で呼び出されるタイマ関数です */
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/

/*
 *  tecs_in_arpinput -- TCP/IP 用 ARP の入力関数
 */

static void
tecs_in_arpinput (CELLCB *p_cellcb, const uint8_t *macaddress, T_NET_BUF *input)
{
	T_NET_BUF	*pending;
	T_ETHER_HDR	*eth;
	T_ARP_HDR	*arph;
	T_ETHER_ARP_HDR	*et_arph;
	T_ARP_ENTRY	*ent;
	T_IFNET		*ifp = IF_GET_IFNET();
	T_IN4_ADDR	saddr, taddr;

	et_arph = GET_ETHER_ARP_HDR(input);

	ntoahl(saddr, et_arph->sproto);		/* 送信元 IP アドレス	*/
	ntoahl(taddr, et_arph->tproto);		/* 解決対象 IP アドレス	*/

	/*
	 *  以下の場合はエラー
	 *    ・送信ホストの物理アドレスが自分
	 *    ・送信ホストの物理アドレスがブロードキャスト
	 */
	if (memcmp(et_arph->shost, macaddress, ETHER_ADDR_LEN) == 0 ||
	    memcmp(et_arph->shost, ether_broad_cast_addr, ETHER_ADDR_LEN) == 0)
		goto err_ret;

	T_IN4_ADDR myaddr = cFunctions_getIPv4Address();

	/*
	 *  送信ホストの IP アドレスが自分の場合は、重複しているので
	 *  相手にも知らせる。
	 *  ただし、自分と相手のアドレスが未定義（IPV4_ADDRANY）の時は何もしない。
	 */
	if ((saddr == myaddr) && (saddr != IPV4_ADDRANY)) {

#ifdef ARP_CFG_CALLBACK_DUPLICATED

		if (arp_callback_duplicated(et_arph->shost)) {
			syslog(LOG_ERROR, "[ARP] IP address duplicated: %s",
			                  ip2str(NULL, &ifp->in4_ifaddr.addr),
			                  mac2str(NULL, et_arph->shost));
			taddr = saddr;
			goto reply;
		}
		else
			goto buf_rel;

#else	/* of #ifdef ARP_CFG_CALLBACK_DUPLICATED */

		syslog(LOG_ERROR, "[ARP] IP address duplicated: %s",
			          ip2str(NULL, &ifp->in4_ifaddr.addr),
			          mac2str(NULL, et_arph->shost));
		taddr = saddr;
		goto reply;

#endif	/* of #ifdef ARP_CFG_CALLBACK_DUPLICATED */

	}

	/*
	 *  以下の場合は何もしない。
	 *    ・解決対象 IP アドレスが自分ではない、注: 元の FreeBSD の
	 *      実装では、ARP PROXY 等のため、自分以外の IP アドレスの
	 *      解決も行っているが、本実装では、自分以外の IP
	 *      アドレスの解決は行わない。
	 */
	if (taddr != myaddr)
		goto buf_rel;

	/*
	 *  送信元 IP アドレスが ARP キャッシュにあるか調べる。
	 *  キャッシュになければ、新たにエントリを登録する。
	 */
	cArpSemaphore_wait();
	// ent = arp_lookup(saddr, true);
	ent = tecs_arp_lookup(p_cellcb, saddr, true);

	memcpy(ent->mac_addr, et_arph->shost, ETHER_ADDR_LEN);
	ent->expire = ARP_CACHE_KEEP;

	/*
	 *  送信がペンデングされているフレームがあれば送信する。
	 */
	if (ent->hold) {

		/* フレームの Ethernet ヘッダを設定する。*/
		memcpy(GET_ETHER_HDR(ent->hold)->dhost, ent->mac_addr, ETHER_ADDR_LEN);

		pending = ent->hold;
		ent->hold = NULL;
		cArpSemaphore_signal();

		/* ペンディングされているフレームを送信する。*/
		//TODO: IF_RAW_OUTPUT(pending, TMO_FEVR);

	}
	else
		cArpSemaphore_signal();

reply:

	arph = GET_ARP_HDR(input);

	/* アドレス解決要求でなければ終了 */
	if (ntohs(arph->opcode) != ARPOP_REQUEST)
		goto buf_rel;

	/* Ethernet ARP ヘッダを設定する。*/
	memcpy(et_arph->thost, et_arph->shost, ETHER_ADDR_LEN);
	memcpy(et_arph->shost, macaddress, ETHER_ADDR_LEN);
	memcpy(et_arph->tproto, (uint8_t*)&et_arph->sproto, sizeof(T_IN_ADDR));
	ahtonl(et_arph->sproto, taddr);

	/* Ethernet ARP ヘッダを設定する。*/
	arph->opcode = htons(ARPOP_REPLY);

	/* Ethernet ヘッダを設定する。*/
	eth = GET_ETHER_HDR(input);
	memcpy(eth->dhost, eth->shost,     ETHER_ADDR_LEN);
	memcpy(eth->shost, macaddress, ETHER_ADDR_LEN);

	/* ARP 応答を送信する。*/
	cEthernetRawOutput_ethernetRawOutput((int8_t*)input, GET_IF_ARP_HDR_SIZE(input), TMO_FEVR);
	// IF_RAW_OUTPUT(input, TMO_FEVR);
	return;

err_ret:
	NET_COUNT_ARP(net_count_arp.in_err_packets, 1);
buf_rel:
	eArpInput_arpInput_inputp_dealloc((void*)input);
}


/*
 *  tecs_arp_lookup -- ARP キャッシュの探索と登録
 *
 *    注意: SEM_ARP_CACHE_LOCK を獲得した状態で呼出すこと
 */

static T_ARP_ENTRY *
tecs_arp_lookup (CELLCB	*p_cellcb, T_IN4_ADDR addr, bool_t create)
{
	int32_t		ix, six;
	uint16_t	min;

	for (ix = ATTR_arpEntry; ix -- > 0; ) {
		if (VAR_arp_cache[ix].expire && VAR_arp_cache[ix].ip_addr == addr)
			return &VAR_arp_cache[ix];
	}

	/* create が真なら、新たなエントリを登録する。*/
	if (create) {

		/* まず、空きがあれば、その空きを利用する。*/
		for (ix = ATTR_arpEntry; ix -- > 0; ) {
			if (VAR_arp_cache[ix].expire == 0) {
				VAR_arp_cache[ix].ip_addr = addr;
				return &VAR_arp_cache[ix];
			}
		}

		/*
		 *  空きがなければ、タイムアウトまで時間が最短の
		 *  エントリーを破棄して利用する。
		 */
		syslog(LOG_EMERG, "[ARP] cache busy, size=%d", ATTR_arpEntry);
		min = 0xffff;
		for (six = ix = ATTR_arpEntry; ix -- > 0; )
			if (VAR_arp_cache[ix].expire < min) {
				six = ix;
				min = VAR_arp_cache[ix].expire;
			}
		VAR_arp_cache[six].expire  = 0;
		VAR_arp_cache[six].ip_addr = addr;
		return &VAR_arp_cache[six];
	}
	else
		return NULL;
}


/*
 *  tecs_arp_request -- MAC アドレス解決要求
 */

static ER
tecs_arp_request (CELLCB *p_cellcb, const uint8_t *macaddress, T_IN4_ADDR dst)
{
	ER		error;
	T_IN4_ADDR	src;
	T_ETHER_HDR	*eth;
	T_ARP_HDR	*arph;
	T_ETHER_ARP_HDR	*et_arph;
	T_NET_BUF	*arp_req;

	NET_COUNT_ARP(net_count_arp.out_octets , IF_ARP_ETHER_HDR_SIZE - IF_HDR_SIZE);
	NET_COUNT_ARP(net_count_arp.out_packets, 1);

	if ((error = cEthernetRawOutput_ethernetRawOutput_outputp_alloc((void **)&arp_req,
				IF_ARP_ETHER_HDR_SIZE, TMO_ARP_GET_NET_BUF)) == E_OK) {

		/* イーサネットヘッダを設定する。*/
		eth     = GET_ETHER_HDR(arp_req);
		memcpy(eth->dhost, ether_broad_cast_addr, ETHER_ADDR_LEN);
		memcpy(eth->shost, macaddress, ETHER_ADDR_LEN);
		eth->type = htons(ETHER_TYPE_ARP);

		/* ARP ヘッダを設定する。*/
		arph    		= GET_ARP_HDR(arp_req);
		arph->hrd_addr  = htons(ARPHRD_ETHER);
		arph->proto     = htons(ETHER_TYPE_IP);
		arph->hdr_len   = sizeof(et_arph->shost);
		arph->proto_len = sizeof(et_arph->sproto);
		arph->opcode    = htons(ARPOP_REQUEST);

		/* イーサネット ARP ヘッダを設定する。*/
		et_arph = GET_ETHER_ARP_HDR(arp_req);
		src 	= cFunctions_getIPv4Address();
		memcpy(et_arph->shost, macaddress, ETHER_ADDR_LEN);
		memset(et_arph->thost, 0, ETHER_ADDR_LEN);
		ahtonl(et_arph->sproto, src);
		ahtonl(et_arph->tproto, dst);
		/* 送信する。*/
		error = cEthernetRawOutput_ethernetRawOutput((int8_t*)arp_req, GET_IF_ARP_HDR_SIZE(input), TMO_ARP_OUTPUT);
	}
	if (error != E_OK)
		NET_COUNT_ARP(net_count_arp.out_err_packets, 1);
	return error;
}