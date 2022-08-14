#include <minux/video.h>
#include <minux/io.h>
#include <std/type.h>
#include <std/string.h>
#include <std/stdarg.h>

static u16 *mem = (u16*)0xB8000;
static u16 x = 0;
static u16 y = 0;
static u8 attr = 0;
static u8 bg = 0;
static u8 fg = 15;

static void cursor_manage_mem(){
	u16 cursor = y*80+x;
	outb(0x3d4, 14);
	outb(0x3d5, cursor >> 8);
	outb(0x3d4, 15);
	outb(0x3d5, cursor);
}

static void cursor_manage_scroll(){
	u8 attr = (0 << 4) | (15 & 0x0f);
	u16 blank = 0x20 | (attr << 8);

	if (y >= 25){
		int i;

		for (i = 0; i < 24*80; i++)
			mem[i] = mem[i+80];

		for (i = 24*80; i < 25*80; i++)
			mem[i] = blank;

		y = 24;
	}
}

void putchar(char c){
	attr = (bg << 4) | (fg & 0x0f);
	u16 att_shft = attr << 8;
	u16 *temp_location;

	if (c == 0x08 && x)
		x--;

	else if (c == '\t')
		x = (x+8) & ~(8-1);

	else if (c == '\r')
		x = 0;

	else if (c == '\n'){
		x = 0;
		y++;
	}

	else if (c >= ' '){
		temp_location = mem + (y*80+x);
		*temp_location = c | att_shft;
		x++;
	}

	if (x >= 80){
		x = 0;
		y++;
	}

	cursor_manage_scroll();
	cursor_manage_mem();
}

void print(char *c){
	while (*c)
		putchar(*c++);
}

int printf(char *c, ...){
	int x;
	char *y;
	va_list arg_list;
	va_start(arg_list, c);

	while(*c){
		if (*c == '%'){
			c++;
			switch (*c){
			case 'd':
				x = va_arg(arg_list, int);
				print(strconv(x, 10));
				break;
			case 's':
				y = va_arg(arg_list, char*);
				print(y);
				break;
			case 'x':
				x = va_arg(arg_list, int);
				print(strconv(x, 16));
				break;
			case 'b':
				x = va_arg(arg_list, int);
				print(strconv(x, 2));
				break;
			default:
				break;
			}
		} 
		else {
			putchar(*c);
		}
	c++;
	}
}

void background_initialize(){
	u8 attr = (bg << 4) | (fg & 0x0f);
	u16 blank = 0x20 | (attr << 8);

	for (int i = 0; x < 25*80; x++){
		mem[i] = blank;
	}

	x = 0;
	y = 0;
	cursor_manage_mem();
}

void background_manage(u8 bg_arg){
	bg = bg_arg;
}

void foreground_manage(u8 fg_arg){
	fg = fg_arg;
}
