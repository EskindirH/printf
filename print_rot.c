#include "main.h"
/**
 * print_rot - prints the rot13'ed string
 * @args: input string
 * @buf: buffer pointer
 * @ibuf: buffer pointer index
 * Return: number of chars printed
 */
int print_rot(va_list args, char *buf, unsigned int ibuf)
{
	char al[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str;
	unsigned int i, j, k;
	char nill[] = "(nill)";

	str = va_arg(args, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			ibuf = handle_buf(buf, nill[i], ibuf);
		return (6);
	}
	for (i = 0; str[i]; i++)
	{
		for (k = j = 0; al[j]; j++)
		{
			if (str[i] == al[i])
			{
				k = 1;
				ibuf = handle_buf(buf, rot[j], ibuf);
				break;
			}
		}
		if (k == 0)
			ibuf = handle_buf(buf, str[i], ibuf);
	}
	return (i);
}
