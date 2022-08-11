#ifndef PROTECT_H
#define PROTECT_H

#include <minux/tss.h>
#include <std/type.h>

/*
 * Segment access bytes
 * for easier understanding
 * the kernel code
 */
#define NULL_S 0x00
#define KERNEL_CODE 0x9A
#define KERNEL_DATA 0x92
#define USER_CODE 0xFA
#define USER_DATA 0xF2
#define TSS_SEG 0x89

/*
 * Segment offsets for
 * accessing
 */
#define NULL_OFFSET 0
#define KERNEL_CODE_OFFSET 0x0008
#define KERNEL_DATA_OFFSET 0x0010
#define USER_CODE_OFFSET 0x0018
#define USER_DATA_OFFSET 0x0020
#define TSS_OFFSET 0x0028

/*
 * Limits for every segment
 */
#define LIMIT 0xFFFFFFFF

/* 
 * GDT pointer that points
 * to GDT entries, e.g
 * base and limits.
 */
struct gdt_ptr_mnx {
	u16 limit;
	u32 bs;
} __attribute__((packed));

/*
 * GDT entry for gate
 * descriptors to set
 * segments
 */
struct gdt_entry_mnx {
	u16 limit;
	u16 bs_l;
	u8 bs_m;
	u8 acc;
	u8 gran;
	u8 bs_h;
} __attribute__((packed));

/*
 * Enable protected mode
 */
extern void en_prot_mode();

/*
 * GDT setting segment
 * descriptors for segments
 */
static void segment_desc_opt(u32 elem, u32 bs, u16 limit, u8 acc, u8 flags);

/*
 * GDT set table
 */
static void set_gdt();
void set_gdt_tbl();

#endif
