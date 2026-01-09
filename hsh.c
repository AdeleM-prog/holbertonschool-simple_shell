#include "shell.h"
/**
 * main - Simple shell 0.1
 * @ac: Argument count (unused)
 * @av: Argument vector
 * @envp: Environment
 * Return: Always 0
 */
int main(int ac __attribute__((unused)), char **av, char **envp)
{
	char *line, *cmd, *args[10];
	int builtin, status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout); }

		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break; }

		cmd = trim_spaces(line);
		if (*cmd == '\0')
		{
			free(line);
			continue; }
		tokenize(cmd, args);
		if (args[0] == NULL)
		{
			free(line);
			continue; }
		builtin = handle_builtins(args, envp);
		if (builtin == -1)
		{
			free(line);
			return (status); }
		if (builtin == 1)
		{
			status = 0;
			free(line);
			continue; }
		status = execute_cmd(args, av[0], envp);
		free(line); }
	return (status);
}
