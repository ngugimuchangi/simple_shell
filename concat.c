#include "main.h"
/**
 * concat - concatinates path directories and command
 * @path: path directory
 * @cmd: command
 * @abs_path: malloced string to store absolute path
 *
 * Description: modification of normal strcat function
 * It allocates enough memory to concatenate two string
 *
 * Return: nothing
 */
void concat(char *path, char *cmd, char *abs_path)
{
	int i, j;

	for (i = 0; path[i] != '\0'; i++)
		abs_path[i] = path[i];
	abs_path[i] = '/';
	for (j = 0, i++; cmd[j] != '\0'; i++, j++)
		abs_path[i] = cmd[j];
	abs_path[i] = '\0';
}
