#include "main.h"
/**
 * print_str - write a string to stdout
 * @args: input string
 * @buf: buffer pointer
 * @ibuf: buffer pointer index
 * Return: 1 for sccess
 */
int print_str(va_list args, char *buf, unsigned int ibuf)
{
	char *str;
	unsigned int i;
	char nill[] = "(null)";

	str = va_arg(args, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			ibuf = handle_buf(buf, nill[i], ibuf);
		return (6);
	}
	for (i = 0; str[i]; i++)
		ibuf = handle_buf(buf, str[i], ibuf);
	return (1);
}
