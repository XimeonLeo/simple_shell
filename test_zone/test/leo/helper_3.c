#include "shell.h"

/**
 * _strspn - returns the length of a sub-string
 *
 * @str1: main string
 * @str2: sub_string
 *
 * Return: num of matched bytes
 */

int _strspn(char *str1, char *str2)
{
	int index = 0;
	int mach = 0;

	while (str1[index] != '\0')
	{
		if (_strchr(str2, str1[index]) == NULL)
			break;
		mach++;
		index++;
	}
	return (mach);
}

/**
 * _strcmp - compare a string with another
 *
 * @first: the first string to consider
 *
 * @second: the sedond string to consider
 *
 * Return: difference of the two strings if different
 */

int _strcmp(char *first, char *second)
{
	int index = 0;

	while (first[index])
	{
		if (first[index] != second[index])
		{
			break;
		}
		index++;
	}
	return (first[index] - second[index]);
}

/**
 * _strcspn - what is in st1 but nit in s2
 *
 * @str1: string to searched
 * @str2: string to consider
 *
 * Return: matched index
 */

int _strcspn(char *str1, char *str2)
{
	int length = 0, index;

	for (index = 0; str1[index] != '\0'; index++)
	{
		if (_strchr(str2, str1[index]) != NULL)
			break;
		length++;
	}
	return (length);
}


/**
 * _strchr - return the index where a character is found
 *
 * @s: string to search
 * @c: what to be searched
 *
 * Return: tge address of where c is found in s
 */

char *_strchr(char *s, char c)
{
	int index;

	for (index = 0; s[index] != c && s[index]; index++)
	{
		;
	}
	if (s[index] == c)
	{
		return (s + index);
	}
	else
		return (NULL);
}

/**
 * _strcat - append two strings together(cat)
 *
 * @destination: main string
 * @source:  string to append to the main
 *
 * Return: a string containing contents of both strings
 */

char *_strcat(char *destination, char *source)
{
	char *cat_str =  NULL;
	int length_1 = _strlen(destination), length_2 = _strlen(source);

	cat_str = malloc(sizeof(*cat_str) * (length_1 + length_2 + 1));
	if (!cay_str)
	{
		return (NULL);
	}
	_strcpy(destination, cat_str);
	_strcpy(source, cat_str + length_1);
	cat_str[length_1 + length_2] = '\0';

	return (cat_str);
}
