#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *read_line(void);
char *trim_spaces(char *str);
void tokenize(char *line, char **args);
void execute_cmd(char **args, char *prog_name, char **envp);
char *search_path(char *cmd, char **envp);
int handle_builtins(char **args, char **envp);

#endif
