#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv, char **envp)
{
char *delim = " \t\n";
size_t bufsize = 0;
ssize_t len = 0;
pid_t pid;
char *token;
char *argv_cmd[2];
char *line = NULL;

(void)argc;
(void)argv;

while (1)
{
printf("$ ");
len = getline(&line, &bufsize, stdin);

if (len == -1)
break;

token = strtok(line, delim);
argv_cmd[0] = token;
argv_cmd[1] = NULL;

if (token != NULL)
{
pid = fork();
if (pid < 0)
return (-1);

if (pid == 0)
{
execve(token, argv_cmd, envp);
perror("execve");
exit(1);
}

if (pid > 0)
wait(NULL);
}
}

printf("\n");
free(line);
return (0);

}