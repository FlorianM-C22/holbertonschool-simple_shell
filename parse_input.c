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
	int index, i;
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

	index = 0;

	while (token != NULL)
	{
		args[index] = malloc(strlen(token) + 1);

		if (args[index] == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		strcpy(args[index], token);

		token = strtok(NULL, " ");

		index++;
	}

	args[index] = NULL;

	for (i = 0; i < index; i++)
	{
		free(args[i]);
	}

	free(input_copy);
}
