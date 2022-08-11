global load_kernel_86
global stack_ptr

extern main

STACK_SIZE equ 0x4000
MODULEALIGN equ 1 << 0
MEMINFO equ 1 << 1
FLAGS equ MODULEALIGN | MEMINFO
MAGIC equ 0x1BADB002
CHECKSUM equ -(MAGIC + FLAGS)

section .mbheader

align 4

multiboot_header:
	dd MAGIC
	dd FLAGS
	dd CHECKSUM

section .text

load_kernel_86:
	mov esp, stack+STACK_SIZE
	push eax
	push ebx

	call main
	cli

get_hanged:
	hlt
	jmp get_hanged

section .bss
align 4

stack:
	resb STACK_SIZE
stack_ptr:
