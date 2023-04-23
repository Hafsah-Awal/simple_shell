#include "head.h"

/**
* get_full_path - Appends the given path to
* the user-entered command
* @path: The path of the command to append
* @cmd: The user-entered command to append to
* Return: A buffer containing the command with the
* path appended on success, or NULL on failure
*/
char *get_full_path(char *path, char *cmd)
{
	char *buf;
	size_t i = 0, j = 0;

	if (cmd == 0)
		cmd = "";

	if (path == 0)
		path = "";

	buf = malloc(sizeof(char) * (string_length(path) + string_length(cmd) + 2));
	if (!buf)
		return (NULL);

	while (path[i])
	{
		buf[i] = path[i];
		i++;
	}

	if (path[i - 1] != '/')
	{
		buf[i] = '/';
		i++;
	}
	while (cmd[j])
	{
		buf[i + j] = cmd[j];
		j++;
	}
	buf[i + j] = '\0';
	return (buf);
}
