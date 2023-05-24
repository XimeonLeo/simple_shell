#include "shell.h"

/**
 * non_interactive - This funct handles non_interactive mode of the shell.
 *
 * Return: void
 */
void non_interactive(void)
{
	int index;
	int entered_cmd = 0;
	size_t nn = 0;
	char **present_cmd = NULL;

	if (!(isatty(STDIN_FILENO)))
	{
		while (getline(&line, &nn, stdin) != -1)
		{
			rmv_nl(line);
			rm_cmt(line);
			commands = tokenizer(line, ";");
			for (index = 0; commands[index] != NULL; index++)
			{
				present_cmd = tokenizer(commands[index], " ");
				if (present_cmd[0] == NULL)
				{
					free(present_cmd);
					break;
				}
				entered_cmd = parse_command(present_cmd[0]);
				initializer(present_cmd, entered_cmd);
				free(present_cmd);
			}
			free(commands);
		}
		free(line);
		exit(status);
	}
}
