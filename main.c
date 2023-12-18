#include "shell.h"

int main(int argc, char *argv[])
{
	if (argc > 1)
		no_interact(argc, argv);
	else
		interactive();

	return (0);
}
