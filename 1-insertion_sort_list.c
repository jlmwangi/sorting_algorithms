#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list: pointer to pointer to listint_t
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *curr, *temp;

	if (list == NULL || *list == NULL)
		return;

	while (*list != NULL)
	{
		curr = *list;
		*list = curr->next;

		if (sorted == NULL || curr->n <= sorted->n)
		{
			curr->next = sorted;
			curr->prev = NULL;
			if (sorted != NULL)
				sorted->prev = curr;
			sorted = curr;
		}
		else
		{
			temp = sorted;

			while (temp->next != NULL && temp->next->n < curr->n)
				temp = temp->next;

			curr->next = temp->next;
			curr->prev = temp;
			if (temp->next != NULL)
				temp->next->prev = curr;
			temp->next = curr;

			if (curr->next != NULL)
				curr->next->prev = curr;
		}
		print_list(sorted);
	}
	*list = sorted;
}
