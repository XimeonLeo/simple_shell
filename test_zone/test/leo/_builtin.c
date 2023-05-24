#include "shell.h"

/**
 * quit - a builtin to exit
 *
 * @tokenized_command: cmd passed
 *
 * Return: nithing
 */

void quit(char **tokenized_command)
{
	int toks_num = 0, cmd;

	for (; tokenized_command[toks_num] != NULL; toks_num++)
	{
		;
	}
	if (toks_num == 1)
	{
		free(tokenized_command), free(line), free(commands);
		exit(status);
	}
	else if (toks_num == 2)
	{
		cmd = _atoi(tokenized_command[1]);
		if (cmd == -1)
		{
			print(shell_name, STDERR_FILENO);
			print(": 1: exit: Illegal number: ", STDERR_FILENO);
			print(tokenized_command[1], STDERR_FILENO);
			print("\n", STDERR_FILENO);
			status = 2;
		}
		else
		{
			free(line), free(tokenized_command), free(commands);
			exit(cmd);
		}
	}
	else
		print("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}


/**
 * env - prints out tne current env variable
 *
 * @tokenized_command: cmd passed
 *
 * Return: nothing
 */

void env(char **tokenized_command __attribute__((unused)))
{
	int index;

	for (index = 0; environ[index] != NULL; index++)
	{
		print(environ[index], STDOUT_FILENO);
		print("\n", STDOUT_FILENO);
	}
}