#include "main.h"
/**
 * _strcpy - copies content of a src to des
 * @des: destination string
 * @src: source string
 *
 * Return: pointer to destination string
 */
char *_strcpy(char *des, char *src)
{
	unsigned int i, j;

	for (i = 0; src[i]; i++)
		;
	for (j = 0; j <= i ; j++)
		des[j] = src[j];

	return (des);
}
