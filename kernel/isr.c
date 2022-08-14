#include <minux/isr.h>
#include <minux/video.h>
#include <std/string.h>
#include <std/type.h>

/*
 * External IDT loading function
 */
extern void load_idt_mnx(u32 idt_pointer_addr);

/*
 * IDT pointer and struct
 * for gates
 */
struct idt_ptr_mnx idt_ptr_mnx_st;
struct idt_entry_mnx idt_entry_mnx_st[256];

/*
 * Setting interrupt gates
 * for interrupt vector list
 * min: 0, max: 255
 */
static void interrupt_desc_opt(u8 elem, u32 bs, u16 ss, u8 attr){
	idt_entry_mnx_st[elem].bs_l = bs & 0xFFFF;
	idt_entry_mnx_st[elem].bs_h = (bs >> 16) & 0xFFFF;

	idt_entry_mnx_st[elem].ss = ss;
	idt_entry_mnx_st[elem].res = 0;
	idt_entry_mnx_st[elem].attr = attr;
}

static void set_idt(){
	idt_ptr_mnx_st.bs = (u32)&idt_entry_mnx_st;
	idt_ptr_mnx_st.lim = sizeof(struct idt_entry_mnx)*256-1;

	memset(&idt_entry_mnx_st, 0, sizeof(struct idt_entry_mnx)*256);

	interrupt_desc_opt(0, (u32)&int_elem_0, 0x08, 0x8E);
	interrupt_desc_opt(1, (u32)&int_elem_1, 0x08, 0x8E);
	interrupt_desc_opt(2, (u32)&int_elem_2, 0x08, 0x8E);
	interrupt_desc_opt(3, (u32)&int_elem_3, 0x08, 0x8E);
	interrupt_desc_opt(4, (u32)&int_elem_4, 0x08, 0x8E);
	interrupt_desc_opt(5, (u32)&int_elem_5, 0x08, 0x8E);
	interrupt_desc_opt(6, (u32)&int_elem_6, 0x08, 0x8E);
	interrupt_desc_opt(7, (u32)&int_elem_7, 0x08, 0x8E);
	interrupt_desc_opt(8, (u32)&int_elem_8, 0x08, 0x8E);
	interrupt_desc_opt(9, (u32)&int_elem_9, 0x08, 0x8E);
	interrupt_desc_opt(10, (u32)&int_elem_10, 0x08, 0x8E);
	interrupt_desc_opt(11, (u32)&int_elem_11, 0x08, 0x8E);
	interrupt_desc_opt(12, (u32)&int_elem_12, 0x08, 0x8E);
	interrupt_desc_opt(13, (u32)&int_elem_13, 0x08, 0x8E);
	interrupt_desc_opt(14, (u32)&int_elem_14, 0x08, 0x8E);
	interrupt_desc_opt(15, (u32)&int_elem_15, 0x08, 0x8E);
	interrupt_desc_opt(16, (u32)&int_elem_16, 0x08, 0x8E);
	interrupt_desc_opt(17, (u32)&int_elem_17, 0x08, 0x8E);
	interrupt_desc_opt(18, (u32)&int_elem_18, 0x08, 0x8E);
	interrupt_desc_opt(19, (u32)&int_elem_19, 0x08, 0x8E);
	interrupt_desc_opt(20, (u32)&int_elem_20, 0x08, 0x8E);
	interrupt_desc_opt(21, (u32)&int_elem_21, 0x08, 0x8E);
	interrupt_desc_opt(22, (u32)&int_elem_22, 0x08, 0x8E);
	interrupt_desc_opt(23, (u32)&int_elem_23, 0x08, 0x8E);
	interrupt_desc_opt(24, (u32)&int_elem_24, 0x08, 0x8E);
	interrupt_desc_opt(25, (u32)&int_elem_25, 0x08, 0x8E);
	interrupt_desc_opt(26, (u32)&int_elem_26, 0x08, 0x8E);
	interrupt_desc_opt(27, (u32)&int_elem_27, 0x08, 0x8E);
	interrupt_desc_opt(28, (u32)&int_elem_28, 0x08, 0x8E);
	interrupt_desc_opt(29, (u32)&int_elem_29, 0x08, 0x8E);
	interrupt_desc_opt(30, (u32)&int_elem_30, 0x08, 0x8E);
	interrupt_desc_opt(31, (u32)&int_elem_31, 0x08, 0x8E);

	load_idt_mnx((u32)&idt_ptr_mnx_st);
}

void set_idt_tbl(){
	set_idt();
}

void int_hndlr(){
	printf("minux: interrupt handler\n");
}
