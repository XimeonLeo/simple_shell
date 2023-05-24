#include "shell.h"

/**
 * quit - a builtin to exit
 *
 * @cmd_toks: cmd passed
 *
 * Return: nithing
 */

void quit(char **cmd_toks)
{
	int toks_num = 0, cmd;

	for (; cmd_toks[toks_num] != NULL; toks_num++)
	{
		;
	}
	if (toks_num == 1)
	{
		free(cmd_toks), free(line), free(commands);
		exit(status);
	}
	else if (toks_num == 2)
	{
		cmd = _atoi(cmd_toks[1]);
		if (cmd == -1)
		{
			_write(shell_name, STDERR_FILENO);
			_write(": 1: exit: Illegal number: ", STDERR_FILENO);
			_write(cmd_toks[1], STDERR_FILENO);
			_write("\n", STDERR_FILENO);
			status = 2;
		}
		else
		{
			free(line), free(cmd_toks), free(commands);
			exit(cmd);
		}
	}
	else
		_write("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}


/**
 * env - prints out the current env variable
 *
 * @tokenized_command: cmd passed
 *
 * Return: nothing
 */

void env(char **cmd_toks __attribute__((unused)))
{
	int index;

	for (index = 0; environ[index] != NULL; index++)
	{
		_write(environ[index], STDOUT_FILENO);
		_write("\n", STDOUT_FILENO);
	}
}
