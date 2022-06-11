#include "main.h"
/**
 * _fork - calls fork function and checks its success
 *
 * Return: process id;
 */
int _fork(void)
{
	int id;

	id = fork();
	if (id == -1)
		err("Error: Unsucessful fork");
	return (id);
}
