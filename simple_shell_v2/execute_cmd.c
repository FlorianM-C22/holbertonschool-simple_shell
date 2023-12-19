#include "shell.h"

/**
 * execute_cmd - command executor
 *@command: command to execute
 *@args: arguments
 * Return: void
 */
int execute_cmd(char *command, char *args[])
{
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		int result = execvp(command, args);

		if (result == -1)
		{
			perror("execvp");
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			return (-1);
		}
	}

	return (0);
}
