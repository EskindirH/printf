#include "main.h"
/**
 * _printf - produces output according to a format.
 * @format: a character string.
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
	unsigned int char_len = 0, i = 0, ibuf = 0;
	int (*func)(va_list, char *, unsigned int);
	char *buffer;
	va_list args;

	va_start(args, format), buffer = malloc(sizeof(char) * 1024);
	if (!format || (format[i] == '%' && !format[i + 1]) || !buffer)
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] != '%')
		{
			if (format[i + 1] == '\0')
			{
				print_buf(buffer, ibuf), free(buffer), va_end(args);
				return (-1);
			}
			else
			{
				func = print_func(format, i + 1);
				if (func == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					handle_buf(buffer, format[i], ibuf), char_len++, i--;
				}
				else
				{
					char_len += func(args, buffer, ibuf);
					i += id_print_func(format, i + 1);
				}
			} i++;
		}
		else
			handle_buf(buffer, format[i], ibuf), char_len++;
		for (ibuf = char_len; ibuf > 1024; ibuf -= 1024)
			;
	}
	print_buf(buffer, ibuf), free(buffer), va_end(args);
	return (char_len);
}
