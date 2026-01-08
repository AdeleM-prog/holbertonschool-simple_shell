#include "shell.h"
/**
* search_path - find the path of the command
* @cmd: command to search in the path
* @envp: Environment
* Return: if success, string containing the path, NULL if fail
*/
char *dispatch_path(char *cmd, char **envp)
{
    int i, has_slash = 0;

    if (cmd == NULL)
        return (NULL);

    for (i = 0; cmd[i] != '\0'; i++)
    {
        if (cmd[i] == '/')
        {
            has_slash = 1;
            break;
        }
    }

    if (has_slash == 1)
        return (cmd_has_slash(cmd));
    else
        return (search_path(cmd, envp));
}
