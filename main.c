#include "shell.h"

/**
 * main - main function - check the code
 *@argc: argument count
 *@argv: argument value
 * Return: 0 SUCCESS
 */
int main(int argc, char *argv[])
{
	if (argc > 1)
		no_interact(argc, argv);
	else
		interactive();

	return (0);
}
