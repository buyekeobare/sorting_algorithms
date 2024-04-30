#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending 
 * order applying the Counting sort algorithm
 * @array: Array of integers
 * @size: Size of array
 */

void counting_sort(int *array, size_t size)
{
	int *count, *sort, total, max;
	size_t i;

	if (array == NULL || size < 2)
		return;

	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
		max = (array[i] > max) ? array[i] : max;
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;

	for (i = 0; i < (size_t)(max + 1); i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 0, total = 0; i < (size_t)(max + 1); i++)
	{
		count[i] += total;
		total = count[i];
	}
	print_array(count, max + 1);

	for (i = 0; i < size; i++)
	{
		sort[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = sort[i];

	free(sort);
	free(count);
}