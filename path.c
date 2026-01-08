#include "shell.h"
/**
 * search_path - find the path of the command
 * @line: command to search in the path
 * @envp: Environment
 * Return: if success, string containing the path, NULL if fail
 */
 char *search_path(char *cmd, char **envp)
{
    int i, j, has_slash = 0;
    char *path_copy, *token, *copy, *path = NULL, *full_path;
    size_t len_dir, len_cmd;

if (cmd == NULL)
return (NULL);

for (i = 0; cmd[i] != '\0'; i++)
{
    if (cmd[i] == '/')
    {
        has_slash =  1;
        break;
    }
}
    if (has_slash == 1) 
    {
        if (access(cmd, F_OK | X_OK) == 0)
        {
            copy = strdup(cmd);
                if (copy == NULL)
                return (NULL);
                else
                return(copy);
        }
        else
        return (NULL);
    }

    else if (has_slash != 1)
    {
        for (j = 0; envp[j] != NULL && envp != NULL; j++)
        { 
            if(strncmp(envp[j], "PATH=", 5) == 0)
                {
                    path = (envp[j] + 5);
                    break;
                }
        }

        if (path == NULL || path[0] == '\0')
            return (NULL);

        path_copy = strdup(path);
        if (path_copy == NULL)
            return(NULL);

        len_cmd = strlen(cmd);
        token = strtok(path_copy, ":");
        while (token != NULL)
        {
            len_dir = strlen(token);
            full_path = malloc(len_dir + 1 + len_cmd + 1);
            if (full_path == NULL)
            {
                free(path_copy);
                return (NULL);
            }

            strcpy(full_path, token);
            full_path[len_dir] = '/';
            strcpy(full_path + len_dir + 1, cmd);

            if (access(full_path, F_OK | X_OK) == 0)
            {
                free(path_copy);
                return(full_path);
            }
            
            free(full_path);
            token = strtok(NULL, ":");
        }
        free(path_copy);
        return(NULL);
    }
    return (NULL);
}
