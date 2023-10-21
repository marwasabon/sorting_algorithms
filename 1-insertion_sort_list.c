#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * insertion_sort_list - sorts a double linked list using inset algorithm
 * @list: a pointer to a double linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *node, *tmp;

	if (!list || !(*list))
		return;

	head = *list;
	node = head->next;

	while (node)
	{
		tmp = node;

		while (tmp && tmp->prev && tmp->n < tmp->prev->n)
		{
			/* Swap nodes */
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			tmp->prev->next = tmp->next;
			tmp->next = tmp->prev;
			if (tmp->next)
				tmp->prev = tmp->next->prev;
			tmp->next->prev = tmp;

			if (tmp->prev)
				tmp->prev->next = tmp;
			else
				head = tmp;

			print_list(head);
		}

		node = node->next;
	}

	*list = head;
}
