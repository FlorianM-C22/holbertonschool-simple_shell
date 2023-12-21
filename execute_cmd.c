#include "shell.h"

/**
 * file_exists - checks if file exists
 * @filename: name of the file
 * Return: 0 SUCCESS
 */
int file_exists(char *filename)
{
	struct stat filestats;

	if (stat(filename, &filestats) >= 0)
	{
		if (filestats.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH))
			return (1);
	}
	return (0);
}

/**
 * get_command - gets the command
 * @path: PATH variable
 * @command: name of the command
 * Return: Command if SUCCESS
 */
char *get_command(char *path, char *command)
{
	char *token = NULL;
	char *full_path = NULL;

	if (command[0] == '/' || command[0] == '.')
	{
		if (file_exists(command))
			return (strdup(command));
		else
			return (NULL);
	}
	token = strtok(path, ":");
	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("malloc");
			return (NULL);
		}
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, command);
		if (file_exists(full_path))
		{
			return (full_path);
		}
		free(full_path);
		full_path = NULL;
		token = strtok(NULL, ":");
	}
	return (NULL);
}

/**
 * execute_cmd - command executor
 * @command: command to execute
 * @args: arguments
 * @data: data struct to store values like exit values
 * Return: void
 */
int execute_cmd(char *command, char *args[], data_t *data)
{
	int result; /*Index values*/
	int i;
	char *path = NULL; /*Declaring a PATH variable*/

	data->exit_status = 0; /*Setting exit_status to 0*/

	path = _getenv("PATH", environ); /*Getting PATH data in a string*/

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
	for (i = 0; args[i]; i++)
	{
		free(args[i]);
		args[i] = NULL;
	}

	return (result);
}

/**
 * search_and_exec - search for the executable in directories and PATH
 * @command: command to execute
 * @args: arguments
 * @path: PATH variable
 * @data: data struct to store values like exit values
 * Return: 0 on success, -1 on failure
 */
int search_and_exec(char *command, char *args[], char *path, data_t *data)
{
	int result = -1;
	int status = 0;
	char *full_command = NULL;

	full_command = get_command(path, command);
	if (full_command == NULL)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", data->argv[0],
				data->command_count, command);
		return (127);
	}
	else if (!fork() && execve(full_command, args, environ) == -1)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", data->argv[0],
				data->command_count, command);
		data->exit_status = 127;
		result = 127;
	}
	else
	{
		wait(&status);
		data->exit_status = status / 256;
		result = status / 256;
	}
	free(full_command);
	return (result);
}
