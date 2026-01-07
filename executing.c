#include "shell.h"
/**
* executing - Executes a command with its arguments
* @args: Array of command arguments
* @prog_name: Name of the program
* @envp: Environement
*/
void executing(char **args, char *prog_name, char **envp)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
		return;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", prog_name, args[0]);
			perror("shell");
			exit(127);
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
