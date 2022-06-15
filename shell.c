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
		signal(SIGINT, handler);
		if (getline(&lineptr, &n, stdin) == -1)
		{
			_free(path);
			free(lineptr);
			write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}
		if (no_input(lineptr) == 0)
			continue;
		ext(lineptr, path);
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
