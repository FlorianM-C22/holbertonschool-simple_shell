#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{

	printf("Address of environ: %p\n", (void *)environ);
	printf("Adress of 3rd Argument of the function (env): %p\n", (void *)env);

	return (0);
}
