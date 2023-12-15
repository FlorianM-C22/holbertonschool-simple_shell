#include "shell.h"

/**
 * main - check the code
 * @argc: argument count
 * @argv: argument value
 * Return: 0 SUCCESS
 */
int main(int argc, char *argv[])
{
	Command *command;
	char *input;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			/*Display the prompt*/
			display_prompt();

		/*Read user input*/
		input = read_input();

		/*Parse the user input*/
		command = parse_input(input);

		/*Execute the command*/
		execute_command(command);

		/*Free allocated memory*/
		free(input);
		free_command(command);
	}

	return (0);
}
