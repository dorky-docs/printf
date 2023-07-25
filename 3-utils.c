#include "main.h"
/**
 * is_printable - Checks if character is printable
 * @k: Character to be checked
 * Return: 1 if printable and 0 if otherwise
 */
int is_printable(char k)
{
	if (k >= 32 && k <= 127)
		return (1);
	else
		return (0);
}
/**
 * append_hexa_code - Appends ASCII in hexacode
 * @buffer: Character array
 * @i: Appending index
 * @Ascii_code: ASCII code
 * Return: Always 3 (Success)
 */
int append_hexa_code(char Ascii_code, char buffer[], int i)
{
	char set[] = "0123456789ABCDEF";

	if (Ascii_code < 0)
		Ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = set[Ascii_code / 16];
	buffer[i] = set[Ascii_code % 16];
	return (3);
}
/**
 * is_digit - Checks if character is a digit
 * @k: Character to be checked
 * Return: 1 if digit and 0 if otherwise
 */
int is_digit(char k)
{
	if (k > '0' && k <= '9')
		return (1);
	else
		return (0);
}
/**
 * convert_size_number - To cast number to size specified
 * @num: Number
 * @size: Number pointing to type
 * Return: Value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);
	return ((int)num);
}
/**
 * convert_size_unsgnd - To cast number to size specified
 * @num: Number
 * @size: Number pointing to type
 * Return: Value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
