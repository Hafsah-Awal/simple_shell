#include "head.h"

/**
 * main - carries out the read, execute then print output loop
 * @ac: argument count
 * @av: argument vector
 * @envp: environment vector
 * Return: 0
*/

int main(int ac, char **av, char *envp[])
{
	char *line = NULL, *pathcommand = NULL, *path = NULL;
	size_t bufsize = 0;
	ssize_t linesize = 0;
	char **command = NULL, **paths = NULL;
	(void)envp, (void)av;
	if (ac < 1)
		return (-1);
	signal(SIGINT, handle_signal);
	while (1)
	{
		buffer_cleaner(command);
		buffer_cleaner(paths);
		free(pathcommand);
		print_shell_prompt();
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
		path = get_path();
		paths = tokenize_input(path);
		pathcommand = check_valid_path(paths, command[0]);
		if (!pathcommand)
			perror(av[0]);
		else
			execute_command(pathcommand, command);
	}
	if (linesize < 0 && flags.interactive)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	return (0);
}

