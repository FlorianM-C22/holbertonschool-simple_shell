#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
	int i;
	int status;
	pid_t child_pid;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			printf("[son] pid %d from [parent] pid %d\n", getpid(), getppid());
			execve(argv[0], argv, NULL);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);

			if (WIFEXITED(status))
				printf("[parent] Child process %d exited with status %d\n", child_pid, WEXITSTATUS(status));

			else if (WIFSIGNALED(status))
				printf("[parent] Child process %d terminated by signal %d\n", child_pid, WTERMSIG(status));

		}
	}
	return (0);
}
