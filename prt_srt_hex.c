#include "main.h"
/**
 * prt_srt_hex - prints a short decimal in hexadecimal
 * @args: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int prt_srt_hex(va_list args, char *buf, unsigned int ibuf)
{
	short int input, i, sign, count, first_digit;
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

	binary = malloc(sizeof(char) * (16 + 1));
	binary = decimal_to_bin(binary, input, sign, 16);
	hexadecimal = malloc(sizeof(char) * (4 + 1));
	hexadecimal = to_hex(binary, hexadecimal, 0, 4);
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
