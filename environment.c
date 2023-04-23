#include "head.h"

/**
 * print_environ - prints the environment variables to stdout
 * Return: void
*/
void print_environ(void)
{
	int x = 0;
	char **env = environ;

	while (env[x])
	{
		write(STDOUT_FILENO, (const void *)env[x], string_length(env[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}

