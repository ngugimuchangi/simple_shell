#include "main.h"

/**
 * main - entry point of our shell program
 * @argc: number of arguments
 * @argv: array of arguments
 * @envp: array
 * Return: 0 (Success)
 */
int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)), char *envp[])
{
	char **cmds;
	char *buf = NULL;
	size_t size = 0;

	while (1)
	{
	write(STDOUT_FILENO, "($) ", 4);
	getline(&buf, &size, stdin);
	cmds = tokenize(argc, buf);
	child(cmds, envp);
	if (isatty(0) != 1)
		break;
	}
	return (0);
}
