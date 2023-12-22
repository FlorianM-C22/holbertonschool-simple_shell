#include "shell.h"

/**
 * def_env - Printing the env variable
 *
 * Return: void
 */
void def_env(void)
{
	/*Getting data from environ in a variable*/
	char *env_var = *environ;

	/*Iterating through the environ variable*/
	while (env_var != NULL)
	{
		printf("%s\n", env_var); /*Printing each line*/
		env_var = *(environ++);
	}
}
