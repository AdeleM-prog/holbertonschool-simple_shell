#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv, char **envp)
{
pid_t pid;
char *args[] = {"ls", "-l", "/tmp", NULL};
int i;

for (i = 0; i < 5; i++)
{
pid = fork();
if (pid < 0)
return (-1);

if (pid == 0)
{
execve("/bin/ls", args, envp);
perror("execve");
exit(1);
}

if (pid > 0)
wait(NULL);

}
return (0);
}
