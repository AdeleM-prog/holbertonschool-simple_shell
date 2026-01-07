#include "shell.h"
/**
* read_line - Reads a command line from standard input
* Return: Pointer to the read line, NULL on error or EOF
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
	{
		line[read - 1] = '\0';
	}
	return (line);
}

/**
* handle_builtin - Handles built-in shell commands (exit, env)
* @args: Array of command arguments
* @envp: Pointer to environment variables array
* Return: -1 to exit shell, 1 if builtin handled, 0 otherwise
*/
int handle_builtin(char **args, char **envp)
{
	int j;

	if (strcmp(args[0], "exit") == 0)
		return (-1);

	else if (strcmp(args[0], "env") == 0)
	{
		for (j = 0; envp[j] != NULL; j++)
			printf("%s\n", envp[j]);
		for (j = 0; args[j] != NULL; j++)
			free(args[j]);

		free(args);
		return (1);
	}
	return (0);
}

/**
* execute_command - Executes an external command (via execve)
* @args: Array of command arguments
* Return: 0 if command executed, 1 on error
*/
int execute_command(char **args, char *prog_name, char **envp)
{
	int j, k;
	char *full_path = pathing(args[0]);

	if (full_path == NULL)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", prog_name, args[0]);
		for (k = 0; args[k] != NULL; k++)
			free(args[k]);
		free(args);
		return (1);
	}
	args[0] = full_path;
	executing(args, prog_name, envp);
	for (j = 1; args[j] != NULL; j++)
		free(args[j]);
	free(args[0]);
	free(args);
	return (0);
}

/**
* process_command - Processes and executes a command
* @line: Command line
* @av: Argument vector
* @envp: Environment variables
* Return: -1 to exit, 0 to continue
*/
int process_command(char *line, char **av, char **envp)
{
	char **args;
	int result, k;

	args = parsing(line);
	if (args == NULL || args[0] == NULL)
		return (0);

	result = handle_builtin(args, envp);
	if (result == -1)
	{
		for (k = 0; args[k] != NULL; k++)
			free(args[k]);
		free(args);
		return (-1);
	}
	else if (result == 1)
		return (0);

	execute_command(args, av[0], envp);
	return (0);
}

/**
* main - Entry point of the shell
* @ac: Argument count (unused)
* @av: Argument vector
* @envp: Environment variables
* Return: Always 0
*/
int main(int ac __attribute__((unused)),
		char **av,
		char **envp)
{
	char *line;
	int interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
		{
			printf("$ ");
			fflush(stdout);
		}

		line = read_line();
		if (line == NULL)
		{
			if (interactive)
				printf("\n");
			break;
		}
		if (process_command(line, av, envp) == -1)
		{
			free(line);
			break;
		}
		free(line);
	}
	return (0);
}
