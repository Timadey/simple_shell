#include "shell.h"
/**
 * check_builtin - check if command entered is builtin
 * @commands: the commands enterd
 * Return: 1
 */
int (*check_builtin(char **commands))(char **commands, char *err)
{
	btin builtins[] = {
		{"cd", change_dir}
	};
	int i = 0;

	if (!commands)
		return (NULL);
	for (; i < 1; i++)
	{
		if (strcmp(commands[0], builtins->command) == 0)
		{
			return (builtins->func);
		}
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
		perror(err);
	}
	else if (chdir(dir[1]) != 0)
	{
		perror(err);
	}
	return (1);
}
