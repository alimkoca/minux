#include <minux/video.h>
#include <minux/vmem.h>
#include <std/type.h>

u32 page_gdir_entry_mnx[1024] __attribute__((aligned(4096)));
u32 page_dir_entry_mnx[1024] __attribute__((aligned(4096)));
u32 page_tab_entry_mnx[1024] __attribute__((aligned(4096)));

static void set_page_dir(){
	for (u32 i = 0; i < 1024; i++){
		page_dir_entry_mnx[i] = 0x00000002;
	}
}

static void set_page_tab(){
	for (u32 i = 0; i < 1024; i++){
		page_tab_entry_mnx[i] = (i * 0x1000) | 3;
	}
}

void bit32_pg_enable(){
	set_page_dir();
	set_page_tab();
	page_dir_entry_mnx[0] = ((u32)page_tab_entry_mnx) | 3;
	en_virt_mem((u32)&page_dir_entry_mnx);
}
