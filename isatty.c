#include "main.h"

/**
 * _isatty - tells you if the standard input are associated with terminal
 * @mode: pointer to file descriptor
 *
 * Return: nothing
 */
void _isatty(int *mode)
{
	if (!isatty(0))
	{
		*mode = 0;
	}
	else
		write(STDOUT_FILENO, "\033[0;32msimple_shell\033[0;37m:$ ", 30);
}
