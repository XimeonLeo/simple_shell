#include "shell.h"


/**
 * _strtok_r - strtok modified!!!
 *
 * @string: string to tokenize
 * @delim: delimiter used for tokenization
 * @save_ptr: pointer to where a delimeter is found
 *
 * Return: The next token if not NULL
 */

char *_strtok_r(char *string, char *delim, char **save_ptr)
{
	char *end;

	if (string == NULL)
	{
		string = *save_ptr;
	}

	if (*string == '\0')
	{
		*save_ptr = string;
		return (NULL);
	}

	string += _strspn(string, delim);

	if (*string == '\0')
	{
		*save_ptr = string;
		return (NULL);
	}

	end = string + _strcspn(string, delim);

	if (*end == '\0')
	{
		*save_ptr = end;
		return (string);
	}

	*end = '\0';
	*save_ptr = end + 1;

	return (string);
}

/**
 * _atoi - changes a char to int
 *
 * @s: the string to consider
 *
 * Return: an int str
 */

int _atoi(char *s)
{
	size_t itger = 0;

	do {
		if (*s == '-')
		{
			return (-1);
		}
		else if ((*s < '0' || *s > '9') && *s != '\0')
		{
			return (-1);
		}
		else if (*s >= '0'  && *s <= '9')
		{
			itger = (itger * 10) + (*s - '0');
		}
		else if (itger > 0)
		{
			break;
		}
	} while (*s++);

	return (itger);
}

/**
 * _realloc - reallocates a memory for other use
 *
 * @ptr: pointer to a malloced memory
 * @old_size: size of ptr
 * @new_size: new size to be reallocatef
 *
 * Return: pointer to tge address of a reallocated memory block
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *tmp;
	size_t index;

	if (ptr == NULL)
	{
		tmp = malloc(new_size);
		return (tmp);
	}
	else if (new_size == old_size)
	{
		return (ptr);
	}
	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		tmp = malloc(new_size);
		if (tmp != NULL)
		{
			for (index = 0; index < min(old_size, new_size); index++)
				*((char *)tmp + index) = *((char *)ptr + index);
			free(ptr);

			return (tmp);
		}
		else
			return (NULL);

	}
}

/**
 * ctrl_c_handler - handles the signal -> CTRL-C
 *
 * @signum: signal val
 *
 * Return: nothinh
 */

void ctrl_c_handler(int signum)
{
	if (signum == SIGINT)
	{
		_write("\n($) ", STDIN_FILENO);
	}
}

/**
 * remove_comment - neglet inputs after '#'
 *
 * @input: input
 *
 * Return: nothing
 */

void remove_comment(char *input)
{
	int index = 0;

	if (input[index] == '#')
	{
		input[index] = '\0';
	}
	while (input[index])
	{
		if (input[index] == '#' && input[index - 1] == ' ')
		{
			break;
		}
		index++;
	}
	input[index] = '\0';
}


