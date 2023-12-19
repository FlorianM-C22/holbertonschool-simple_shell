#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

extern char **environ;

#define MAX_INPUT_LENGTH 100
#define MAX_ARGS 10
#define MAX_PATH_LENGTH 1024

void interactive(void);
void no_interact(int argc, char *argv[]);
char *_which(const char *filename, int all_occurrences);
char *_getenv(const char *name, char **env);
void parse_input(char *input, char *command, char *args[]);
void def_env(void);
int execute_cmd(char *command, char *args[]);

#endif
