#include "shell.h"


	int status = 0;
	char **commands = NULL;
	char *line = NULL;
	char *shell_name = NULL;

/**
 * main - Entry point of the main shell code.
 * @argc: The num of args passed.
 * @argv: program args to be parsed.
 * puts to work the funcs in utils and helpers implement EOF.
 * Prints error on Failure
 * Return: 0 on success
 */

int main(int argc __attribute__((unused)), char **argv)
{
	size_t nn = 0;
	char **present_cmd = NULL;
	int index;
	int entered_cmd = 0;

	signal(SIGINT, ctrl_c);
	shell_name = argv[0];
	while (1)
	{
		non_interactive();
		_write(" ($ ) ", STDOUT_FILENO);
		if (getline(&line, &nn, stdin) == -1)
		{
			free(line);
			exit(status);
		}
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
			entered_cmd = parse_cmd(present_cmd[0]);

			initializer(present_cmd, entered_cmd);
			free(present_cmd);
		}
		free(commands);
	}
	free(line);

	return (status);
}

