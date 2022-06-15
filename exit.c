#include "main.h"
/**
 * ext - checks if the user has entered exit
 * @str: user input
 * @path: malloc'd char pointers to path list
 *
 * Return: nothing
 */
void ext(char *str, char **path)
{
	if ((_strcmp(str, "exit\n") == 0))
	{
		_free(path);
		free(str);
		exit(0);
	}
}
