#include "shell.h"
/**
* execute_cmd - Execute exact command path (Simple shell 0.1)
* @args: Full command path
* @prog_name: argv[0]
* @envp: Environment
*/
void execute_cmd(char **args, char *prog_name, char **envp)
{
	pid_t pid;
	int status;
	char *path;

	path = search_path(args[0], envp);
	if (path == NULL)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", prog_name, args[0]);
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(path, args, envp) == -1)
		{
			free(path);
			exit(127);
		}
	}
	else if (pid > 0)
	{
		wait(&status);
		free(path);
	}
	else
	{
		perror("fork");
		free(path);
	}
}
