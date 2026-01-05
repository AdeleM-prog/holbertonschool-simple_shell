#include "shell.h"
/**
* executing - Executes a command with its arguments
* @args: Array of command arguments
*/
void executing(char **args)
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
			perror("shell");
			exit(1);
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
