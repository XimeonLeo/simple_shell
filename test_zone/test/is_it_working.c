#include "shell.h"

int main(int ac, char **av, char **ev)
{
	char str[] = "Jesus help us";
	char *new_str = NULL;
	char *delim = " :\n";
	char **toks;
	int i = 0, j, num_column = 0;
	char *path = NULL, *tmp_path = NULL;
	char *cmd = "ls -la", *exe_cmd = NULL;
	struct stat st;

	if (stat(cmd, &st) == 0)
	{
		printf("found... just testing\n");
	}
	else
	{
		printf("nothimg found... it works\n");
	}

	printf("\n**************************************************\n");
	while (i < ac)
	{
		printf("av = %s\n", av[i]);
		i++;
	}

	printf("\n\n\n*********JUST MAKING USE OF AV AND AC************\n\n\n");
	new_str = _strdup(str);

	printf("\n**************************************************\n");
	printf("The duplicated string = %s\n", new_str);
	printf("\n\n\n*********TESTING DUPLICATING FUNCTION*************\n\n\n");

	toks = tokenizer(new_str, delim);

	printf("\n\n\n**************************************************\n\n\n");
	i = 0;
	while (toks[i])
	{
		printf("Token[%d] = %s\n", (i + 1), toks[i]);
		i++;
	}
	printf("\n\n\n*******TESTING TOKENIZER FUNCTION WITH A STR*******\n\n\n");

	printf("\n**************************************************\n");
	i = 0;
	while (ev[i])
	{
		printf("**********MY ENV[%d]**********\n%s\n",(i + 1), ev[i]);
		i++;
	}
	printf("\n\n\n**************PRINTING EV VARIABLE*****************\n\n\n");

	printf("\n\n\n**************************************************\n\n\n");
	for (i = 0; ev[i]; i++)
	{
		if (_strncmp(ev[i], "PATH=", 5) == 0)
		{
			path = _strdup(ev[i]);
		}
	}
	if (!path)
	{
		perror(av[0]);
	}
	printf("The path ->  %s\n", path);
	printf("\n\n\n*********LOCATING THE PATH*****************\n\n\n");


	printf("\n**************************************************\n");

	i = 0;
	while (path[i])
	{
		printf("\n");
		if (path[i] == ':')
		{
			num_column++;
		}
		else
			break;
	}

	tmp_path = malloc(sizeof(char) * _strlen(path) + (num_column + 2));
	if (!tmp_path)
	{
                perror("malloc failed");
                return (0);
        }

        for (i = 0, j = 0; path[i]; i++)
        {
                if (path[i] == ':')
                {
                        tmp_path[j++] = '/';
                        tmp_path[j++] = ':';
                }
                else
                {
                        tmp_path[j++] = path[i];
                }
        }
	tmp_path[j++] = '/';
        tmp_path[j++] = '\0';

        _strcpy(path, tmp_path); /* copy the new string back into the original */

	printf("My new path -> %s\n", path);

	free(toks);
	toks = tokenizer(path, delim);

	i = 0;
	while (toks[i])
	{
		printf("Path_tokens[%d] = %s\n", (i + 1), toks[i]);
		i++;
	}


	printf("\n***********TOKENIZING THE PATH VARIABLE*************\n");

	_builtin(cmd, ev);
	i = 0;
	while (toks[i])
	{
		exe_cmd = _strcat(toks[i], cmd);

		if (!exe_cmd)
		{
			return (-1);
		}
		printf("comand[%d] = %s\n", (i + 1), exe_cmd);
		if (stat(exe_cmd, &st) == 0)
		{
			printf("At last\n");
		}
		else
		{
			printf("File not found, its working\n");
		}
		free(exe_cmd);

		i++;
	}

	free(tmp_path);
	free(new_str);
	free(toks);
	free(path);

	return (0);
}
