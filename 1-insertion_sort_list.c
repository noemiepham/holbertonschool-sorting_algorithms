#include "sort.h"
#include <stdlib.h>

/**
 * insertion_sort_list - Sorts a linked list of integers in ascending order
 * @list: The head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *looper = *list;
	listint_t *previous;
	listint_t *temp;

	if (!list || !*list)
		return;

	while (looper)
	{
		temp = looper;

		while (temp->prev && temp->n < temp->prev->n)
		{
			previous = temp->prev;
			if (temp->next)
				temp->next->prev = previous;
			if (previous->prev)
				previous->prev->next = temp;
			else
				*list = temp;

			previous->next = temp->next;
			temp->prev = previous->prev;
			temp->next = previous;
			previous->prev = temp;

			print_list(*list);
		}

		looper = looper->next;
	}
}

