#include <stdarg.h>
#include "main.h"

/*int word_count(char *string);*/
int _printf(const char *format, ...);

/**
 * _printf - function that produces output according to a format.
 *
 * @format: format
 * @...: variadic parameters
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list aps;
	int i = 0;

	va_start(aps, format);

	while (format[i] != '\0')
	{
		if(format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				_putchar(va_arg(aps, int));
			}
		}
		else
		{
			_putchar(format[i]);
		}
		i++;
	}
	_putchar('\n');

	va_end(aps);
	return (0);
}
