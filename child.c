#include "main.h"

/**
 * child - creates a child process and runs
 * execve system call
 * @line: pointer to command
 * @argv: array of arguments
 * Return: parent id
 */
int child(char *line, char *argv[])
{
	int id;
	int rv __attribute__((unused)) = 0;
	char *envs[] = {NULL};

	id = fork();
	if (id == 0)
	{
		rv = execve(line, argv, envs);
	}
	return (id);
}
