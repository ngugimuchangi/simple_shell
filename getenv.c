#include "main.h"
/**
 * _getenv - check for environment variables
 * @name: name of environment variable
 *
 * Return: pointer to variable's value
 */
char *_getenv(const char *name)
{
	int i, j, flag;
	char *str = NULL;

	for (i = 0; environ[i]; i++)
	{
		flag = 0;
		for (j = 0; environ[i][j] != '='; j++)
			if (name[j] != environ[i][j])
			{
				flag++;
				break;
			}
		if (flag == 0)
		{
			str = &(environ[i][j + 1]);
			break;
		}
	}
	return (str);
}
