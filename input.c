#include "shell.h"
/**
 * get_input - collect user raw input from the shell
 * Return: the string
 */
char *get_input(void)
{
	char *lineptr = NULL;
	size_t n_byte = 0;
	ssize_t get_byte = 0;

	get_byte = getline(&lineptr, &n_byte, stdin);
	if (get_byte < 0)
	{
		perror("tsh: couldn't read input");
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	return (lineptr);
}
/**
 * parse_input - tokenize user input
 * @input: the input to tokenize
 * Return: the tokenize inputs
 */
char **parse_input(char *input)
{
	char **tokens;
	char *token;
	char *delim = " ";
	unsigned int token_size = TOKEN_SIZE;
	unsigned int n = 0;

	tokens = malloc(sizeof(char *) * token_size);
	if (!tokens)
	{
		perror("tsh: token allocation error");
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
				perror("tsh: token allocation error");
				free(tokens);
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, delim);
	}
	return (tokens);
}
