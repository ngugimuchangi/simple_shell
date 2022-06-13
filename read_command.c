#include "main.h"
/**
 * read_cmd - breaks down the user input into commands and arguments
 * directors
 * @str: pointer to user input
 * @av: command and arguments
 *
 * Return: nothing
 */
void read_cmd(char *str, char **av)
{
	int i;

	i = parse(str, " \n", av);
	av[i] = NULL;
}
