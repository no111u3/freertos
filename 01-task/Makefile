#*-----------------------------------------------------------------------------
#* Author: Boris Vinogradov(nis) : no111u3@gmail.com
#* File: Makefile
#* Type: Makefile
#* Project: f4examples/00-base
#* 2012
#*-----------------------------------------------------------------------------
# Compilator prefix
CROSS_PREFIX=arm-none-eabi-
# Compilators and utils
CC=$(CROSS_PREFIX)gcc
OBJCOPY=$(CROSS_PREFIX)objcopy
SIZE=$(CROSS_PREFIX)size
# Paths
STM_PATH=../../stlink/example
LIBS_STM_PATH=$(STM_PATH)/libs_stm
FREERTOS_PATH=../FreeRTOSV7.1.1/Source
# Platform
PLATFORM=stm32f10x
# Primary compiler flags
CFLAGS=-g -O0 -mlittle-endian -mthumb -ffreestanding -fno-exceptions
CFLAGS+= -mcpu=cortex-m3 -DSTM32F10X_MD
# Secondary compiler flags
CFLAGS+= -I.
CFLAGS+= -I$(LIBS_STM_PATH)/inc/base
CFLAGS+= -I$(LIBS_STM_PATH)/inc/core_support
CFLAGS+= -I$(LIBS_STM_PATH)/inc/device_support
CFLAGS+= -I$(FREERTOS_PATH)/include
CFLAGS+= -I$(FREERTOS_PATH)/portable/GCC/ARM_CM3
CFLAGS+= -Wl,-T,stm32f102xb_flash.ld
# Linker flags
LDFLAGS=-L. -nostartfiles
# Sources and objects
SRCS=$(wildcard *.c)
SRCS+=$(FREERTOS_PATH)/list.c
SRCS+=$(FREERTOS_PATH)/croutine.c
SRCS+=$(FREERTOS_PATH)/queue.c
SRCS+=$(FREERTOS_PATH)/tasks.c
SRCS+=$(FREERTOS_PATH)/timers.c
SRCS+=$(FREERTOS_PATH)/portable/GCC/ARM_CM3/port.c
SRCS+=$(FREERTOS_PATH)/portable/MemMang/heap_1.c

OBJS=$(SRCS:.c=.o)
# Rules for compile
all: firmware.bin
# Making binary firmware file
%bin: %elf
	$(OBJCOPY) -O binary $^ $@
	$(SIZE) $^
# Making elf
firmware.elf: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)
# Making objects
%.o: $.c
	$(CC) $(CFLAGS) -c -o $@ $^
# Rules for clean
clean:
	rm -rf *.o *.elf *.bin $(OBJS)
# Rules for write firmware to mcu
write: firmware.bin
	qstlink2 -cewV ./firmware.bin
# PHONY
.PHONY: all clean
