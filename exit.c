#include "main.h"
/**
 * _atoi - convert string to integer
 * @str: string to convert to integer
 *
 * Return: integer
 */
long int _atoi(char *str)
{
	long int i, res = 0, p_value = 1;

	if (str[0] == '-')
		p_value *= -1;
	i = (str[0] == '-') ? 1 : 0;
	for (; str[i]; i++)
		p_value *= 10;
	i = (str[0] == '-') ? 1 : 0;
	for (p_value /= 10; str[i]; i++, p_value /= 10)
		res += ((str[i] - 48) * p_value);
	return (res);
}
/**
 * ext - checks if the user has entered exit
 * @str: user input
 * @prog: program name to be used in error message
 * @av: pointers to arguments
 *
 * Description: allows the user to exit the program
 * Can also be used to set exit status
 *
 * Return: 0 on success, 1 on failure
 */
int ext(char *str, char *prog, char **av)
{
	int i, j;
	long int status = 0;

	if ((_strcmp(av[0], "exit") == 0))
	{
		if (!av[1])
		{
			free(str);
			exit(status);
		}
		for (j = 0; av[j]; j++)
			if (j >= 2)
			{
				err_no_exit(prog, ": exit: too many arguments\n");
				return (1);
			}
		if (av[1][0] == '\0')
		{
			err_no_exit(prog, ": exit: numeric argument required\n");
			return (1);
		}
		i = (av[1][0] == '-') ? 1 : 0;
		for (; av[1][i]; i++)
		{
			if (av[1][i] < 48 || av[1][i] > 57)
			{
				err_no_exit(prog, ": exit: numeric argument required\n");
				return (1);
			}
		}
		status = _atoi(av[1]);
		if (status > 255)
			status %= 256;
		if (status < 0)
			status = 256 - ((status * -1) % 256);
		free(str);
		exit((int) status);
	}
	return (0);
}
