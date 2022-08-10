#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
char **arg_array(char *line);
char *read_line();
int execute(char **args);
void loop(void);
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit();
int lsh_num_builtins();
int shell_process(char **args);
#endif 