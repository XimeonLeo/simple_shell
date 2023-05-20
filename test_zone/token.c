#include "shell.h"

/**
 * tokenizer - tokenize a command string
 * @cmd: the command to tokenize
 * @delim: the delimiter to use for tokenization
 *
 * Return: an array of strings (toks) that were tokenized
 */
char **tokenizer(char *cmd, char *delim)
{
	int num_of_tokens = 0, i = 0;
	char *cmd_copy = NULL, *token = NULL, **toks = NULL;

	malok(cmd_copy, (_strlen(cmd) + 1));
	_strcpy(cmd_copy, cmd);
	token = strtok(cmd_copy, delim); /* Count the number of tokens */
	while (token != NULL)
	{
		num_of_tokens++;
		token = strtok(NULL, delim);
	}
	malok(*toks, (num_of_tokens + 1));
	token = strtok(cmd, delim); /* Tokenize the command */
	while (token != NULL)
	{
		toks[i] = strdup(token);
		if (toks[i] == NULL)
		{
			perror("strdup");
			for (int j = 0; j < i; j++)
			{
				free(toks[j]);
			}
			free(toks);
			free(cmd_copy);
			return (NULL);
		}
		token = strtok(NULL, delim);
		i++;
	}
	toks[i] = NULL; /* Terminate the array with a null pointer */
	free(cmd_copy);
	return (toks);
}

/**
 * malok - helper function to allocate space
 * @add: the address of tne space to be allocated
 * @size: the size to allocate
 * Return: a null pointer
 */
void *malok(char *add, int size)
{
	add = malloc(sizeof(char) * size);
	if (!add)
	{
		perror("malloc");
		free(add);
		return (NULL);
	}
	return (add);
}
