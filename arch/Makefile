AS=nasm
AS_ARGS = -felf32
AS_DEP = x86/boot_x86.asm

all: $(AS_DEP)
	$(AS) $(AS_ARGS) $(AS_DEP) -o boot_x86.o
