#include <minux/init.h>

/* 
 * This is where our story starts again...
 */
int main(){
	/*
	 * First we need to setup GDT, IDT and Interrupt handler,
	 * then enter to protected mode, finally enable virtual
	 * memory.
	 */
	init_proc();
}
