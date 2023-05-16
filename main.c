#include "shell.h"

/**
 * main - Simple shell program entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: Always 0
 */
int main(/*int argc, char **argv*/)
{
	char *buffer = NULL;
	ssize_t read_bytes;
	size_t buffer_size = BUFFER_SIZE;
	char **args = NULL;

	while (1)
	{
		display_prompt();
		read_bytes = getline(&buffer, &buffer_size, stdin);
		if (buffer == NULL)
		{
			printf("\n");
			break;
		}
		buffer[read_bytes - 1] = '\0'; /* Remove the newline character */

		args = parse_command(buffer);

		if (args == NULL)
		{
			free(buffer);
			continue;
		}

		if (is_builtin_command(args[0]))
		{
			handle_builtin_command(args);
		}
		else
		{
			execute_command(args);
		}

		free_args(args);
	}

	free(buffer); /* Free the allocated buffer */

	return (0);
}
