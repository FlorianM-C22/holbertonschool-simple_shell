#include<stdio.h>
#include<stdlib.h>
/**
 * main - prints all arguments without using ac
 * Return: number of characters read
*/

int main (void)
{
	char *cmd = NULL;
	size_t len = 0;
	ssize_t read;

	printf("$ ");

	read = getline(&cmd, &len, stdin);

	if (read != -1)
		printf("%s", cmd);

	else
		fprintf(stderr, "Error reading input\n");

	free(cmd);

	return (len);
}
