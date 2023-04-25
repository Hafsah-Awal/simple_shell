#include "head.h"

/**
 * is_exe_cmd - checks if a file is an executable command
 * @info: pointer to the info struct
 * @path: pointer to the path string of the file
 * Checks if the file located at the given path is an executable command.
 * Return: 1 if it is, 0 otherwise.
 */

int is_exe_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * duplic_char - duplicates characters from a string
 * @pathstr: the string to duplicate from
 * @start: starting index of characters to duplicate
 * @stop: stopping index of characters to duplicate
 * Return: a pointer to the new buffer containing the duplicated characters
 */
char *duplic_char(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * search_path - searches for a command in
 * the directories listed in the PATH variable
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the command to search for
 * Return: a pointer to a string containing the full
 * path of the command if found, or NULL if not found
 */

char *search_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_exe_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = duplic_char(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_exe_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}

