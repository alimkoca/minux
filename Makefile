CC = gcc
CC_ARGS = -T linker.ld -ffreestanding -nostdlib -m32 -O2 -lgcc -mno-sse -mno-sse2
OBJ = arch/x86/boot_x86.o arch/x86/mem.o arch/x86/vmem.o arch/x86/isr.o \
      kernel/main.o kernel/init.o kernel/video.o kernel/vmem.o \
      kernel/mem.o kernel/isr.o kernel/io.o kernel/string.o \
      kernel/panic.o

.PHONY : kernel

install: iso_install
	@echo "Successfully build Minux!"

clean:
	rm $(OBJ)

iso_install: bin_install
	@echo "Building iso file..."
	mv minux.bin iso/boot/
	grub-mkrescue -o minux.iso iso

bin_install: kernel arch_x86
	@echo "Building binary file..."
	$(CC) $(CC_ARGS) $(OBJ) -o minux.bin

arch_x86:
	@echo "Building arch objects..."
	$(MAKE) all -C arch

kernel:
	@echo "Building kernel objects..."
	$(MAKE) all -C kernel
