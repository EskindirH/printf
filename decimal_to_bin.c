#include "main.h"

/**
 * decimal_to_bin - prints decimal in binary
 * @binary: pointer to binary
 * @input: input number
 * @sign: if input number is negative
 * @limit: size of the binary
 * Return: number of chars printed.
 */
char *decimal_to_bin(char *binary, long int input, int sign, int limit)
{
	int i;

	for (i = 0; i < limit; i++)
		binary[i] = '0';
	binary[limit] = '\0';
	for (i = limit - 1; input > 1; i--)
	{
		if (input == 2)
			binary[i] = '0';
		else
			binary[i] = (input % 2) + '0';
		input /= 2;
	}
	if (input != 0)
		binary[i] = '1';
	if (sign)
	{
		for (i = 0; binary[i]; i++)
			if (binary[i] == '0')
				binary[i] = '1';
			else
				binary[i] = '0';
	}
	return (binary);
}
