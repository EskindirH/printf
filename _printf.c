#include "main.h"
/**
 * _printf - produces output according to a format.
 * @format: a character string.
 *
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
	unsigned int char_len = 0, i = 0;
	va_list arguments;

	if (!format || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);

	va_start(arguments, format);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] != '%')
		{
			write(1, format + i, 1);
			char_len++;
		}
		else
		{
			if (format[i + 1] == '\0')
				return (-1);
			if (format[i + 1] == '%')
			{
				write(1, format + (i + 1), 1);
				char_len++;
			}
			else if (format[i + 1] == 'c')
			{
				char ch = va_arg(arguments, int);

				write(1, &ch, 1);
				char_len++;
			}
			else if (format[i + 1] == 's')
			{
				char *str = va_arg(arguments, char*);
				int str_len = strlen(str);

				write(1, str, str_len);
				char_len += str_len;
			}
		i++;
		}
	}
	va_end(arguments);
	return (char_len);
}

