#ifndef __SHELL_H__
#define __SHELL_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#define BUFSIZE 512
#define MAX_ARGS 64

char *_strdup(char *string);
int _strlen(char *str);
char **tokenizer(char *str, const char *delim);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _builtin(char *cmd, char **ev);
char *path_finder(char **av, char **ev);
char *modif_path(char *path);
char **exec_cmd(char **cmd_toks, size_t num_toks, char **av, char **ev);
int tok_num(char *str, const char *delim);
int execute(char **cmd, char **ev);
#endif
