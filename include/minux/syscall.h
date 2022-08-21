#ifndef SYSCALL_H
#define SYSCALL_H

#include <minux/isr.h>
#include <std/type.h>

int syscall_hndlr(struct int_stats_mnx *int_stats);

#endif
