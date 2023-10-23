#include "main.h"
/**
 * prt_num_oct - print the number in octal begining with zero
 * @args: input string
 * @buf: buffer pointer
 * @ibuf: buffer pointer index
 * Return: number of chars printed
 */
int prt_num_oct(va_list args, char *buf, unsigned int ibuf)
{
	int input, i, sign, count, first_digit;
	char *octal, *binary;

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
	ibuf = handle_buf(buf, '0', ibuf);
	binary = malloc(sizeof(char) * (32 + 1));
	binary = decimal_to_bin(binary, input, sign, 32);
	octal = malloc(sizeof(char) * (11 + 1));
	octal = to_oct(binary, octal);
	for (first_digit = i = count = 0; octal[i]; i++)
	{
		if (octal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = handle_buf(buf, octal[i], ibuf);
			count++;
		}
	}
	free(binary);
	free(octal);
	return (count + 1);
}
