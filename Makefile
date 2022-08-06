CC = gcc
CC_ARGS = -T linker.ld -ffreestanding -nostdlib -m32 -O2 -lgcc
OBJ = arch/boot_x86.o kernel/main.o

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
