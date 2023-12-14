#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fcntl.h>
#include <signal.h>
#include <stdarg.h>
#include <stdbool.h>

/**
 *struct command - command structure
 *@command_name: name of the command
 *@arguments: name of the arguments
 */
typedef struct command
{
	char *command_name;
	char **arguments;
} Command;


/*Needed prototype functions*/

#endif
