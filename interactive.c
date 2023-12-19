#include "shell.h"

/**
 * interactive - interactive mod for simple shell
 *
 * Return: void
 */
void interactive(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t bytes_read;
	char *command;
	char *args[MAX_ARGS];

	if (!isatty(STDIN_FILENO))
	{
		fprintf(stderr, "Error: Not in interactive mode.\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		printf("$ ");

		bytes_read = getline(&input, &input_size, stdin);

		if (bytes_read == -1)
		{
			printf("\n");
			break;
		}

		if (bytes_read > 0 && input[bytes_read - 1] == '\n')
			input[bytes_read - 1] = '\0';

		if (strcmp(input, "exit") == 0)
			break;

		else if (strcmp(input, "env") == 0)
			def_env();

		else
		{
			command = strtok(input, " ");
			if (command != NULL)
			{
				parse_input(input, command, args);
				execute_cmd(command, args);
			}
		}
	}

	free(input);
}
