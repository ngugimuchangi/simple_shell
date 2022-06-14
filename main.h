#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

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

void _isatty(int *mode);
unsigned int logic_tree(char **s);
int parse(char *str, const char *del, char **des);
void parse_path(char **path);
void read_cmd(char *str, char **av);
ssize_t _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *des, char *src);
char *_strtok(char *str, const char *delim);
void concat(char *path, char *cmd, char *abs_path);
ssize_t _getline(char **lineptr, size_t *n);
void *_memset(void *s, int c, size_t n);
int find_cmd(char *cmd, char **path, char *command);
void cd(char *str);
int _fork(char *cmd, char **av);
void err(char *str);
void no_file(char *av);
void _free(char **ptr);
cmd_list *add_node(cmd_list **head, char *cmd, char **arg);
void free_list(cmd_list *head);

#endif
