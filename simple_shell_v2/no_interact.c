#include "shell.h"

void no_interact(int argc, char *argv[])
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS];

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s command [args...]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	parse_input(argv[1], command, args, sizeof(args) / sizeof(args[0]));

	execute_cmd(command, args);
}
