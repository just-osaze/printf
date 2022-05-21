#ifndef MAIN
#define MAIN
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int _printf(const char *format, ...);
int print_chr(va_list arguments, char *buf, unsigned int abf);
int ev_print_func(const char *s, int index);
unsigned int handl_buf(char *buf, char c, unsigned int ibuf);
#endif
