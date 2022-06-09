#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
int child(char **cmds, char *argv[], char *envp[]);
char **tokenize(int argc, char *buf);
#endif
