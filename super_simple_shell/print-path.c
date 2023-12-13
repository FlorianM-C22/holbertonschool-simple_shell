#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 4096

/**
 * _which - Search for the location of file in the current PATH.
 * @filename: The file to search for.
 */
void print_path(const char *filename)
