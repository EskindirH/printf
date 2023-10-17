#include "main.h"
/**
 * print_unt - prints unsigned int
 * @args: number to print
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int print_unt(va_list args, char *buf, unsigned int ibuf)
{
	unsigned int input, temp, i, div;

	input = va_arg(args, unsigned int);
	temp = input;
	div = 1;
	while (temp > 9)
	{
		div *= 10;
		temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = handle_buf(buf, ((input / div) % 10) + '0', ibuf);
	}
	return (i);
}
