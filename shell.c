#include "main.h"
/**
 * main - shell entry point
 *
 * Return: Always 0
 */
int main(void)
{
	size_t n = 0;
	char *lineptr = NULL, *av[100], *path[100], cmd[100];
	int mode = 1;

	parse_path(path);
	while (mode)
	{
		if (!isatty(0))
		{
			mode = 0;
		}
		else
		{
		write(STDOUT_FILENO, "\033[0;32msimple_shell:$ \033[0;37m", 30);
		}
		if (getline(&lineptr, &n, stdin) == -1)
		{
			free(lineptr);
			continue;
		}
		if (_strcmp(lineptr, "\n") == 0)
			continue;
		if ((_strcmp(lineptr, "exit\n") == 0))
		{
			_free(path);
			free(lineptr);
			return (0);
		}
		read_cmd(lineptr, av);
		_strcpy(cmd, av[0]);
		if (!find_cmd(av[0], path, cmd))
			write(STDOUT_FILENO, "No such file or directory\n", 26);
		else
			_fork(cmd, av);
		_free(av);
	}
	return (0);
}
