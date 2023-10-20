#include "main.h"
/**
 * prt_lng_oct - prints long decimal number in octal
 * @args: input number
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int prt_lng_oct(va_list args, char *buf, unsigned int ibuf)
{
	long int input, i, sign, count, first_digit;
	char *octal, *binary;

	input = va_arg(args, long int);
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

	binary = malloc(sizeof(char) * (64 + 1));
	binary = decimal_to_bin(binary, input, sign, 64);
	octal = malloc(sizeof(char) * (22 + 1));
	octal = lng_oct(binary, octal);
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
	return (count);
}
