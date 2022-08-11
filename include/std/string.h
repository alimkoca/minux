#ifndef STRING_H
#define STRING_H

#include <std/type.h>

#define NULL (void*)0

typedef u16 size_t;

void *memset(void *a, int b, u32 c);
int memcmp(const void *a, const void *b, size_t n);
size_t strlen(const char *a);
bool isspace(char a);
int strcat(const void *a, const void *b);

#endif
