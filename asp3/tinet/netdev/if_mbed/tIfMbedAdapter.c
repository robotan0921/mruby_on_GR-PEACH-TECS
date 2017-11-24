/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tIfMbedAdapter_template.c => src/tIfMbedAdapter.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cNicDriver signature: sNicDriver context:task
 *   void           cNicDriver_init( );
 *   void           cNicDriver_start( int8_t* outputp, int32_t size, uint8_t align );
 *   void           cNicDriver_read( int8_t** inputp, int32_t* size, uint8_t align );
 *   void           cNicDriver_getMac( uint8_t* macaddress );
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
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tIfMbedAdapter_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

#define CAST(type, val)		((type)(val))

#include <kernel.h>
#include <sil.h>
#include <t_syslog.h>
#include "kernel_cfg.h"
#include "kernel/kernel_impl.h"

#include <tinet_defs.h>
#include <tinet_config.h>

#include <net/if.h>
#include <net/ethernet.h>
#include <net/if_arp.h>
#include <net/net.h>
#include <net/net_timer.h>
#include <net/net_count.h>
#include <net/net_buf.h>
#include <net/ethernet.h>

#include "mbed_interface.h"
#include "ethernet_api.h"
#include "ethernetext_api.h"
#include <string.h>
#include "if_mbed.h"
#include "iodefine.h"

#ifdef _MSC_VER
#include <stdlib.h>
#endif

#include "tecs_if_mbed.h"
extern T_IF_SOFTC;

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/

/*
 * mbed_init -- ネットワークインタフェースの初期化
 */
void
if_mbed_init (T_IF_SOFTC *ic)
{
	cNicDriver_init();
}


/*
 * mbed_reset -- ネットワークインタフェースをリセットする。
 */
void
if_mbed_reset (T_IF_SOFTC *ic)
{
    cNicDriver_reset();
}

/*
 * mbed_read -- フレームの読み込み
 */
T_NET_BUF *
if_mbed_read (T_IF_SOFTC *ic)
{
	int8_t** inputp;
	int32_t* size;
	uint8_t align;

	return cNicDriver_read(inputp, size, align);
}

/*
 * mbed_start -- 送信フレームをバッファリングする。
 */
void
if_mbed_start (T_IF_SOFTC *ic, T_NET_BUF *output)
{
	//int8_t* outputp;
	int32_t size;
	uint8_t align;

	cNicDriver_start((int8_t *)output, size, align);
}

/*
 * mbed_probe -- ネットワークインタフェースの検出
 */
void
if_mbed_probe (T_IF_SOFTC *ic)
{
	cNicDriver_probe(ic->ifaddr.lladdr);
}