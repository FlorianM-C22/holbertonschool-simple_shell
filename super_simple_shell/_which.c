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
	/*Resolve the value of the PATH environment variable*/
	char *path_env = getenv("PATH");
	char *path_copy, *token;

	/*Checks if PATH variable isn't set*/
	if (path_env == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not found.\n");
		return;
	}
	/*Create a copy of PATH to avoid modifying the original*/
	path_copy = strdup(path_env);
	token = strtok(path_copy, ":");

	/*Iterate through each directory in path*/
	while (token != NULL)
	{
		/*Construct the full path by appending the filename to the current dir*/
		char path[MAX_PATH_LENGTH];

		snprintf(path, sizeof(path), "%s/%s", token, filename);

		/*File exists to the current dir ?*/
		if (access(path, F_OK) == 0)
		{
			printf("%s\n", path);
			free(path_copy);
			return;
		}
		/*Move to the next directory*/
		token = strtok(NULL, ":");
	}
	/*If not found, error*/
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
	int i;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
		return (1);
	}

	for (i = 1; i < argc; i++)
	{
		_which(argv[i]);
	}

	return (0);
}
