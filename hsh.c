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
	char *line;
	char *cmd;
    char *args[10];
    int i = 0;
    char *token;

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

        i = 0;
        args[0] = NULL;
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

		execute_cmd(args, av[0], envp);
		free(line);
	}

	return (0);
}