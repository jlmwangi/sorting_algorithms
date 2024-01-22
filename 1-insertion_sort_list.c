#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list: pointer to pointer to listint_t
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *curr, *next, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = *list;
	while (curr != NULL)
	{
		next = curr->next;

		if (sorted == NULL || curr->n < sorted->n)
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
			if (temp->next != NULL)
				temp->next->prev = curr;
			curr->prev = temp;
			temp->next = curr;
		}
		print_list(sorted);
		curr = next;
	}
	*list = sorted;
}
