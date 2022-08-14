CC = gcc
CC_ARGS = -ffreestanding -nostdlib -m32 -O2 -lgcc -mno-sse -mno-sse2
CC_DEP = main.c init.c mem.c panic.c vmem.c video.c isr.c io.c string.c

.PHONY : all

all: $(CC_DEP)
	$(CC) $(CC_ARGS) -c $(CC_DEP) -I ../include
