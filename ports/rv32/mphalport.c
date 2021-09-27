#include <string.h>

#include "py/runtime.h"
#include "py/stream.h"
#include "py/mperrno.h"
#include "py/mphal.h"
#include "extmod/misc.h"

#include "monio.h"
#include "rv32ic.h"

mp_uint_t mp_hal_ticks_ms(void) {
    return 0;
}


uintptr_t mp_hal_stdio_poll(uintptr_t poll_flags) {
    uintptr_t ret = 0;
    if (poll_flags & MP_STREAM_POLL_RD) {
        if (UARTRXC & 0x01) {
            ret |= MP_STREAM_POLL_RD;
        }
    	/*
        if (*KEY AVAILABLE*) {
            ret |= MP_STREAM_POLL_RD;
        }
    	*/
    }
    return ret;
}
