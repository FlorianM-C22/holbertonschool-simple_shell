#include "shell.h"

/**
 * execute_command - execute external command
 * @command: command called by the user
 * @command_path: path to the command
 */
void execute_command(const char *command_path, command_t *command)
{
	pid_t pid;
	int status, i;

	if (is_builtin(command->command_name))
		builtins(command, command_path);
	/*
	* else
	*	if (!path_handling(command))
	*	{
	*		fprintf(stderr, "Command not found: %s\n", command->command_name);
	*		return;
	*	}
	*/

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		/* Child process */
		if (execve(command_path, command->arguments, environ) == -1)
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

/**
 * is_builtin - check if a command is a built-in command
 * @command_name: name of the command
 * Return: 1 if built-in, 0 otherwise
 */
int is_builtin(const char *command_name)
{
	return (strcmp(command_name, "exit") == 0 ||
	strcmp(command_name, "echo") == 0);
}
