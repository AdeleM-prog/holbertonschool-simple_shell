#include "shell.h"
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
