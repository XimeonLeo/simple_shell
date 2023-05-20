#include "shell.h"

/**
 * _builtin - Handles built-in commands
 *
 * @args: Array of strings containing the command and its arguments
 *
 * Return: 1 if command is a built-in, 0 otherwise
 */

int _builtin(char *cmd, char **ev)
{
	if (cmd == NULL)
	{
		return (1);
	}
	if (_strcmp(cmd, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp(cmd, "env") == 0)
	{
		int i;

		for (i = 0; ev[i]; i++)
		{
			printf("%s\n", ev[i]);
		}
		return (1);
	}
	return (0);
}

/**
 * _strcpy - to copy a string using pointers
 * @dest: where to copy into
 * @src: string to copy
 *
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int block = 0;

	while (src[block] != '\0')
	{
		dest[block] = src[block];
		block++;
	}

	dest[block] = '\0';

	return (dest);
}

/**
 * _strncmp - compares the first n bytes of two trings
 *
 * @str1: the first string to consider
 * @str2: the second string to consider
 * @n: the number of bytes to consider
 *
 * Return: the difference between the bytes considered
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		else if (str1[i] == '\0' || str2[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}
