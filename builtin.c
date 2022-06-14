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
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
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
	char cur_dir[PATH_MAX];

	if (getcwd(cur_dir, sizeof(cur_dir)) == NULL)
	{
		perror(err);
	};
	if (dir[1] == NULL)
	{
		dir[1] = getenv("HOME");
	}
	else if ((strncmp(dir[1], "-", 1)) == 0)
	{
		dir[1] = getenv("OLDPWD");
	};
	if (chdir(dir[1]) != 0)
	{
		perror(err);
	}
	if ((setenv("PWD", dir[1], 1)) == -1)
		perror(err);
	if ((setenv("OLDPWD", cur_dir, 1)) == -1)
		perror(err);

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
/**
 * _setenv - set an environment variable
 */
int _setenv(char **com, char *err)
{
	if (com)
	{
		if (com[1] != NULL && com[2] != NULL)
		{
			if ((setenv(com[1], com[2], 1)) == -1)
				perror(err);
		}
		else
			perror(err);
	};
	return (1);
}
/**
 * _unsetenv - unset an environment variable
 */
int _unsetenv(char **com, char *err)
{
	(void)com;
	(void)err;

	return (1);
}
