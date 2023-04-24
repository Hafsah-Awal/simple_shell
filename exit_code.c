#include "head.h"

/**
 * handle_exit_command - Handles the exit command.
 * @command: A null-terminated array of strings
 * representing the tokenized input command.
 * @line: The input string read from stdin.
 * Return: no return
 */

void handle_exit_command(char **command, char *line)
{
	free(line);
	free_buffers(command);
	exit(0);
}

