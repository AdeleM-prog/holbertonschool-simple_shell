#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * read_line - Read line from stdin
 * Return: Line or NULL on EOF
 */
char *read_line(void)
{
    char *line = NULL;
    size_t len = 0, i = 0, start = 0, j, read;
    ssize_t read_bytes = getline(&line, &len, stdin);

    line = malloc(1024);
    if (!line)
        return (NULL);
    
    read_bytes = getline(&line, &len, stdin);
    if (read_bytes == -1)
    {
        free(line);
        return (NULL);
    }
    
    read = (size_t)read_bytes;

    while (read > 0 && (line[read - 1] == '\n' || line[read - 1] == ' ' || line[read - 1] == '\t'))
        line[--read] = '\0';
    
    while (start < read && (line[start] == ' ' || line[start] == '\t'))
        start++;
    
    for (j = start; j < read; j++)
        line[i++] = line[j];
    line[i] = '\0';

    return (line);
}

/**
 * execute_cmd - Execute exact command path (0.1)
 * @cmd: Full path
 * @prog_name: argv[0]
 * @envp: Environment
 */
void execute_cmd(char *cmd, char *prog_name, char **envp)
{
    pid_t pid;
    int status;
    char *args[2];

    args[0] = cmd;
    args[1] = NULL;

    if (access(cmd, F_OK | X_OK) == -1)
    {
        fprintf(stderr, "%s: 1: %s: not found\n", prog_name, cmd);
        return;
    }

    pid = fork();
    if (pid == 0)
    {
        if (execve(cmd, args, envp) == -1)
            exit(127);
    }
    else if (pid > 0)
        wait(&status);
    else
        perror("fork");
}

/**
 * main - Simple shell 0.1
 */
int main(int ac __attribute__((unused)), char **av, char **envp)
{
    char *line;

    while (1)
    {
        if (isatty(STDIN_FILENO))
        {
            printf("$ ");
            fflush(stdout);
        }
        line = read_line();
        if (line == NULL)
        {
            if (isatty(STDIN_FILENO))
                printf("\n");
            break;
        }
        execute_cmd(line, av[0], envp);
        free(line);
    }
    return (0);
}
