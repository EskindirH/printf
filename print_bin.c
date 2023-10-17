#include "main.h"
/**
 * print_bin - prints binary
 * @args: input string
 * @buf: buffer pointer
 * @ibuf: buffer pointer index
 * Return: number of chars printed.
 */
int print_bin(va_list args, char *buf, unsigned int ibuf)
{
	int count, input, i, sign, first_one;
	char *binary;

	input = va_arg(args, int);
	sign = 0;
	if (input == 0)
	{
		ibuf = handle_buf(buf, '0', ibuf);
		return (1);
	}
	if (input < 0)
	{
		input = (input * -1) - 1;
		sign = 1;
	}
	binary = malloc(sizeof(char) * (32 + 1));
	binary = decimal_to_bin(binary, input, sign, 32);
	first_one = 0;
	for (count = i = 0; binary[i]; i++)
	{
		if (first_one == 0 && binary[i] == '1')
			first_one = 1;
		if (first_one == 1)
		{
			ibuf = handle_buf(buf, binary[i], ibuf);
			count++;
		}
	}
	free(binary);
	return (count);
}
