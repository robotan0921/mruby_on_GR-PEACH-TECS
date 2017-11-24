#ifndef _TECS_IN_VAR_H_
#define _TECS_IN_VAR_H_

/*
 *  ルーティングエントリ状態フラグ
 */
#ifndef IN_RTF_DEFINED

#define IN_RTF_DEFINED		UINT_C(0x01)	/* 定義済み			*/
#define IN_RTF_REDIRECT		UINT_C(0x10)	/* 向け直しにより自動設定された	*/


/*
 *  IP アドレスの定義
 */

#define IN4_IS_NET_ADDR_MULTICAST(a)	IN4_IS_ADDR_MULTICAST(ntohl(*(a)))

#endif	/* of #ifndef IN_RTF_DEFINED */

#endif	/* of #ifndef _TECS_IN_VAR_H_ */
