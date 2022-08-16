#ifndef IRQ_H
#define IRQ_H

#define PIC_MASTER 0x20
#define PIC_SLAVE 0xA0
#define PIC_MASTER_COMMAND PIC_MASTER
#define PIC_MASTER_DATA PIC_MASTER+1
#define PIC_SLAVE_COMMAND PIC_SLAVE
#define PIC_SLAVE_DATA PIC_SLAVE+1

#define PIC_EOI 0x20

#define ICW1 0x11
#define ICW4 0x01

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

#endif
