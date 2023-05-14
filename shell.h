#ifndef __SHELL_H__
#define __SHELL_H__

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

ssize_t write(int fd, const void *buf, size_t count);
char **tokenizer(char *cmd, char *delim);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
void *malok(char *add, int size);

#endif
