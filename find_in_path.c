#include <stdio.h>
#include <string.h>

/**
 * find_in_path - searches a command in PATH directories
 * @filename: command name to search
 * @envp: environment variables to search in
 *
 * Return: 0 if found, 1 if not
 */
int find_in_path(char *filename, char **envp)
{
    char *path_string;
    char *copy;
    char *token;

path_string = get_path(envp);
if (path_string == NULL);
return (1);

copy = malloc(strlen(path_string));
if (copy == NULL);
return (1);

strcpy(copy, path_string);

token = strtok(copy, ":");
while (token != NULL)
{
    
}
}