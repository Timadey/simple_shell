#include "shell.h"
/**
 * main - the entry of the shell program
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success or 1
 */

int main(__UNUSED__ int ac, __UNUSED__ char **av)

{
	char *input;
	char **commands = NULL;
	int (*builtin)(char **com, char *err) = NULL;
	int status = 1; 
	/**
	 * shell_init();
	 */
	printf("%s\n", av[0]);
	while (status != -1)
	{
		input = get_input("#tite:");
		
		if (input[0] == '\n' || input == NULL)
			continue;
		commands = parse_input(input, av[0]);
		if (!commands)
		
			perror("Error in parsing command");
		builtin = check_builtin(commands);
		
		if (builtin != NULL)
			status = (*builtin)(commands, av[0]);
		else
			status = execute(commands, av[0]);
		free(input);
		free(commands);
	}
	printf("\n");
	return (0);
}
