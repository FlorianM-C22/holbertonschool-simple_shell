#include "shell.h"

/**
 * main - main function - check the code
 *@argc: argument count
 *@argv: argument value
 * Return: 0 SUCCESS
 */
int main(int argc, char *argv[])
{
	data_t data; /*Structure to store data related to the shell*/

	data.argv = argv;
	data.command_count = 0;
	data.exit_status = 0;

	/*Is this non-interactive mode ?*/
	if (!isatty(STDIN_FILENO))
	{
		/*Execute non-interactive*/
		no_interact(argc, argv, &data);
	}
	else
	{
		/*Else, execute interactive*/
		interactive(&data);
	}
	while (1)
	/*Return the exit status of the shell terminal*/
	return (data.exit_status);
}
