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
  * partitions -  partitions an array into 2 sub arrays
  * @array: pointer to the array
  * @size: Size of array
  * @up: First index of array
  * @down: Last index of array
  * Return: Index of pivot element of array.
  */
int partitions(int *array, size_t size, int up, int down)
{
	int i, part_i = up;
	int pivot = array[down];

	for (i = up; i < down; i++)
	{
		if (array[i] < pivot)
		{
			if (part_i < i)
			{
				swaps_int(&array[i], &array[part_i]);
				print_array(array, size);
			}
			part_i++;
		}
	}
	if (array[part_i] > pivot)
	{
		swaps_int(&array[part_i], &array[size - 1]);
		print_array(array, size);
	}

	return (part_i);
}
