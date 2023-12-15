#include "shell.h"

/**
 * builtins - handle builtins commands
 * @command: typed command
 * Return: 0 SUCCESS
 */
void builtins(command_t *command)
{
	int i;

	/*Check if statement is NULL*/
	if (command == NULL)
		return;

	/*Check for echo command*/
	if (strcmp(command->argv[0]), "echo" == 0)
	{
		for (i = 1; i < command->argc; i++)
		{
			printf("%s", command->argv[i]);
			if (i < command->argc - 1)
				printf(" ");
		}
	}
	printf("\n");

	/*Check for exit command*/
	if (strcmp(command->argv[0], "exit") == 0)
		exit(0);

	else
		/*Execute external command*/
		execute_command(command);
}
