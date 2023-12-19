#include "shell.h"

/**
 * execute_cmd - command executor
 * @command: command to execute
 * @args: arguments
 * Return: void
 */
int execute_cmd(char *command, char *args[], data_t *data)
{
	pid_t pid;
	int result, status, i;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		char *path = _getenv("PATH", environ);

		if (path == NULL)
		{
			fprintf(stderr, "PATH variable not found\n");
			_exit(EXIT_FAILURE);
		}
		result = search_and_exec(command, args, path, data);

		if (result == -1)
			_exit(EXIT_FAILURE);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			data->exit_status = status / 256;
			perror("waitpid");
			return -1;
		}
		data->exit_status = status / 256;

		if (WIFEXITED(status))
		{
			result = WEXITSTATUS(status);
		}
		else
		{
			fprintf(stderr, "Child process did not terminate normally\n");
			result = -1;
		}
	}
	for (i = 0; args[i] != NULL; i++)
		free(args[i]);

	return (result);
}

/**
 * search_and_exec - search for the executable in directories and PATH
 * @command: command to execute
 * @args: arguments
 * @path: PATH variable
 * Return: 0 on success, -1 on failure
 */
int search_and_exec(char *command, char *args[], char *path, data_t *data)
{
	char *token, *path_copy, *full_path;
	int result = -1;
	struct stat file_stat;

	if (stat(command, &file_stat) == 0 && S_ISREG(file_stat.st_mode) && (file_stat.st_mode & S_IXUSR))
	{
		if (execve(command, args, environ) != -1)
			return (0);
		else
		{
			perror("execve");
			return (-1);
		}
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

		if (stat(full_path, &file_stat) == 0 && S_ISREG(file_stat.st_mode) && (file_stat.st_mode & S_IXUSR))
		{
			if (execve(full_path, args, environ) != -1)
			{
				result = 0;
				break;
			}
		}


		free(full_path);
		full_path = NULL;
		token = strtok(NULL, ":");
	}
	if (full_path != NULL)
		free(full_path);
	else
	{
		fprintf(stderr, "%s: %d: %s: not found\n", data->argv[0], data->command_count, command);
		data->exit_status = 127;
	}
	free(path_copy);
	return (result);
}
