#include <minux/init.h>
#include <minux/isr.h>
#include <minux/io.h>
#include <minux/mem.h>
#include <minux/vmem.h>
#include <minux/video.h>

int init_proc(){
	// Set the GDT, IDT table and enable protected mode
	printf("minux: loading gdt\n");
	set_gdt_tbl();
	printf("minux: loading idt\n");
	set_idt_tbl();
	printf("minux: protected mode\n");
	en_prot_mode();
	// Enable paging and virtual memory
	printf("minux: 32 bit paging\n");
	bit32_pg_enable();

	outb(0xa, 0xb);
	if (inb(0xa) > 0){
		printf("minux: perfect");
	}
	for (;;){
		asm volatile ("hlt");
	}
}
