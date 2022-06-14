#include "shell.h"
/**
 * check_builtin - check if command entered is builtin
 * @commands: the commands enterd
 * Return: 1
 */
int (*check_builtin(char **commands))(char **commands, char *err)
{
	btin builtins[] = {
		{"cd", change_dir},
		{"exit", shell_exit},
		{"env", pr_env},
		{NULL, NULL}
	};
	int i = 0;

	if (!commands)
		return (NULL);
	/**
	for (builtins; builtins != NULL; builtins = builtins + 1)
	{
		printf("\ncommand: %s\nbuiltin: %s\n", commands[0], builtins->command);
		if (strcmp(builtins->command, commands[0]) == 0)
		{
			return (builtins->func);
		}
	};
	*/

	while (builtins[i].command != NULL)
	{
		if (strcmp(builtins[i].command, commands[0]) == 0)
		{
			return (builtins[i].func);
		}
		i++;
	}
	return (NULL);
}
/**
 * change_dir - change directory
 * @dir - directory to change to
 * Return: 1
 */
int change_dir(char **dir, char *err)
{
	if (dir[1] == NULL)
	{
		printf("\n cd error\n");
		perror(err);
	}
	else if (chdir(dir[1]) != 0)
	{
		perror(err);
	}
	return (1);
}
/**
 * exit - exit the shell
 * Return: void
 */
int shell_exit(char **com, char *err)
{
	int status = 0;

	(void)err;
	if (com[1] != NULL)
	{
		status = atoi(com[1]);
		exit(status);
	}
	exit(EXIT_SUCCESS);
}
/**
 * pr_env - print environmental variable
 * Return: 1
 */
int pr_env(char **com, char *err)
{
	extern char **environ;
	(void)com;
	(void)err;

	while(*environ != NULL)
	{
		printf("%s\n", *environ);
		environ++;
	}
	return (1);
}

