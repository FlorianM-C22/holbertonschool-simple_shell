#include "shell.h"

/**
 * def_env - Defining env
 *
 * Return: void
 */
void def_env(void)
{
	char *env_var = *environ;

	while (env_var != NULL)
	{
		printf("%s\n", env_var);
		env_var = *(environ++);
	}
}
