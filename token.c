#include "shell.h"
/**
* tokenize - Splits a command line into arguments
* @line: Command line to tokenize
* @args: Array of arguments
*/
 void tokenize(char *line, char **args)
{
	int i = 0;
	char *token;

	token = strtok(line, " \t");
	while (token != NULL && i < 9)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " \t");
	}
	args[i] = NULL;
}