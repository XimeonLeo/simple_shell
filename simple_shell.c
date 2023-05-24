#include "shell.h"

/**
 * main - a simple shell program
 *
 * @ac: command argumennt count
 * @av: command argument vector
 * @ev: environment variable
 *
 * Return: successful in Jesus name
 */

int main(__attribute__((unused)) int ac, char **av, char **ev)
{
	int begin = 1;
	char *promt = "#cisfun$ ", *cmd = NULL, *tmp_cmd = NULL;
	size_t cmd_size = 0, num_toks = 0;
	char **exe_cmd = NULL, **cmd_toks  = NULL;
	struct stat st;

	signal(SIGINT, SIG_IGN); /* This helps to handle ctrl + c */
	sleep(1);
	while (begin)
	{
		begin = isatty(STDIN_FILENO);
		if (begin == 1)
			write(STDOUT_FILENO, promt, 9);
		if (getline(&cmd, &cmd_size, stdin) == -1)
			break;
		if (*cmd == '\n')
			continue;
		if ((_strcmp(cmd, "exit\n")) == 0 || (_strcmp(cmd, "env\n")) == 0)
		{
			_builtin(cmd, ev);
			continue; /* cross check */
		}
		tmp_cmd = _strdup(cmd);
		cmd_toks = tokenizer(cmd, " \n");
		num_toks = tok_num(tmp_cmd, " \n");
		if (stat(cmd_toks[0], &st) == 0)
		{
			execute(cmd_toks, ev);
			free(tmp_cmd), free(cmd_toks);
			continue;
		}	exe_cmd = exec_cmd(cmd_toks, num_toks, av, ev);
		if (exe_cmd == NULL)
		{
			free(tmp_cmd);
			continue;
		}	execute(exe_cmd, ev);
		free(exe_cmd), free(tmp_cmd);
	}
	free(cmd);
	return (0);
}

/**
 * exec_cmd - makes appeneds a comand with the right path
 *
 * @cmd_toks: an array of command
 * @num_toks: the number of tokens in the command
 * @av: the argument vector
 * @ev: the environment variable
 *
 * Return: the right command path
 */
char **exec_cmd(char **cmd_toks, size_t num_toks, char **av, char **ev)
{
	char **path_toks = NULL, **exe_cmd = NULL;
	char *path = NULL, *tmp = NULL;
	struct stat st;
	size_t len = 0, i = 0, j = 0;

	path = path_finder(av, ev);
	tmp = modif_path(path); /* malloced */
	path_toks = tokenizer(tmp, " :=\n"); /* malloced */
	exe_cmd = malloc(sizeof(char *) * num_toks + 1);

	while (path_toks[i])
	{
		len = ((_strlen(path_toks[i])) + (_strlen(cmd_toks[0])) + 1);
		exe_cmd[0] = malloc(sizeof(char) * len);
		_strcpy(exe_cmd[0], path_toks[i]);
		strcat(exe_cmd[0], cmd_toks[0]);
		if (stat(exe_cmd[0], &st) == 0)
		{
			for (j = 1; cmd_toks[j] != NULL; j++)
			{
				exe_cmd[j] = malloc(_strlen(cmd_toks[j]) + 1);
				_strcpy(exe_cmd[j], cmd_toks[j]);
			}
			exe_cmd[j] = NULL;
			free(cmd_toks), free(path);
			free(tmp), free(path_toks);
			return (exe_cmd);
		}
		free(exe_cmd[0]);
		i++;
	}
	perror(av[0]);
	free(cmd_toks), free(path);
	free(tmp), free(path_toks), free(exe_cmd);
	return (NULL);
}


/**
 * execute - executes the function passed
 *
 * @cmd: the command to execute
 * @ev: the environment variable
 *
 * Return: 1 for success, 0 if fail
 */
int execute(char **cmd, char **ev)
{
	int status = 0;
	pid_t child;

	child = fork();

	if (child == -1)
	{
		perror("Child failed");
		return (0);
	}
	else if (child == 0)
	{
		if (execve(cmd[0], cmd, ev) == -1)
		{
			perror("execve");
			free(cmd);
			return (0);
		}
	}
	else
		wait(&status);
	return (1);
}
