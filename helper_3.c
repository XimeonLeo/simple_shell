#include "shell.h"

/**
 * tok_num - gets the number of tokens from a string
 *
 * @str: the string to tokenize
 * @delim: the delimeter used
 *
 * Return: the number of tokens
 */

int tok_num(char *str, const char *delim)
{
	size_t num = 0;
	char *token = NULL;

	token = strtok(str, delim);

	while (token)
	{
		num++;

		token = strtok(NULL, delim);
	}
	return (num);
}
