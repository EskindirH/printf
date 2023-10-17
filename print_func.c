#include "main.h"

/**
 * print_func - Selects the correct function to perform the operation.
 * @c: argument identifier
 * @iarg: argument identifier index
 * Return: pointer to function.
 */
int (*print_func(const char *s, int iarg))(va_list, char *, unsigned int)
{
	print_f pr[] = {
		{"c", print_chr}, {"s", print_str},
		{"i", print_int}, {"d", print_int},
		{"b", print_bin}, {"u", print_unt},
		{"x", print_hex}, {"p", print_adr},
		{"%", print_mod}, {"l", print_mod},
		{"h", print_mod}, {"r", print_rev},
		{" %", print_mod}, {NULL, NULL},
	};
	int i = 0, j = 0, first_index;

	first_index = iarg;
	while (pr[i].type_arg)
	{
		if (s[iarg] == pr[i].type_arg[j])
		{
			if (pr[i].type_arg[j + 1] != '\0')
				iarg++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			iarg = first_index;
		}
	}
	return (pr[i].f);
}
