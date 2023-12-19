#include "shell.h"

/**
 * no_interact - non interactive mod for simple shell
 * @argc: argument count
 * @argv: argument value
 * Return: void
 */
void no_interact(int __attribute__((unused)) argc, char __attribute__((unused)) *argv[])
{
	char command[MAX_INPUT_LENGTH];
	char *args[MAX_ARGS];

	if (fgets(command, MAX_INPUT_LENGTH, stdin) == NULL)
	{
		fprintf(stderr, "Error reading command from stdin\n");
		exit(EXIT_FAILURE);
	}

	command[strcspn(command, "\n")] = '\0';

	args[0] = NULL;

	parse_input(command, command, args);
	execute_cmd(command, args);
}
