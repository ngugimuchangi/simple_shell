#include "main.h"
/**
 * _free - frees used memmory
 * @cmds: double pointer
 *
 */
void _free(char **cmds)
{
	int i;

	if (cmds != NULL)
	{
		for (i = 0; cmds[i]; i++)
		{
			free(cmds[i]);
		}
		free(cmds);
	}
}
