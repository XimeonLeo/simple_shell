#include "shell.h"

/**
 * init - This func starts executing our code.
 * @current_command: checks recent token used.
 * @type_command: This rep parse token.
 *
 * Return: void function.
 */
void init(char **current_command, int type_command)
{
	pid_t PID;

	if (type_command == EXTERNAL_COMMAND || type_command == PATH_COMMAND)
	{
		PID = fork();
		if (PID == 0)
		{
			exec_comd(current_command, type_command);
		}
		else
		{
			waitpid(PID, &status, 0);
			status >>= 8;
		}
	}
	else
		exec_comd(current_command, type_command);
}
