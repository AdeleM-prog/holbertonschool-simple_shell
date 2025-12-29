#include <string.h>

/**
 * get_path - identify the right string in envp,
 * isolate the right part
 * @envp: environment variable to get path in
 *
 * Return: 0, NULL if fails
 */
 int get_path(char **envp)
 {
int i;

while (envp[i] != NULL)
{ 
    if(strncmp(envp[i], "PATH=", 5) == 0)
    {
        return (envp[i] + 5);
    }
    i++;
}
return (NULL);
}