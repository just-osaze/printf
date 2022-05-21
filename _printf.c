#include "main.h"




/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */
int _printf(const char *format, ...)
{
	unsigned int a = 0, abf = 0, len = 0;
	va_list arguments;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(arguments, format), buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[a] == '%' && !format[a + 1]))
		return (-1);
	if (!format[a])
		return (0);
	for (a = 0; format && format[a]; a++)
	{
		if (format[a] == '%')
		{
			if (format[a + 1] == '\0')
			{	print_buf(buffer, abf), free(buffer), va_end(arguments);
				return (-1);
			}
			else
			{	function = get_print_func(format, a + 1);
				if (function == NULL)
				{
					if (format[a + 1] == ' ' && !format[a + 2])
						return (-1);
					handl_buf(buffer, format[a], abf), len++, a--;
				}
				else
				{
					len += function(arguments, buffer, abf);
					a += ev_print_func(format, a + 1);
				}
			} a++;
		}
		else
			handl_buf(buffer, format[a], abf), len++;
		for (abf = len; abf > 1024; abf -= 1024)
			;
	}
	print_buf(buffer, abf), free(buffer), va_end(arguments);
	return (len);
}
