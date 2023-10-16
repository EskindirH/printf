#include "main.h"

/**
 * handle_buf - concatenates the buffer characters.
 * @buf: buffer pointer
 * @c: character to concat
 * @ibuf: buffer index
 *
 * Return: buffer index
 */
unsigned int handle_buf(char *buf, char c, unsigned int ibuf)
{
	if (ibuf == 1024)
	{
		print_buf(buf, ibuf);
		ibuf = 0;
	}
	buf[ibuf] = c;
	ibuf++;
	return (ibuf);
}
