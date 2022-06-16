#include "main.h"
/**
 * find_cmd - finds command if its exists
 * @cmd: command to find
 * @command: absolute path of command to execute
 *
 * Return: Return 1 if command is found, else 0;
 */
int find_cmd(char *cmd, char *command)
{
	char *path, *path_cpy, *abs_path, *token;
	path_list *head = NULL, *temp;
	struct stat st;

	if (stat(cmd, &st) == 0)
		return (1);
	path = _getenv("PATH");
	if (!path)
		err("Error: could not get path variable\n");
	path_cpy = _strdup(path);
	token = strtok(path_cpy, ":");
	while (token != NULL)
	{
		add_path_node(&head, token);
		token = strtok(NULL, ":");
	}
	free(path_cpy);
	temp = head;
	while (temp)
	{
		abs_path = malloc(sizeof(char) * (temp->len + _strlen(cmd) + 2));
		if (!abs_path)
			err("Error: Malloc failed\n");
		concat(temp->str, cmd, abs_path);
		if (stat(abs_path, &st) == 0)
		{
			_strcpy(command, abs_path);
			free(abs_path);
			free_path_list(head);
			return (1);
		}
		free(abs_path);
		temp = temp->next;
	}
	free_path_list(head);
	return (0);
}
