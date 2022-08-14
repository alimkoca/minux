#include <minux/panic.h>
#include <minux/isr.h>
#include <minux/video.h>

void panic_mnx(struct int_stats_mnx *int_stats){
	printf("Kernel Panic, dump:\n\n");
	printf("\tds: 0x%x\n", int_stats->ds);
	printf("\teax: 0x%x\n", int_stats->eax);
	printf("\tecx: 0x%x\n", int_stats->ecx);
	printf("\tedx: 0x%x\n", int_stats->edx);
	printf("\tesp: 0x%x\n", int_stats->esp);
	printf("\tebp: 0x%x\n", int_stats->ebp);
	printf("\tesi: 0x%x\n", int_stats->esi);
	printf("\tedi: 0x%x\n", int_stats->edi);
	printf("\teip: 0x%x\n", int_stats->eip);
	printf("\tcs: 0x%x\n", int_stats->cs);
	printf("\teflags: %b\n", int_stats->eflags);
	printf("\tuesp: 0x%x (hex)\n", int_stats->uesp);
	printf("\tss: 0x%x (hex)\n", int_stats->ss);
	printf("\tint: %d\n\terrno: %d", int_stats->int_n, int_stats->errno);
	asm volatile ("cli");
	asm volatile ("hlt");
}
