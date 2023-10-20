#include "main.h"
/**
 * prt_lng_unt - prints a long unsigned integer
 * @args: number to print
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int prt_lng_unt(va_list args, char *buf, unsigned int ibuf)
{
	unsigned long int input, temp, i, div;

	input = va_arg(args, unsigned long int);
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
