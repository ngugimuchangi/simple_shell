#include "main.h"
/**
 * _strdup - creates a duplicate of string
 * @str: string to duplicated
 *
 * Return: malloc'd pointer to duplicate string
 */
char *_strdup(const char *str)
{
	int i, size;
	char *copy = NULL;

	if (!str)
		return (copy);
	size = _strlen(str) + 1;
	copy = malloc(sizeof(char) * size);
	if (!copy)
		return (copy);
	for (i = 0; i < size; i++)
		copy[i] = str[i];
	return (copy);
}
