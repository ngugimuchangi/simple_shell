#include "main.h"

/**
 * path - parses PATH
 * @cmd: command
 * Return: double pointer to parsed PATH
 */
char *path(char *cmd)
{
	struct stat st;
	char **paths, *path, *pathenv;
	char *fp;
	int i, k = 0, j;

	pathenv = strdup(getenv("PATH"));
	j = dir_count(pathenv);
	paths = malloc(sizeof(char *) * j);
	path = strtok(pathenv, ":");
	while (path != NULL)
	{
		paths[k] = path;
		path = strtok(NULL, ":");
		k++;
	}
	paths[k] = '\0';
	for (i = 0; paths[i]; i++)
	{
		fp = _strcat3(paths[i], "/", cmd);
		if (stat(fp, &st) == 0)
		{
			return (fp);
		}
		free(fp);
	}
	return (cmd);
}
