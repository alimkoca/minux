#include <minux/syscall.h>
#include <minux/isr.h>
#include <std/type.h>

int syscall_hndlr(struct int_stats_mnx *int_stats)
{
	int syscall_return = 0;

	/*if (int_stats->int_n == 0x80) {
		switch(int_stats->eax) {
		case 0:
			SYSCALL_READ(&int_stats);
			syscall_return = 0;
			break;
		case 1:
			SYSCALL_WRITE(&int_stats);
			syscall_return = 1;
			break;
		case 2:
			SYSCALL_OPEN(&int_stats);
			syscall_return = 2;
			break;
		case 3:
			SYSCALL_EXEC(&int_stats);
			syscall_return = 3;
			break;
		default:
			syscall_return = -1;
		}
	}*/

	return syscall_return;
}
