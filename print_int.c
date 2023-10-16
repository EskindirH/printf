#include "main.h"

/**
 * print_int - prints an integer
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: buffer pointer index
 * Return: nummber of characters printed.
 */
int print_int(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input;
	unsigned int i, has_sign, input, temp, div;

	int_input = va_arg(arguments, int);
	has_sign = 0;
	if (int_input < 0)
	{
		input = int_input * -1;
		ibuf = handle_buf(buf, '-', ibuf);
		has_sign = 1;
	}
	else
	{
		input = int_input;
	}
	temp = input;
	div = 1;

	while (temp > 9)
	{
		div *= 10;
		temp /= 10;
	}

	for (i = 0; div > 0; div /= 10, i++)
		ibuf = handle_buf(buf, ((input / div) % 10) + '0', ibuf);
	return (i + has_sign);
}
