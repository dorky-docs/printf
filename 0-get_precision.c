#include "main.h"
/**
 * get_precision - Precision calculation
 * @format: String formatted to print arguments
 * @i: Arguments list to be printed
 * @list: Argument list
 * Return: Precision
 */
int get_precision(const char *format, int *i, va_list list)
{
	int cu_i = *i + 1;
	int precision = -1;

	if (format[cu_i] != '.')
		return (precision);
	precision = 0;

	for (cu_i += 1; format[cu_i] != '\0'; cu_i++)
	{
		if (is_digit(format[cu_i]))
		{
			precision *= 10;
			precision += format[cu_i] - '0';
		}
		else if (format[cu_i] == '*')
		{
			cu_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = cu_i - 1;
	return (precision);
}
