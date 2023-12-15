#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

int main(void)
{
	char input[MAX_INPUT_SIZE]; /*Buffer to store user input*/
	pid_t child_pid;			/*Process ID for the child process*/
	int status;					/* Status of the child process*/

	while (1)
	{
		printf("$ "); /*Waiting for user input*/
		/*Reads user input*/
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			perror("fgets");
			exit(EXIT_FAILURE);
		}
		/*Remove the newline character at the end of the input*/
		input[strcspn(input, "\n")] = '\0';
		if (strcmp(input, "exit") == 0) /*Checks if user wants to exit*/
			break;
		child_pid = fork();

		if (child_pid == -1)
		{
			/*Fork failed*/
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			/* Execute the specified command */
			execlp(input, input, (char *)NULL);
			/*If execlp fails print an error and exit child process*/
			perror("execlp");
			exit(EXIT_FAILURE);
		}
		else
		{
			/*Waiting for the child process to finish*/
			waitpid(child_pid, &status, 0);
		}
	}
	return (0);
}
