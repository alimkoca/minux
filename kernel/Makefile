CC = gcc
CC_ARGS = -ffreestanding -nostdlib -m32 -O2 -lgcc
CC_DEP = main.c

.PHONY : all

all: $(CC_DEP)
	$(CC) $(CC_ARGS) -c $(CC_DEP)
