#include "shell.h"

/**
 * parse_input - Parse user input into command and arguments.
 * @input: User input string.
 * @command: Pointer to store the command.
 * @args: Array to store arguments.
 */
void parse_input(char *input, char *command, char *args[])
{
	char *input_copy = strdup(input);
	int index = 0;
	char *token;

	if (input_copy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	token = strtok(input_copy, " ");

	if (token == NULL)
	{
		command[0] = '\0';
		free(input_copy);
		return;
	}
	strcpy(command, token);

	while (token != NULL && index < MAX_ARGS - 1)
	{
		token = strtok(NULL, " ");

		if (token != NULL)
		{
			args[index] = strdup(token);

			if (args[index] == NULL)
			{
				perror("malloc/strdup");
				exit(EXIT_FAILURE);
			}

			index++;
		}
	}
	args[index] = NULL;

	free(input_copy);
}
