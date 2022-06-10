#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PATH "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin"
#define EXEC 0
#define SEQ 1
#define AND 2
#define OR 3

extern char **environ;

/**
 * struct list - structure of commands and arguments
 * @type: command execution pattern
 * @cmd: command to execute
 * @arg: arguments for the commands
 * @next: pointer to the next list
 *
 * Description: command linked list node structure
 */
typedef struct list
{
	int type;
	char *cmd;
	char **arg;
	struct list *next;
} cmd_list;

unsigned int logic_tree(char **s);
int parse_path(char *s1, char **s2);
ssize_t _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *_strtok(char *str, const char *delim);
void _strcat(char *s1, char *s2, char *des);
ssize_t _getline(char **lineptr, size_t *n);
void *_memset(void *s, int c, size_t n);
void cd(char *s);
void _fork(void);
void err(char *s, int ext);
cmd_list *add_node(cmd_list **head, char *cmd, char **arg);
void free_list(cmd_list *head);

#endif
