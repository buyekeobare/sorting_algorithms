#include "sort.h"
#include <stdio.h>

/**
 * swaps_node - Swaps a node with the next node in the list
 * @list: Double pointer to the start of the list
 * @node: Node to swap
 *
 * Return: void
 */
void swaps_node(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order applying the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of doubly linked list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	char swap = 1;
	listint_t *temp;

	if (list == NULL || *list == NULL)
		return;
	temp = *list;
	while (swap != 0)
	{
		swap = 0;
		while (temp->next != NULL)
		{
			if (temp->next->n < temp->n)
			{
				swaps_node(list, temp);
				swap = 1;
				print_list(*list);
			}
			else
				temp = temp->next;
		}
		if (swap == 0)
			break;
		swap = 0;
		while (temp->prev != NULL)
		{
			if (temp->prev->n > temp->n)
			{
				swaps_node(list, temp->prev);
				swap = 1;
				print_list(*list);
			}
			else
				temp = temp->prev;
		}
	}
}