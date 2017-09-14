/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tIPv4Output_template.c => src/tIPv4Output.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * fragId           uint16_t         VAR_fragId
 *
 * 呼び口関数 #_TCPF_#
 * call port: cEthernetOutput signature: sEthernetOutput context:task optional:true
 *   bool_t     is_cEthernetOutput_joined()                     check if joined
 *   ER             cEthernetOutput_ethernetOutput( int8_t* outputp, int32_t size, T_IN4_ADDR dstaddr, TMO tmout );
 * call port: cFunctions signature: sIPv4Functions context:task
 *   uint16_t       cFunctions_checkSum( const int8_t* data, uint32_t len );
 *   T_IN4_ADDR     cFunctions_getIPv4Address( );
 *   T_IN4_ADDR     cFunctions_getIPv4Mask( );
 * call port: cRoutingTable signature: sIPv4RoutingTable context:task
 *   T_IN4_ADDR     cRoutingTable_routeAlloc( T_IN4_ADDR dst );
 *   void           cRoutingTable_redirect( T_IN4_ADDR gateway, T_IN4_ADDR target, uint8_t flags, uint32_t tmo );
 * call port: cIPv4CheckSum signature: sIPv4CheckSum context:task
 *   uint16_t       cIPv4CheckSum_ipv4CheckSum( int8_t* data, int32_t size, uint32_t offset, uint8_t proto );
 * allocator port for call port:cEthernetOutput func:ethernetOutput param: outputp
 *   ER             cEthernetOutput_ethernetOutput_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cEthernetOutput_ethernetOutput_outputp_dealloc( const void* buf );
 *   ER             cEthernetOutput_ethernetOutput_outputp_reuse( void* buf );
 *   ER_UINT        cEthernetOutput_ethernetOutput_outputp_bufferSize( const void* buf );
 *   uint32_t       cEthernetOutput_ethernetOutput_outputp_bufferMaxSize( );
 * allocator port for call port:eOutput func:IPv4Output param: outputp
 *   ER             eOutput_IPv4Output_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             eOutput_IPv4Output_outputp_dealloc( const void* buf );
 *   ER             eOutput_IPv4Output_outputp_reuse( void* buf );
 *   ER_UINT        eOutput_IPv4Output_outputp_bufferSize( const void* buf );
 *   uint32_t       eOutput_IPv4Output_outputp_bufferMaxSize( );
 * allocator port for call port:eOutput func:IPv4Reply param: outputp
 *   ER             eOutput_IPv4Reply_outputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             eOutput_IPv4Reply_outputp_dealloc( const void* buf );
 *   ER             eOutput_IPv4Reply_outputp_reuse( void* buf );
 *   ER_UINT        eOutput_IPv4Reply_outputp_bufferSize( const void* buf );
 *   uint32_t       eOutput_IPv4Reply_outputp_bufferMaxSize( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tIPv4Output_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

#include <string.h>

#ifdef TARGET_KERNEL_ASP

#include <kernel.h>
#include <sil.h>

#endif	/* of #ifdef TARGET_KERNEL_ASP */

#ifdef TARGET_KERNEL_JSP

#include <s_services.h>
#include <t_services.h>

#endif	/* of #ifdef TARGET_KERNEL_JSP */

#include <tinet_defs.h>
#include <tinet_config.h>

#include <net/if.h>
#include <net/if_loop.h>
#include <net/if_ppp.h>
#include <net/ethernet.h>
#include <net/ppp.h>
#include <net/net.h>
#include <net/net_buf.h>
#include <net/net_count.h>

#include <netinet/in.h>
#include <netinet/in_var.h>
#include <netinet/ip.h>
#include <netinet/ip_var.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>


#if defined(SUPPORT_IPSEC)
#include <netinet6/ipsec.h>
#endif

static uint16_t frag_id = 0;

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eOutput
 * entry port: eOutput
 * signature:  sIPv4Output
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eOutput_IPv4Output
 * name:         eOutput_IPv4Output
 * global_name:  tIPv4Output_eOutput_IPv4Output
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eOutput_IPv4Output(CELLIDX idx, int8_t* outputp, int32_t size, TMO tmout)
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
	T_NET_BUF *output = (T_NET_BUF *)outputp;
	T_IP4_HDR *ip4h;
	T_IN4_ADDR gw;
	int32_t offset, mtu;
	uint8_t proto;

#ifdef SUPPORT_IPSEC
	T_SECPOLICY* sp;
	int ipsec_error;
    int policy;
#endif /* SUPPORT_IPSEC */

	NET_COUNT_MIB(ip_stats.ipOutRequests, 1);

#ifdef SUPPORT_IPSEC
        /* XXX: IPsecの処理はパケット断片化の前に行われる */

	/* SPDを取得する */
	sp = ipsec4_getpolicybyaddr(output, IPSEC_DIR_OUTBOUND, &ipsec_error);
	if (sp==NULL) {
    	ercd = ipsec_error;
        return ercd;
	}

        /* ポリシをチェックする*/
#if 0
        switch (sp->policy) {

        case IPSEC_POLICY_BYPASS:
        case IPSEC_POLICY_NONE:
        case IPSEC_POLICY_TCP:
                goto skip_ipsec;

                break; /* NOTREACHED */

        case  IPSEC_POLICY_IPSEC:
                /* XXX: SH2ではここでillegal Instructionが発生する。コンパイラのバグ? */
                if (sp->req == NULL) {
                        /* 鍵交換デーモンに対してSAの取得を要求する */
                        goto bad;
                }
                break;

        default:
                /* 不正なポリシ */
                goto bad;
                break;
        }
#else /* 0 */
        /* XXX: コンパイラの不具合回避のため switchをやめif文で書き直した */
        policy = sp->spinitb->policy;

        if (policy == IPSEC_POLICY_BYPASS ||
            policy == IPSEC_POLICY_NONE ||
            policy == IPSEC_POLICY_TCP)
                goto skip_ipsec;
        else if (policy == IPSEC_POLICY_IPSEC) {
                if (sp->req == NULL)
                        /* 鍵交換デーモンに対してSAの取得を要求する */
                        goto bad;
        } else
                goto bad;

#endif /* 0 */

		{
			T_IPSEC_OUTPUT_STATE state;

			state.m = output;
			/* XXX: ipsec4_output()内では、ip->{len,off}をネットワークバイトオーダとする */
			ercd = ipsec4_output (&state, sp, 0 /* flags */ );
			output = state.m;

			if (ercd) {
				/* net_buf はipsec4_outputによって既に解放されている */
				switch (ercd) {
				default:
					syslog (LOG_NOTICE, "ip_output:%d error", __LINE__);
				}
			}
		}

        /* ipsec4_outputに影響を受けた値を更新する */
        /* XXX: 必要か? */

skip_ipsec:
#endif /* SUPPORT_IPSEC */

#ifdef IP4_CFG_FRAGMENT

	/*******IPフラグメント処理　mikan*******/
	if (output->off.protocolflag & FLAG_USE_UDP)
		proto = IPPROTO_UDP;
	if (output->off.protocolflag & FLAG_USE_TCP)
		proto = IPPROTO_TCP;
	if (output->off.protocolflag & FLAG_USE_ETHER)
		mtu = ETHER_MTU;

	ip4h = GET_IP4_HDR(output);
	//TODO: ip4h = GET_IP4_HDR(output, output->off.ifhdrlen);

	/* IP ヘッダを設定する ---------------------*/
	ip4h->vhl	= IP4_MAKE_VHL(IPV4_VERSION, IP4_HDR_SIZE >> 2);
	ip4h->len	= htons(output->len - output->off.ifhdrlen + output->off.ifalign);
	ip4h->proto	= proto;
	ip4h->ttl	= IP4_DEFTTL;
	ip4h->type	= 0;
	ip4h->id	= ip4h->flg_off = ip4h->sum = 0;

	// gw = in4_rtalloc(ntohl(ip4h->dst));
	gw = cRoutingTable_routeAlloc(ntohl(ip4h->dst));

	/*
	 *  データグラムサイズがネットワークの MTU を超えていれば、
	 *  分割して送信する。
	 */
	if (ntohs(ip4h->len) > IF_MTU) {
		T_NET_BUF	*frag;
		T_IP4_HDR	*fip4h;
		uint_t		off, hlen, len, flen, align;

		NET_COUNT_IP4(net_count_ip4[NC_IP4_FRAG_OUT], 1);
		NET_COUNT_MIB(ip_stats.ipFragCreates, 1);

		len  = ntohs(ip4h->len);
		off  = hlen = GET_IP4_HDR_SIZE(output);
		while (off < len) {
			if (off + (IF_MTU - IP4_HDR_SIZE) < len)
				flen = IF_MTU - IP4_HDR_SIZE;
			else
				flen = len - off;

			/* データ長は 4 オクテット境界に調整する。	*/
			align = (flen + 3) >> 2 << 2;

			/* ネットワークバッファを獲得する。*/
			if (tget_net_buf(&frag, align + IF_IP4_HDR_SIZE, TMO_IP4_FRAG_GET_NET_BUF) == E_OK) {

				/* フラグメントをコピーする。*/
				memcpy(GET_IP4_SDU(frag), (uint8_t *)ip4h + off, flen);

				/* ヘッダを埋める。*/
				fip4h		= GET_IP4_HDR(frag);
				*fip4h		= *ip4h;
				fip4h->flg_off	= htons(IP4_MAKE_FLGOFF(off + flen == len ? 0 : IP4_MF,
						                       (off - hlen) >> 3));
				fip4h->len	= htons(flen + IP4_HDR_SIZE);
				fip4h->id	= htons(frag_id);
				fip4h->sum	= 0;
				fip4h->sum	= in_cksum(fip4h, GET_IP4_HDR_SIZE(frag));

				NET_COUNT_IP4(net_count_ip4[NC_IP4_OUT_OCTETS], ntohs(fip4h->len));
				NET_COUNT_IP4(net_count_ip4[NC_IP4_OUT_PACKETS], 1);
				NET_COUNT_IP4(net_count_ip4[NC_IP4_FRAG_OUT_FRAGS], 1);

				IF_SET_PROTO(frag, IF_PROTO_IP);
				if ((ercd = IF_OUTPUT(frag, &gw, NULL, tmout)) != E_OK) {
					syscall(rel_net_buf(output));
					NET_COUNT_IP4(net_count_ip4[NC_IP4_OUT_ERR_PACKETS], 1);
					NET_COUNT_MIB(ip_stats.ipFragFails, 1);
					return ercd;
				}
			}
			else {
				/* 獲得できなければ、送信をあきらめる。*/
				syscall(rel_net_buf(output));
				NET_COUNT_IP4(net_count_ip4[NC_IP4_OUT_ERR_PACKETS], 1);
				NET_COUNT_MIB(ip_stats.ipFragFails, 1);
				return E_NOMEM;
			}

			off += IF_MTU - IP4_HDR_SIZE;
		}
		syscall(rel_net_buf(output));
		VAR_fragId ++;
		NET_COUNT_MIB(ip_stats.ipFragOKs, 1);
	}
	else {
		/* ヘッダを埋める。*/
		ip4h->id  = htons(VAR_fragId);
		VAR_fragId ++;
		ip4h->sum = 0;
		ip4h->sum = cFunctions_checkSum((void*)ip4h, (uint_t)GET_IP4_HDR_SIZE(output));

		NET_COUNT_IP4(net_count_ip4[NC_IP4_OUT_OCTETS], ntohs(ip4h->len));
		NET_COUNT_IP4(net_count_ip4[NC_IP4_OUT_PACKETS], 1);

		IF_SET_PROTO(output, IF_PROTO_IP);
		if ((ercd = IF_OUTPUT(output, &gw, NULL, tmout)) != E_OK)
			NET_COUNT_IP4(net_count_ip4[NC_IP4_OUT_ERR_PACKETS], 1);
	}

#else	/* of #ifdef IP4_CFG_FRAGMENT */

	/*******IPフラグメント処理　mikan*******/
	if (output->off.protocolflag & FLAG_USE_UDP)
		proto = IPPROTO_UDP;
	if (output->off.protocolflag & FLAG_USE_TCP)
		proto = IPPROTO_TCP;
	if (output->off.protocolflag & FLAG_USE_ETHER)
		mtu = ETHER_MTU;

	ip4h = GET_IP4_HDR(output);
	//TODO: ip4h = GET_IP4_HDR(output, output->off.ifhdrlen);

	/* IP ヘッダを設定する ---------------------*/
	ip4h->vhl	= IP4_MAKE_VHL(IPV4_VERSION, IP4_HDR_SIZE >> 2);
	ip4h->len	= htons(output->len - output->off.ifhdrlen + output->off.ifalign);
	ip4h->proto	= proto;
	ip4h->ttl	= IP4_DEFTTL;
	ip4h->type	= 0;
	ip4h->id	= ip4h->flg_off = ip4h->sum = 0;

	/* データグラムサイズがネットワークの MTU を超えていればエラー */
	if (ntohs(ip4h->len) > IF_MTU)
		return E_PAR;

	/* ヘッダを埋める。*/
	ip4h->id  = htons(VAR_fragId);
	VAR_fragId ++;
	ip4h->sum = 0;
	ip4h->sum = cFunctions_checkSum((void*)ip4h, (uint_t)GET_IP4_HDR_SIZE(output));

	NET_COUNT_IP4(net_count_ip4[NC_IP4_OUT_OCTETS], ntohs(ip4h->len));
	NET_COUNT_IP4(net_count_ip4[NC_IP4_OUT_PACKETS], 1);

	// gw = in4_rtalloc(ntohl(ip4h->dst));
	gw = cRoutingTable_routeAlloc(ntohl(ip4h->dst));

	if ((is_cEthernetOutput_joined()) && (output->off.protocolflag & FLAG_USE_ETHER)) {
		if ((ercd = cEthernetOutput_ethernetOutput(output, size, gw, tmout)) != E_OK)
			return ercd;
		return ercd;
	}

#endif	/* of #ifdef IP4_CFG_FRAGMENT */

#ifdef SUPPORT_IPSEC
	bad:
#endif /* SUPPORT_IPSEC */

	eOutput_IPv4Output_outputp_dealloc((void*)outputp);
	return E_ID;
}

/* #[<ENTRY_FUNC>]# eOutput_getOffset
 * name:         eOutput_getOffset
 * global_name:  tIPv4Output_eOutput_getOffset
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eOutput_getOffset(CELLIDX idx, T_OFF_BUF* offset)
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
	offset->iphdrlen = IP4_HDR_SIZE;
	offset->ipmss 	 = TCP_MSS;

	if(is_cEthernetOutput_joined()) {			//mikan いまいち未完
		offset->protocolflag |= FLAG_USE_ETHER;
		offset->ifhdrlen 	  = ETHER_HDR_SIZE;
		offset->ifalign 	  = NETBUFFER_ALIGN;
		return E_OK;
	}

	return E_ID;
}

/* #[<ENTRY_FUNC>]# eOutput_getIPv4Address
 * name:         eOutput_getIPv4Address
 * global_name:  tIPv4Output_eOutput_getIPv4Address
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
T_IN4_ADDR
eOutput_getIPv4Address(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	return cFunctions_getIPv4Address();
}

/* #[<ENTRY_FUNC>]# eOutput_setHeader
 * name:         eOutput_setHeader
 * global_name:  tIPv4Output_eOutput_setHeader
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eOutput_setHeader(CELLIDX idx, int8_t* outputp, int32_t size, T_IN4_ADDR dstaddr, T_IN4_ADDR srcaddr)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* エラー処理コードをここに記述します */
	} /* end if VALID_IDX(idx) */

	/* ここに処理本体を記述します #_TEFB_# */
	T_NET_BUF 	*output = (T_NET_BUF*)outputp;
	T_IP4_HDR	*ip4h 	= GET_IP4_HDR(output);
	// T_IP4_HDR	*ip4h 	= GET_IP4_HDR(output, output->off.ifhdrlen);

	/* IP アドレスを設定する。*/
	ip4h->dst	= htonl(dstaddr);

	if (srcaddr == IPV4_ADDRANY)
		ip4h->src = htonl(cFunctions_getIPv4Address());
	else
		ip4h->src = htonl(srcaddr);
}

/* #[<ENTRY_FUNC>]# eOutput_IPv4Reply
 * name:         eOutput_IPv4Reply
 * global_name:  tIPv4Output_eOutput_IPv4Reply
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eOutput_IPv4Reply(CELLIDX idx, int8_t* outputp, int32_t size, TMO tmout)
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
	T_NET_BUF 	*output = (T_NET_BUF*)outputp;
	T_IP4_HDR	*ip4h;
	T_IN4_ADDR	gw;

	//TODO: ip4h = GET_IP4_HDR(output,output->off.ifhdrlen);
	ip4h = GET_IP4_HDR(output);

	/* ヘッダを埋める。*/
	ip4h->id  = htons(VAR_fragId);
	VAR_fragId ++;
	ip4h->sum = 0;
	ip4h->sum = cFunctions_checkSum((void*)ip4h, (uint_t)GET_IP4_HDR_SIZE(output));

	syslog(LOG_EMERG,"IPv4 REPLY dst is %d.%d.%d.%d",
		(0x000000FF&ip4h->dst), (0x0000FF00&ip4h->dst)>>8, (0x00FF0000&ip4h->dst)>>16, (0xFF000000&ip4h->dst)>>24);

	gw = cRoutingTable_routeAlloc(ntohl(ip4h->dst));

	if ((output->off.protocolflag & FLAG_USE_ETHER) && is_cEthernetOutput_joined()) {
		return cEthernetOutput_ethernetOutput(outputp, size, gw, tmout);
	}

	eOutput_IPv4Reply_outputp_dealloc((void*)outputp);

	return(ercd);
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
