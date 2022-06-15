#include "main.h"
/**
 * no_input - checks if the user has not entered any input
 * @str: user input
 *
 * Return: 0 if there's no input
 * > 0 if there's input
 */
int no_input(char *str)
{
	int i, j = 0;

	for (i = 0; str[i]; i++)
		if (str[i] != ' ' && str[i] != '\n')
			j++;
	return (j);
}
