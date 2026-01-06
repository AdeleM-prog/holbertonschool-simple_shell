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
	{
		for (j = 0; args[j] != NULL; j++)
		return (-1);
	}
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
int execute_command(char **args)
{
	int j, k;

	char *full_path = pathing(args[0]);

	if (full_path == NULL)
	{
		fprintf(stderr, "shell: %s: command not found\n", args[0]);
		for (k = 0; args[k] != NULL; k++)
			free(args[k]);
		free(args);
		return (1);
	}
	args[0] = full_path;
	executing(args);
	for (j = 1; args[j] != NULL; j++)
	{
		free(args[j]);
	}
	free(args[0]);
	free(args);
	return (0);
}

/**
* main - Entry point of the shell
* @ac: Argument count (unused)
* @av: Argument vector (unused)
* @envp: Environment variables
* Description: Main loop that reads, parses, and executes commands
* Return: Always 0
*/
int main(int ac __attribute__((unused)),
		char **av __attribute__((unused)),
		char **envp)
{
	char *line;
	char **args;
	int result, k;

	while (1)
	{
		printf("$ ");
		fflush(stdout);
		line = read_line();

		if (line == NULL)
			break;

		args = parsing(line);
		if (args == NULL || args[0] == NULL)
		{
			free(line);
			continue;
		}

		result = handle_builtin(args, envp);
		if (result == -1)
		{
			for (k = 0; args[k] != NULL; k++)
				free(args[k]);
			free(args);
			free(line);
			break;
		}
		else if (result == 1)
		{
			free(line);
			continue;
		}

		execute_command(args);
		free(line);
	}
	return (0);
}
