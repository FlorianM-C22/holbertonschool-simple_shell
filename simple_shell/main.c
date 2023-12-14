#include "shell.h"

/**
 * main - check the code
 * Return: 0 SUCCESS
 */
int main(void)
{
	while (1)
	{
		/*Display the prompt*/
		display_prompt();

		/*Read user input*/
		char *input = read_input();

		/*Check for exit command*/
		if (strcmp(input, "exit") == 0)
			break;

		/*Parse the user input*/
		Command *command = parse_input(input);

		/*Execute the command*/
		execute_command(command);

		/*Free allocated memory*/
		free(input);
		free_command(command);
	}

	return (0);
}
