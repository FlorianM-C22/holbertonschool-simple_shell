#include "shell.h"

/**
 * free_command - free dynamically allocated memory in a command structure
 * @command: command structure
 */
void free_command(command_t *command)
{
	int i;

	if (command == NULL)
		return;

	free(command->command_name);

	if (command->arguments != NULL)
	{
		for (i = 0; command->arguments[i] != NULL; i++)
			free(command->arguments[i]);

		free(command->arguments);
	}
	command->command_name = NULL;
	command->arguments = NULL;
}
