#include "shell.h"

/**
 * parse_input - Parse user input into command and arguments.
 * @input: User input string.
 * @command: Pointer to store the command.
 * @args: Array to store arguments.
 */
void parse_input(char *input, char *command, char *args[])
{
	char *token = strtok(input, " ");
	int index;

	if (token == NULL)
	{
		command = NULL;
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
}
