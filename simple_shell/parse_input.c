#include "shell.h"

/**
 * parse_input - parses user input
 * @input: user input
 * @command: command structure
 * Return: 0 SUCCESS
 */
void parse_input(const char *input, command_t *command)
{
	char *input_copy, *token;
	char delim[] = " \t\n";
	int words = 0;
	int i = 0;

	if (input == NULL)
	{
		fprintf(stderr, "Error: Input is NULL\n");
		exit(EXIT_FAILURE);
	}

	input_copy = strdup(input);

	if (input_copy == NULL)
	{
		perror("Error duplicating input");
		exit(EXIT_FAILURE);
	}

	token = strtok(input_copy, delim);

	if (token == NULL)
	{
		fprintf(stderr, "Invalid input: no command\n");
		free(input_copy);
		exit(EXIT_FAILURE);
	}

	command->command_name = strdup(token);

	if (command->command_name == NULL)
	{
		perror("Error duplicating command name");
		exit(EXIT_FAILURE);
	}

	while (strtok(NULL, delim))
		words++;

	strtok(input_copy, delim);

	command->arguments = malloc(sizeof(char *) * (words + 2));

	if (command->arguments == NULL)
	{
		perror("Error allocating memory for arguments");
		exit(EXIT_FAILURE);
	}

	words++;

	while ((token = strtok(NULL, delim)) != NULL)
	{
		command->arguments[i] = strdup(token);

		if (command->arguments[i] == NULL)
		{
			perror("Error duplicating argument");
			exit(EXIT_FAILURE);
		}

		i++;
	}

	command->arguments[i] = NULL;

	free(input_copy);
}
