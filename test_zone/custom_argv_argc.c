#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int ac, i;
	char **av = NULL;
	char *cmd = NULL, *cmd_dup = NULL;
	char *token = NULL, *delim = " \n";
	size_t cmd_size = 0;

	printf("(⁠ヘ⁠･⁠_⁠･⁠)⁠ヘ ");
	if (getline(&cmd, &cmd_size, stdin) == -1)
	{
		return (-1);
	}
	else
	{
		cmd_dup = malloc(sizeof(char) * strlen(cmd) + 1);
		strcpy(cmd_dup, cmd);

		token = strtok(cmd, delim);
		ac = 0;
		while(token)
		{
			token = strtok(NULL, delim);
			ac++;
		}
		printf("ac = %d\n", ac);

		av = malloc(sizeof(char *) * ac);

		token = strtok(cmd_dup, delim);
		i = 0;
		while (token)
		{
			av[i] = token;
			token = strtok(NULL, delim);
			i++;
		}
		av[i] = '\0';

		i = 0;
		while(av[i])
		{
			printf("token in index[%d] is %s\n", i, av[i]);
			i++;
		}
			free(cmd_dup);
			free(cmd);
			free(av);
	}
	return (0);
}
