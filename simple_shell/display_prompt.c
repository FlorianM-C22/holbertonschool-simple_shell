#include "shell.h"

/**
 * display_prompt - display the shell prompt
 * Return: input if success
 */
char *display_prompt(void)
{
	ssize_t bytes_read;
	size_t input_size = 0;
	char *input = NULL;

	printf("$");

	/* Reads user input using getline */
	bytes_read = getline(&input, &input_size, stdin);

	if (bytes_read == -1)
	{
		/* Error or End of file */
		if (feof(stdin))
		{
			printf("End of file. Exiting.\n");
			free(input);  /*Free memory allocated by getline*/
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			free(input);  /*Free memory allocated by getline*/
			exit(EXIT_FAILURE);
		}
	}
	return (input);
}
