#include "shell.h"

/**
 * parse_input - parses user input
 *@input: user input
 *@command: command structure
 * Return: 0 SUCCESS
 */
void parse_input(const char *input, command_t *command)
{
	char *token;
	char *buffer;
	char delim[] = " ";
	int words = 0;
	int i = 0;

	/*Duplicating the 1st tokenized word and saving it as command name*/
	command->command_name = strdup(strtok(input, delim));

	if (command->command_name == NULL)
		perror("Error duplicating command name");
		exit(EXIT_FAILURE);

	/*Counting the words*/
	while (strtok(NULL, delim))
		words++;

	/*Resetting strtok at the beginning of the arguments*/
	strtok(input, delim);

	/*Allocating memory*/
	command->arguments = malloc(sizeof(char *) * words);

	if (command->arguments == NULL)
		perror("Error allocating memory for arguments");
		exit(EXIT_FAILURE);

	while (i < words)
	{
		/*Duplicating the remaining tokenized words and saving them as cmd*/
		command->arguments[i] = strdup(strtok(NULL, delim));
		i++;
	}
}
