#include "head.h"

/**
 * check_valid_path - Checks whether a path is
 * valid and appends the user entered command
 * @path: Tokenized path
 * @cmd: User entered command
 * Return: Path appended with command on success, NULL on failure
*/

char *check_valid_path(char **path, char *cmd)
{
	int i = 0;
	char *output;

	while (path[i])
	{
		output = append_path(path[i], cmd);
		if (access(output, F_OK | X_OK) == 0)
			return (output);
		free(output);
		i++;
	}
	return (NULL);
}
