#ifndef HEAP_H
#define HEAP_H

#include <std/type.h>

/*
 * 0: Kernel, default usage
 * 1: Kernel, atomic
 * 2: User, only use in userspace
 */
#define GFP_KERNEL 0
#define GFP_ATOMIC 1
#define GFP_USER 2

/*
 * Will be used free-list
 * for demo :d
 */
struct memory_block_mnx {
	u16 *memory;
	bool isfree;
	struct memory_block_mnx *memblock;
};

/*
 * NOTE-1: Specific flags written as
 * big characters like below.
 *
 * NOTE-2: If you pass a TYPE value 
 * greater than 2, will give
 * error and return -ENOFLAGS
 */
u16 *malloc(size_t size);
u16 *kmalloc(size_t size, u8 TYPE);
u16 *brk(u16 memaddr);

u16 first_free_page();

#endif
