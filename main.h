#ifndef MAIN
#define MAIN
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct print - struct for printer functions
 * @type_arg: identifier
 * @f: pointer to a printer functions
 *
 * Description: struct that stores pointers to a
 * printer functions.
 */

typedef struct print

{
	char *type_arg;
	int (*f)(va_list, char *, unsigned int);
} print_t;


int _printf(const char *format, ...);
int print_chr(va_list arguments, char *buf, unsigned int abf);
int ev_print_func(const char *s, int index);
unsigned int handl_buf(char *buf, char c, unsigned int ibuf);

#endif
