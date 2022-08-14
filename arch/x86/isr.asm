global load_idt_mnx

load_idt_mnx:
	mov eax, [esp+4]
	lidt [eax]
	ret

%macro ISR_PSH_ERR 1
global int_elem_%1
int_elem_%1:
	cli
	push byte %1
	push 1
	jmp isr_goto_int_hndlr
%endmacro

%macro ISR_NT_PSH_ERR 1
global int_elem_%1
int_elem_%1:
	cli
	push 0
	jmp isr_goto_int_hndlr
%endmacro

extern int_hndlr

ISR_NT_PSH_ERR 0
ISR_NT_PSH_ERR 1
ISR_NT_PSH_ERR 2
ISR_NT_PSH_ERR 3
ISR_NT_PSH_ERR 4
ISR_NT_PSH_ERR 5
ISR_NT_PSH_ERR 6
ISR_NT_PSH_ERR 7
ISR_PSH_ERR 8
ISR_NT_PSH_ERR 9
ISR_PSH_ERR 10
ISR_PSH_ERR 11
ISR_PSH_ERR 12
ISR_PSH_ERR 13
ISR_PSH_ERR 14
ISR_NT_PSH_ERR 15
ISR_NT_PSH_ERR 16
ISR_PSH_ERR 17
ISR_NT_PSH_ERR 18
ISR_NT_PSH_ERR 19
ISR_NT_PSH_ERR 20
ISR_NT_PSH_ERR 21
ISR_NT_PSH_ERR 22
ISR_NT_PSH_ERR 23
ISR_NT_PSH_ERR 24
ISR_NT_PSH_ERR 25
ISR_NT_PSH_ERR 26
ISR_NT_PSH_ERR 27
ISR_NT_PSH_ERR 28
ISR_NT_PSH_ERR 29
ISR_PSH_ERR 30
ISR_NT_PSH_ERR 31

isr_goto_int_hndlr:
	pusha

	mov ax, ds
	push eax

	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	call int_hndlr

	pop eax
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	popa

	pop eax
	cmp eax, 1
	je clean_errno

	sti
	iret

clean_errno:
	add esp, 8

	sti
	iret
