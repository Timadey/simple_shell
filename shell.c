#include "shell.h"
/**
 * main - the entry of the shell program
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success or 1
 */

int main(__UNUSED__ int ac, __UNUSED__ char **av)

{
	int (*builtin)(char **com, char *err) = NULL;
	int status = 1; 
	/**
	 * shell_init();
	 */
	err = av[0];
	while (status)
	{
		input = get_input("#tite:");
		
		if (input[0] == '\n')
		{
			free(input);
			continue;
		};
		commands = parse_input(input, err);
		if (!commands)
		
			perror("Error in parsing command");
		builtin = check_builtin(commands);
		
		if (builtin != NULL)
			status = (*builtin)(commands, av[0]);
		else
			status = execute(commands, av[0]);
		free(input);
		printf("\n free input\n");
		free(commands);
		printf("\n free commands\n");
	}
	return (0);
}
