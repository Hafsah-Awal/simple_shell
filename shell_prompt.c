#include "head.h"

/**
 * print_shell_prompt - prints the shell prompt
 * This function prints the shell prompt, which consists of a '$' symbol
 * followed by a space. If the shell is in interactive mode, it also prints
 * the current working directory.
 */
void print_shell_prompt(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive = 1;
	if (flags.interactive)
		write(STDERR_FILENO, "$ ", 2);
}

