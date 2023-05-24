#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>


/*constants*/
#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define PATH_COMMAND 3
#define INVALID_COMMAND -1

#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 *struct zone - a struct that maps a command name to a function 
 *
 *@command_name: name of the command
 *@func: the function that executes the command
 */
typedef struct zone
{
	char *cmd;
	void (*func)(char **command);
} funs_zone;

extern char **environ;
extern char *line;
extern char **commands;
extern char *shell_name;
extern int status;

/*helpers*/
void _write(char *str, int stm);
char **tokenizer(char *cmd, char *delim);
void rmv_nl(char *str);
int _strlen(char *str);
void _strcpy(char *s1, char *s2);

/*helpers2*/
int my_strspn(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
char *_strcat(char *str1, char *str2);
int my_strcspn(char *s1, char *s2);
char *my_strchr(char *s1, char s2);

/*helpers3*/
char *my_strtok(char *str, char *delim, char **new_ptr);
int _atoi(char *str);
void *_realloc(void *ptr, size_t old_mem, size_t new_mem);
void ctrl_c(int);
void rm_cmt(char *sig_val);

/*utils*/
int parse_cmd(char *cmd);
void exec_comd(char **cmd_toks, int cmd_typ);
char *path_inspect(char *cmd);
void (*get_function(char *cmd))(char **);
char *get_environ(char *pt);

/*built_in*/
void env(char **cmd_toks);
void quit(char **cmd_toks);

/*main*/
extern void non_interactive(void);
extern void initializer(char **current_command, int type_command);

#endif /*SHELL_H*/