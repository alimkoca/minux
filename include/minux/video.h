#ifndef VIDEO_H
#define VIDEO_H

#include <std/type.h>

void putchar(char c);
void print(char *c);
int printf(char *c, ...);
void background_initialize();
void background_manage(u8 bg_arg);
void foreground_manage(u8 fg_arg);

#endif
