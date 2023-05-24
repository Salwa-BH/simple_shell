#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
extern char **environ;

/* Function Declarations */
void display_prompt(void);
char **parse_command(char *buffer);
char *get_command_path(char *command);
void execute_command(char **args);
void free_args(char **args);
int is_builtin_command(char *command);
void handle_builtin_command(char **args);

#endif /* SHELL_H */
