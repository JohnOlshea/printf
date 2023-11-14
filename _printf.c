/**#include <stdio.h>*/
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
	int char_printed = 0;
	int str_count = 0;
	char *aps_string;

	va_start(aps, format);

	while (format[i] != '\0')
	{
		if(format[i] == '%')
		{
			i++;
			if (format[i] == 's')
			{
				aps_string = va_arg(aps, char *);
				str_count = word_count(aps_string);

				char_printed += str_count;
				print_word(aps_string);
			}
			else if (format[i] == 'c')
			{
				_putchar(va_arg(aps, int));
				char_printed++;
			}
			else if (format[i] == '%')
			{
				_putchar('%');
				char_printed++;
			}
		}
		else
		{
			_putchar(format[i]);
			char_printed++;
		}
		i++;
	}
	/**printf("\ntotals print : %d \n", char_printed);*/
	_putchar('\n');

	va_end(aps);
	return (char_printed);
}
