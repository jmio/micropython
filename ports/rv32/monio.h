/*
	rv32ic monitor io stub
*/

/* xprintf.h */
extern void (*xprintf) (const char* fmt, ...);

/* console.h */
extern void (*console_clear)();
extern void (*console_scroll)();
extern void (*console_putc)(unsigned char c) ;
extern void (*console_puts)(unsigned char *c) ;

/* keyboard.h */
extern void (*pollkey)() ;
extern int (*key_getc)(void);

/* serial.h */
/* USE TX/RX POLLING */
extern void (*pollrx)(void) ;
extern void (*polltx)(void) ;
/* UART0 initialisation */
extern void (*uart_init)(void) ;
/* get one char from recv buffer */
extern int (*uart_getc)(void) ;
/* put one char to send buffer */
extern char (*uart_putc)(unsigned char c) ;
/* put __xdata strings to send buffer */
extern char (*uart_puts)(unsigned char *s) ;
/* uart send wait */
extern char (*uart_wait)(void) ;

/* LOAD ADDRESS */
void monio_init(void);

