#include "main.h"

/**
 * _strlen - Calculate length of string
 * @s: pointer to string
 *
 * Return: length of string
 */
ssize_t _strlen(const char *s)
{
	ssize_t i = 0;

	for (; s[i]; i++)
		;
	return (i);
}
