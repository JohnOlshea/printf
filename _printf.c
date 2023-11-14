#include <stdarg.h>
#include "main.h"

int print_int(int num);
int print_string(char *str);
int handle_format(const char *format, int *i, va_list aps);

/**
 * _printf - Custom printf function.
 * @format: Format string.
 * @...: Variable arguments.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list aps;
	int i = 0, char_printed = 0;

	va_start(aps, format);

	for (; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			char_printed += handle_format(format, &i, aps);
		}
		else
		{
			_putchar(format[i]);
			char_printed++;
		}
	}

	va_end(aps);

	return (char_printed);
}

/**
 * handle_format - Handle the format specifier.
 * @format: Format string.
 * @i: Current position in the format string.
 * @aps: Argument list.
 * Return: Number of characters printed.
 */
int handle_format(const char *format, int *i, va_list aps)
{
	int char_printed = 0;
	char *aps_string;

	if (format[*i] == 's')
	{
		aps_string = va_arg(aps, char *);
		char_printed += print_string(aps_string);
	}
	else if (format[*i] == 'd' || format[*i] == 'i')
	{
		char_printed += print_int(va_arg(aps, int));
	}
	else if (format[*i] == 'c')
	{
		_putchar(va_arg(aps, int));
		char_printed++;
	}
	else if (format[*i] == '%')
	{
		_putchar('%');
		char_printed++;
	}

	return (char_printed);
}

/**
 * print_string - Print a string.
 * @str: String to print.
 * Return: Number of characters printed.
 */
int print_string(char *str)
{
	int str_count = word_count(str);
	print_word(str);
	return (str_count);
}

/**
 * print_int - Print an integer.
 * @num: Integer to print.
 * Return: Number of characters printed.
 */
int print_int(int num)
{
	int divisor = 1;
	return (handle_int(num, divisor));
}
