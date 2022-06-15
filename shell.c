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
			free(lineptr);
			write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}
		if (no_input(lineptr) == 0)
			continue;
		read_cmd(lineptr, av);
		if (ext(lineptr, argv[0], av))
				continue;
		_strcpy(cmd, av[0]);
		if (!find_cmd(av[0], path, cmd))
			err_no_exit(argv[0], ": No such file or directory\n");
		else
			_fork(cmd, av);
	}
	return (0);
}
