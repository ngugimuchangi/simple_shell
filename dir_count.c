#include "main.h"

/**
 * dir_count - counts number of directories in path
 * @pathenv: is the PATH
 * Return: number of paths
 */
int dir_count(char *pathenv)
{
	int i, j = 1;

	for (i = 0; pathenv[i]; i++)
	{
		if (pathenv[i] == ':')
		{
			j++;
		}
	}
	return (j);
}
