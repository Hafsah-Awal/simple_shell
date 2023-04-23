#include "head.h"

/**
 * _putchar - prints a single character to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned and errno set appropriately
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - prints a string
 * @s: string to be printed
 * Return: number of characters printed
*/

int print_string(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}

	return (i);
}

