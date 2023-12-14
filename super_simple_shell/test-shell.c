#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_INPUT_SIZE 1024

int main(void)
{
	char *input = NULL;    /* Pointer to store user input */
	size_t input_size = 0; /* Size of the input buffer */
	pid_t child_pid;       /* Process ID for the child process */
	int status;            /* Status of the child process */

	while (1)
	{
		ssize_t bytes_read;
		printf("$ "); /* Waiting for user input */

		/* Reads user input using getline */
		bytes_read = getline(&input, &input_size, stdin);

		if (bytes_read == -1)
		{
			/* Error or End of file */
			if (feof(stdin))
			{
				printf("End of file. Exiting.\n");
				break;
			}
			else
			{
				perror("getline");
				exit(EXIT_FAILURE);
			}
		}

		/* Remove the newline character at the end of the input */
		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "exit") == 0) /* Checks if the user wants to exit */
			break;

		child_pid = fork();

		if (child_pid == -1)
		{
			/* Fork failed */
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			/* Execute the specified command */
			char *command = input;

			char *args[2];
			args[0] = command;
			args[1] = NULL;

			execve(command, args, NULL);

			/* If execve fails, print an error and exit the child process */
			perror("execve");
			_exit(EXIT_FAILURE);
		}
		else
		{
			/* Waiting for the child process to finish */
			waitpid(child_pid, &status, 0);
		}
	}

	/* Free the allocated memory for input */
	free(input);

	return 0;
}
