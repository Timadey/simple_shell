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

	/**
	 * shell_init();
	 */
	input = get_input();
	commands = parse_input(input);
	execvp(commands[0], commands);
	return (0);
}
