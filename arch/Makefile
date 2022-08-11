AS=nasm
AS_ARGS = -felf32
AS_FILES = x86/boot_x86.asm x86/mem.asm x86/vmem.asm x86/isr.asm

all: $(AS_FILES)
	$(AS) $(AS_ARGS) x86/boot_x86.asm
	$(AS) $(AS_ARGS) x86/mem.asm
	$(AS) $(AS_ARGS) x86/vmem.asm
	$(AS) $(AS_ARGS) x86/isr.asm
