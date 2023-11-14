#include <stdarg.h>
#include "main.h"

int print_int(int num);
int print_string(char *str);
int handle_format(const char *format, int *i, va_list aps);
int handle_binary(unsigned int num);
int print_unsigned(unsigned int num);
int print_octal(unsigned int num);
int handle_unsigned(unsigned int num, int divisor);
int handle_octal(unsigned int num);
int handle_hexadecimal(unsigned int num);

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
	unsigned int u_num = 0;

	switch (format[*i])
	{
	case 's':
		aps_string = va_arg(aps, char *);
		char_printed += print_string(aps_string);
		break;
	case 'd':
	case 'i':
		char_printed += print_int(va_arg(aps, int));
		break;
	case 'c':
		_putchar(va_arg(aps, int));
		char_printed++;
		break;
	case 'u':
		char_printed += print_unsigned(va_arg(aps, unsigned int));
		break;
	case 'o':
		char_printed += print_octal(va_arg(aps, unsigned int));
		break;
	case 'b':
		u_num = va_arg(aps, unsigned int);
		char_printed += handle_binary(u_num);
		break;
	case 'x':
		u_num = va_arg(aps, unsigned int);
		char_printed += handle_hexadecimal(u_num);
		break;
	case '%':
		_putchar('%');
		char_printed++;
		break;
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

/**
 * print_unsigned - Print an unsigned integer.
 * @num: Unsigned integer to print.
 * Return: Number of characters printed.
 */
int print_unsigned(unsigned int num)
{
	int divisor = 1;
	return (handle_unsigned(num, divisor));
}

/**
 * print_octal - Print an octal number.
 * @num: Unsigned integer to print in octal.
 * Return: Number of characters printed.
 */
int print_octal(unsigned int num)
{
	int octal_count = handle_octal(num);
	return (octal_count);
}

/**
 * handle_unsigned - Handle printing of an unsigned integer.
 * @num: Unsigned integer to print.
 * @divisor: Divisor for handling integer.
 * Return: Number of characters printed.
 */
int handle_unsigned(unsigned int num, int divisor)
{
	int num_count = 0;

	while (num / divisor > 9)
	{
		divisor *= 10;
	}
	while (divisor != 0)
	{
		_putchar(num / divisor + '0');
		num %= divisor;
		divisor /= 10;

		num_count++;
	}

	return (num_count);
}

/**
 * handle_octal - Handle printing of an octal number.
 * @num: Unsigned integer to print in octal.
 * Return: Number of characters printed.
 */
int handle_octal(unsigned int num)
{
	int octal_count = 0;
	int octal[100];
	int i = 0;

	while (num != 0)
	{
		octal[i] = num % 8 + '0';
		num /= 8;
		i++;
	}

	for (i = i - 1; i >= 0; i--)
	{
		_putchar(octal[i]);
		octal_count++;
	}

	return (octal_count);
}

/**
 * handle_binary - Handle printing of an unsigned integer in binary.
 * @num: Unsigned integer to print in binary.
 * Return: Number of characters printed.
 */
int handle_binary(unsigned int num)
{
	int binary_count = 0;
	int binary[100];
	int i = 0;

	while (num != 0)
	{
		binary[i] = num % 2 + '0';
		num /= 2;
		i++;
	}

	for (i = i - 1; i >= 0; i--)
	{
		_putchar(binary[i]);
		binary_count++;
	}

	return (binary_count);
}

/**
 * handle_hexadecimal - Handle printing of an unsigned integer in hexadecimal.
 * @num: Unsigned integer to print in hexadecimal.
 * Return: Number of characters printed.
 */
int handle_hexadecimal(unsigned int num)
{
    int hex_count = 0;
    char hex[100];
    int i = 0;

    while (num != 0)
    {
        int remainder = num % 16;
        hex[i] = (remainder < 10) ? remainder + '0' : remainder - 10 + 'a';
        num /= 16;
        i++;
    }

    for (i = i - 1; i >= 0; i--)
    {
        _putchar(hex[i]);
        hex_count++;
    }

    return hex_count;
}
