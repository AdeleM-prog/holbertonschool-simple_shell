#include "shell.h"
/**
* parsing - Parses a command line into arguments
* @line: Line to parse
* Return: Array of arguments, NULL on error
*/
char **parsing(char *line)
{
	char **args, *token;
	int i = 0, k = 0;

	args = malloc(64 * sizeof(char *));

	token = strtok(line, " \r\t\n");
	while (token != NULL)
	{
		args[i] = strdup(token);
		if (args[i] == NULL)
		{
			for (k = 0; k < i; k++)
				free(args[k]);
				
			free(args);
			exit(EXIT_FAILURE);
		}

		i++;
		token = strtok(NULL, " \r\t\n");
	}

	args[i] = NULL;
	return (args);
}
