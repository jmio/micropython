#include <stdint.h>
#include <stdbool.h>

#include "murax.h"
#include "syscall.h"
#include "symtable.h"

/* xprintf.h */
void (*xprintf) (const char* fmt, ...);

/* console.h */
void (*console_clear)();
void (*console_scroll)();
void (*console_putc)(unsigned char c) ;
void (*console_puts)(unsigned char *c) ;

/* keyboard.h */
void (*pollkey)() ;
int (*key_getc)(void);

/* serial.h */
/* USE TX/RX POLLING */
void (*pollrx)(void) ;
void (*polltx)(void) ;
/* UART0 initialisation */
void (*uart_init)(void) ;
/* get one char from recv buffer */
int (*uart_getc)(void) ;
/* put one char to send buffer */
char (*uart_putc)(unsigned char c) ;
/* put __xdata strings to send buffer */
char (*uart_puts)(unsigned char *s) ;
char (*uart_wait)(void) ;

#define LOADADR(VAR,STR) \
	VAR = (void *)(symt_get(STR)->address) \

void monio_init(void)
{
	uint32_t res = syscall0(MY_SYSCALL_GETSYMPTR);
	symt_init((SYMTABLE *)res);

	/* xprintf.h */
	LOADADR(xprintf,"xprintf");
	
	/* console.h */
	LOADADR(console_clear,"console_clear");
	LOADADR(console_scroll,"console_scroll");
	LOADADR(console_putc,"console_putc");
	LOADADR(console_puts,"console_puts");

	/* keyboard.h */
	LOADADR(pollkey,"pollkey");
	LOADADR(key_getc,"key_getc");

	/* serial.h */
	/* USE TX/RX POLLING */
	LOADADR(pollrx,"pollrx");
	LOADADR(polltx,"polltx");
	/* UART0 initialisation */
	LOADADR(uart_init,"uart_init");
	/* get one char from recv buffer */
	LOADADR(uart_getc,"uart_getc");
	/* put one char to send buffer */
	LOADADR(uart_putc,"uart_putc");
	/* put __xdata strings to send buffer */
	LOADADR(uart_puts,"uart_puts");
	LOADADR(uart_wait,"_uart_wait");
}
