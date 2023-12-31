#include "main.h"
/**
 * prt_str_int - prints a short integer
 * @args: input string
 * @buf: buffer pointer
 * @ibuf: buffer pointer index
 * Return: number of chars printed.
 */
int prt_srt_int(va_list args, char *buf, unsigned int ibuf)
{
	short int int_input;
	unsigned short int int_in, int_temp, i, div, isneg;

	int_input = va_arg(args, int);
	isneg = 0;
	if (int_input < 0)
	{
		int_in = int_input * -1;
		ibuf = handle_buf(buf, '-', ibuf);
		isneg = 1;
	}
	else
	{
		int_in = int_input;
	}
	int_temp = int_in;
	div = 1;
	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = handle_buf(buf, ((int_in / div) % 10) + '0', ibuf);
	}
	return (i + isneg);
}
