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

/* These are macros for reading and writing buffers */
#define READ_BUFF_SIZE 1024
#define WRITE_BUFF_SIZE 1024
#define BUFF_FLUSH -1

/* There are macros for chaining */
#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

/* These are macros for converting numbers*/
#define CONVERT_LOWERCASE 1
#define CONVERT_UNISGNED 2

/* These are macros for getlines */
#define USE_GETLINE 0
#define USE_STRTOK 0

/* These are macors for its history*/
#define H_FILE ".simple_shell_history"
#define H_FILE 4096

/* These are macros for general information*/
#define INFO_INIT
{
NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
0, 0, 0, 0, 0, 0, 0, 0, 0
}

/* This function is for global variables*/
extern char** environ;

/**
 *struct liststr - linked list
 *@num: field number
 *@str: string
 *@next: pointer to the next node
 */
typedef struct liststr
{
	int num;
	char* str;
	struct liststr* next;
} list_t;

/**
 * struct passinfo - struct contains arguments to pass the function
 * @arg: string that generates from the getline
 * @argv: array of the string generates from the arg
 * @path: string path for the current command
 * @argc: argument count
 * @line_count: eroor that counts them
 * @err_num: error code for exit
 * @linecount_flag: count line of the inputs
 * @fname: file name
 * @env: linked list for copy of env
 * @history: history node
 * @alias: alias node
 * @environ: pointer to environ
 * @env_changed: if env was changed
 * @status: return status of the list exec command
 * *cmd_buff: address poiitner to the command buffer
 * @cmd_buff_type: ||, &&, ;
 * @readfd: fd from which read line input
 * @histcount: the history line number that counts
 */

#endif /* SHELL_H */
