#include "head.h"

/**
 * main - carries out the read, execute then print output loop
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment vector
 * Return: 0
*/

int main(int argc, char **argv, char *envp[])
{
	char *line = NULL, *pathcommand = NULL, *path = NULL;
	size_t bufsize = 0;
	ssize_t linesize = 0;
	char **command = NULL, **paths = NULL;
	(void)envp, (void)argv;
	if (argc < 1)
		return (-1);
	signal(SIGINT, signal_handler);
	while (1)
	{
		free_buffers(command);
		free_buffers(paths);
		free(pathcommand);
		prompt_user();
		linesize = getline(&line, &bufsize, stdin);
		if (linesize < 0)
			break;
		info.ln_count++;
		if (line[linesize - 1] == '\n')
			line[linesize - 1] = '\0';
		command = tokenize_input(line);
		if (command == NULL || *command == NULL || **command == '\0')
			continue;
		if (check_builtin(command, line))
			continue;
		path = find_path();
		paths = tokenize_input(path);
		pathcommand = check_valid_path(paths, command[0]);
		if (!pathcommand)
			perror(argv[0]);
		else
			execute_command(pathcommand, command);
	}
	if (linesize < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	return (0);
}

