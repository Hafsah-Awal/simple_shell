#include "head.h"

/**
* check_builtin - Checks whether the command is a built-in function
* @cmd: Null-terminated array of strings
* representing the tokenized input command
* @buf: Input string read from stdin using getline function
*Return: 1 if cmd executed, 0 if cmd is not executed
*/

int check_builtin(char **cmd, char *buf)
{
	if (handle_builtin(cmd, buf))
		return (1);
	else if (**cmd == '/')
	{
		execution(cmd[0], cmd);
		return (1);
	}
	return (0);
}
