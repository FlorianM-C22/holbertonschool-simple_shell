#include "shell.h"

/**
 * parse_arguments - parses arguments from user input
 * @input: user input
 * @command: command structure
 */
void parse_arguments(const char *input, command_t *command)
{
	char *input_copy = strdup(input);
	char *token;
	int i = 0;

	token = strtok(input_copy, " \n\t");

	while (token != NULL)
	{
		command->arguments[i++] = strdup(token);
		token = strtok(NULL, " \n\t");
	}

	command->arguments[i] = NULL;

	free(input_copy);
}

/**
 * parse_input - parses arguments from user input
 * @input: user input
 * @command: command structure
 */
void parse_input(const char *input, command_t *command)
{
	char *input_copy = strdup(input);

	if (input_copy == NULL)
	{
		perror("Error duplicating input");
		exit(EXIT_FAILURE);
	}

	command->command_name = strdup(strtok(input_copy, " \n\t"));

	command->arguments = malloc(sizeof(char *) * 1024);

	if (command->arguments == NULL)
	{
		perror("Error allocating memory for arguments");
		exit(EXIT_FAILURE);
	}

	if (strtok(NULL, " \n\t") != NULL)
	{
		parse_arguments(input_copy, command);
	}
	else
	{
		command->arguments[0] = NULL;
	}

	free(input_copy);
}
