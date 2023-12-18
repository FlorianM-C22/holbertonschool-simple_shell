#include "shell.h"

void builtins(command_t *command);

/**
 * main - check the code
 *
 * Return: 0 SUCCESS
 */
int main(void)
{
	command_t command;
	char *input;
	int interactive;

	interactive = isatty(STDIN_FILENO);

	while (1)
	{
		/*Checks if interactive mode*/
		if (interactive)
			input = display_prompt();

		/*Parse the user input*/
		parse_input(input, &command);

		/*Execute the command*/
		execute_command(&command);

		/*Free allocated memory*/
		free(input);
		free_command(&command);
	}

	return (0);
}

/**
 * builtins - handles builtins commands such as 'echo' and 'exit'
 * @command: the command used
 * Return: void
 */
void builtins(command_t *command)
{
	int i;

	/*Handle invalid command structure*/
	if (command == NULL || command->command_name == NULL)
		return;

	/* Check for the echo command */
	if (strcmp(command->command_name, "echo") == 0)
	{
		for (i = 0; command->arguments[i] != NULL; i++)
		{
			printf("%s", command->arguments[i]);
			if (command->arguments[i + 1] != NULL)
			{
				printf(" ");
			}
		}
	}
	printf("\n");

	/*Check for the exit command*/
	if (strcmp(command->command_name, "exit") == 0)
		exit(0);

	else
		/*Execute external command*/
		execute_command(command);
}
