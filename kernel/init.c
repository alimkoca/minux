#include <minux/init.h>
#include <minux/pro.h>
#include <minux/isr.h>
#include <minux/virt.h>
#include <minux/kernel.h>
#include <minux/tty.h>

int init_proc(){
	// Set the GDT table 
	set_gdt_tbl();
	// Set the IDT table for interrupt
	set_idt_tbl();
	// Interrupt handler for protected mode
	hndl_int_rq();
	// Enable Protected mode
	en_prot_mode();
	// Enable virtual memory
	en_virt_mem();
	// Finally print success and drop into shell
	printk("Minux 0.0.1-rc1: Welcome\n");
	tty_dev_init();
}
