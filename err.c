#include "main.h"
/**
 * err - prints error message and exit program
 * * @s: error message
 *
 * Return: nothing
 */
void err(char *s)
{
	write(STDOUT_FILENO, s, _strlen(s));
	exit(1);
}
