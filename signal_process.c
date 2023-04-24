#include "head.h"

/**
 * signal_handler - Handles the signal received by the shell
 * @m: The signal number
 * Return: Nothing.
 */

void signal_handler(int m)
{
	(void)m;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}

