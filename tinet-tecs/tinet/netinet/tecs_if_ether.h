#ifndef _TECS_IF_ETHER_H_
#define _TECS_IF_ETHER_H_

#define ETHER_ADDR_LEN		6	/* Ethernet (MAC) Address	*/

/*
 *  ARP キャッシュエントリ
 */

typedef struct arp_entry {
	T_NET_BUF	*hold;		/* ARP の解決待ち出力フレーム	*/
	T_IN4_ADDR	ip_addr;	/* IP アドレス			*/
	uint16_t	expire;		/* 破棄までの時間、0 なら未使用	*/
	uint8_t		mac_addr[ETHER_ADDR_LEN];	/* MAC アドレス	*/
	} T_ARP_ENTRY;

#endif	/* of #ifndef _IF_ETHER_H_ */