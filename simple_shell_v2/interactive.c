#include "shell.h"

void interactive(void)
{
	char input[MAX_INPUT_LENGTH];
	char *command;
	char *args[MAX_ARGS];
	size_t input_length;

	if (!isatty(STDIN_FILENO))
	{
		fprintf(stderr, "Error: Not in interactive mode.\n");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		printf("$ ");

		if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
		{
			printf("\n");
			break;
		}

		input_length = strlen(input);

		if (input_length > 0 && input[input_length - 1] == '\n')
		{
			input[input_length - 1] = '\0';
		}

		if (strcmp(input, "exit") == 0)
		{
			break;
		}
		else if (strcmp(input, "env") == 0)
		{
			def_env();
		}
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
}
