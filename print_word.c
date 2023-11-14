#include "main.h"

/**
 * print_word - prints string to standard output
 *
 * @string: string to print
 */
void print_word(char *string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		_putchar(string[i]);
		i++;
	}
}

