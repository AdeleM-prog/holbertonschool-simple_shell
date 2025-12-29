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
len_dir = strlen(token);
len_file = strlen(filename);
total_len = len_dir + 1 + len_file + 1;

full_path = malloc(total_len);
if (full_path == NULL)
{
    free(path_copy);
    return (1);
}

free(full_path);
token = strtok(NULL, ";");
}

free(path_copy);
return(1);
}