#include "main.h"

/**
 * print_func - Selects the correct function to perform the operation.
 * @g: argument identifier
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
		{" %", print_mod}, {"li", prt_lng_int},
		{"ld", prt_lng_int}, {"lu", prt_lng_unt},
		{"lo", prt_lng_oct}, {"lx", prt_lng_hex},
		{"lX", prt_lng_upx}, {"hi", prt_srt_int},
		{"hd", prt_srt_int}, {"hu", prt_srt_unt},
		{"ho", prt_srt_oct}, {"hx", prt_srt_hex},
		{"hX", prt_srt_upx}, {"#i", print_int},
		{"#d", print_int}, {" +i", prt_pls_int},
		{" +d", prt_pls_int}, {"+ i", prt_pls_int},
		{"#u", print_unt}, {"+i", prt_pls_int},
		{"+d", prt_pls_int}, {"+u", print_unt},
		{"+o", print_oct}, {"+x", print_hex},
		{"+X", print_upx}, {" i", prt_srt_int},
		{" d", prt_srt_int}, {" u", print_unt},
		{" o", print_oct}, {" x", print_hex},
		{" X", print_upx}, {"R", print_rot},
		{"+ d", prt_pls_int}, {"#o", prt_num_oct},
		{"#x", prt_num_hex}, {"#X", prt_num_upx},
		{"S", print_usr}, {"o", print_oct},
		{"X", print_upx}, {NULL, NULL},
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
