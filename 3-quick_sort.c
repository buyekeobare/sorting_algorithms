#include "sort.h"

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
 * partition - partition through an array of integers 
 * using the Lomuto scheme
 * @array: Array to sort
 * @size: Size of the array
 * @l: lowest index of array to sort
 * @h: highest index of array to sort
 *
 * Return: new index of the partition
 */
int partition(int *array, size_t size, int l, int h)
{
	int pivot = array[h], i = l, j;

	for (j = l; j <= h - 1; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swaps_int(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (pivot != array[i])
	{
		swaps_int(&array[i], &array[h]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quicksort_lomuto - Applies the quick sort algorithm using recursion
 * @array: Array to sort
 * @size: Size of the array
 * @l: lowest index of the array to sort
 * @h: highest index of the array to sort
 * Return: 0
 */

void quicksort_lomuto(int *array, size_t size, int l, int h)
{
	int i;

	if (l < h)
	{
		i = partition(array, size, l, h);
		quicksort_lomuto(array, size, l, i - 1);
		quicksort_lomuto(array, size, i + 1, h);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order 
 * applying the Quick sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 * Return: 0
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort_lomuto(array, size, 0, size - 1);
}