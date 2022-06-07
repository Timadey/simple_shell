#ifndef _SHELL_H_
#define _SHELL_H_
/**
 * constants
 */
#define TOKEN_SIZE 6
#define TOKEN_DELIM " \t\r\n\a"
/**
 * header files
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * structs
 */
/**
 * struct btin - struct for builtins
 */
typedef struct btin
{
	char *command;
	int (*func)(char **arg);
}btin;
/**
 * declarations
 */
char *get_input(void);
char **parse_input(char *input);
int execute(char **commands);
int (*check_builtin(char **commands))(char **commands);
int change_dir(char **dir);
int builtin_num(btin builtins);

#endif
