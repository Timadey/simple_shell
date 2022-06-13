#include "shell.h"
/**
 * execute - execute command
 * @commands - the commands to execute
 * Return: int
 */
int execute(char **commands, char *err)
{
	pid_t pid;
	int status;

	if (!commands || !err)
		return (-1);
	if (commands[0][0] == '/')
	{
		if (access(commands[0], F_OK) == -1)
		{
			perror(err);
			return (1);
		}
	}
	pid = fork();
	if (pid == 0)
	{
		if (execvp(commands[0], commands) == -1)
		{
			perror(err);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror(err);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
