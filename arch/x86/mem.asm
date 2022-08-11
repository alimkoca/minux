[global load_gdt_mnx]

extern main

load_gdt_mnx:
	mov eax, [esp+4]
	lgdt [eax]

	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax

	; Far jump to code segment, 0x08
	jmp 0x08:.code_entry_p

.code_entry_p:
	ret
