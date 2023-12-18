#include "shell.h"

/**
 * no_interact - non interactive mod for simple shell
 * @argc: argument count
 * @argv: argument value
 * Return: void
 */
void no_interact(int argc, char *argv[])
{
	char command[MAX_INPUT_LENGTH];
	char *args[MAX_ARGS];

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s command [args...]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	strncpy(command, argv[1], MAX_INPUT_LENGTH - 1);
	command[MAX_INPUT_LENGTH - 1] = '\0';

	parse_input(argv[1], command, args);
	execute_cmd(command, args);
}
