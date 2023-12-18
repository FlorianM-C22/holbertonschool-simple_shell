#include "shell.h"

/**
 * get_path - Find the full path of the command using PATH environment variable
 * @command_name: Name of the command
 * Return: Full path of the command or NULL if not found
 */
char *get_path(const char *command_name)
{
	char *path_env = getenv("PATH");
	char *path = strdup(path_env);
	char *token = strtok(path, ":");

	while (token != NULL)
	{
		char *full_path = malloc(strlen(token) + strlen(command_name) + 2);

		sprintf(full_path, "%s/%s", token, command_name);

		if (access(full_path, X_OK) == 0)
		{
			free(path);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}

/**
 * execute_command - Execute the command using the full path
 * @full_path: Full path of the command
 * @command: Command structure
 */
void execute_command(const char *full_path, command_t *command)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		/* Child process */
		if (execve(full_path, command->arguments, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
}
