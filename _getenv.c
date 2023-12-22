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
	size_t name_len = strlen(name); /*Length of the environment variable*/
	char *value; /*Pointer to store the value of the environment variable*/
	int i;
	/*Loop through the array of environment variables*/
	for (i = 0; env[i]; i++)
	{
	/*If current env var starts with the specified name and followed by '=' */
		if (strncmp(env[i], name, name_len) == 0 && env[i][name_len] == '=')
		{
			/*Copy the content after the '=' character*/
			value = strdup(&env[i][name_len + 1]);
			/*If unsuccessful, ERROR*/
			if (value == NULL)
			{
				perror("strdup");
				exit(EXIT_FAILURE);
			}
			/*Return allocated string containing the content of env*/
			return (value);
		}
	}
	return (NULL); /*If not found, return NULL*/
}
