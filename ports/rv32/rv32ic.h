#ifndef _rv32ic_h
#define _rv32ic_h

#define VRAM      ((volatile unsigned char *)0x80010000)
#define SDRAM     ((volatile unsigned int  *)0x10000000)
#define UARTRXD   (*((volatile unsigned char *)0x80020000))
#define UARTRXC   (*((volatile unsigned char *)0x80020004))
#define UARTRXP   (*((volatile unsigned char *)0x80020010))
#define UARTTXD   (*((volatile unsigned char *)0x80020008))
#define UARTTXC   (*((volatile unsigned char *)0x8002000C))
#define HLINEBUF  ((volatile unsigned char *)0x80030000)

#define HLINEBUF_E ((volatile unsigned int *)0x80030000)
#define HLINEBUF_O ((volatile unsigned int *)0x80030200)

#define IRQENABLE (*((volatile unsigned char *)0x80040000))
#define UART_RX_IRQ_ENABLE_BIT (0x00000001)
#define HSYNC_IRQ_ENABLE_BIT (0x00000002)

#define STATUS    (((volatile unsigned int *)0x80050000))

#define FLASHCTL  (*((volatile unsigned int *)0x41000000))

#define VRAMSIZE (2048)



/* reset.S */
int rv32_settimer(int newvalue) ;
int rv32_maskirq(int newvalue) ;
int syscall0(int num);

#endif /* of _rv32ic_h */