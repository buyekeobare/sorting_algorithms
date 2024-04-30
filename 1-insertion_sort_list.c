 #include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in 
 * ascending order by applying the Insertion sort algorithm
 * @list: The doubly linked list to be sorted
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr_swap, *next_swap;

	if (list == NULL || *list == NULL)
		return;
	curr_swap = (*list)->next;
	while (curr_swap != NULL)
	{
		next_swap = curr_swap->next;
		while (curr_swap->prev != NULL && curr_swap->prev->n > curr_swap->n)
		{
			curr_swap->prev->next = curr_swap->next;
			if (curr_swap->next != NULL)
				curr_swap->next->prev = curr_swap->prev;
			curr_swap->next = curr_swap->prev;
			curr_swap->prev = curr_swap->next->prev;
			curr_swap->next->prev = curr_swap;
			if (curr_swap->prev == NULL)
				*list = curr_swap;
			else
				curr_swap->prev->next = curr_swap;
			print_list(*list);
		}
		curr_swap = next_swap;
	}
}