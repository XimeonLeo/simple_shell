#include "shell.h"

/**
 * _strlen - gets the length of a string
 *
 * @string: tge string to be considered
 *
 * Return: the string length
 */

int _strlen(char *string)
{
	int str_len;

	if (string == NULL)
		return (str_len);
	str_len = 0;
	while (string[str_len])
	{
		str_len++;
	}
	return (str_len);
}


/**
 * remove_newline - removes the new line as a result of enter
 * @str: string to remove newline from
 *
 * Return: nothing
 */

void remove_newline(char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '\n')
			break;
		index++;
	}
	str[index] = '\0';
}


/**
 * tokenizer - tokenizes cmd and save as array of strings
 *
 * @input_string: string to be tokenized
 *
 * @delim: what to tokenize with
 *
 * Return: array of string containing commans
 */

char **tokenizer(char *input_string, char *delim)
{
	int num = 0;
	char **c_str = NULL, *toks = NULL, *pt = NULL;

	toks = _strtok_r(input_string, delim, &pt);

	while (toks != NULL)
	{
		c_str = _realloc(c_str, sizeof(*c_str) * num, sizeof(*c_str) * (num + 1));
		c_str[num] = toks;
		toks = _strtok_r(NULL, delim, &pt);
		num++;
	}

	c_str = _realloc(c_str, sizeof(*c_str) * num, sizeof(*c_str) * (num + 1));
	c_str[num] = NULL;

	return (c_str);
}

/**
 * _strcpy - copies a string to a new address
 *
 * @source: where to copy from
 * @dest: where to copy to
 *
 * Return: nothing
 */

void _strcpy(char *source, char *dest)
{
	int index;

	for (index = 0; source[index]; index++)
	{
		dest[index] = source[index];
	}
	dest[index] = '\0';
}

/**
 * print - help prints to user
 *
 * @string: what to print
 * @stream: where to print to (in out or err)
 *
 * Return: return nothing
 */

void print(char *string, int stream)
{
	int index;

	for (index = 0; string[index]; index++)
	{
		write(stream, &string[index], 1);
	}
}
