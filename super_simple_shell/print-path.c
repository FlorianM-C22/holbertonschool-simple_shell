#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 4096

/**
 * print_path - prints each directory contained
 * in the environment variable PATH one directory per line
 */
void print_path(void)
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

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}
}

/**
 * main - prints check the code
 * Return: 0 success
 */
int main(void)
{
	print_path();
	return (0);
}
