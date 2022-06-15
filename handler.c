#include "main.h"
/**
 * handler - handles terminate signal
 * @num: number
 *
 * Return: nothing
 */
void handler(__attribute__((unused))int num)
{
	write(STDOUT_FILENO, "\n", 1);
	exit(0);
}
