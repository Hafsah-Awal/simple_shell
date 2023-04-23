#include "head.h"

/**
 * get_path - finds the PATH from the global environment variables
 * Return: pointer to the PATH string, or NULL if PATH is not found
*/

char *get_path(void)
{
	int x;
	char **env = environ, *path = NULL;

	while (*env)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env;
			while (*path && x < 5)
			{
				path++;
				x++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}

