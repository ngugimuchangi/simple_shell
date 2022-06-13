#include "main.h"
/**
 * _free - free list of pointers
 * @ptr: list of pointers to free
 *
 * Description: frees list of pointers
 * used for parsing.
 *
 * Return: nothing
 */
void _free(char **ptr)
{
	int i;

	for (i = 0; ptr[i]; i++)
		free(ptr[i]);
}
