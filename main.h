#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
int child(char **cmds, char *envp[]);
char **tokenize(int argc, char *buf);
char *path(char *cmd);
int dir_count(char *pathenv);
char * _strcat3(char *path, char *sep, char *cmd);
void _free(char **cmds);
#endif
