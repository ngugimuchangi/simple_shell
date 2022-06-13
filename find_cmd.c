#include "main.h"
/**
 * find_cmd - finds command if its exists
 * @cmd: command to find
 * @path: list of path directories
 * @command: absolute path of command to execute
 *
 * Return: Return 1 if command is found, else 0;
 */
int find_cmd(char *cmd, char **path, char *command)
{
	int i;
	char *abs_path;
	struct stat st;

	if (stat(cmd, &st) == 0)
		return (1);
	for (i = 0; path[i]; i++)
	{
		abs_path = malloc(sizeof(char) * (_strlen(path[i]) + _strlen(cmd) + 2));
		if (!abs_path)
			err("Error: Malloc failed\n");
		concat(path[i], cmd, abs_path);
		if (stat(abs_path, &st) == 0)
		{
			_strcpy(command, abs_path);
			free(abs_path);
			return (1);
		}
		free(abs_path);
	}
	return (0);
}
