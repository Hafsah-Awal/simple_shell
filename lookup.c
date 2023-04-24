#include "head.h"

/**
 * check_builtin - Checks whether the command is a built-in function
 * @command: Null-terminated array of strings
 * representing the tokenized input command
 * @buf: Input string read from stdin using getline function
 *Return: 1 if cmd executed, 0 if cmd is not executed
 */

int check_builtin(char **command, char *buf)
{
	if (execute_builtin_command(command, buf))
		return (1);
	else if (**command == '/')
	{
		execute_command(command[0], command);
		return (1);
	}
	return (0);
}

