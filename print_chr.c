#include "main.h"
/**
 * print_chr - write character to stdout
 * @args: input char
 * @buf: buffer pointer
 * @ibuf: buffer pointer index
 * Return: 1
 */
int print_chr(va_list args, char *buf, unsigned int ibuf)
{
	char c;

	c = va_arg(args, int);
	handle_buf(buf, c, ibuf);
	return (1);
}
