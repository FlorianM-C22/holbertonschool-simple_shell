#include "shell.h"

/**
 * search_in_path - search for executable in the PATH
 * @command: command structure
 * Return: 1 if found, 0 if not found
 */
int search_in_path(command_t *command)
{
	char *path = getenv("PATH");
	char *path_copy, *token, *full_path;

	if (path == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not set\n");
		return (0);
	}
	path_copy = strdup(path);

	if (path_copy == NULL)
	{
		perror("Error duplicating PATH");
		exit(EXIT_FAILURE);
	}
	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(command->command_name) + 2);
		if (full_path == NULL)
		{
			perror("Error allocating memory for full_path");
			exit(EXIT_FAILURE);
		}
		sprintf(full_path, "%s/%s", token, command->command_name);

		if (access(full_path, X_OK) == 0)
		{
			free(command->command_name);
			command->command_name = strdup(full_path);
			free(full_path);
			free(path_copy);
			return (1);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (0);
}
