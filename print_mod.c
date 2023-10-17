#include "main.h"
/**
 * print_mod - prints % to stdout
 * @args: input char
 * @buf: buffer pointer
 * @ibuf: buffer index
 * Return: 1
 */
int print_mod(va_list args __attribute__((unused)), char *buf, unsigned int ibuf)
{
	handle_buf(buf, '%', ibuf);
	return (1);
}
