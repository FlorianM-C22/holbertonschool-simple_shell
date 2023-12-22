#include "shell.h"

/**
 * interactive - interactive mod for simple shell
 * @data: data struct
 * Return: void
 */
void interactive(data_t *data)
{
	char *input = NULL; /*Input line from the user*/
	size_t input_size = 0; /*Size of the input buffer.*/
	ssize_t bytes_read;
	char *command; /*Parsed command.*/
	char *args[MAX_ARGS]; /*Array to store parsed arguments.*/
	int i;

	while (1) /*Continuous loop for interactive mode*/
	{
		printf("$ "); /*Display shell prompt.*/
		bytes_read = getline(&input, &input_size, stdin); /*Reads input*/

		data->command_count++;
		/* Error or End of file */
		if (bytes_read == -1)
		{
			printf("\n");
			free(input);  /*Free memory allocated by getline*/
			exit(data->exit_status);
		} /*Remove newline character from the end of the input.*/
		if (bytes_read > 0 && input[bytes_read - 1] == '\n')
			input[bytes_read - 1] = '\0';
		if (strcmp(input, "exit") == 0)
		{	/*Check if the user entered "exit" to terminate the shell.*/
			free(input);
			input = NULL;
			break;
		}/*Check if the user entered "env"*/
		else if (strcmp(input, "env") == 0)
			def_env();
		else
		{	/*Tokenize the input to extract the command and arguments.*/
			command = strtok(input, " ");
			if (command != NULL)
			{
				parse_input(input, command, args);
				execute_cmd(command, args, data);
				for (i = 0; args[i] != NULL; i++)
				{
					free(args[i]);
					args[i] = NULL;
				}
			}
		}
		if (input != NULL)
		{
			free(input);
			input = NULL;
		}

	}
	if (input != NULL)
		free(input);
}
