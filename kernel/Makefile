CC = gcc
CC_ARGS = -g -ffreestanding -nostdlib -m32 -O2 -lgcc -mno-sse -mno-sse2
CC_DEP = main.c init.c panic.c video.c isr.c irq.c io.c timer.c syscall.c

.PHONY : all

all: $(CC_DEP)
	$(CC) $(CC_ARGS) -c $(CC_DEP) -I ../include
