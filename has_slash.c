#include "shell.h"
/**
* cmd_has_slash - handle the case where a command has a slash
* @cmd: command to search in
* Return: if success, string containing the path, NULL if fail
*/
char *cmd_has_slash(char *cmd)
{
    char *copy;

    if (cmd == NULL)
        return (NULL);

    if (access(cmd, F_OK | X_OK) == 0)
    {
        copy = strdup(cmd);
        if (copy == NULL)
            return (NULL);
        return (copy);
    }
    return (NULL);
}
