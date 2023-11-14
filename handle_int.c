#include "main.h"

/**
 * handle_int - prints integer
 *
 * @num: number to print
 * @divisor: number to divide with
 *
 * Return: numbers and sign count
 */
int handle_int(int num, int divisor)
{
	int num_count = 0;
	if (num < 0)
	{
		_putchar('-');
		num = -num;

		num_count++;
	}
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
