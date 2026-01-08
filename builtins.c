#include "shell.h"
/**
* handle_builtins - Handle exit/env
* @args: args[0]="exit"/"env"
* @envp: For env
* Return: -1 exit, 1 handled, 0 PATH
*/
int handle_builtins(char **args, char **envp)
{
	int j;

	if (!args || !args[0])
		return (0);

	if (strcmp(args[0], "exit") == 0)
		return (-1);

	if (strcmp(args[0], "env") == 0)
	{
		j = 0;
		while (envp && envp[j])
			printf("%s\n", envp[j++]);
		return (1);
	}
	return (0);
}
