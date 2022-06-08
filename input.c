#include "shell.h"
/**
 * get_input - collect user raw input from the shell
 * Return: the string
 */
char *get_input(char *msg)
{
	char *lineptr = NULL;
	size_t n_byte = 0;
	ssize_t get_byte = 0;
	char dir[PATH_MAX];

	if (getcwd(dir, sizeof(dir)) == NULL)
	{
		perror(msg);
	}
	printf("%s%s$ ", msg, dir);
	get_byte = getline(&lineptr, &n_byte, stdin);
	if (get_byte == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror(msg);
			free(lineptr);
			exit(EXIT_FAILURE);
		}
	}
	return (lineptr);
}
/**
 * parse_input - tokenize user input
 * @input: the input to tokenize
 * Return: the tokenize inputs
 */
char **parse_input(char *input, char *err )
{
	char **tokens;
	char *token;
	char *delim = TOKEN_DELIM;
	unsigned int token_size = TOKEN_SIZE;
	unsigned int n = 0;

	if (!input || !err)
		return (NULL);
	tokens = malloc(sizeof(char *) * token_size);
	if (!tokens)
	{
		perror(err);
		free(tokens);
		exit(EXIT_FAILURE);
	}
	token = strtok(input, delim);
	while (token != NULL)
	{
		tokens[n] = token;
		if (++n > token_size)
		{
			token_size += TOKEN_SIZE;
			tokens = realloc(tokens, token_size * sizeof(char *));
			if (!tokens)
			{
				perror(err);
				free(tokens);
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, delim);
	}
	return (tokens);
}
