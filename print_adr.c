#include "main.h"

/**
 * print_adr - prints the address of an input variable
 * @args: input address.
 * @buf: buffer pointer.
 * @ibuf: index for buffer pointer
 *
 * Return: number of chars printed.
 */
int print_adr(va_list args, char *buf, unsigned int ibuf)
{
	void *add;
	long int input;
	int i, count, first_digit, sign;
	char *hexadecimal, *binary;
	char nill[] = "(nil)";

	add = (va_arg(args, void *));
	if (add == NULL)
	{
		for (i = 0; nill[i]; i++)
			ibuf = handle_buf(buf, nill[i], ibuf);
		return (6);
	}
	input = (intptr_t)add;
	sign = 0;
	if (input < 0)
	{
		input = (input * -1) - 1;
		sign = 1;
	}
	binary = malloc(sizeof(char) * (64 + 1));
	binary = decimal_to_bin(binary, input, sign, 64);
	hexadecimal = malloc(sizeof(char) * (16 + 1));
	hexadecimal = to_hex(binary, hexadecimal, 0, 16);
	ibuf = handle_buf(buf, '0', ibuf);
	ibuf = handle_buf(buf, 'x', ibuf);
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
	return (count + 2);
}
