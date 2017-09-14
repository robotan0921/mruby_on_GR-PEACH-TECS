/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tIPv4Functions_template.c => src/tIPv4Functions.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 属性アクセスマクロ #_CAAM_#
 * IPv4AddressInit  T_IN4_ADDR       ATTR_IPv4AddressInit
 * IPv4MaskInit     T_IN4_ADDR       ATTR_IPv4MaskInit
 * IPv4GatawayInit  T_IN4_ADDR       ATTR_IPv4GatawayInit
 * IPv4Address      T_IN4_ADDR       VAR_IPv4Address
 * IPv4Mask         T_IN4_ADDR       VAR_IPv4Mask
 * IPv4Gataway      T_IN4_ADDR       VAR_IPv4Gataway
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tIPv4Functions_tecsgen.h"

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

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eFunctions
 * entry port: eFunctions
 * signature:  sIPv4Functions
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eFunctions_checkSum
 * name:         eFunctions_checkSum
 * global_name:  tIPv4Functions_eFunctions_checkSum
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
uint16_t
eFunctions_checkSum(const int8_t* data, uint32_t len)
{
	uint16_t sum;

	sum = (uint16_t)in_cksum_carry(in_cksum_sum(data, len));
	return (uint16_t)(~htons(sum));
}

/* #[<ENTRY_FUNC>]# eFunctions_getIPv4Address
 * name:         eFunctions_getIPv4Address
 * global_name:  tIPv4Functions_eFunctions_getIPv4Address
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
T_IN4_ADDR
eFunctions_getIPv4Address()
{
	return VAR_IPv4Address;
}

/* #[<ENTRY_FUNC>]# eFunctions_getIPv4Mask
 * name:         eFunctions_getIPv4Mask
 * global_name:  tIPv4Functions_eFunctions_getIPv4Mask
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
T_IN4_ADDR
eFunctions_getIPv4Mask()
{
	return VAR_IPv4Mask;
}

/* #[<ENTRY_PORT>]# eCheckSum
 * entry port: eCheckSum
 * signature:  sIPv4CheckSum
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eCheckSum_ipv4CheckSum
 * name:         eCheckSum_ipv4CheckSum
 * global_name:  tIPv4Functions_eCheckSum_ipv4CheckSum
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
uint16_t
eCheckSum_ipv4CheckSum(int8_t* data, int32_t size, uint32_t offset, uint8_t proto)
{
	uint32_t	sum;
	uint_t		align;
	T_NET_BUF *input = (T_NET_BUF *)data;

	/* IPヘッダの決定 */
	T_IP4_HDR *iphdr;
	//TODO: オフセットの情報を引数に加える
	//iphdr = GET_IP4_HDR(input, input->off.ifhdrlen);
	iphdr = GET_IP4_HDR(input);
	uint32_t len = input->len - offset + input->off.ifalign;
	// uint32_t len = input->len - offset;

	/* 4 オクテット境界のデータ長 */
	align = (len + 3) >> 2 << 2;

	/* 4 オクテット境界までパディングで埋める。*/
	if (align > len)
		memset((uint8_t*)input->buf + offset + len, 0, (size_t)(align - len));

	sum = in_cksum_sum(input->buf + offset, align)
	    + in_cksum_sum(&(iphdr->src), sizeof(T_IN4_ADDR) * 2)
	    + len + proto;

	sum = in_cksum_carry(sum);

	return (uint16_t)(~htons((uint16_t)sum));
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
