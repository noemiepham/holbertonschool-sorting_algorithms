#include "sort.h"
#include <stdlib.h>

/**
 * insertion_sort_list - Sorts a linked list of integers in ascending order
 * @list: The head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *looper = *list;
	listint_t *temp;
	int swapped = 0;
	/*	listint_t *subsublooper;
		int i = 0;
		int j = 0;
		int k = 0;
		*/

	while (looper)
	{
		if (looper->next && looper->n > looper->next->n)
		{
			swapped = 1;

			printf("ok before\n");
			temp = looper->prev;
			looper->prev = looper->next;
			if (looper->next->next)
				looper->next = looper->next->next;
			else
				looper->next = NULL;

			printf("ok 1\n");
				temp->next = looper->prev;
				printf("ok 2\n");
				temp->next->prev = temp;
				printf("ok 3\n");
				temp->next->next = looper;

			print_list(*list);
			break;
		}

		looper = looper->next;
	}

	if (swapped == 1)
		insertion_sort_list(list);
}
/*
   while (looper)
   {
   if (looper->next && looper->n > looper->next->n)
   {
   to_insert = looper;
//delete_nodeint_at_index(list, i);

if (!sorted)
{
to_insert->next = NULL;
sorted = to_insert;
}
else if (sorted->n > to_insert->n)
{
printf("ok sorted first\n");
to_insert->next = sorted;
sorted->next = to_insert;
}
else
{
sublooper = sorted;
printf("ok sublooper\n");
while (sublooper->next && to_insert->n < sublooper->next->n)
{
printf("ok while\n");
sublooper = sublooper->next;
}

to_insert->next = sublooper->next;
sublooper->next = to_insert;

}

printf("ok before print list\n");
print_list(*list);
printf("ok after print list\n");
}
looper = looper->next;
}
*/
