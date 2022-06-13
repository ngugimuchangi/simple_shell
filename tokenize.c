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
	args = malloc(sizeof(args) * argc + 1);
	token = strtok(buf, " \n");
	while (token != NULL)
	{
		args[i] = malloc(sizeof(char) * strlen(token));
		args[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	return (args);
}
