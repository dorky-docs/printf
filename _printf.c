#include "main.h"
#include <stdarg.h>
/**
 * _printf - A function that prints according to a format
 * @format: format to loop through
 * Return: Characters printed
 */
int _printf(const char *format, ...)
{
	int j, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list my_args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(my_args, format);

	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '%')
		{
			buffer[buff_ind++] = format[j];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &j);
			width = get_width(format, &j, my_args);
			precision = get_precision(format, &j, my_args);
			size = get_size(format, &j);
			++j;
			printed = handle_print(format, &j, my_args, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(my_args);
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
