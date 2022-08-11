#include <minux/init.h>
#include <minux/isr.h>
#include <minux/mem.h>
//#include <minux/vmem.h>
#include <minux/video.h>

int init_proc(){
	// Set the GDT, IDT table and enable protected mode
	set_gdt_tbl();
	set_idt_tbl();
	en_prot_mode();
	// Finally print success
	put_str("Minux 0.0.1-rc1: Welcome", 15);
}
