#ifndef _TECS_ETHERNET_H_
#define _TECS_ETHERNET_H_

#if 0	/* 4バイト境界に合わせる必要があるなら */
#define NETBUFFER_ALIGN 2
#else
#define NETBUFFER_ALIGN 0
#endif

#define ETHER_HDR_SIZE (sizeof(T_ETHER_HDR))

#define ETHER_MTU 1500

#ifndef T_IN4_ADDR_DEFINED

typedef uint32_t T_IN4_ADDR;

#define T_IN4_ADDR_DEFINED

#endif	/* of #ifndef T_IN4_ADDR_DEFINED */

#endif	/* of #ifndef _TECS_ETHERNET_H_ */
