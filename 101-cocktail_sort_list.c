#include "sort.h"
#include <stdio.h>



void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp, *curr;
	int swapped;

	curr = *list;
	do {
		while (curr->next != NULL)
		{
			swapped = 0;
			if (curr->n > curr->next->n)
			{
				swapped = 1;
				tmp = curr->next;
				if (curr->prev != NULL)
					curr->prev->next = tmp;
				else
					*list = tmp;
				tmp->prev = curr->prev;
				curr->prev = tmp;
				curr->next = tmp->next;
				if (tmp->next != NULL)
					tmp->next->prev = curr;
				tmp->next = curr;
				curr = tmp;
				print_list(*list);
			}
			curr = curr->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		while (curr->prev != NULL)
		{
			if (curr->n < curr->prev->n)
			{
				swapped = 1;
				tmp = curr->prev;

				if (tmp->prev != NULL)
					tmp->prev->next = curr;
				else
					*list = curr;
				curr->prev = tmp->prev;
				tmp->next = curr->next;
				if (curr->next != NULL)
					curr->next->prev = tmp;
				curr->next = tmp;
				tmp->prev = curr;
				curr = tmp;
				print_list(*list);
			}
			curr = curr->prev;
		}
	} while (swapped);
}
