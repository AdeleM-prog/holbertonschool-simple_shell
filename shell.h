#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char **parsing(char *line);
void executing(char **args);
char *pathing(char *command);
int handle_builtin(char **args, char **envp);
char *read_line(void);
int execute_command(char **args, char *prog_name);

#endif
