CC = gcc
CC_ARGS = -T linker.ld -ffreestanding -nostdlib -m32 -O2 -lgcc -mno-sse -mno-sse2
OBJ = arch/x86/boot_x86.o arch/x86/mem.o arch/x86/vmem.o arch/x86/isr.o  arch/x86/irq.o\
      kernel/main.o kernel/init.o kernel/video.o mm/vmem.o \
      mm/mem.o kernel/isr.o kernel/irq.o kernel/io.o include/string.o \
      kernel/panic.o kernel/syscall.o kernel/timer.o

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
	$(MAKE) all -C mm
	$(MAKE) all -C include
