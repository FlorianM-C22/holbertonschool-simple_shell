#include "shell.h"

/**
 * _which - Search for the location of file in the current PATH.
 * @filename: The file to search for.
 * @all_occurrences: Flag indicating whether to find all occurrences.
 *                   If 0, return the first occurrence found; otherwise, print all occurrences.
 * Return: If all_occurrences is 0, return the first occurrence found; otherwise, return NULL.
 */
char *_which(const char *filename, int all_occurrences)
{
	char *path_env = getenv("PATH");
	char *path_copy, *token, *all_occurrences_buffer;

	if (path_env == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not found.\n");
		return NULL;
	}

	path_copy = strdup(path_env);
	token = strtok(path_copy, ":");

	all_occurrences_buffer = NULL;

	while (token != NULL)
	{
		char path[MAX_PATH_LENGTH];
		snprintf(path, sizeof(path), "%s/%s", token, filename);

		if (access(path, F_OK) == 0)
		{
			if (all_occurrences)
			{
				if (!all_occurrences_buffer)
				{
					all_occurrences_buffer = malloc(MAX_PATH_LENGTH * MAX_ARGS);
					if (!all_occurrences_buffer)
					{
						perror("malloc");
						exit(EXIT_FAILURE);
					}
				}
				strcat(all_occurrences_buffer, path);
				strcat(all_occurrences_buffer, "\n");
			}
			else
			{
				printf("%s\n", path);
				free(path_copy);
				free(all_occurrences_buffer);
				return strdup(path);
			}
		}
		token = strtok(NULL, ":");
	}
	if (all_occurrences)
	{
		fprintf(stderr, "Error: %s not found in PATH.\n", filename);
		free(all_occurrences_buffer);
		return NULL;
	}

	fprintf(stderr, "Error: %s not found in PATH.\n", filename);
	free(path_copy);
	return NULL;
}
