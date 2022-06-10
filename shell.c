#include "main.h"
/**
 * main - shell entry point
 *
 * Return: Always 0
 */
int main(void)
{
	size_t i, n;
	char *lineptr;

	while (1)
	{
		write(STDOUT_FILENO, "simple_shell:$ ", 15);
		i = getline(&lineptr, &n, stdin);
		if ((_strcmp(lineptr, "exit\n") == 0))
			return (0);
		write(STDOUT_FILENO, lineptr, i);
	}
	return (0);
}
