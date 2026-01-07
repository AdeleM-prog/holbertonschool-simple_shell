#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * read_line - Read line from stdin
 * Return: Line or NULL on EOF
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read = getline(&line, &len, stdin);

	if (read == -1)
	{
		free(line);
		return (NULL);
	}
	if (read > 0 && line[read - 1] == '\n')
		line[read - 1] = '\0';
	return (line);
}

/**
 * execute_cmd - Execute exact command path (Tâche 0.1: no PATH)
 * @cmd: Full command path
 * @prog_name: argv[0] for errors
 */
void execute_cmd(char *cmd, char *prog_name)
{
	pid_t pid;
	int status;

	if (access(cmd, F_OK | X_OK) == -1)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", prog_name, cmd);
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		char *args[] = {cmd, NULL};  /* No args en 0.1 */
		if (execve(cmd, args, environ) == -1)
			exit(127);
	}
	else if (pid > 0)
		wait(&status);
	else
		perror("fork");
}

/**
 * main - Simple shell 0.1
 */
int main(int ac, char **av)
{
	char *line;
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}
		execute_cmd(line, av[0]);
		free(line);
	}
	return (0);
}
