#include "sort.h"
#include <stddef.h>

/**
 * swaps_int - swaps two elements in an array
 * @a: the first element 
 * @b: the second element
 */

void swaps_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - Sorts an array of integers in 
 * ascending order applying the Shell sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 * Return: Nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t x, y, gap;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap <= (size / 3);)
		gap = gap * 3 + 1;
	for (; gap >= 1; gap /= 3)
	{
		for (x = gap; x < size; x++)
		{
			for (y = x; y >= gap && array[x - gap] > array[x]; x -= gap)
			{
				swaps_int(array + x, array + (x - gap));
			}
		}
		print_array(array, size);

	}
}