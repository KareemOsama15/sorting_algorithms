#include "sort.h"

/**
 * insertion_sort_list - function that implement the insertion sort algorithm
 * @list: the head of doubly linked list
 * Return: no return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *temp = NULL;

	if (list == NULL || *list == NULL)
		return;

	current = *list;
	while (current)
	{
		temp = current;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			temp->next = temp->prev;
			temp->prev = temp->next->prev;
			temp->next->prev = temp;

			if (temp->prev == NULL)
				*list = temp;
			else
				temp->prev->next = temp;

			print_list(*list);
		}
		current = current->next;
	}
}
