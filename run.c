#include "head.h"

/**
* execute_command - Executes the command passed by the user
* @cp: Command to be executed
* @cmd: Vector array of pointers to commands
* Return: 0 on success, -1 on failure
*/

void execute_command(char *cp, char **cmd)
{
	pid_t child_pid;
	int status;
	char **env = environ;

	child_pid = fork();
	if (child_pid < 0)
		perror(cp);
	if (child_pid == 0)
	{
		execve(cp, cmd, env);
		perror(cp);
		free(cp);
		free_buffers(cmd);
		exit(98);
	}
	else
		wait(&status);
}
