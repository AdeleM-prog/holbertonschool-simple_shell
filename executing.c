#include "shell.h"
/**
* executing - Executes a command with its arguments
* @args: Array of command arguments
*/
void executing(char **args, char *prog_name)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
	{
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", prog_name, args[0]);
			perror("shell");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		wait(&status);
	}
	else
	{
		perror("fork");
	}
}
