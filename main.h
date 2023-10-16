#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...);
int print_int(va_list arguments, char *buf, unsigned int ibuf);
unsigned int handle_buf(char *buf, char c, unsigned int ibuf);
int print_buf(char *buf, unsigned int nbuf);

#endif
