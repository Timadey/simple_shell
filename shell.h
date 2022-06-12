#ifndef _SHELL_H_
#define _SHELL_H_
/**
 * constants
 */
#define TOKEN_SIZE 6
#define TOKEN_DELIM " \t\r\n\a"
#define __UNUSED__ __attribute__((__unused__))
/**
 * header files
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <linux/limits.h>
/**
 * structs
 */
/**
 * struct btin - struct for builtins
 */
typedef struct btin
{
	char *command;
	int (*func)(char **arg, char *err);
} btin;
/**
 * declarations
 */
char *get_input(char *msg);
char **parse_input(char *input, char *err);
int execute(char **commands, char *err);
int (*check_builtin(char **commands))(char **commands, char *err);
int change_dir(char **dir, char *err);
int builtin_num(btin builtins);
int shell_exit(char **com, char *err);

#endif
