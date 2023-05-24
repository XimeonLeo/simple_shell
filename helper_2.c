#include "shell.h"

/**
 * modif_path - modifies the path variable
 *
 * @path: the path variable
 *
 * Return: a modified path variable
 */

char *modif_path(char *path)
{
	int num_of_column = 0, i = 0, j = 0;
	char *tmp_path = NULL;

	i = 0;
	while (path[i])
	{
		if (path[i] == ':')
			num_of_column++;
		else
			break;
	}
	tmp_path = malloc(sizeof(char) * _strlen(path) + (num_of_column + 2));
	if (!tmp_path)
	{
		perror("malloc");
		return (NULL);
	}
	for (i = 0, j = 0; path[i]; i++)
	{
		if (path[i] == ':')
		{
			tmp_path[j++] = '/';
			tmp_path[j++] = ':';
		}
		else
			tmp_path[j++] = path[i];
	}
	tmp_path[j++] = '/';
	tmp_path[j++] = '\0';

	return (tmp_path);
}

/**
 * path_finder - gets the PATH variable from the environment variable
 *
 * @av: argument vector
 * @ev: the environment variable
 *
 * Return: the path if found
 */

char *path_finder(char **av, char **ev)
{
	int i;
	char *path = NULL;

	for (i = 0; ev[i]; i++)
	{
		if (_strncmp(ev[i], "PATH=", 5) == 0)
		{
			path = _strdup(ev[i]); /* malloced */
		}
	}
	if (!path)
	{
		perror(av[0]);
	}

	return (path);
}

/**
 * _builtin - Handles built-in commands
 *
 * @cmd: Array of strings containing the command and its arguments
 * @ev: The environment variable
 *
 * Return: 0 if command is a built-in, -1 otherwise
 */

int _builtin(char *cmd, char **ev)
{
	if (cmd == NULL)
	{
		return (-1);
	}
	if (_strcmp(cmd, "exit\n") == 0)
	{
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp(cmd, "env\n") == 0)
	{
		int i;

		for (i = 0; ev[i]; i++)
		{
			printf("%s\n", ev[i]);
		}
		free(cmd);
		return (0);
	}
	return (-1);
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
