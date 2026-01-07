#include "shell.h"
/**
* execute_cmd - Execute exact command path (Simple shell 0.1)
* @cmd: Full command path
* @prog_name: argv[0]
* @envp: Environment
*/
void execute_cmd(char **args, char *prog_name, char **envp)
{
	pid_t pid;
	int status;
	char *cmd;

	cmd = args[0];

	if (access(cmd, F_OK | X_OK) == -1)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", prog_name, cmd);
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(cmd, args, envp) == -1)
			exit(127);
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
