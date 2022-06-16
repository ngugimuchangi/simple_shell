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
#include <signal.h>

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

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for path directories
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} path_list;

void _isatty(int *mode);
void handler(int num);
int no_input(char *str);
int ext(char *str, char *prog, char **av);
void logic_tree(char **s, cmd_list *head);
int parse(char *str, const char *del, char **des);
void create_path_list(path_list *path);
void read_cmd(char *str, char **av);
ssize_t _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *des, char *src);
char *_strtok(char *str, const char *delim);
char *_strdup(const char *str);
void concat(char *path, char *cmd, char *abs_path);
ssize_t _getline(char **lineptr, size_t *n);
int find_cmd(char *cmd, char *command);
void cd(char *str);
int _fork(char *cmd, char **av);
void err(char *str);
void err_no_exit(char *prog, char *msg);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
cmd_list *add_cmd_node(cmd_list **head, char *cmd, char **arg);
path_list *add_path_node(path_list **head, const char *str);
void free_cmd_list(cmd_list *head);
void free_path_list(path_list *head);

#endif
