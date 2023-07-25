#include "main.h"
/**
 * get_flags - Active flags calculation
 * @format: String formatted to print argument
 * @i: To take the parameter
 * Return: Flags
 */
int get_flags(const char *format, int *i)
{
	int g, cu_i;
	int flags = 0;
	const char FLAGS_CHR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_AR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cu_i = *i + 1; format[cu_i] != '\0'; cu_i++)
	{
		for (g = 0; FLAGS_CHR[g] != '\0'; g++)
			if (format[cu_i] == FLAGS_CHR[g])
			{
				flags |= FLAGS_AR[g];
				break;
			}
		if (FLAGS_CHR[g] == 0)
			break;
	}
	*i = cu_i - 1;
	return (flags);
}
