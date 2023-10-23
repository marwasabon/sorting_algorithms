#include "sort.h"



void cocktail_sort_list(listint_t **list)
{
	int i;
	listint_t *temp;

	for (i = 0; ((*list) + i + 1)->next != NULL; i++)
	{
		if (((*list) + i)->n > ((*list) + i + 1)->n)
		{
			temp = ((*list) + i + 1);
			((*list) + i)->next = temp->next;
			((*list) + i + 1)->next = ((*list) + i);
			((*list) + i + 1)->prev = ((*list) + i)->prev;
			((*list) + i + 1)->prev = ((*list) + i + 1);
			temp->prev = ((*list) + i);
			print_list(*list);
		}
	}
}
