#include <stdint.h>
#include "murax.h"

// options to control how MicroPython is built

// You can disable the built-in MicroPython compiler by setting the following
// config option to 0.  If you do this then you won't get a REPL prompt, but you
// will still be able to execute pre-compiled scripts, compiled with mpy-cross.
#define MICROPY_ENABLE_COMPILER     (1)
#define MICROPY_QSTR_BYTES_IN_HASH  (1)
//#define MICROPY_QSTR_EXTRA_POOL     mp_qstr_frozen_const_pool
#define MICROPY_ALLOC_PATH_MAX      (256)
#define MICROPY_ALLOC_PARSE_CHUNK_INIT (16)

// compiler configuration
#define MICROPY_COMP_CONST          (0)
#define MICROPY_COMP_DOUBLE_TUPLE_ASSIGN (0)
#define MICROPY_COMP_MODULE_CONST   (1)
#define MICROPY_COMP_TRIPLE_TUPLE_ASSIGN (1)
#define MICROPY_COMP_RETURN_IF_EXPR (1)

#define MICROPY_ENABLE_GC           (1)
#define MICROPY_GC_ALLOC_THRESHOLD  (0)
#define MICROPY_HELPER_REPL         (1)
#define MICROPY_ERROR_REPORTING     (MICROPY_ERROR_REPORTING_TERSE)
#define MICROPY_BUILTIN_METHOD_CHECK_SELF_ARG (1)
#define MICROPY_PY_ASYNC_AWAIT      (1)
#define MICROPY_USE_INTERNAL_ERRNO  (1)
#define MICROPY_PY_FUNCTION_ATTRS   (1)
#define MICROPY_PY_DESCRIPTORS      (1)
#define MICROPY_PY_DELATTR_SETATTR  (1)
#define MICROPY_PY_ALL_SPECIAL_METHODS (1)
#define MICROPY_PY_BUILTINS_BYTEARRAY (1)
#define MICROPY_PY_BUILTINS_DICT_FROMKEYS (1)
#define MICROPY_PY_BUILTINS_ENUMERATE (1)
#define MICROPY_PY_BUILTINS_FILTER  (1)
#define MICROPY_PY_BUILTINS_REVERSED (1)
#define MICROPY_PY_BUILTINS_SET     (1)
#define MICROPY_PY_BUILTINS_SLICE   (1)
#define MICROPY_PY_BUILTINS_PROPERTY (1)
#define MICROPY_PY_BUILTINS_MIN_MAX (1)
#define MICROPY_PY_BUILTINS_STR_UNICODE (1)
#define MICROPY_PY_BUILTINS_STR_CENTER (1)
#define MICROPY_PY_BUILTINS_STR_PARTITION (1)
#define MICROPY_PY_BUILTINS_STR_SPLITLINES (1)
#define MICROPY_PY_BUILTINS_STR_COUNT (1)
#define MICROPY_PY_BUILTINS_STR_OP_MODULO (1)
#define MICROPY_PY_BUILTINS_FROZENSET (1)
#define MICROPY_PY_BUILTINS_MEMORYVIEW (1)
#define MICROPY_PY_BUILTINS_HELP    (1)
#ifndef MICROPY_PY_BUILTINS_HELP_TEXT
#define MICROPY_PY_BUILTINS_HELP_TEXT rv32_help_text
#endif
#define MICROPY_PY___FILE__         (1)
#define MICROPY_PY_GC               (1)
#define MICROPY_PY_ARRAY            (1)
#define MICROPY_PY_ATTRTUPLE        (1)
#define MICROPY_PY_COLLECTIONS      (1)
#define MICROPY_PY_COLLECTIONS_DEQUE (1)
#define MICROPY_PY_COLLECTIONS_ORDEREDDICT (1)
#define MICROPY_PY_CMATH            (1)
#define MICROPY_PY_IO               (1)
#define MICROPY_PY_IO_IOBASE        (1)
#define MICROPY_PY_IO_FILEIO        (MICROPY_VFS_FAT) // because mp_type_fileio/textio point to fatfs impl
#define MICROPY_PY_SYS              (1)
#define MICROPY_PY_SYS_MAXSIZE      (1)
#define MICROPY_PY_SYS_MODULES      (1)
#define MICROPY_PY_SYS_EXIT         (1)
#define MICROPY_PY_SYS_STDFILES     (1)
#define MICROPY_PY_SYS_STDIO_BUFFER (1)
//#define MICROPY_MODULE_FROZEN_MPY   (1)
#define MICROPY_PY_UERRNO           (1)
#define MICROPY_PY_UBINASCII        (1)
#define MICROPY_PY_UCTYPES          (1)
#define MICROPY_PY_UHASHLIB         (1)
#define MICROPY_PY_UHEAPQ           (1)
#define MICROPY_PY_UTIMEQ           (1)
#define MICROPY_PY_UJSON            (1)
#define MICROPY_PY_URANDOM          (1)
#define MICROPY_PY_URE              (1)
#define MICROPY_PY_URE_SUB          (1)
#define MICROPY_PY_SYS_EXC_INFO     (1)
#define MICROPY_ENABLE_EMERGENCY_EXCEPTION_BUF   (1)
#define MICROPY_EMERGENCY_EXCEPTION_BUF_SIZE  (256)
#define MICROPY_CPYTHON_COMPAT      (0)
#define MICROPY_MODULE_GETATTR      (0)
#define MICROPY_PY_MACHINE          (1)
#define MICROPY_PY_MICROPYTHON_MEM_INFO (1)
#define MICROPY_PY_FRAMEBUF         (1)
#define MICROPY_KBD_EXCEPTION       (1)

#define MICROPY_ENABLE_SOURCE_LINE  (1)
#ifndef MICROPY_FLOAT_IMPL // can be configured by each board via mpconfigboard.mk
#define MICROPY_FLOAT_IMPL          (MICROPY_FLOAT_IMPL_FLOAT)
#endif

#define MICROPY_VFS                 (1)
#define MICROPY_VFS_FAT             (1)
#define MICROPY_READER_VFS          (1)

#define MICROPY_FATFS_ENABLE_LFN    (1)
#define MICROPY_FATFS_RPATH         (2)
#define MICROPY_FATFS_MAX_SS        (4096)
#define MICROPY_FATFS_LFN_CODE_PAGE 437 /* 1=SFN/ANSI 437=LFN/U.S.(OEM) */
#define MICROPY_FATFS_MULTI_PARTITION  (1)
#define MICROPY_MOUNT_SD_CARD       (1)

#define MICROPY_MODULE_WEAK_LINKS   (1)
#define MICROPY_CAN_OVERRIDE_BUILTINS (1)

#define MICROPY_LONGINT_IMPL        (MICROPY_LONGINT_IMPL_MPZ)
#define MP_SSIZE_MAX (0x40000000)

// type definitions for the specific machine
extern const struct _mp_obj_module_t mp_module_uos;
extern const struct _mp_obj_module_t fb_module;

#define mp_type_fileio mp_type_vfs_fat_fileio
#define mp_type_textio mp_type_vfs_fat_textio

// use vfs's functions for import stat and builtin open
#define mp_import_stat mp_vfs_import_stat
#define mp_builtin_open mp_vfs_open
#define mp_builtin_open_obj mp_vfs_open_obj

typedef intptr_t mp_int_t; // must be pointer size
typedef uintptr_t mp_uint_t; // must be pointer size
typedef long mp_off_t;

// extra built in names to add to the global namespace
#define MICROPY_PORT_BUILTINS \
    { MP_ROM_QSTR(MP_QSTR_open), MP_ROM_PTR(&mp_builtin_open_obj) },

#define MICROPY_PORT_BUILTIN_MODULES                       \
    { MP_ROM_QSTR(MP_QSTR_machine), MP_ROM_PTR(&mp_module_machine) }, \
    { MP_ROM_QSTR(MP_QSTR_uos), MP_ROM_PTR(&mp_module_uos) }, \
    { MP_ROM_QSTR(MP_QSTR_fb), MP_ROM_PTR(&fb_module) }, \

#define MICROPY_PORT_BUILTIN_MODULE_WEAK_LINKS \
    { MP_ROM_QSTR(MP_QSTR_binascii), MP_ROM_PTR(&mp_module_ubinascii) }, \
    { MP_ROM_QSTR(MP_QSTR_framebuffer), MP_ROM_PTR(&mp_module_framebuffer) }, \
    { MP_ROM_QSTR(MP_QSTR_collections), MP_ROM_PTR(&mp_module_collections) }, \
    { MP_ROM_QSTR(MP_QSTR_errno), MP_ROM_PTR(&mp_module_uerrno) }, \
    { MP_ROM_QSTR(MP_QSTR_hashlib), MP_ROM_PTR(&mp_module_uhashlib) }, \
    { MP_ROM_QSTR(MP_QSTR_io), MP_ROM_PTR(&mp_module_io) }, \
    { MP_ROM_QSTR(MP_QSTR_json), MP_ROM_PTR(&mp_module_ujson) }, \
    { MP_ROM_QSTR(MP_QSTR_os), MP_ROM_PTR(&mp_module_uos) }, \
    { MP_ROM_QSTR(MP_QSTR_random), MP_ROM_PTR(&mp_module_urandom) }, \
    { MP_ROM_QSTR(MP_QSTR_re), MP_ROM_PTR(&mp_module_ure) }, \
    { MP_ROM_QSTR(MP_QSTR_struct), MP_ROM_PTR(&mp_module_ustruct) }, \
    { MP_ROM_QSTR(MP_QSTR_time), MP_ROM_PTR(&utime_module) }, \
    { MP_ROM_QSTR(MP_QSTR_zlib), MP_ROM_PTR(&mp_module_uzlib) }, \

// We need to provide a declaration/definition of alloca()
#include <alloca.h>

#define MICROPY_HW_BOARD_NAME "Softcore"
#define MICROPY_HW_MCU_NAME "rv32"

#ifdef __linux__
#define MICROPY_MIN_USE_STDOUT (1)
#endif

#ifdef __thumb__
#define MICROPY_MIN_USE_CORTEX_CPU (1)
#define MICROPY_MIN_USE_STM32_MCU (1)
#endif

//#ifdef __rv32__
#define MICROPY_MIN_USE_RV32_CPU (1)
//#endif


#define MP_STATE_PORT MP_STATE_VM

#define MICROPY_PORT_ROOT_POINTERS \
    const char *readline_hist[8];

/* !!! THIS IS MACHINE DEPENDENT PART !!! */
#define MP_MURAX_UART_STATUS      (*(uint32_t *)(0xF0010004))
#define MP_RV32_BREAK() { if ((MP_MURAX_UART_STATUS >> 24) != 0) mp_sched_keyboard_interrupt(); } // vm.c (patched)
