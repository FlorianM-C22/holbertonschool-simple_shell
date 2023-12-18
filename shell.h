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

extern char **environ;

/**
 *struct command - command structure
 *@command_name: name of the command
 *@has_arguments: checks if arguments or not
 *@arguments: array of arguments
 */
typedef struct command
{
	char *command_name;
	char **arguments;
	int *has_arguments;
} command_t;

void free_command(command_t *command);
char *display_prompt(void);
char *get_path(const char *command_name);
void execute_command(const char *full_path, command_t *command);
void parse_input(const char *input, command_t *command);
void parse_arguments(const char *input, command_t *command);

#endif
