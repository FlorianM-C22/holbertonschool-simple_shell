#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 4096

/**
 * _which - Search for the location of file in the current PATH.
 * @filename: The file to search for.
 */
void _which(const char *filename)
{
	char *path_env = getenv("PATH");

	if (path_env == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not found.\n");
		return;
	}

	char *path_copy = strdup(path_env);
	char *token = strtok(path_copy, ":");

	while (token != NULL)
	{
		char path[MAX_PATH_LENGTH];

		snprintf(path, sizeof(path), "%s/%s", token, filename);

		if (access(path, F_OK) == 0)
		{
			printf("%s\n", path);
			free(path_copy);
			return;
		}

		token = strtok(NULL, ":");
	}

	fprintf(stderr, "Error: %s not found in PATH.\n", filename);
	free(path_copy);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
		return (1);
	}

	for (int i = 1; i < argc; i++)
	{
		_which(argv[i]);
	}

	return (0);
}
