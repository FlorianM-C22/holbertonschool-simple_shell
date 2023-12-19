#include "shell.h"

void parse_input(char *input, char *command, char *args[], size_t args_size)
{
	char *token = strtok(input, " ");
	size_t index = 0;

	if (token != NULL)
	{
		strncpy(command, token, args_size - 1);
		command[args_size - 1] = '\0';
		index++;
	}
	else
	{
		command[0] = '\0';
		return;
	}

	while (token != NULL && index < args_size - 1)
	{
		token = strtok(NULL, " ");

		if (token != NULL)
		{
			args[index] = malloc(strlen(token) + 1);

			if (args[index] == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}

			strcpy(args[index], token);
			index++;
		}
	}

	args[index] = NULL;
}
