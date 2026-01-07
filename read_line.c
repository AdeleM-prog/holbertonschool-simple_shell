#include "shell.h"
/**
* read_line - Read line from stdin
* Return: Line or NULL on EOF
*/
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