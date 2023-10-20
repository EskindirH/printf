#include "main.h"
/**
 * prt_lng_upx - prints a long decimal in hexadecimal
 * @args: The character to print
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int prt_lng_upx(va_list args, char *buf, unsigned int ibuf)
{
	long int input, i, sign, count, first_digit;
	char *hexadecimal, *binary;

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
	hexadecimal = malloc(sizeof(char) * (16 + 1));
	hexadecimal = to_hex(binary, hexadecimal, 1, 16);
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
