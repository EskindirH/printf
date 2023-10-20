#include "main.h"
/**
 * prt_pls_int - print integer with plus sign
 * @args: input string
 * @buf: buffer pointer
 * @ibuf: buffer pointer index
 * Return: number of chars printed
 */
int prt_pls_int(va_list args, char *buf, unsigned int ibuf)
{
	int input;
	unsigned int int_in, temp, i, div;

	input = va_arg(args, int);
	if (input < 0)
	{
		int_in = input * -1;
		ibuf = handle_buf(buf, '-', ibuf);
	}
	else
	{
		int_in = input;
		ibuf = handle_buf(buf, '+', ibuf);
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
	return (i + 1);
}
