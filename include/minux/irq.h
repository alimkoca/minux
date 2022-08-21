#ifndef IRQ_H
#define IRQ_H

#include <minux/isr.h>
#include <std/type.h>

#define PIC_MASTER 0x20
#define PIC_SLAVE 0xA0
#define PIC_MASTER_COMMAND PIC_MASTER
#define PIC_MASTER_DATA PIC_MASTER+1
#define PIC_SLAVE_COMMAND PIC_SLAVE
#define PIC_SLAVE_DATA PIC_SLAVE+1

#define PIC_EOI 0x20

#define ICW1 0x11
#define ICW4 0x01

#define IRQ0 32
#define IRQ1 33
#define IRQ2 34
#define IRQ3 35
#define IRQ4 36
#define IRQ5 37
#define IRQ6 38
#define IRQ7 39
#define IRQ8 40
#define IRQ9 41
#define IRQ10 42
#define IRQ11 43
#define IRQ12 44
#define IRQ13 45
#define IRQ14 46
#define IRQ15 47

extern void irq_elem_0();
extern void irq_elem_1();
extern void irq_elem_2();
extern void irq_elem_3();
extern void irq_elem_4();
extern void irq_elem_5();
extern void irq_elem_6();
extern void irq_elem_7();
extern void irq_elem_8();
extern void irq_elem_9();
extern void irq_elem_10();
extern void irq_elem_11();
extern void irq_elem_12();
extern void irq_elem_13();
extern void irq_elem_14();
extern void irq_elem_15();

void irq_set_interrupts();

typedef void (*irq_mnx)(struct int_stats_mnx irq_stats);
void set_irq_hndlr(u8 n, irq_mnx hndlr);

#endif
