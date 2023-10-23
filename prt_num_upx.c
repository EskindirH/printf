#include "main.h"
/**
 * prt_num_upx - prints number in uppercase hex
 * @args: input string
 * @buf: buffer pointer
 * @ibuf: buffer pointer index
 * Return: number of chars printed
 */
int prt_num_upx(va_list args, char *buf, unsigned int ibuf)
{
	int input, i, sign, count, first_digit;
	char *hex, *binary;

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
	ibuf = handle_buf(buf, 'X', ibuf);
	binary = malloc(sizeof(char) * (32 + 1));
	binary = decimal_to_bin(binary, input, sign, 32);
	hex = malloc(sizeof(char) * (8 + 1));
	hex = to_hex(binary, hex, 1, 8);
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
	return (count + 2);
}
