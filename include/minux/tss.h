#ifndef TSS_H
#define TSS_H

#include <std/type.h>

#define TSS_SIZE 112

/*
 * TSS pointer
 */
struct tss_ptr_mnx {
	u16 limit;
	u32 base;
} __attribute__((packed));

/*
 * TSS entry for every task
 * as private or may be
 * shared for IPC
 */
struct tss_entry_mnx {
	u32 p_tss;
	u32 esp0;
	u32 ss0;
	u32 esp1;
	u32 ss1;
	u32 esp2;
	u32 ss2;
	u32 cr3;
	u32 eip;
	u32 eflags;
	u32 eax;
	u32 ecx;
	u32 edx;
	u32 ebx;
	u32 esp;
	u32 ebp;
	u32 esi;
	u32 edi;
	u32 es;
	u32 cs;
	u32 ss;
	u32 ds;
	u32 fs;
	u32 gs;
	u32 ldt;
	u16 trap;
	u16 iomap_base;
} __attribute__((packed));

#endif
