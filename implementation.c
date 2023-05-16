#include "shell.h"

/**
 * display_prompt - Display the shell prompt
 */
void display_prompt(void)
{
	printf("#cisfun$ ");
}

/**
 * parse_command - Parse the command line into arguments
 * @buffer: The command line buffer
 * Return: Array of command arguments
 */
char **parse_command(char *buffer)
{
	char **args = NULL;
	char *token;
	int arg_count = 0;

	token = strtok(buffer, " ");
	while (token != NULL)
	{
		args = realloc(args, sizeof(char *) * (arg_count + 1));
		if (args == NULL)
		{
			perror("Allocation Error");
			return (NULL);
		}
		args[arg_count] = token;
		arg_count++;
		token = strtok(NULL, " ");
	}
	args = realloc(args, sizeof(char *) * (arg_count + 1));
	if (args == NULL)
	{
		perror("Allocation Error");
		return (NULL);
	}
	args[arg_count] = NULL;

	return (args);
}
/**
 * get_command_path - Get the full path of the command
 * @command: The command name
 * Return: The full path of the command, or NULL if not found
 */
char *get_command_path(char *command)
{
	char *path = getenv("PATH");
	char *token;
	char *command_path = NULL;
    char *temp = NULL;

	token = strtok(path, ":");
	while (token != NULL)
	{
		temp = malloc(strlen(token) + strlen(command) + 2);

		if (temp == NULL)
		{
			perror("Allocation Error");
			return (NULL);
		}
		strcpy(temp, token);
		strcat(temp, "/");
		strcat(temp, command);

		if (access(temp, X_OK) == 0)
		{
			command_path = temp;
			break;
		}
		free(temp);
		token = strtok(NULL, ":");
	}

	return (command_path);
}

/**
 * execute_command - Execute the command with arguments
 * @args: Array of command arguments
 */
void execute_command(char **args)
{
	pid_t child_pid;
    char *command = NULL;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork Error");
		return;
	}
	if (child_pid == 0)
	{
		command = get_command_path(args[0]);

		if (command == NULL)
		{
			printf("Command not found: %s\n", args[0]);
			exit(EXIT_FAILURE);
		}

		if (execve(command, args, NULL) == -1)
		{
			perror("Execution Error");
			exit(EXIT_FAILURE);
		}

		free(command);
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(NULL);
	}
}
