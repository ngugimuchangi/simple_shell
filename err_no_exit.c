#include "main.h"
/**
 * err_no_exit - prints error message without exiting shell
 * @prog: name of shell program
 * @msg: error message
 *
 * Return: nothing
 */
void err_no_exit(char *prog, char *msg)
{
	int i, j, k;
	char *buff = NULL;

	k = _strlen(prog) + _strlen(msg);
	buff = malloc(sizeof(char) * (k + 1));
	if (!buff)
		err("Error: Malloc failed\n");
	for (i = 0; prog[i]; i++)
		buff[i] = prog[i];
	for (j = 0; msg[j]; j++, i++)
		buff[i] = msg[j];
	buff[i] = '\0';
	write(STDERR_FILENO, buff, k);
	free(buff);
}
