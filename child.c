#include "main.h"

/**
 * child - creates a child process and runs
 * execve system call
 * @cmds: array of pointers
 * @envp: array
 * Return: parent id
 */
int child(char **cmds, char *envp[])
{
	int id, rtrn;

	id = fork();
	wait(NULL);
	if (id == 0)
	{
		rtrn = execve(cmds[0], cmds, envp);
		if (rtrn == -1)
		{
			printf("bash: %s: No such file or directory\n", cmds[0]);
			exit(0);
		}
	}
	return (id);
}
