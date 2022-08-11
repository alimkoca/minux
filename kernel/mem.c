#include <minux/mem.h>
#include <minux/tss.h>
#include <std/type.h>

/*
 * Load GDT table via lgdt [gdt_ptr]
 * instruction.
 */
extern void load_gdt_mnx(u32 gdt_pointer_addr);

struct gdt_ptr_mnx gdt_ptr_mnx_st;
struct gdt_entry_mnx gdt_entry_mnx_st[6];
struct tss_entry_mnx tss_entry_mnx_st;

// minux/mem.h
static void segment_desc_opt(u32 elem, u32 bs, u16 limit, u8 acc, u8 flags){
	gdt_entry_mnx_st[elem].bs_l = (bs & 0XFFFF);
	gdt_entry_mnx_st[elem].bs_m = (bs >> 16) & 0xFF;
	gdt_entry_mnx_st[elem].bs_h = (bs >> 24) & 0xFF;
	gdt_entry_mnx_st[elem].limit = (limit & 0xFFFF);
	gdt_entry_mnx_st[elem].gran = (limit >> 16) & 0x0F;
	gdt_entry_mnx_st[elem].gran |= (flags << 4) & 0xF0;
	gdt_entry_mnx_st[elem].acc = acc;
}

// minux/mem.h
static void set_gdt(){
	gdt_ptr_mnx_st.limit = (sizeof(gdt_entry_mnx_st)*6)-1;
	gdt_ptr_mnx_st.bs = (u32)&gdt_entry_mnx_st;

	segment_desc_opt(0, 0, (u16)LIMIT, NULL_S, 0x0);
	segment_desc_opt(1, 0, (u16)LIMIT, KERNEL_CODE, 0xC);
	segment_desc_opt(2, 0, (u16)LIMIT, KERNEL_DATA, 0xC);
	segment_desc_opt(3, 0, (u16)LIMIT, USER_CODE, 0xC);
	segment_desc_opt(4, 0, (u16)LIMIT, USER_DATA, 0xC);
	segment_desc_opt(5, (u32)&tss_entry_mnx_st, (u8)TSS_SIZE, TSS_SEG, 0x0);

	load_gdt_mnx((u32)&gdt_ptr_mnx_st);
}

void set_gdt_tbl(){
	set_gdt();
}
