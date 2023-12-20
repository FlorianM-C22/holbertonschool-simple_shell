#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

extern char **environ;

#define EXIT_SUCCESS 0
#define EXIT_GENERAL_ERROR 1
#define EXIT_BUILTIN_ERROR 2
#define EXIT_NOT_EXECUTABLE 126
#define EXIT_COMMAND_NOT_FOUND 127

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64
#define MAX_PATH_LENGTH 1024

/**
 * struct data_s - struct containing shell data
 * @argv: arguments passed to shell
 * @command_count: number of commands executed
 * @exit_status: exit status of last command executed
 */
typedef struct	data_s
{
	char	**argv;
	int		command_count;
	int		exit_status;
}				data_t;

void print_error(data_t *data, char *command);

void interactive(data_t *data);
void no_interact(int argc, char *argv[], data_t *data);
char *_which(const char *filename, int all_occurrences);
char *_getenv(const char *name, char **env);
void parse_input(char *input, char *command, char *args[]);
void def_env(void);
int execute_cmd(char *command, char *args[], data_t *data);
int search_and_exec(char *command, char *args[], char *path, data_t *data);

#endif
