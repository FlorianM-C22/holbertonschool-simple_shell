#include "shell.h"

/**
 * no_interact - non interactive mod for simple shell
 * @argc: argument count
 * @argv: argument value
 * @data: data struct
 * Return: void
 */
void no_interact(int argc, char *argv[], data_t *data)
{
	char command[MAX_INPUT_LENGTH];
	char *args[MAX_ARGS];
	int i;
	/*Suppressing unused variables warnings*/
	(void)argc;
	(void)argv;
	/*Reading the command from the standard input*/
	if (fgets(command, MAX_INPUT_LENGTH, stdin) == NULL)
	{
		fprintf(stderr, "Error reading command from stdin\n");
		exit(EXIT_FAILURE); /*If reading failed, ERROR*/
	}
	/*Remove the newline character from the end of the command.*/
	command[strcspn(command, "\n")] = '\0';

	args[0] = NULL; /*Setting the args[0] array to NULL*/
	data->command_count++; /*Counting commands written for the shell*/
	parse_input(command, command, args); /*Parse the input in tokens*/
	execute_cmd(command, args, data); /*Execute the parsed command*/

	for (i = 0; args[i] != NULL; i++)
		free(args[i]); /*Freeing memory of any data stored in the array*/
}
