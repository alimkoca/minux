#ifndef ISR_H
#define ISR_H

#include <std/type.h>

/*
 * IDT pointer points
 * to IDT and using to
 * load IDT using lidt
 * instruction
 */
struct idt_ptr_mnx {
	u16 lim;
	u32 bs;
} __attribute__((packed));

/*
 * IDT entry for IDT
 * table, loading using pointer
 * and lidt instruction
 */
struct idt_entry_mnx {
	u16 bs_l;
	u16 ss;
	u8 res;
	u8 attr;
	u16 bs_h;
} __attribute__((packed));

struct int_stats_mnx {
	u32 ds; // Data segment
	u32 edi, esi, ebp, esp, ebx, edx, ecx, eax; // All general purpose registers
	u32 int_n, errno; // Errno and int no
	u32 eip, cs, eflags, uesp, ss; // Others...
} __attribute__((packed));

/*
 * IDT set table and vector
 */
static void set_idt();
void set_idt_tbl();

/*
 * Setting interrupt gates
 * for interrupt vector list
 * min: 0, max: 255
 */
void interrupt_desc_opt(u8 elem, u32 bs, u16 ss, u8 attr);

extern void int_elem_0();
extern void int_elem_1();
extern void int_elem_2();
extern void int_elem_3();
extern void int_elem_4();
extern void int_elem_5();
extern void int_elem_6();
extern void int_elem_7();
extern void int_elem_8();
extern void int_elem_9();
extern void int_elem_10();
extern void int_elem_11();
extern void int_elem_12();
extern void int_elem_13();
extern void int_elem_14();
extern void int_elem_15();
extern void int_elem_16();
extern void int_elem_17();
extern void int_elem_18();
extern void int_elem_19();
extern void int_elem_20();
extern void int_elem_20();
extern void int_elem_21();
extern void int_elem_22();
extern void int_elem_23();
extern void int_elem_24();
extern void int_elem_25();
extern void int_elem_26();
extern void int_elem_27();
extern void int_elem_28();
extern void int_elem_29();
extern void int_elem_30();
extern void int_elem_31();

#endif
