#include "shell.h"

/**
 * path_handling - search for executable in the PATH
 * @command: command structure
 * @envp: environment pointer
 * Return: 1 if found, 0 if not found
 */
int path_handling(command_t *command)
{
	char *path = getenv("PATH");
	char *path_copy, *token, *full_path;
	size_t path_len;

	if (path == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not set\n");
		return 0;
	}

	path_len = strlen(path);
	path_copy = malloc(path_len + 2);

	if (path_copy == NULL)
	{
		perror("Error allocating memory for path_copy");
		exit(EXIT_FAILURE);
	}

	strcpy(path_copy, path);
	path_copy[path_len] = ':';
	path_copy[path_len + 1] = '\0';

	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(command->command_name) + 2);

		if (full_path == NULL)
		{
			perror("Error allocating memory for full_path");
			exit(EXIT_FAILURE);
		}

		snprintf(full_path, strlen(token) + strlen(command->command_name) + 2, "%s/%s", token, command->command_name);

		printf("Checking path: %s\n", full_path);

		if (access(full_path, X_OK) == 0)
		{
			printf("Command found: %s\n", full_path);

			free(command->command_name);
			command->command_name = strdup(full_path);

			if (command->command_name == NULL)
			{
				perror("Error allocating memory for command_name");
				exit(EXIT_FAILURE);
			}

			free(full_path);
			free(path_copy);
			return 1;
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (0);
}
