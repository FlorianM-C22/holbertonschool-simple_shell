#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**
 * main - splits a string and returns an array of each word of the string
 * Return: 0 = SUCCESS
*/

int main(void)
{
	char str[] = "Je m'appelle Florian et je suis avec Léo";
	char delim[] = " ";
	char *ptr;

	ptr = strtok(str, delim);

	while (ptr != NULL)
	{
		printf("%s\n", ptr);
		ptr = strtok(NULL, delim);
	}

	return (0);
}
