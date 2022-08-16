CC = gcc
CC_ARGS = -g -ffreestanding -nostdlib -m32 -O2 -lgcc -mno-sse -mno-sse2
CC_DEP = vmem.c mem.c

.PHONY : all

all: $(CC_DEP)
	$(CC) $(CC_ARGS) -c $(CC_DEP) -I ../include
