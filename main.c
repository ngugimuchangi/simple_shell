#include "main.h"

/**
 * main - entry point of our shell program
 * @argc: number of arguments
 * @argv: array of arguments
 * @envp: array
 * Return: 0 (Success)
 */
int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)), char *envp[] __attribute__((unused)))
{
	char **cmds;
	char *buf = NULL;
	size_t size = 0;
	int i;

	/*while (1)*/
	/*{*/
	write(STDOUT_FILENO, "($) ", 4);
	getline(&buf, &size, stdin);
	cmds = tokenize(argc, buf);
	printf("%s\n", buf);
	for (i = 0; cmds[i]; i++)
	{
		printf("%s\n", cmds[i]);
	}
	free(buf);
	free(cmds);
	/*cmds[0] = path(cmds[0]);*/
	/*child(cmds, envp);*/
	/*free(cmds);*/
	/*if (isatty(0) != 1)*/
	/*	break;*/
	/*}*/
	return (0);
}
