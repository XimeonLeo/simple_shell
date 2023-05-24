#include "shell.h"


/**
 * parse_command - This func decides the kind of the comd.
 * @command: comd to be parsed.
 *
 * Return: The const representing the kind of the comd
 * Description - EXTERNAL_COMMAND (1) reps commands such as /bin/ls.
 *		 INTERNAL_COMMAND (2) reps commands such as env, exit etc.
 *		 PATH_COMMAND (3) reps commands that is found in the PATH e.g ls
 *		 INVALID_COMMAND (-1) reps all invalid commands on this code.
 */

int parse_command(char *command)
{
	char *int_cmd[] = {"env", "exit", NULL};
	char *path = NULL;
	int index;

	for (index = 0; command[index] != '\0'; index++)
	{
		if (command[index] == '/')
			return (EXTERNAL_COMMAND);
	}
	for (index = 0; int_cmd[index] != NULL; index++)
	{
		if (_strcmp(command, int_cmd[index]) == 0)
			return (INTERNAL_COMMAND);
	}

	path = check_path(command);
	if (path != NULL)
	{
		free(path);
		return (PATH_COMMAND);
	}

	return (INVALID_COMMAND);
}

/**
 * execute_command - This executes a cmd based on it's kind.
 * @tokenized_command: form of the cmd that has been tokenized.
 * @command_type: type of the cmd
 *
 * Return: void
 */

void execute_command(char **tokenized_command, int command_type)
{
	void (*func)(char **command);

	if (command_type == EXTERNAL_COMMAND)
	{
		if (execve(tokenized_command[0], tokenized_command, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (command_type == PATH_COMMAND)
	{
		if (execve(check_path(tokenized_command[0]), tokenized_command, NULL) == -1)
		{
			perror(_getenv("PWD"));
			exit(2);
		}
	}
	if (command_type == INTERNAL_COMMAND)
	{
		func = get_func(tokenized_command[0]);
		func(tokenized_command);
	}
	if (command_type == INVALID_COMMAND)
	{
		_write(shell_name, STDERR_FILENO);
		_write(": 1: ", STDERR_FILENO);
		_write(tokenized_command[0], STDERR_FILENO);
		_write(": not found\n", STDERR_FILENO);
		status = 127;
	}
}

/**
 * check_path - This confirms if a cmd is found in the PATH.
 * @command: cmd to be implemented.
 *
 * Return: path where the cmd is found in, else, NULL if not found.
 */
char *check_path(char *command)
{
	char *temp, *temp2, *path_cpy;
	char **patharray = NULL;
	char *path = _getenv("PATH");
	int index;

	if (path == NULL || _strlen(path) == 0)
		return (NULL);
	path_cpy = malloc(sizeof(*path_cpy) * (_strlen(path) + 1));
	_strcpy(path, path_cpy);
	patharray = tokenizer(path_cpy, ":");

	for (index = 0; patharray[index] != NULL; index++)
	{
		temp2 = _strcat(patharray[index], "/");
		temp = _strcat(temp2, command);
		if (access(temp, F_OK) == 0)
		{
			free(temp2);
			free(patharray);
			free(path_cpy);
			return (temp);
		}
		free(temp);
		free(temp2);
	}
	free(path_cpy);
	free(patharray);
	return (NULL);
}

/**
 * get_func - gets a func based on the cmd given.
 * @command: the string to check against the mapping.
 *
 * Return: pointer to the proper function, or null on fail
 */

void (*get_func(char *command))(char **)
{
	int index;
	funs_zone tracking[] = {
		{"env", env}, {"exit", quit}
	};

	for (index = 0; index < 2; index++)
	{
		if (_strcmp(command, tracking[index].cmd) == 0)
			return (tracking[index].func);
	}

	return (NULL);
}

/**
 * _getenv - tracks the value of an envir var.
 * @name: the name of the environment var
 *
 * Return: the value of the variable as a string
 */

char *_getenv(char *name)
{
	char *pair_ptr;
	char **our_environ_var;
	char *nameCopy;

	for (our_environ_var = environ; *our_environ_var != NULL; our_environ_var++)
	{
		for (pair_ptr = *our_environ_var, nameCopy = name;
		     *pair_ptr == *nameCopy; pair_ptr++, nameCopy++)
		{
			if (*pair_ptr == '=')
				break;
		}
		if ((*pair_ptr == '=') && (*nameCopy == '\0'))
			return (pair_ptr + 1);
	}

	return (NULL);
}

