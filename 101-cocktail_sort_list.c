#include "sort.h"
#include <stdio.h>

/**
 * _len - Counts the number of elements in a doubly linked list.
 *
 * This function counts the number of elements in a doubly linked list.
 *
 * @list: A pointer to the head of the linked list.
 *
 * Return: The number of elements in the list.
 */
int _len(listint_t *list)
{
	listint_t *tmp;
	int n = 0;

	if (list == NULL)
		return (0);
	tmp = list;

	while (tmp != NULL)
	{
		n++;
		tmp = tmp->next;
	}
	return (n);
}

/**
 * _swap_node - Swaps two adjacent elements in a doubly linked list.
 *
 * This function swaps two adjacent elements in a doubly linked list.
 *
 * @list: A double pointer to the head of the linked list.
 * @curr: A double pointer to the current node to be swapped.
 * @reverse: A flag indicating the direction of the swap
 *   (0 for forward, 1 for reverse).
 */
void _swap_node(listint_t **list, listint_t **curr, int reverse)
{
	listint_t *tmp;

	if (!reverse)
	{
		tmp = (*curr)->next;
		if ((*curr)->prev != NULL)
			(*curr)->prev->next = tmp;
		else
			*list = tmp;
		tmp->prev = (*curr)->prev;
		(*curr)->prev = tmp;
		(*curr)->next = tmp->next;
		if (tmp->next != NULL)
			tmp->next->prev = *curr;
		tmp->next = *curr;
		*curr = tmp;
	} else
	{
		tmp = (*curr)->prev;
		if (tmp->prev != NULL)
			tmp->prev->next = *curr;
		else
			*list = *curr;
		(*curr)->prev = tmp->prev;
		tmp->next = (*curr)->next;
		if ((*curr)->next != NULL)
			(*curr)->next->prev = tmp;
		(*curr)->next = tmp;
		tmp->prev = *curr;
		*curr = tmp;
	}
}
/**
 * cocktail_sort_list - Sorts a doubly linked list of integers using the
 *                     Cocktail Shaker Sort algorithm.
 *
 * This function sorts a doubly linked list of integers in ascending order
 * using the Cocktail Shaker Sort algorithm.
 *
 * @list: A double pointer to the head of the linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr;
	int swapped;

	if (list == NULL || _len(*list) < 2)
		return;
	curr = *list;
	do {
		while (curr->next != NULL)
		{
			swapped = 0;
			if (curr->n > curr->next->n)
			{
				swapped = 1;
				_swap_node(list, &curr, 0);
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
				_swap_node(list, &curr, 1);
				print_list(*list);
			}
			curr = curr->prev;
		}
	} while (swapped);
}
