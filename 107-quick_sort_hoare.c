#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * partition_sort_hoare- partition for quicksort applying Hoare scheme
 * @array: Array to sort
 * @l: Lowest index of the partition to be sorted
 * @h: Highest index of the partition to be sorted
 * @size: Size of the array
 *
 * Return: new index of the partition
 */
size_t partition_sort_hoare(int *array, ssize_t l, ssize_t h, size_t size)
{
	int swapped, pivot;

	pivot = array[h];
	while (l <= h)
	{
		while (array[l] < pivot)
			l++;
		while (array[h] > pivot)
			h--;
		if (l <= h)
		{
			if (l != h)
			{
				swapped = array[l];
				array[l] = array[h];
				array[h] = swapped;
				print_array(array, size);
			}
			l++;
			h--;
		}
	}
	return (h);
}

/**
 * partition_sort - Sorts a partition of an array of integers.
 * @array: Array to sort
 * @l: Lowest index of the partition to be sorted
 * @h: Highest index of the partition to be sorted
 * @size: Size of the array
 *
 * Return: void
 */
void partition_sort(int *array, ssize_t l, ssize_t h, size_t size)
{
	ssize_t pivot;

	if (l < h)
	{
		pivot = partition_sort_hoare(array, l, h, size);
		partition_sort(array, l, pivot, size);
		partition_sort(array, pivot + 1, h, size);

	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending 
 * order applying the Quick sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	partition_sort(array, 0, size - 1, size);
}
