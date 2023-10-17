#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/**
 * struct print - struct for printer functions
 * @type_arg: identifier
 * @fp: function pointer to print functions
 */
typedef struct print
{
	char *type_arg;
	int (*f)(va_list, char*, unsigned int);
} print_f;

int _printf(const char *format, ...);
int (*print_func(const char *s, int iarg))(va_list, char *, unsigned int);
int id_print_func(const char *s, int iarg);
int print_int(va_list arguments, char *buf, unsigned int ibuf);
int print_chr(va_list arguments, char *buf, unsigned int ibuf);
int print_str(va_list arguments, char *buf, unsigned int ibuf);
int print_bin(va_list arguments, char *buf, unsigned int ibuf);
int print_unt(va_list arguments, char *buf, unsigned int ibuf);
int print_hex(va_list arguments, char *buf, unsigned int ibuf);
int print_adr(va_list arguments, char *buf, unsigned int ibuf);
int print_rev(va_list arguments, char *buf, unsigned int ibuf);
int print_mod(va_list __attribute__((unused)), char *buf, unsigned int ibuf);
char *decimal_to_bin(char *binary, long int input, int sign, int limit);
char *to_hex(char *bnr, char *hex, int isupp, int limit);
unsigned int handle_buf(char *buf, char c, unsigned int ibuf);
int print_buf(char *buf, unsigned int nbuf);

#endif
