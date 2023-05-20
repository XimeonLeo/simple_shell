#include "shell.h"

/**
 * tokenizer - it tokenize the command gotten from getline
 *
 * @cmd: the command to tokenize
 * @delim: the delimeter to use to tokenize
 *
 * Return: an array of strings(toks) that was tokenized
 */

char **tokenizer(char *cmd, char *delim)
{
	int num_of_token = 0, counter = 0;
	char *cmd_cpy = NULL, *token = NULL;
	char tok[MAX_ARR];

	cmd_cpy = malloc(sizeof(char) * _strlen(cmd) + 1);
	_strcpy(cmd_cpy, cmd);

	token = strtok(cmd_cpy, delim);

	while (token)
	{
		token = strtok(NULL, delim);
		num_of_token++;
	}

	token = strtok(cmd, delim);

	while (token)
	{
		tok[counter] = strdup(token);
		token = strtok(NULL, delim);
		counter++;
	}
	tok[counter] = token;

	return (tok);
}
