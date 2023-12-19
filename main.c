#include "shell.h"

/**
 * main - main function - check the code
 *@argc: argument count
 *@argv: argument value
 * Return: 0 SUCCESS
 */
int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	if (!isatty(STDIN_FILENO))
	{
		no_interact(argc, argv);
	}
	else
	{
		interactive();
	}

	return (0);
}
