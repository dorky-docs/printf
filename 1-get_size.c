#include "main.h"
/**
 * get_size - Size calculation
 * @format: String formatted to print argument
 * @i: Argument list
 * Return: Size
 */
int get_size(const char *format, int *i)
{
	int cu_i = *i + 1;
	int size = 0;

	if (format[cu_i] == 'l')
		size = S_LONG;
	else if (format[cu_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = cu_i - 1;
	else
		*i = cu_i;
	return (size);
}
