#include "head.h"

/**
 * buffer_cleaner - frees a double pointer buffer
 * @buf: buffer to be freed
 * Return: no return
*/

void buffer_cleaner(char **buf)
{
	int i = 0;

	if (!buf || buf == NULL)
		return;
	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free(buf);
}

