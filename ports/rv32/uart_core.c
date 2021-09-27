#include <unistd.h>
#include "py/mpconfig.h"

#if MICROPY_MIN_USE_RV32_CPU 
#include "monio.h"
#endif

/*
 * Core UART functions to implement for a port
 */

#if MICROPY_MIN_USE_STM32_MCU
typedef struct {
    volatile uint32_t SR;
    volatile uint32_t DR;
} periph_uart_t;
#define USART1 ((periph_uart_t *)0x40011000)
#endif

// Receive single character
int mp_hal_stdin_rx_chr(void) {
    unsigned char c = 0;
    #if MICROPY_MIN_USE_STDOUT
    int r = read(STDIN_FILENO, &c, 1);
    (void)r;
    #elif MICROPY_MIN_USE_STM32_MCU
    // wait for RXNE
    while ((USART1->SR & (1 << 5)) == 0) {
    }
    c = USART1->DR;
    #elif MICROPY_MIN_USE_RV32_CPU
	{
		int i = -1;
		while(i < 0) {
			pollrx();
			i = uart_getc() ;
			if (i < 0) {
				pollkey();
				i = key_getc();
			}
		}
		c = (unsigned char)(i & 0xFF);
	}
		
    #endif
    return c;
}

// Send string of given length
void mp_hal_stdout_tx_strn(const char *str, mp_uint_t len) {
    #if MICROPY_MIN_USE_STDOUT
    int r = write(STDOUT_FILENO, str, len);
    (void)r;
    #elif MICROPY_MIN_USE_STM32_MCU
    while (len--) {
        // wait for TXE
        while ((USART1->SR & (1 << 7)) == 0) {
        }
        USART1->DR = *str++;
    }
    #elif MICROPY_MIN_USE_RV32_CPU
    while (len--) {
    	int i = *str++;
		uart_putc((unsigned char)i) ;
		console_putc(i & 0xFF);    	
    }
	uart_wait();
    #endif
}
