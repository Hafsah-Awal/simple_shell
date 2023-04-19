#include "shell.h"

/**
* signal_handler - Handles the signal received by the shell
* @sig_num: The signal number
* Return: Nothing.
*/

void signal_handler(int sig_num)
{
	(void)sig_num;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
