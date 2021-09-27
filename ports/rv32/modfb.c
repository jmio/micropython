#include <stdio.h>
#include <stdint.h>

#include "py/runtime.h"
#include "py/mphal.h"
#include "py/obj.h"

/// \function fb.fb_data()
/// This returns the pointer to frame buffer as byte array if it is allocated.
STATIC mp_obj_t fb_data(void) {
        return mp_obj_new_bytearray_by_ref(800*480*2, (void *) 0x40000000);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_0(fb_data_obj, fb_data);

STATIC const mp_rom_map_elem_t fb_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_fb) },
    { MP_ROM_QSTR(MP_QSTR_fb_data), MP_ROM_PTR(&fb_data_obj) },
};
STATIC MP_DEFINE_CONST_DICT(fb_module_globals, fb_module_globals_table);

const mp_obj_module_t fb_module = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*) &fb_module_globals,
};
