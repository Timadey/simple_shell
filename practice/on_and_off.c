#include "shell.h"
/**
 * shell_init - contructor
 */
void __attribute__((constructor)) shell_init()
{
	printf("\nWelcome\n");
}

/**
 * shell_destroy
 */
void __attribute__((destructor)) shell_destroy()
{
	if (input != NULL)
	{	free(input);
	};
	if (commands != NULL)
	{
		free(commands);
	};
}
