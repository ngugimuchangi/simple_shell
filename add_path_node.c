#include "main.h"
/**
 * add_path_node - adds nodes for different path directories
 * @head: pointer to the beginning of the list
 * @str: path directory
 *
 * Return: address of new node
 */
path_list *add_path_node(path_list **head, const char *str)
{
	unsigned int i;
	path_list *new, *temp;

	if (!str)
		return (NULL);
	new = malloc(sizeof(path_list));
	if (!new)
		return (NULL);
	new->str = _strdup(str);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}
	for (i = 0; str[i]; i++)
		;
	new->len = i;
	new->next = NULL;
	if (!*head)
	{
		*head = new;
		return (new);
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return (new);
}
