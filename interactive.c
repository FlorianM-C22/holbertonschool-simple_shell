#include "shell.h"

/**
 * interactive - interactive mod for simple shell
 * @data: data struct
 * Return: void
 */
void interactive(data_t *data)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t bytes_read;
	char *command;
	char *args[MAX_ARGS];
	int i;

	while (1)
	{
		printf("$ ");
		bytes_read = getline(&input, &input_size, stdin);

		data->command_count++;
		/* Error or End of file */
		if (bytes_read == -1)
		{
			printf("\n");
			free(input);  /*Free memory allocated by getline*/
			exit(data->exit_status);
		}
		if (bytes_read > 0 && input[bytes_read - 1] == '\n')
			input[bytes_read - 1] = '\0';
		if (strcmp(input, "exit") == 0)
		{
			free(input);
			input = NULL;
			break;
		}
		else if (strcmp(input, "env") == 0)
			def_env();
		else
		{
			command = strtok(input, " ");
			if (command != NULL)
			{
				printf("A\n");
				parse_input(input, command, args);
				printf("B\n");
				execute_cmd(command, args, data);
				printf("C\n");
				for (i = 0; args[i] != NULL; i++)
				{
					free(args[i]);
					args[i] = NULL;
				}
				printf("D\n");
			}
		}
				printf("E\n");
		if (input != NULL)
		{
			free(input);
			input = NULL;
		}
				printf("F\n");

	}
	if (input != NULL)
		free(input);
}
