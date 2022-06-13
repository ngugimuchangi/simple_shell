#include "main.h"
/**
 * err - prints error message and exit program
 * @str: error message
 *
 * Return: nothing
 */
void err(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
	exit(1);
}
