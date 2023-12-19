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

	(void)argc;
	(void)argv;

	if (fgets(command, MAX_INPUT_LENGTH, stdin) == NULL)
	{
		fprintf(stderr, "Error reading command from stdin\n");
		exit(EXIT_FAILURE);
	}

	command[strcspn(command, "\n")] = '\0';

	args[0] = NULL;
	data->command_count++;
	parse_input(command, command, args);
	execute_cmd(command, args, data);

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
}
