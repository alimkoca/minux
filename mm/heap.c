#include <minux/heap.h>
#include <minux/vmem.h>
#include <std/type.h>

u16 first_free_page()
{
	for (int a = 0; a < 1024; a++) {
		for (int b = 0; b < 1024; b++) {
			if (page_dir_entry_mnx[a][b] & (1 << 0))
			       return &(page_dir_entry_mnx[a][b]);
		}
	}
}
