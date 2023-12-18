#include "shell.h"

/**
 * main - check the code
 * Return: 0 SUCCESS
 */
int main(void)
{
	command_t command;
	char *input, *full_path;
	int interactive;

	interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
			input = display_prompt();

		parse_input(input, &command);

		full_path = get_path(command.command_name);

		if (full_path != NULL)
		{
			execute_command(full_path, &command);
			free(full_path);
		}
		else
		{
			fprintf(stderr, "Command not found: %s\n", command.command_name);
		}

		free(input);
		free_command(&command);
	}

	return (0);
}
