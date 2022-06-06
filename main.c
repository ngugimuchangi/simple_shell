#include "main.h"

/**
 * main - entry point of our shell program
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 (Success)
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	char *line;
	int i, n = 1;
	int ppid __attribute__((unused)), flag = 1;

	while (flag)
	{
	write(STDOUT_FILENO, "($) ", 4);
	line = input();
	}
	/*count number of words in line typed*/
	for (i = 0; line[i]; i++)
	{
		if (line[i] == ' ')
		{
			n++;
		}
	}
	ppid = child(line, argv);
	return (0);
}
