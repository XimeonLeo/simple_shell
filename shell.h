#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <signal.h>


#define PATH_COMMAND 3
#define INVALID_COMMAND -1
#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2

#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 * struct zone - a struct that maps a command name to a function
 *
 * @cmd: name of the command
 * @func: the function that executes the command
 */
typedef struct zone
{
	char *cmd;
	void (*func)(char **command);
} funs_zone;

extern char **environ;
extern char *line;
extern char **commands;
extern char *my_shell;
extern int status;

void _write(char *str, int stm);
char **tokenizer(char *cmd, char *delim);
void rmv_nl(char *str);
int _strlen(char *str);
void _strcpy(char *s1, char *s2);
char *my_strtok(char *str, char *delim, char **new_ptr);
int _atoi(char *str);
void *_realloc(void *ptr, size_t old_mem, size_t new_mem);
void ctrl_c(int);
void rm_cmt(char *sig_val);
int my_strspn(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
char *_strcat(char *str1, char *str2);
int my_strcspn(char *s1, char *s2);
char *my_strchr(char *s1, char s2);
int parse_cmd(char *cmd);
void exec_comd(char **cmd_toks, int cmd_typ);
char *path_inspect(char *cmd);
void (*get_function(char *cmd))(char **);
char *get_environ(char *pt);
void env(char **cmd_toks);
void quit(char **cmd_toks);
extern void non_interac_mode(void);
extern void init(char **current_command, int type_command);

#endif
