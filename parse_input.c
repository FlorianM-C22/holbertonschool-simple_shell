#include "shell.h"

/**
 * parse_input - Parse user input into command and arguments.
 * @input: User input string.
 * @command: Pointer to store the command.
 * @args: Array to store arguments.
 */
void parse_input(char *input, char *command, char *args[])
{
	char *input_copy = strdup(input); /*Make a copy of the input string.*/
	int index = 1; /*Index for arguments in the args array.*/
	char *token;
	/*Check for memory allocation failure.*/
	if (input_copy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	token = strtok(input_copy, " "); /*Tpkenizing with ' ' as delimiter*/
	if (token == NULL)
	{
		command[0] = '\0'; /*If 1st token is NULL, set cmd to an empty string*/
		free(input_copy);
		return;
	}
	strcpy(command, token); /*Copy the first token to the command variable.*/
	args[0] = strdup(token); /*Duplicate 1st token, store it in the args array.*/
	if (args[0] == NULL)
	{
		perror("malloc/strdup");
		exit(EXIT_FAILURE);
	}
	while (token != NULL && index < MAX_ARGS - 1) /*Continue tokenizing*/
	{
		token = strtok(NULL, " ");
		if (token != NULL) /*Token isnt NULL, duplicate and store in args array.*/
		{
			args[index] = strdup(token);

			if (args[index] == NULL) /*Check for memory allocation failure.*/
			{
				perror("malloc/strdup");
				exit(EXIT_FAILURE);
			}
			index++;
		}
	}
	args[index] = NULL; /*Last element of args array to NULL, indicating end*/
	free(input_copy);
}
