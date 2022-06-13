#include "main.h"
/**
 * _fork - calls fork function and checks its success
 * @cmd: command to execute
 * @av: command's argument
 *
 * Return: process id
 */
int _fork(char *cmd, char **av)
{
	int id, status;

	id = fork();
	if (id == -1)
		err("Error: Unsucessful fork\n");
	if (id == 0)
	{
		if (execve(cmd, av, environ) == -1)
			err("Err: Could not execute command\n");
	}
	else
		wait(&status);
	return (id);
}
