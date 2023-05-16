#include "shell.h"
#include <unistd.h>

/**
 * free_args - Free the memory allocated for command arguments
 * @args: Array of command arguments
 */
void free_args(char **args)
{
    int i = 0;

	if (args != NULL)
	{
		for (; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);
	}
}

/**
 * handle_builtin_command - Handle the execution of built-in commands
 * @args: Array of command arguments
 */
void handle_builtin_command(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		free_args(args);
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		extern char **environ;
		char **env = environ;
		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
		free_args(args);
	}
}
/**
 * is_builtin_command - Check if the command is a built-in command
 * @command: The command name
 * Return: 1 if it's a built-in command, 0 otherwise
 */
int is_builtin_command(char *command)
{
	if (strcmp(command, "exit") == 0 || strcmp(command, "env") == 0)
	{
		return (1);
	}
	return (0);
}

