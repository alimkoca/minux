#include <minux/timer.h>
#include <minux/video.h>
#include <minux/isr.h>
#include <minux/irq.h>
#include <minux/io.h>
#include <std/type.h>

u64 tick = 0;

static void timer_int(struct int_stats_mnx irq_stats)
{
	tick++;
	printf("%d\n", tick);
}

void init_timer_int(u32 hz)
{
	set_irq_hndlr(IRQ0, &timer_int);

	u32 div = 1193180 / hz;

	outb(0x43, 0x36);

	u8 low_freq = div & 0xff;
	u8 hi_freq = (div >> 8) & 0xff;

	outb(0x40, low_freq);
	outb(0x40, hi_freq);
}
