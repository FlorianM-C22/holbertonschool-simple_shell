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
} command_t;

void parse_input(const char *input, command_t *command);
void builtins(command_t *command, char **envp);
void execute_command(command_t *command, char **envp);
int path_handling(command_t *command);
char *display_prompt(void);
void free_command(command_t *command);

#endif
