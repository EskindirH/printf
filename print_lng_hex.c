#include "main.h"
/**
 * prt_lng_hex - prints a long decimal in hexadecimal
 * @args: input string
 * @buf: buffer pointer
 * @ibuf: buffer pointer index
 * Return: number of chars printed
 */
int prt_lng_hex(va_list args, char *buf, unsigned int ibuf)
{
	long int input, i, sign, count, first_digit;
	char *hex, *binary;

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
	hex = malloc(sizeof(char) * (16 + 1));
	hex = to_hex(binary, hex, 0, 16);
	for (first_digit = i = count = 0; hex[i]; i++)
	{
		if (hex[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = handle_buf(buf, hex[i], ibuf);
			count++;
		}
	}
	free(binary);
	free(hex);
	return (count);
}
