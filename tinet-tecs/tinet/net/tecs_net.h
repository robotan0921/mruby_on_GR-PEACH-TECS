#ifndef TECS_NET_H
#define TECS_NET_H

#define FLAG_USE_UDP	(0x01)	/* TCPを利用するフラグ */
#define FLAG_USE_TCP	(0x02)	/* UDPを利用するフラグ */

#define FLAG_USE_IPV4   (0x04) 	/* IPv4 */
#define FLAG_USE_IPV6   (0x08) 	/* IPv6 */

#define FLAG_USE_ETHER  (0x10) 	/* ethernet */

#endif /* TECS_NET_H */