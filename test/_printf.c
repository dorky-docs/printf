#include "main.h"
#include <stdarg.h>
/**
 * _printf - A function that prints according to a format
 * @format: format to loop through
 * Return: Characters printed
 */
void print_buffer(char buffer[], int *buff_ind)

int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list lists;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(lists, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, lists);
			precision = get_precision(format, &i, lists);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, lists, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);
	va_end(lists);
	return (printed_chars);
}
/**
 * print_buffer - Prints the contents of the existing  buffer
 * @buffer: an array of characters
 * @buff_ind:to keep track of characters printed 
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
