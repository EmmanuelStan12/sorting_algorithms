#include "sort.h"

listint_t *swap_nodes(listint_t *first, listint_t *second)
{
	listint_t *next = NULL, *prev = NULL;

	if (second->next)
		next = second->next;
	if (first->prev)
	{
		prev = first->prev;
		prev->next = second;
	}
	second->prev = prev;
	second->next = first;
	first->prev = second;
	first->next = next;
	if (next)
		next->prev = first;
	return (second);
}

/**
 * insertion_sort_list: sorts a doubly linked list
 * @list: the list to sort
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;

	if (!list)
		return;
	current = *list;
	if (!current)
		return;
	while (current)
	{
		listint_t *prev = NULL;
		int swaps = 1;
		listint_t *cur = current;

		if (cur->prev)
			prev = cur->prev;
		else
		{
			current = current->next;
			continue;
		}
		while (prev && swaps)
		{
			int res = compare(prev->n, cur->n);

			swaps = 0;
			if (res == 1)
			{
				listint_t *p = swap_nodes(prev, cur);
				
				swaps++;
				if (cur->prev)
					cur = p;
				else
					*list = p;
				print_list(*list);
				prev = cur->prev;
			}
		}
		current = current->next;
	}
}
