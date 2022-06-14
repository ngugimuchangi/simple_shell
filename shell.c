#include "main.h"
/**
 * main - shell entry point
 * @argc: argument count
 * @argv: argument list
 *
 * Return: Always 0
 */
int main(int __attribute__((unused)) argc, char **argv)
{
	size_t n = 0;
	char *lineptr = NULL, *av[100], *path[100], cmd[100];
	int mode = 1;

	parse_path(path);
	while (mode)
	{
		_isatty(&mode);
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
			no_file(argv[0]);
		else
			_fork(cmd, av);
		_free(av);
	}
	return (0);
}
