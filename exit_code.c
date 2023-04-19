#include "head.h"

/**
* handle_exit_command - Handles the exit command.
* @cmd: A null-terminated array of strings
* representing the tokenized input command.
* @ln: The input string read from stdin.
* Return: no return
*/

void handle_exit_command(char **cmd, char *ln)
{
	free(line);
	free_buffers(cmd);
	exit(0);
}
