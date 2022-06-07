#include "shell.h"
#include <stdio.h>
#include <unistd.h>

/**
 * main - the entry of the shell program
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success or 1
 */

int main()
{
	char *input;
	char **commands;
	int (*builtin)(char **com);

	/**
	 * shell_init();
	 */
	input = get_input();
	commands = parse_input(input);
	builtin = check_builtin(commands);
	if (builtin)
		(*builtin)(commands);
	else
		execute(commands);
	free(input);
	free(commands);
	return (0);
}
