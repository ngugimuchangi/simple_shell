#include "main.h"

/**
 * tokenize - take entered command and split it in tokens
 * @argc: number of arguments
 * @buf: commands written through stdin
 * Return: array of pointers
 */
char **tokenize(int argc, char *buf)
{
	char **args;
	char *token;
	int i;

	i = 0;
	args = malloc(sizeof(char *) * argc);
	token = strtok(buf, " \n");
	args[i] = token;
	while (token != NULL)
	{
		i++;
		token = strtok(NULL, " \n");
		args[i] = token;
	}
	return (args);
}
