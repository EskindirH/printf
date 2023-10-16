#include "main.h"
/**
 * print_buf - prints buffer
 * @buf: buffer pointer
 * @bytes: number of bytes to print.
 * Return: number of bytes printed.
 */
int print_buf(char *buf, unsigned int bytes)
{
	return (write(1, buf, bytes));
}
