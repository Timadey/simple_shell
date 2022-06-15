#include "shell.h"
/**
 * get_input - collect user raw input from the shell
 * Return: the string
 */
char *get_input(char *msg)
{
	char *lineptr = NULL;
	size_t n_byte = 0;
	int get_byte = 0;
	char dir[PATH_MAX];

	if (getcwd(dir, sizeof(dir)) == NULL)
	{
		perror(msg);
	}
	printf("%s%s$ ", msg, dir);
	get_byte = _getline(&lineptr, &n_byte, stdin);
	if (get_byte == EOF)
	{
		free(lineptr);
		exit(EXIT_SUCCESS);
		/*if (feof(stdin))
		{
			printf("\n");
			free(lineptr);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror(msg);
			free(lineptr);
			exit(EXIT_FAILURE);
		}*/
	}
	return (lineptr);
}
/**
 * parse_input - tokenize user input
 * @input: the input to tokenize
 * Return: the tokenize inputs
 */
char **parse_input(char *input, char *err)
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
/**
 * check_malloc - check if malloc failed
 */
void check_malloc (char *mallocd)
{
	if (mallocd == NULL)
	{
		free(mallocd);
		perror(err);
		exit(EXIT_FAILURE);
	}
}
/**
 * getline
 * assume that we're working with stdin for the moment which is opened already
 * so we don't need to open and close
 */

int _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *line;
	size_t buf_size = BUF_SIZE;
	size_t index = 0;
	int c;

	(void) stream;
	line = malloc(buf_size * sizeof(char));
	check_malloc(line);
	while(1)
	{
		c = getchar();
		if (c == '\n')
		{
			line[index] = c;
			*n = index;
			*lineptr = line;
			return (index);
		}
		else if (c == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			line[index] = c;
		}
		index++;

		if (index >= buf_size)
		{
			buf_size += BUF_SIZE;
			line = realloc(*lineptr, buf_size * sizeof(char));
			check_malloc(line);
		}
	}

	return (1);
}

