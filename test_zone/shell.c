#include "shell.h"

int main(__attribute__((unused)) int argc, __attribute__((unused)) char *av[], char **env)
{
	char *cmd = NULL;
	size_t buff_size = 0;
	ssize_t ret_val, int_mode = 1;
	char *token = NULL, *delim = " \n";
	pid_t child_pid;
	int status = 0;

	while (int_mode)
	{
		char *buffer = NULL;

		int_mode = isatty(STDIN_FILENO);
		if (int_mode == 1)
		{
			printf("#cisfun$ ");
		}

		ret_val = getline(&cmd, &buff_size, stdin);

		if (ret_val == -1)
		{
			break;
		}
		else
		{
			token = strtok(cmd, delim);

			child_pid = fork();

			if (child_pid == -1)
			{
				exit(EXIT_FAILURE);
			}
			else if (child_pid == 0)
			{
				char *argv[] = {token, NULL};

				if (execve(argv[0], argv, env) == -1)
				{
					perror(av[0]);
				}
			}
			else
			{
				wait(&status);
			}
		}
		free(buffer);
	}

	return (0);
}
