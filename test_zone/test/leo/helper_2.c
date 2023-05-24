#include "shell.h"


/**
 * _strtok_r - strtok modified!!!
 *
 * @str: string to tokenize
 * @delim: delimiter used for tokenization
 * @new_ptr: pointer to where a delimeter is found
 *
 * Return: The next token if not NULL
 */

char *_strtok_r(char *str, char *delim, char **new_ptr)
{
	char *end;

	if (str == NULL)
	{
		str = *new_ptr;
	}

	if (*str == '\0')
	{
		*new_ptr = str;
		return (NULL);
	}

	str += _strsub(str, delim);

	if (*str == '\0')
	{
		*new_ptr = str;
		return (NULL);
	}

	end = str + my_strcspn(str, delim);

	if (*end == '\0')
	{
		*new_ptr = end;
		return (str);
	}

	*end = '\0';
	*new_ptr = end + 1;

	return (str);
}

/**
 * _atoi - changes a char to int
 *
 * @s: the string to consider
 *
 * Return: an int str
 */

int _atoi(char *str)
{
	size_t itger = 0;

	do {
		if (*str == '-')
		{
			return (-1);
		}
		else if ((*str < '0' || *str > '9') && *str != '\0')
		{
			return (-1);
		}
		else if (*str >= '0'  && *str <= '9')
		{
			itger = (itger * 10) + (*str - '0');
		}
		else if (itger > 0)
		{
			break;
		}
	} while (*str++);

	return (itger);
}

/**
 * _realloc - reallocates a memory for other use
 *
 * @ptr: pointer to a malloced memory
 * @old_mem: size of ptr
 * @new_mem: new size to be reallocatef
 *
 * Return: pointer to tge address of a reallocated memory block
 */

void *_realloc(void *ptr, size_t old_mem, size_t new_mem)
{
	void *tmp;
	size_t index;

	if (ptr == NULL)
	{
		tmp = malloc(new_mem);
		return (tmp);
	}
	else if (new_mem == old_mem)
	{
		return (ptr);
	}
	else if (new_mem == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		tmp = malloc(new_mem);
		if (tmp != NULL)
		{
			for (index = 0; index < min(old_mem, new_mem); index++)
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
 * @sig_val: signal val
 *
 * Return: nothinh
 */

void ctrl_c_handler(int sig_val)
{
	if (sig_val == SIGINT)
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


