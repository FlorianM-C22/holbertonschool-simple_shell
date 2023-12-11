#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**
 * main - prints the command entered by a user on the next line
 * Return: number of characters read
*/

int main(void)
{
	char *cmd = NULL;
	size_t len = 0;
	ssize_t read;

	printf("$ ");

	read = getline(&cmd, &len, stdin);
	len = (strlen(cmd) - 1);

	if (read != -1)
		printf("%s\n", cmd);

	else
		fprintf(stderr, "Error reading input\n");

	free(cmd);

	return (len);
}
