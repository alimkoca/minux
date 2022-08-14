global en_prot_mode
global en_virt_mem

; Setting page directory/page table/page
extern set_page_dtp

; Showing that 32 bits mode
[bits 32]
; Enable protected mode for 32 bit registers
en_prot_mode:
	mov eax, cr0 ; Loading to eax register for PE bit
	or eax, 1 ; Enable first bit
	mov cr0, eax ; Set PE bit to 1

	ret ; Return to calling convention

; Enabling virtual memory and taking physical
; address of PDBR for page directory.
en_virt_mem:
	; 31th bit of cr0 is PG, which is paging bit
	; enables paging mode and loads PDBR to upper
	; 20 bits of cr3
	mov eax, [esp+4]
	mov cr3, eax

	mov eax, cr0 ; Loading to eax register for enabling
	or eax, 1 << 31 ; Shifting to set 31th bit
	mov cr0, eax ; Set PG bit to 1

	ret
