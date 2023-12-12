#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(void)
{
	char **env = environ;

	/* Iterate through the environment variables */
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}

	return (0);
}
