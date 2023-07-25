#include "main.h"
/**
 * get_width - Width calculation
 * @format: String formatted to print arguments
 * @i: Argument list to be printed
 * @list: Argument list
 * Return: Width
 */
int get_width(const char *format, int *i, va_list list)
{
	int cu_i;
	int width = 0;

	for (cu_i = *i - 1; format[cu_i] != '\0'; cu_i++)
	{
		if (is_digit(format[cu_i]))
		{
			width *= 10;
			width = format[cu_i] - '0';
		}
		else if (format[cu_i] == '*')
		{
			cu_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = cu_i - 1;
	return (width);
}
