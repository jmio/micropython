include ../../py/mkenv.mk

CROSS = 1

# qstr definitions (must come before including py.mk)
QSTR_DEFS = qstrdefsport.h

# MicroPython feature configurations
MICROPY_ROM_TEXT_COMPRESSION ?= 1

# include py core make definitions
include $(TOP)/py/py.mk

ifeq ($(CROSS), 1)
CROSS_COMPILE ?= riscv-none-embed-
OBJDUMP = $(CROSS_COMPILE)objdump
endif

INC += -I.
INC += -I$(TOP)
INC += -I$(BUILD)

ifeq ($(CROSS), 1)
FFCONF = -DFFCONF_H=\"ffconf.h\"
CFLAGS2 = -Wa,-adhln -g
CFLAGS  = -DRV32_VM_BREAK=1 $(INC) $(FFCONF) --specs=sim.specs -std=c99 -ffunction-sections -nostartfiles -march=rv32ic -mabi=ilp32 -O
LD = $(CROSS_COMPILE)gcc
LDFLAGS = $(CFLAGS) $(CFLAGS2) -Wl,--gc-sections -Tlink.ld
#DFU = $(TOP)/tools/dfu.py
#PYDFU = $(TOP)/tools/pydfu.py
#CFLAGS_CORTEX_M4 = -mthumb -mtune=cortex-m4 -mcpu=cortex-m4 -msoft-float -fsingle-precision-constant -Wdouble-promotion -Wfloat-conversion
#CFLAGS = $(INC) -Wall -Werror -std=c99 -nostdlib $(CFLAGS_CORTEX_M4) $(COPT)
#LDFLAGS = -nostdlib -T stm32f405.ld -Map=$@.map --cref --gc-sections
else
CFLAGS = -m32 $(INC) -Wall -Werror -Wdouble-promotion -Wfloat-conversion -std=c99 $(COPT)
LDFLAGS = -m32 -Wl,-Map=$@.map,--cref -Wl,--gc-sections
endif

CSUPEROPT = -O # save some code space

# Tune for Debugging or Optimization
ifeq ($(DEBUG), 1)
CFLAGS += -O0 -ggdb
else
CFLAGS += -Os -DNDEBUG
CFLAGS += -fdata-sections -ffunction-sections
endif

LIBS =

SRC_C = \
	main.c \
	help.c \
	symtable.c \
	monio.c \
	uart_core.c \
	modmachine.c \
	modfb.c \
	machine_sdcard.c \
	sdmm.c \
	mphalport.c \
	moduos.c \
	fatfs_port.c \
	shared/libc/printf.c \
	shared/readline/readline.c \
	shared/runtime/pyexec.c \
	shared/runtime/stdout_helpers.c \
	shared/runtime/interrupt_char.c \
	shared/runtime/sys_stdio_mphal.c \
	shared/timeutils/timeutils.c \

#	$(BUILD)/_frozen_mpy.c \

ifeq ($(CROSS), 1)
SRC_C += shared/libc/string0.c
endif

SRC_S = start.S

# FatFS VFS support
SRC_LIB += $(addprefix lib/,\
	oofatfs/ff.c \
	oofatfs/ffunicode.c \
	libm/math.c \
	libm/fmodf.c \
	libm/nearbyintf.c \
	libm/ef_sqrt.c \
	libm/log1pf.c \
	libm/acoshf.c \
	libm/asinhf.c \
	libm/atanhf.c \
	libm/kf_rem_pio2.c \
	libm/kf_sin.c \
	libm/kf_cos.c \
	libm/kf_tan.c \
	libm/ef_rem_pio2.c \
	libm/erf_lgamma.c \
	libm/sf_sin.c \
	libm/sf_cos.c \
	libm/sf_tan.c \
	libm/sf_frexp.c \
	libm/sf_modf.c \
	libm/sf_ldexp.c \
	libm/sf_erf.c \
	libm/wf_lgamma.c \
	libm/wf_tgamma.c \
	libm/asinfacosf.c \
	libm/atanf.c \
	libm/atan2f.c \
	)


OBJ = $(PY_O) $(addprefix $(BUILD)/, $(SRC_C:.c=.o) $(SRC_MOD:.c=.o) $(SRC_S:.S=.o) $(SRC_LIB:.c=.o))
#OBJ = $(PY_CORE_O) $(addprefix $(BUILD)/, $(SRC_C:.c=.o)) $(addprefix $(BUILD)/, $(SRC_S:.S=.o))

# List of sources for qstr extraction
SRC_QSTR += $(SRC_C) $(SRC_MOD) $(SRC_LIB)

$(BUILD)/$(OOFATFS_DIR)/ff.o: COPT += -Os
$(filter $(PY_BUILD)/../extmod/vfs_fat_%.o, $(PY_O)): COPT += -Os
$(filter $(PY_BUILD)/../extmod/vfs_reader.o, $(PY_O)): COPT += -Os

all: $(BUILD)/v.elf

$(BUILD)/_frozen_mpy.c: frozentest.mpy $(BUILD)/genhdr/qstrdefs.generated.h
	$(ECHO) "MISC freezing bytecode"
	$(Q)$(TOP)/tools/mpy-tool.py -f -q $(BUILD)/genhdr/qstrdefs.preprocessed.h -mlongint-impl=none $< > $@

$(BUILD)/v.elf: $(OBJ)
	$(Q)$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)
	$(OBJDUMP) -D $@ > $@.txt
	$(Q)$(OBJCOPY) -O ihex $(BUILD)/v.elf $(BUILD)/v.hex
	$(Q)$(SIZE) $@

#$(BUILD)/firmware.bin: $(BUILD)/firmware.elf
#	$(Q)$(OBJCOPY) -O binary -j .isr_vector -j .text -j .data $^ $(BUILD)/firmware.bin

#$(BUILD)/firmware.dfu: $(BUILD)/firmware.bin
#	$(ECHO) "Create $@"
#	$(Q)$(PYTHON) $(DFU) -b 0x08000000:$(BUILD)/firmware.bin $@

#deploy: $(BUILD)/firmware.dfu
#	$(ECHO) "Writing $< to the board"
#	$(Q)$(PYTHON) $(PYDFU) -u $<

# Run emulation build on a POSIX system with suitable terminal settings
run:
	stty raw opost -echo
	build/firmware.elf
	@echo Resetting terminal...
# This sleep is useful to spot segfaults
	sleep 1
	reset

test: $(BUILD)/firmware.elf
	$(Q)/bin/echo -e "print('hello world!', list(x+1 for x in range(10)), end='eol\\\\n')\\r\\n\\x04" | $(BUILD)/firmware.elf | tail -n2 | grep "^hello world! \\[1, 2, 3, 4, 5, 6, 7, 8, 9, 10\\]eol"

include $(TOP)/py/mkrules.mk
