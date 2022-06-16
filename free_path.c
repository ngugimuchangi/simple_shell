#include "main.h"
/**
 * free_path_list - frees a list of path directories
 * @head: pointer to the first node
 *
 * Return: nothing
 */
void free_path_list(path_list *head)
{
	path_list *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
	}
}
