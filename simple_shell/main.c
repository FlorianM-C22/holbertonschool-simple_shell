#include "shell.h"

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
			display_prompt();

		/*Read user input*/
		input = read_input();

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
