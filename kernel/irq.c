#include <minux/irq.h>
#include <minux/isr.h>
#include <minux/io.h>
#include <minux/video.h>
#include <std/type.h>

/*
 * This is remapping of irq table for
 * mapping interrupts to interrupt
 * descriptor table
 */
static void irq_remap_table(){
        // Sending ICW1 to master and slave
        outb(PIC_MASTER_COMMAND, ICW1);
        outb(PIC_SLAVE_COMMAND, ICW1);

        // Remap master and slave
        outb(PIC_MASTER_DATA, 0x20);
        outb(PIC_SLAVE_DATA, 0x28);

        // Connecting with slave
        outb(PIC_MASTER_DATA, 0x04);
        outb(PIC_SLAVE_DATA, 0x02);

        // Send ICW4 to data register of
        // master and slave
        outb(PIC_MASTER_DATA, ICW4);
        outb(PIC_SLAVE_DATA, ICW4);

        // Enable interrupt requests
        outb(PIC_MASTER_DATA, 0x00);
        outb(PIC_MASTER_DATA, 0x00);
}

void irq_set_interrupts(){
        irq_remap_table();

        interrupt_desc_opt(32, (u32)irq_elem_0, 0x08, 0x8e);
        interrupt_desc_opt(33, (u32)irq_elem_1, 0x08, 0x8e);
        interrupt_desc_opt(34, (u32)irq_elem_2, 0x08, 0x8e);
        interrupt_desc_opt(35, (u32)irq_elem_3, 0x08, 0x8e);
        interrupt_desc_opt(36, (u32)irq_elem_4, 0x08, 0x8e);
        interrupt_desc_opt(37, (u32)irq_elem_5, 0x08, 0x8e);
        interrupt_desc_opt(38, (u32)irq_elem_6, 0x08, 0x8e);
        interrupt_desc_opt(39, (u32)irq_elem_7, 0x08, 0x8e);
        interrupt_desc_opt(40, (u32)irq_elem_8, 0x08, 0x8e);
        interrupt_desc_opt(41, (u32)irq_elem_9, 0x08, 0x8e);
        interrupt_desc_opt(42, (u32)irq_elem_10, 0x08, 0x8e);
        interrupt_desc_opt(43, (u32)irq_elem_11, 0x08, 0x8e);
        interrupt_desc_opt(44, (u32)irq_elem_12, 0x08, 0x8e);
        interrupt_desc_opt(45, (u32)irq_elem_13, 0x08, 0x8e);
        interrupt_desc_opt(46, (u32)irq_elem_14, 0x08, 0x8e);
        interrupt_desc_opt(47, (u32)irq_elem_15, 0x08, 0x8e);        
}

int irq_hndlr(struct int_stats_mnx irq_stats){
	printf("Hello, world!");
}
