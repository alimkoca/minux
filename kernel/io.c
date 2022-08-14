#include <minux/io.h>
#include <std/type.h>

void outb(u16 port, u8 value){
	asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

void outw(u16 port, u16 value){
	asm volatile ("outw %1, %0" : : "dN" (port), "a" (value));
}

void outl(u16 port, u32 value){
	asm volatile ("outl %1, %0" : : "dN" (port), "a" (value));
}

u8 inb(u16 port){
	u8 ret;
	asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

u16 inw(u16 port){
	u16 ret;
	asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

u32 inl(u16 port){
	u32 ret;
	asm volatile("inl %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}
