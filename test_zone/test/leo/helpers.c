#include "shell.h"

/**
 * _strlen - gets the length of a string
 *
 * @str: the string to be considered
 *
 * Return: the string length
 */

int _strlen(char *str)
{
	int str_len;

	if (str == NULL)
	{
		return (0);
	}
	str_len = 0;
	while (str[str_len])
	{
		str_len++;
	}

	return (str_len);
}


/**
 * rmv_nl - removes the new line as a result of enter
 * @str: string to remove newline from
 *
 * Return: nothing
 */

void rmv_nl(char *str)
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
 * @cmd: string to be tokenized
 *
 * @delim: what to tokenize with
 *
 * Return: array of string containing commans
 */

char **tokenizer(char *cmd, char *delim)
{
	int num = 0;
	char **c_str = NULL, *toks = NULL, *pt = NULL;

	toks = _strtok_r(cmd, delim, &pt);

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
 * @s1: where to copy from
 * @s2: where to copy to
 *
 * Return: nothing
 */

void _strcpy(char *s1, char *s2)
{
	int index;

	for (index = 0; s1[index]; index++)
	{
		s2[index] = s1[index];
	}
	s2[index] = '\0';
}

/**
 * _write - help prints to user
 *
 * @str: what to print
 * @stm: where to print to (in out or err)
 *
 * Return: return nothing
 */

void _write(char *str, int stm)
{
	int index;

	for (index = 0; str[index]; index++)
	{
		write(stm, &str[index], 1);
	}
}
