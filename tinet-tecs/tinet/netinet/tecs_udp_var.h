#ifndef _TECS_UDP_VAR_H_
#define _TECS_UDP_VAR_H_

/*
 *  UDP 通信端点フラグ
 */

#define UDP_CEP_FLG_POST_OUTPUT	UINT_C(0x0200)	/* 送信を開始する。		*/
#define UDP_CEP_FLG_DYNAMIC	UINT_C(0x0400)	/* 動的生成・削除可能通信端点。	*/
#define UDP_CEP_FLG_VALID	UINT_C(0x0800)	/* 生成済みで有効な通信端点。	*/

#endif /* end of _TECS_UDP_VAR_H_ */
