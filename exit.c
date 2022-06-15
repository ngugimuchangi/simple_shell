#include "main.h"
/**
 * ext - checks if the user has entered exit
 * @str: user input
 *
 * Return: nothing
 */
void ext(char *str)
{
	if ((_strcmp(str, "exit\n") == 0))
	{
		free(str);
		exit(0);
	}
}
