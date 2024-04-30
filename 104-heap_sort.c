#include "sort.h"

/**
 * swaps_int - swap 2 elements
 * @a: First element
 * @b: Second element to swap with
 * Return: nothing
 */

void swaps_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heap_sort_helper - Helper funtion for heap sort
 * @array: Array to sort
 * @subarray: The subarray
 * @super_node: Super node
 * @size: Size of the array
 */
void heap_sort_helper(int *array, int subarray, int super_node, size_t size)
{
	int max, end, top;

	max = super_node;
	end = super_node * 2 + 1;
	top = end + 1;

	if (end < subarray && array[end] > array[max])
		max = end;
	if (top < subarray && array[top] > array[max])
		max = top;
	if (max != super_node)
	{
		swaps_int(array + max, array + super_node);
		print_array(array, size);
		heap_sort_helper(array, subarray, max, size);
	}
}


/**
 * heap_sort - Sorts an array of integers in ascending 
 * order applying the Heap sort algorithm
 * @array: Array to sort
 * @size: Size of array
 */
void heap_sort(int *array, size_t size)
{
	int a, n = (int)size;

	for (a = n / 2 - 1; a >= 0; a--)
		heap_sort_helper(array, n, a, size);
	for (a = n - 1; a > 0; a--)
	{
		swaps_int(array + 0, array + a);
		print_array(array, size);
		heap_sort_helper(array, a, 0, size);
	}

}
