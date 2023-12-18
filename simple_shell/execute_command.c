#include "shell.h"

int is_builtin(const char *command_name);

/**
 * execute_command - execute external command
 * @command: command called by the user
 * @envp: environment pointer
 */
void execute_command(command_t *command, char **envp)
{
	pid_t pid;
	int status;

	if (is_builtin(command->command_name))
		builtins(command, envp);
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
			printf("|%s|\n", command->command_name);

			for (int i = 0; envp[i]; i++)
				printf("%s\n", envp[i]);
			if (execve(command->command_name, command->arguments, envp) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
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
