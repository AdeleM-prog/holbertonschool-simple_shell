#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *read_line(void);
void execute(char *cmd, char *prog_name);

/**
 * main - Simple shell 0.1
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
    char *line;
    while (1)
    {
        if (isatty(STDIN_FILENO))
            printf("#cisfun$ ");
        fflush(stdout);
        line = read_line();
        if (!line)
            break;
        execute(line, av[0]);
        free(line);
    }
    return (0);
}

/**
 * read_line - Read line from stdin
 */
char *read_line(void)
{
    char *line = NULL;
    size_t len = 0;
    if (getline(&line, &len, stdin) == -1)
    {
        free(line);
        return (NULL);
    }
    line[strcspn(line, "\n")] = 0;  /* trim \n */
    return (line);
}

/**
 * execute - Fork + execve single command (no args)
 */
void execute(char *cmd, char *prog_name)
{
    pid_t pid;
    int status;

    if (access(cmd, X_OK) == -1)
    {
        fprintf(stderr, "%s: No such file or directory\n", prog_name);
        return;
    }
    pid = fork();
    if (pid == 0)
    {
        if (execve(cmd, (char *[]){cmd, NULL}, env) == -1)
            perror(prog_name);
        exit(1);
    }
    else if (pid > 0)
        wait(&status);
    else
        perror("fork");
}
