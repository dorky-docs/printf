#include "main.h"
/**
 * print_binary - prints binary
 * @types: Arguments
 * @buffer: array of buffer
 * @flags: active flags
 * @width: to get the width
 * @precision: precision
 * @size: The size
 * Return: Binary
 */
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	unsigned int r[32];
	unsigned int x, y, b, all;
	int c;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(width);
	UNUSED(size);

	x = va_arg(types, unsigned int);
	y = 2147483647;
	r[0] = x / y;

	for (b = 1; b < 32; b++)
	{
		y /= 2;
		r[b] = (x / y) % 2;
	}
	for (b = 0, all = 0, c = 0; b < 32; b++)
	{
		all += r[b];
		if (all || b == 31)
		{
			char d = '0' + r[b];

			write(1, &d, 1);
			c++;
		}
	}
	return (c);
}
