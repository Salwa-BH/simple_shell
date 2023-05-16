#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <linux/limits.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/* Function Declarations */
void display_prompt(void);
char **parse_command(char *buffer);
char *get_command_path(char *command);
void execute_command(char **args);
void free_args(char **args);
int is_builtin_command(char *command);
void handle_builtin_command(char **args);

/* GLOBAL VARIABLES */
extern char **environ;

#endif /* SHELL_H */
