#include "shell.h"


	int status = 0;
	char **commands = NULL;
	char *line = NULL;
	char *my_shell = NULL;

/**
 * main - begining of shell
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */

int main(int argc __attribute__((unused)), char **argv)
{
	size_t buff_size = 0;
	char **cmd_pssd = NULL;
	int index;
	int entered_cmd = 0;

	signal(SIGINT, ctrl_c);
	my_shell = argv[0];
	while (1)
	{
		non_interac_mode();
		_write(" :) ", STDOUT_FILENO);
		if (getline(&line, &buff_size, stdin) == -1)
		{
			free(line);
			exit(status);
		}
			rmv_nl(line);
			rm_cmt(line);
			commands = tokenizer(line, ";");

		for (index = 0; commands[index] != NULL; index++)
		{
			cmd_pssd = tokenizer(commands[index], " ");
			if (cmd_pssd[0] == NULL)
			{
				free(cmd_pssd);
				break;
			}
			entered_cmd = parse_cmd(cmd_pssd[0]);

			init(cmd_pssd, entered_cmd);
			free(cmd_pssd);
		}
		free(commands);
	}
	free(line);

	return (status);
}

