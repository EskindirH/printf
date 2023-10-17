#include "main.h"
/**
 * id_print_func - returns the amount of identifiers.
 * @s: argument indentifier
 * @iarg: index of argument identifier.
 * Return: amount of identifiers.
 */
int id_print_func(const char *s, int iarg)
{
	print_f pr[] = {
		{"c", print_chr}, {"s", print_str}, {"i", print_int},
		{"d", print_int}, {"b", print_bin}, {"u", print_unt},
		{"x", print_hex}, {"p", print_adr}, {"%", print_mod},
		{"l", print_mod}, {"h", print_mod}, {" %", print_mod},
		{"r", print_rev}, {NULL, NULL},
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
	return (j);
}
