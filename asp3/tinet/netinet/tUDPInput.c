/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tUDPInput_template.c => src/tUDPInput.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cCEPInput signature: sUDPCEPInput context:task
 *   ID             cCEPInput_receiveTaskID( subscript );
 *   ER             cCEPInput_check( subscript, const int8_t* dstaddr, int32_t len, uint16_t dstport );
 *   ER             cCEPInput_sendData( subscript, int8_t* input, int32_t size );
 *       subscript:  0...(NCP_cCEPInput-1)
 * call port: cCallback signature: sUDPCallback context:task optional:true
 *   bool_t     is_cCallback_joined(int subscript)        check if joined
 *   void           cCallback_callback( subscript, FN fncd, ER_UINT error );
 *       subscript:  0...(NCP_cCallback-1)
 * call port: cICMP4Error signature: sICMP4Error context:task optional:true
 *   bool_t     is_cICMP4Error_joined()                     check if joined
 *   void           cICMP4Error_error( int8_t* inputp, int32_t size, uint8_t code );
 * call port: cIPv4CheckSum signature: sIPv4CheckSum context:task optional:true
 *   bool_t     is_cIPv4CheckSum_joined()                     check if joined
 *   uint16_t       cIPv4CheckSum_ipv4CheckSum( int8_t* data, int32_t size, uint32_t offset, uint8_t proto );
 * allocator port for call port:cCEPInput func:sendData param: input
 *   ER             cCEPInput_sendData_input_alloc( subscript, void** buf, const int32_t minlen, TMO tmout );
 *   ER             cCEPInput_sendData_input_dealloc( subscript, const void* buf );
 *   ER             cCEPInput_sendData_input_reuse( subscript, void* buf );
 *   ER_UINT        cCEPInput_sendData_input_bufferSize( subscript, const void* buf );
 *   uint32_t       cCEPInput_sendData_input_bufferMaxSize( subscript );
 *       subscript:  0...(NCP_cCEPInput_sendData_input-1)
 * allocator port for call port:cICMP4Error func:error param: inputp
 *   ER             cICMP4Error_error_inputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             cICMP4Error_error_inputp_dealloc( const void* buf );
 *   ER             cICMP4Error_error_inputp_reuse( void* buf );
 *   ER_UINT        cICMP4Error_error_inputp_bufferSize( const void* buf );
 *   uint32_t       cICMP4Error_error_inputp_bufferMaxSize( );
 * allocator port for call port:eInput func:UDPInput param: inputp
 *   ER             eInput_UDPInput_inputp_alloc( void** buf, const int32_t minlen, TMO tmout );
 *   ER             eInput_UDPInput_inputp_dealloc( const void* buf );
 *   ER             eInput_UDPInput_inputp_reuse( void* buf );
 *   ER_UINT        eInput_UDPInput_inputp_bufferSize( const void* buf );
 *   uint32_t       eInput_UDPInput_inputp_bufferMaxSize( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tUDPInput_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

#include <string.h>

#ifdef TARGET_KERNEL_ASP

#include <kernel.h>
#include <sil.h>
#include <t_syslog.h>
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
#include <net/if_loop.h>
#include <net/if_ppp.h>
#include <net/ethernet.h>
#include <net/ppp_ipcp.h>
#include <net/net.h>
#include <net/net_buf.h>
#include <net/net_count.h>

#include <netinet/in.h>
#include <netinet/in_var.h>
#include <netinet/in_itron.h>
#include <netinet/ip.h>
#include <netinet/ip_var.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <netinet/udp_var.h>

#include <net/if_var.h>

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eInput
 * entry port: eInput
 * signature:  sUDPInput
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eInput_UDPInput
 * name:         eInput_UDPInput
 * global_name:  tUDPInput_eInput_UDPInput
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
/*
 *  udp_input -- UDP の入力関数
 */

uint32_t
eInput_UDPInput(int8_t* inputp, int32_t size, const int8_t* dstaddr, int32_t addrlen)
{
	T_NET_BUF	*input = (T_NET_BUF *)inputp;
	T_UDP_HDR	*udph;
	uint32_t 	ix;
	uint32_t 	len, hlen, ulen;
	uint32_t 	offset = input->off.ifhdrlen + input->off.iphdrlenall;

	input->off.protocolflag |= FLAG_USE_UDP;
	input->off.tphdrlen 	 = UDP_HDR_SIZE;
	input->off.tphdrlenall   = UDP_HDR_SIZE;

#if defined(_IP6_CFG) && defined(_IP4_CFG) && API_PROTO == API_PROTO_IPV4
	T_UDP6_CEP	*cep6;
#endif

	hlen = (uint_t)GET_IF_IP_HDR_SIZE(input);

	// NET_COUNT_UDP(net_count_udp.in_octets,  input->len - hlen);
	// NET_COUNT_UDP(net_count_udp.in_packets, 1);
	// NET_COUNT_MIB(udp_stats.udpInDatagrams, 1);

	/* ヘッダ長をチェックする。*/
	if (input->len < hlen + UDP_HDR_SIZE)
		goto buf_rel;

	//TODO: udph = (T_UDP_HDR *)(input->buf + *offp);
	udph = (T_UDP_HDR *)(input->buf + offset);

	/* データグラム長をチェックする */
	ulen  = ntohs(udph->ulen);
	if (ulen != input->len - hlen)
		goto buf_rel;

	/* 宛先ポートが 0 のデータグラムは破棄する。RFC768 */
	if (udph->dport == 0)
		goto buf_rel;

#ifdef UDP_CFG_IN_CHECKSUM

	/* チェックサムをチェックする */
	//TODO: if (udph->sum && IN_CKSUM(input, IPPROTO_UDP, *offp, ulen) != 0)
	// 	goto buf_rel;
	if ((input->off.protocolflag & FLAG_USE_IPV4) && is_cIPv4CheckSum_joined()) {
		if (udph->sum && cIPv4CheckSum_ipv4CheckSum(inputp, size, offset, IPPROTO_UDP) != 0)
		  goto buf_rel;
	}

#endif	/* of #ifdef UDP_CFG_IN_CHECKSUM */

#if defined(_IP6_CFG) && defined(_IP4_CFG) && API_PROTO == API_PROTO_IPV4

#if TNUM_UDP4_CEPID > 0

	/* UDP 通信端点を得る。*/
	cep = udp4_find_cep(input, *offp);

	if (cep != NULL)
		udp4_input_select(cep, input, *offp);
	else if ((cep6 = udp6_find_cep(input, *offp)) != NULL)
		udp6_input_select(cep6, input, *offp);
	else
		udp4_reply_no_port(input, *offp);

	return IPPROTO_DONE;

#else	/* of #if TNUM_UDP4_CEPID > 0 */

	cep = 0;	/* warning 回避用のダミー */
	if ((cep6 = udp6_find_cep(input, *offp)) != NULL)
		udp6_input_select(cep6, input, *offp);
	else
		udp4_reply_no_port(input, *offp);

	return IPPROTO_DONE;

#endif	/* of #if TNUM_UDP4_CEPID > 0 */

#else	/* of #if defined(_IP6_CFG) && defined(_IP4_CFG) && API_PROTO == API_PROTO_IPV4 */

	/* UDP 通信端点を得る。*/
	// cep = UDP_FIND_CEP(input, *offp);

	// if (cep != NULL)
	// 	UDP_INPUT_SELECT(cep, input, *offp);
	// else
	// 	UDP_REPLY_NO_PORT(input, *offp);

	for (ix = N_CP_cCEPInput; ix -- > 0; ) {
		if (cCEPInput_check(ix, dstaddr, addrlen, ntohs(udph->dport)) == E_OK) {
			len = (uint32_t)(ntohs(udph->ulen) - UDP_HDR_SIZE);

			if (cCEPInput_receiveTaskID(ix) != TA_NULL) {
				if (cCEPInput_sendData(ix, inputp, size) != E_OK)
					goto buf_rel;
			}
			//TODO:mikan UDPのノンブロッキングコールをサポートするならばの処理
			else if (is_cCallback_joined(ix)) {
				/*
				 * コールバックで勝手にバッファを解放する場合はとかそういう処理が入るのですが、
				 * 難易度が高いので先送っちゃうのでかってに解放して下さいということにする
				 */
				if (cCEPInput_sendData(ix, inputp, size) != E_OK)
					goto buf_rel;
				cCallback_callback(ix, TEV_UDP_RCV_DAT, len);
			}
			else
			  goto buf_rel;

			return IPPROTO_DONE;
		}
	}

	/*
	 * 該当CEPがなかった場合のエラー処理は下位プロトコルにコールバックで依頼する
	 */
	if ((input->off.protocolflag & FLAG_USE_IPV4) && is_cICMP4Error_joined()) {
		cICMP4Error_error(inputp, size, ICMP4_UNREACH_PORT);
	}

#endif	/* of #if defined(_IP6_CFG) && defined(_IP4_CFG) && API_PROTO == API_PROTO_IPV4 */

buf_rel:
	// NET_COUNT_UDP(net_count_udp.in_err_packets, 1);
	// NET_COUNT_MIB(udp_stats.udpInErrors, 1);
	eInput_UDPInput_inputp_dealloc((void*)inputp); /* mikan どっちにしろ同じアロケータ利用を前提 */
	return IPPROTO_DONE;
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
