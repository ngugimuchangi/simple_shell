#include "main.h"
/**
 * parse_path - breaks down the path variable into different
 * directories
 * @path: pointer to different path directories
 *
 * Return: nothing
 */
void parse_path(char **path)
{
	int i;

	i = parse(getenv("PATH"), ":", path);
	path[i] = NULL;
}
