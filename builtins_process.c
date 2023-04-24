#include "head.h"

/**
 * execute_builtin_command - Executes a builtin command if it exists
 * @command: A null-terminated array of strings
 * representing the tokenized input command
 * @line: The input string read from stdin
 * Return: 1 if the command was executed successfully, 0 otherwise
 */

int execute_builtin_command(char **command, char *line)
{
	struct builtin builtin = {"env", "exit"};

	if (string_compare(*command, builtin.env) == 0)
	{
		print_environ();
		return (1);
	}
	else if (string_compare(*command, builtin.exit) == 0)
	{
		execute_builtin_command(command, line);
		return (1);
	}
	return (0);
}

