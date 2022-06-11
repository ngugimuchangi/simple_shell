#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
#include <stdlib.h>
/**
 * parse_path - parses PATH into specific directories
 * @s1: string to parse
 * @s2: destination of parsed directories
 * Return: numbers of directories
 */
int parse_path(char *s1, char **s2)
{
	char *piece;
	int i;

	piece = strtok(s1, ":");
	for (i = 0; piece; i++)
	{
		s2[i] = piece;
		piece = strtok(NULL, ":");
	}
	return (i);
}
/**
 * concat - concatinate two strings without overflow
 * @s1: second string
 * @s2: first string
 * @des: destination string
 * Return: nothing
 */
void concat(char *s1, char *s2, char *des)
{
	int i, j;

	for (i = 0; s1[i] != '\0'; i++)
	{
		des[i] = s1[i];
	}
	des[i] = '/';
	for (j = 0, i++; s2[j] != '\0'; j++, i++)
	{
		des[i] = s2[j];
	}
	des[i] = '\0';
}
/**
 * main - check if file exists in path
 * @ac: argument count
 * @av: argument vector
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
	unsigned int i, j, k, flag = 0;
	char *path = getenv("PATH");
	char *_path[100], *abs_path;
	struct stat st;

	if (ac < 2)
	{
		printf("Usage: %s _which filename...\n", av[0]);
		return (1);
	}
	i = parse_path(path, _path);
	for (j = 1; av[j]; j++)
	{
		printf("%s:", av[j]);
		for (k = 0; k < i; k++)
		{
			abs_path = malloc(sizeof(char) * (strlen(_path[k]) +
							strlen(av[j]) + 2));
			if (!abs_path)
			{
				printf("Err: malloc failed\n");
				exit(98);
			}
			concat(_path[k], av[j], abs_path);
			if (stat(abs_path, &st) == 0)
			{
				printf(" FOUND \n");
				flag = 1;
				free(abs_path);
				break;
			}
			free(abs_path);
		}
		if (flag == 0)
			printf(" NOT FOUND\n");
		flag = 0;
	}
	return (0);
}
