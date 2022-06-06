#include "main.h"

/**
 * input - read the commands typed into stdin
 *
 * Return: pointer to the line typed
 */
char *input(void)
{
	char *buf = NULL;
	size_t len = 0;
	ssize_t size __attribute__((unused));

	size = getline(&buf, &len, stdin);
	return (buf);
}
