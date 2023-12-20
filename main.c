#include "shell.h"

/**
 * main - main function - check the code
 *@argc: argument count
 *@argv: argument value
 * Return: 0 SUCCESS
 */
int main(int argc, char *argv[])
{
	data_t data;

	data.argv = argv;
	data.command_count = 0;
	data.exit_status = 0;
	if (!isatty(STDIN_FILENO))
	{
		no_interact(argc, argv, &data);
	}
	else
	{
		interactive(&data);
	}
	return (data.exit_status);
}
