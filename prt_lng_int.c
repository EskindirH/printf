#include "main.h"
/**
 * prt_lng_int - prints a long integer
 * @args: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int prt_lng_int(va_list args, char *buf, unsigned int ibuf)
{
	long int input;
	unsigned long int int_in, temp, i, div, sign;

	input = va_arg(args, long int);
	sign = 0;
	if (input < 0)
	{
		int_in = input * -1;
		ibuf = handle_buf(buf, '-', ibuf);
		sign = 1;
	}
	else
	{
		int_in = input;
	}

	temp = int_in;
	div = 1;
	while (temp > 9)
	{
		div *= 10;
		temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = handle_buf(buf, ((int_in / div) % 10) + '0', ibuf);
	}
	return (i + sign);
}
