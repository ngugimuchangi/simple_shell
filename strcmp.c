#include "main.h"
/**
 * _strcmp - compares if two strings are the same
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if they are the same
 * >0 if s1 is longer than s2
 * <0 if s1 is shorter than s2
 */
int _strcmp(char *s1, char *s2)
{
	int i, j = 0;

	for (i = 0; s1[i] || s2[i]; i++)
		if (s1[i] != s2[i])
		{
			j = s1[i] - s2[i];
			break;
		}
	return (j);
}
