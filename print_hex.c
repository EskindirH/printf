#include "main.h"
/**
 * print_hex - prints a decimal in hexadecimal
 * @args: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int print_hex(va_list args, char *buf, unsigned int ibuf)
{
	int input, i, sign, count, first_digit;
	char *hexadecimal, *binary;

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
	hexadecimal = malloc(sizeof(char) * (8 + 1));
	hexadecimal = to_hex(binary, hexadecimal, 0, 8);
	for (first_digit = i = count = 0; hexadecimal[i]; i++)
	{
		if (hexadecimal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = handle_buf(buf, hexadecimal[i], ibuf);
			count++;
		}
	}
	free(binary);
	free(hexadecimal);
	return (count);
}
