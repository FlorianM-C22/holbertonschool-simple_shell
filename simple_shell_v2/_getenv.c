#include "shell.h"

/**
 * _getenv - Find the environment variable.
 * @name: Environment variable.
 * @env: Array of environment variables.
 * Return: Allocated string containing the content
 * of the environment variable or NULL if not found.
 */
char *_getenv(const char *name, char **env)
{
	size_t name_len = strlen(name);
	char *value;
	int i;

	for (i = 0; env[i]; i++)
	{
		if (strncmp(env[i], name, name_len) == 0 && env[i][name_len] == '=')
		{
			value = strdup(&env[i][name_len + 1]);

			if (value == NULL)
			{
				perror("strdup");
				exit(EXIT_FAILURE);
			}
			return (value);
		}
	}

	return (NULL);
}
