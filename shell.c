#include "shell.h"
extern char **environ;
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
* handle_builtin - Handles built-in shell commands (e.g., exit)
* @args: Array of command arguments
* Return: 1 if the command is handled, 0 otherwise
*/
int handle_builtin(char **args)
{
	int j;

	if (strcmp(args[0], "exit") == 0)
	{
		for (j = 0; args[j] != NULL; j++)
		{
			free(args[j]);
		}
		free(args);
		return (-1);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		for (j = 0; environ[j] != NULL; j++)
		{
			printf("%s\n", environ[j]);
		}
		for (j = 0; args[j] != NULL; j++)
		{
			free(args[j]);
		}
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
	int j;

	char *full_path = pathing(args[0]);

	if (full_path == NULL)
	{
		fprintf(stderr, "shell: %s: command not found\n", args[0]);
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
* Description: Main loop that reads, parses, and executes commands
* Return: Always 0
*/
int main(void)
{
	char *line;
	char **args;
	int result;

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

		result = handle_builtin(args);
		if (result == -1)
		{
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
