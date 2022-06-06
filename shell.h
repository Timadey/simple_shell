#ifndef _SHELL_H_
#define _SHELL_H_
/**
 * constants
 */
#define TOKEN_SIZE 6
/**
 * header files
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
/**
 * declarations
 */
char *get_input(void);
char **parse_input(char *input);
#endif
