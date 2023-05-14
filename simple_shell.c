#include "shell.h"

/**
 * main - a simple shell program
 *
 * @argc: command argumennt count
 * @argv: command argument vector
 * @env: environment variable
 *
 * Return: successful in Jesus name
 */

int main(int argc, char **argv, char **env)
{
	int begin = 1;
	char *promt = "#cisfun$ ", *cmd = NULL, *delim = " \n";
	size_t cmd_size;
	int i = 0;
	char **token;

	while (begin)
	{
		begin = isatty(STDIN_FILENO);
		if (begin == 1)
		{
			write(STDOUT_FILENO, promt, 9);
		}

		if (getline(&cmd, &cmd_size, stdin) == -1)
		{
			break;
		}
		token = tokenizer(cmd, delim);
		while (token[i])
		{
			printf("%s\n", token[i]);
			i++;
		}
	}
	free(cmd);

	return (0);
}
