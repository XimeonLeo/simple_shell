#include "shell.h"

/**
 * _strsub - returns the length of a sub-string
 *
 * @s1: main string
 * @s2: sub_string
 *
 * Return: num of matched bytes
 */

int my_strspn(char *s1, char *s2)
{
	int index = 0;
	int mach = 0;

	while (s1[index] != '\0')
	{
		if (my_strchr(s2, s1[index]) == NULL)
			break;
		mach++;
		index++;
	}
	return (mach);
}

/**
 * _strcmp - compare a string with another
 *
 * @s1: the first string to consider
 *
 * @s2: the sedond string to consider
 *
 * Return: difference of the two strings if different
 */

int _strcmp(char *s1, char *s2)
{
	int index = 0;

	while (s1[index])
	{
		if (s1[index] != s2[index])
		{
			break;
		}
		index++;
	}
	return (s1[index] - s2[index]);
}

/**
 * my_strcspn - what is in st1 but not in s2
 *
 * @s1: string to searched
 * @s2: string to consider
 *
 * Return: matched index
 */

int my_strcspn(char *s1, char *s2)
{
	int length = 0, index;

	for (index = 0; s1[index] != '\0'; index++)
	{
		if (my_strchr(s2, s1[index]) != NULL)
			break;
		length++;
	}
	return (length);
}


/**
 * my_strchr - return the index where a character is found
 *
 * @s1: string to search
 * @s2: what to be searched
 *
 * Return: the address of where s2 is found in s1
 */

char *my_strchr(char *s1, char s2)
{
	int index;

	for (index = 0; s1[index] != s2 && s1[index]; index++)
	{
		;
	}
	if (s1[index] == s2)
	{
		return (s1 + index);
	}
	else
		return (NULL);
}

/**
 * _strcat - append two strings together(cat)
 *
 * @str1: main string
 * @str2:  string to append to the main
 *
 * Return: a string containing contents of both strings
 */

char *_strcat(char *str1, char *str2)
{
	char *cat_str =  NULL;
	int length_1 = _strlen(str1), length_2 = _strlen(str2);

	cat_str = malloc(sizeof(*cat_str) * (length_1 + length_2 + 1));
	if (!cat_str)
	{
		return (NULL);
	}
	_strcpy(str1, cat_str);
	_strcpy(str2, cat_str + length_1);
	cat_str[length_1 + length_2] = '\0';

	return (cat_str);
}
