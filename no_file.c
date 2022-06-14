#include "main.h"
/**
 * no_file - print to error to stdout that no file was found
 * @av: name of the program
 *
 * Return: nothing
 */
void no_file(char *av)
{
	int i, j, k;
	char *buff, *no_file = ": No such file or directory\n";

	k = _strlen(av) + _strlen(no_file);
	buff = malloc(sizeof(char) * (k + 1));
	if (!buff)
		err("Error: Malloc failed\n");
	for (i = 0; av[i]; i++)
		buff[i] = av[i];
	for (j = 0; no_file[j]; j++, i++)
		buff[i] = no_file[j];
	buff[i] = '\0';
	write(STDERR_FILENO, buff, k);
	free(buff);
}
