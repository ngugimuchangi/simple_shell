#include "main.h"

/**
 * parse - parses string into words
 * @str: string to parse
 * @del: delimiter
 * @des: pointer to strings of words
 *
 * Return: number of words
 */
int parse(char *str, const char *del, char **des)
{
	int i;
	char *piece;

	piece = strtok(str, del);
	for (i = 0; piece; i++)
	{
		des[i] = (piece);
		piece = strtok(NULL, del);
	}
	return (i);
}
