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
	char words[50][50];
	int i;
	int count = 0;

	ptr = strtok(str, delim);

	while (ptr != NULL && count < 50)
	{
		strcpy(words[count], ptr);
		count++;
		ptr = strtok(NULL, delim);
	}

	for (i = 0; i < count; i++)
		printf("%s\n", words[i]);

	return (0);
}
