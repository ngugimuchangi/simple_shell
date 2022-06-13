#include "main.h"

/**
 * _strcat3 - concats three strings
 * @path: path from PATH
 * @sep: /
 * @cmd: command
 * Return: pointer to full path
 */
char *_strcat3(char *path, char *sep, char *cmd)

{
	char *string;
	int l1, l2, l3, i, j, k;

	l1 = strlen(path);
	l2 = strlen(sep);
	l3 = strlen(cmd);
	string = malloc(sizeof(char) * (l1 + l2 + l3));
	for (i = 0; path[i]; i++)
	{
		string[i] = path[i];
	}
	for (j = 0; sep[j]; j++)
	{
		string[i + j] = sep[j];
	}
	for (k = 0; cmd[k]; k++)
	{
		string[i + j + k] = cmd[k];
	}
	string[i + j + k] = '\0';
	return (string);
}
