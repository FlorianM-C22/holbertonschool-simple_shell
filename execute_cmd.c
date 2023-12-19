#include "shell.h"

/**
 * execute_cmd - command executor
 * @command: command to execute
 * @args: arguments
 * Return: void
 */
int execute_cmd(char *command, char *args[])
{
	pid_t pid;
	int result;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return -1;
	}
	else if (pid == 0)
	{
		char *path = _getenv("PATH", environ);

		if (path == NULL)
		{
			fprintf(stderr, "PATH variable not found\n");
			_exit(EXIT_FAILURE);
		}

		printf("Debug: Before calling search_and_exec for command: %s\n", command);

		result = search_and_exec(command, args, path);

		printf("Debug: After calling search_and_exec, result: %d\n", result);

		if (result == -1)
			_exit(EXIT_FAILURE);
	}
	else
	{
		int status;
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			return -1;
		}
	}

	return 0;
}

/**
 * search_and_exec - search for the executable in directories listed in PATH
 * @command: command to execute
 * @args: arguments
 * @path: PATH variable
 * Return: 0 on success, -1 on failure
 */
int search_and_exec(char *command, char *args[], char *path)
{
	char *token, *path_copy, *full_path;
	int result = -1;

	if (command[0] == '/')
	{
		if (execve(command, args, NULL) != -1)
			return 0;

		perror("execve");
		return -1;
	}

	path_copy = strdup(path);

	if (path_copy == NULL)
	{
		perror("strdup");
		return -1;
	}

	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("malloc");
			free(path_copy);
			return (-1);
		}

		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, command);

		printf("Debug: Trying to execute %s\n", full_path);

		if (execve(full_path, args, NULL) != -1)
		{
			result = 0;
			free(full_path);
			break;
		}

		free(full_path);

		token = strtok(NULL, ":");
	}
	free(path_copy);

	if (result == -1)
	{
		fprintf(stderr, "Debug: No such file or directory\n");
	}

	return (result);
}
