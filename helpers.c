#include "shell.h"

/**
 * _strcat - to append two strings
 *
 * @dest: first string to append
 * @src: second string to append
 *
 * Return: dest for success
 */

char *_strcat(char *dest, char *src)
{
	char *concat_string = NULL;
	int index, total_len = 0;

	index = 0;
	while (dest[index++])
	{
		total_len++;
	}
	index = 0;
	while (src[index++])
	{
		total_len++;
	}
	concat_string = malloc(sizeof(char) * total_len + 1);
	if (!concat_string)
	{
		return (NULL);
	}
	for (index = 0, total_len = 0; dest[index]; index++)
	{
		concat_string[total_len++] = dest[index];
	}
	for (index = 0; src[index]; index++)
	{
		concat_string[total_len++] = src[index];
	}
	concat_string[total_len] = '\0';

	return (concat_string);
}

/**
 * _strcmp - to compare two strings
 *
 * @s1: first string to consider
 * @s2: second string to consider
 *
 * Return: difference of strings
 */

int _strcmp(char *s1, char *s2)
{
	int length = 0;

	while (s1[length] == s2[length] && s1[length])
	{
		length++;
	}

	return (s1[length] - s2[length]);
}

/**
 * tokenizer - tokenizes a string into an array of strings
 *
 * @str: the string to tokenize
 * @delim: the delimiter to use for tokenization
 *
 * Return: pointer to array of strings(tokens)
 */

char **tokenizer(char *str, const char *delim)
{
	char **toks = NULL;
	char *token = NULL;
	int i = 0;

	toks = malloc(sizeof(char *) * MAX_ARGS);
	if (!toks)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(str, delim);
	while (token)
	{
		toks[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	toks[i] = NULL;

	return (toks);
}

/**
 * _strlen - Returns the length of a string.
 * @str: string to consider
 *
 * Return: Length of tge string
 */

int _strlen(char *str)
{
	int string_length = 0;

	while (str[string_length])
	{
		string_length++;
	}
	return (string_length);
}

/**
 * _strdup - Duplicates a string
 *
 * @string: String to duplicate
 *
 *Return: Pointer to the duplicated string
 */

char *_strdup(char *string)
{
	int index = 0, length = 0;
	char *str_dup;

	if (string == NULL)
	{
		return (NULL);
	}

	length = _strlen(string);

	str_dup = malloc(sizeof(char) * (length + 1));

	if (str_dup == NULL)
	{
		return (NULL);
	}
	for (index = 0; index < length; index++)
	{
		str_dup[index] = string[index];
	}
	str_dup[index] = '\0';

	return (str_dup);
}
