#include <minux/init.h>
#include <minux/mem.h>
#include <minux/kernel.h>
#include <minux/tty.h>

int init_proc(){
	// Set the GDT, IDT table and enable protected mode
	set_gdt_tbl();
	set_idt_tbl();
	en_prot_mode();
	// Enable virtual memory for every process
	en_virt_mem();
	// Finally print success and drop into shell
	printk("Minux 0.0.1-rc1: Welcome\n");
	tty_dev_init();
}
