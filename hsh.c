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
	ssize_t read;

	read = getline(&line, &len, stdin);
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
 * trim_spaces - Remove leading and trailing spaces
 * @str: Input string
 * Return: Pointer to trimmed string
 */
char *trim_spaces(char *str)
{
	char *end;

	while (*str == ' ' || *str == '\t')
		str++;

	if (*str == '\0')
		return (str);

	end = str + strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t'))
	{
		*end = '\0';
		end--;
	}

	return (str);
}

/**
 * execute_cmd - Execute exact command path (Simple shell 0.1)
 * @cmd: Full command path
 * @prog_name: argv[0]
 * @envp: Environment
 */
void execute_cmd(char *cmd, char *prog_name, char **envp)
{
	pid_t pid;
	int status;
	char *cmd = args[0];

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

/**
 * main - Simple shell 0.1
 * @ac: Argument count (unused)
 * @av: Argument vector
 * @envp: Environment
 * Return: Always 0
 */
int main(int ac __attribute__((unused)), char **av, char **envp)
{
	char *line;
	char *cmd;
    char *arg[10];
    int i = 0;

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

		cmd = trim_spaces(line);

		if (*cmd == '\0')
		{
			free(line);
			continue;
		}
token = strtok(cmd, " \t");
while (token != NULL && i < 9)
{
    args[i] = token;
    i++;
    token = strtok(NULL, " \t");
}
args[i] = NULL;

if (args[0] == NULL)
{
    free(line);
    continue;
}

		execute_cmd(cmd, av[0], envp);
		free(line);
	}

	return (0);
}