#include "shell.h"
/**
 * main - the entry of the shell program
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success or 1
 */

int main(int ac, char **av)

{
	char *input;
	char **commands;
	int (*builtin)(char **com, char *err);

	/**
	 * shell_init();
	 */
	printf("%s\n", av[0]);
	while (ac)
	{
		input = get_input("#tite:");
		commands = parse_input(input, av[0]);
		builtin = check_builtin(commands);
		if (builtin)
			(*builtin)(commands, av[0]);
		else
			execute(commands, av[0]);
		free(input);
		free(commands);
	}
	return (0);
}
