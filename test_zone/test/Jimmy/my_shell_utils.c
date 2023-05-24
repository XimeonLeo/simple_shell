#include "shell.h"


/**
<<<<<<< HEAD
 * parse_cmd - This func decides the kind of the comd.
 * @command: comd to be parsed.
=======
 * parse_command - This func decides the kind of the comd.
 * @cmd: comd to be parsed.
>>>>>>> e7a2930354fa513adbcbbc95cceb77c959bb98bc
 *
 * Return: The const representing the kind of the comd
 * Description - EXTERNAL_COMMAND (1) reps commands such as /bin/ls.
 *		 INTERNAL_COMMAND (2) reps commands such as env, exit etc.
 *		 PATH_COMMAND (3) reps commands that is found in the PATH e.g ls
 *		 INVALID_COMMAND (-1) reps all invalid commands on this code.
 */

<<<<<<< HEAD
int parse_cmd(char *command)
=======
int parse_command(char *cmd)
>>>>>>> e7a2930354fa513adbcbbc95cceb77c959bb98bc
{
	char *int_cmd[] = {"env", "exit", NULL};
	char *path = NULL;
	int index;

	for (index = 0; cmd[index] != '\0'; index++)
	{
		if (cmd[index] == '/')
			return (EXTERNAL_COMMAND);
	}
	for (index = 0; int_cmd[index] != NULL; index++)
	{
		if (_strcmp(cmd, int_cmd[index]) == 0)
			return (INTERNAL_COMMAND);
	}

<<<<<<< HEAD
	path = path_inspect(command);
=======
	path = check_path(cmd);
>>>>>>> e7a2930354fa513adbcbbc95cceb77c959bb98bc
	if (path != NULL)
	{
		free(path);
		return (PATH_COMMAND);
	}

	return (INVALID_COMMAND);
}

/**
<<<<<<< HEAD
 * exec_comd - This executes a cmd based on it's kind.
 * @tokenized_command: form of the cmd that has been tokenized.
 * @command_type: type of the cmd
=======
 * execute_command - This executes a cmd based on it's kind.
 * @cmd_toks: form of the cmd that has been tokenized.
 * @cmd_typ: type of the cmd
>>>>>>> e7a2930354fa513adbcbbc95cceb77c959bb98bc
 *
 * Return: void
 */

<<<<<<< HEAD
void exec_comd(char **tokenized_command, int command_type)
=======
void execute_command(char **cmd_toks, int cmd_typ)
>>>>>>> e7a2930354fa513adbcbbc95cceb77c959bb98bc
{
	void (*func)(char **command);

	if (cmd_typ == EXTERNAL_COMMAND)
	{
		if (execve(cmd_toks[0], cmd_toks, NULL) == -1)
		{
			perror(get_environ("PWD"));
			exit(2);
		}
	}
	if (cmd_typ == PATH_COMMAND)
	{
<<<<<<< HEAD
		if (execve(path_inspect(tokenized_command[0]), tokenized_command, NULL) == -1)
=======
		if (execve(check_path(cmd_toks[0]), cmd_toks, NULL) == -1)
>>>>>>> e7a2930354fa513adbcbbc95cceb77c959bb98bc
		{
			perror(get_environ("PWD"));
			exit(2);
		}
	}
	if (cmd_typ == INTERNAL_COMMAND)
	{
<<<<<<< HEAD
		func = get_function(tokenized_command[0]);
		func(tokenized_command);
=======
		func = get_func(cmd_toks[0]);
		func(cmd_toks);
>>>>>>> e7a2930354fa513adbcbbc95cceb77c959bb98bc
	}
	if (cmd_typ == INVALID_COMMAND)
	{
		_write(shell_name, STDERR_FILENO);
		_write(": 1: ", STDERR_FILENO);
		_write(cmd_toks[0], STDERR_FILENO);
		_write(": not found\n", STDERR_FILENO);
		status = 127;
	}
}

/**
<<<<<<< HEAD
 * path_inspect - This confirms if a cmd is found in the PATH.
 * @command: cmd to be implemented.
 *
 * Return: path where the cmd is found in, else, NULL if not found.
 */
char *path_inspect(char *command)
=======
 * check_path - This confirms if a cmd is found in the PATH.
 * @cmd: cmd to be implemented.
 *
 * Return: path where the cmd is found in, else, NULL if not found.
 */
char *check_path(char *cmd)
>>>>>>> e7a2930354fa513adbcbbc95cceb77c959bb98bc
{
	char *temp, *temp2, *path_cpy;
	char **patharray = NULL;
	char *path = get_environ("PATH");
	int index;

	if (path == NULL || _strlen(path) == 0)
		return (NULL);
	path_cpy = malloc(sizeof(*path_cpy) * (_strlen(path) + 1));
	_strcpy(path, path_cpy);
	patharray = tokenizer(path_cpy, ":");

	for (index = 0; patharray[index] != NULL; index++)
	{
		temp2 = _strcat(patharray[index], "/");
		temp = _strcat(temp2, cmd);
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
<<<<<<< HEAD
 * get_function - gets a func based on the cmd given.
 * @command: the string to check against the mapping.
=======
 * get_func - gets a func based on the cmd given.
 * @cmd: the string to check against the mapping.
>>>>>>> e7a2930354fa513adbcbbc95cceb77c959bb98bc
 *
 * Return: pointer to the proper function, or null on fail
 */

<<<<<<< HEAD
void (*get_function(char *command))(char **)
=======
void (*get_func(char *cmd))(char **)
>>>>>>> e7a2930354fa513adbcbbc95cceb77c959bb98bc
{
	int index;
	funs_zone tracking[] = {
		{"env", env}, {"exit", quit}
	};

	for (index = 0; index < 2; index++)
	{
		if (_strcmp(cmd, tracking[index].cmd) == 0)
			return (tracking[index].func);
	}

	return (NULL);
}

/**
<<<<<<< HEAD
 * get_environ - tracks the value of an envir var.
 * @name: the name of the environment var
=======
 * _getenv - tracks the value of an envir var.
 * @pt: the name of the environment var
>>>>>>> e7a2930354fa513adbcbbc95cceb77c959bb98bc
 *
 * Return: the value of the variable as a string
 */

<<<<<<< HEAD
char *get_environ(char *name)
=======
char *_getenv(char *pt)
>>>>>>> e7a2930354fa513adbcbbc95cceb77c959bb98bc
{
	char *pair_ptr;
	char **our_environ_var;
	char *nameCopy;

	for (our_environ_var = environ; *our_environ_var != NULL; our_environ_var++)
	{
		for (pair_ptr = *our_environ_var, nameCopy = pt;
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

