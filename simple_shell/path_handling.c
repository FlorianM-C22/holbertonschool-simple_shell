#include "shell.h"

/**
 * path_handling - searches for the executable in directories specified in PATH
 * @command: the command structure
 * Return: void
 */
void path_handling(command_t *command)
{
	char *path_env = NULL;
	char *path = NULL;
	char *token = NULL;
	char *command_path = NULL;

	/*Get the PATH environment variable*/
	path_env = getenv("PATH");

	/*If PATH is not set, return*/
	if (path_env == NULL)
	{
		fprintf(stderr, "PATH environment variable is not set.\n");
		return;
	}

	/*Duplicate the PATH environment variable for tokenization*/
	path = strdup(path_env);

	/*Tokenize the PATH to get individual directories*/
	token = strtok(path, ":");
	while (token != NULL)
	{
		/*Construct the full path to the executable*/
		command_path = malloc(strlen(token) + strlen(command->command_name) + 2);
		sprintf(command_path, "%s/%s", token, command->command_name);

		/*Check if the executable exists*/
		if (access(command_path, X_OK) == 0)
		{
			/*Execute the command*/
			execute_command(command_path, command);

			/*Free allocated memory*/
			free(command_path);
			free(path);

			return;
		}

		/*Free allocated memory for the current path*/
		free(command_path);

		/*Move to the next token*/
		token = strtok(NULL, ":");
	}

	/*If the loop completes, the command was not found*/
	fprintf(stderr, "Command not found: %s\n", command->command_name);

	/*Free allocated memory*/
	free(path);
}
