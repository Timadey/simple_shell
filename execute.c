#include "shell.h"
/**
 * execute - execute command
 * @commands - the commands to execute
 * Return: int
 */
int execute(char **commands)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(commands[0], commands) == -1)
		{
			perror("Execution error");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Execution error");
	}
	else
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
