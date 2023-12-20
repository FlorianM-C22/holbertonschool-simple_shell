#include "shell.h"

/**
 * execute_cmd - command executor
 * @command: command to execute
 * @args: arguments
 * Return: void
 */
int execute_cmd(char *command, char *args[], data_t *data)
{
	pid_t pid; /*Declaring a Parent id*/
	int result, status, i; /*Index values*/

	pid = fork();
	data->exit_status = 0; /*Setting exit_status to 0*/
	if (pid == -1)
	{	/*If forking failed == ERROR*/
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		char *path = _getenv("PATH", environ); /*Getting PATH data in a string*/

		if (path == NULL)
		{	/*If PATH not found = ERROR*/
			fprintf(stderr, "PATH variable not found\n");
			exit(EXIT_FAILURE);
		}
		/*Search the command and execute it*/
		result = search_and_exec(command, args, path, data);
		/*If command not executed = ERROR*/
		free(path);
		if (result == -1)
			exit(EXIT_FAILURE);
		data->exit_status = result;
		exit(result); /*Exit with the result*/
	}
	else
	{	/*Parent process*/
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			return (-1);
		}
		if (WIFEXITED(status))
		{
			result = WEXITSTATUS(status);
			if (data->exit_status == 0)
				data->exit_status = status / 256;
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

	if (stat(command, &file_stat) == 0)
	{
		if (!S_ISREG(file_stat.st_mode) || !(file_stat.st_mode & S_IXUSR))
		{
			fprintf(stderr, "%s: %d: %s: Permission denied\n", data->argv[0], data->command_count, command);
			data->exit_status = 126;
			return (result);
		}
		if (execve(command, args, environ) != -1)
			return (EXIT_SUCCESS);
		else
		{
			perror("execve");
			return (EXIT_GENERAL_ERROR);
		}
	}
	path_copy = strdup(path);

	if (path_copy == NULL)
	{
		perror("strdup");
		return EXIT_GENERAL_ERROR;
	}

	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);

		if (full_path == NULL)
		{
			perror("malloc");
			free(path_copy);
			return (EXIT_GENERAL_ERROR);
		}
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (stat(full_path, &file_stat) == 0)
		{
			if (!S_ISREG(file_stat.st_mode) || !(file_stat.st_mode & S_IXUSR))
			{
				fprintf(stderr, "%s: %d: %s: Permission denied\n", data->argv[0], data->command_count, command);
				result = 126;
				break;
			}
			if (execve(full_path, args, environ) != -1)
			{
				result = EXIT_SUCCESS;
				break;
			}
			else {
				result = EXIT_BUILTIN_ERROR;
			}
		}

		free(full_path);
		full_path = NULL;
		token = strtok(NULL, ":");
	}
	if (full_path != NULL)
	{

		free(full_path);
	}
	else
	{
		fprintf(stderr, "%s: %d: %s: not found\n", data->argv[0], data->command_count, command);
		result = 127;
	}
	free(path_copy);
	return (result);
}
