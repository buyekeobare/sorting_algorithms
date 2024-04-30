#include "sort.h"

/**
 * get_max_array - Gets the max of array
 *@array: Array to sort
 *@size: Size to sort
 *
 * Return: int
 */
int get_max_array(int *array, int size)
{
	int max_array, index;

	for (max_array = array[0], index = 1; index < size; index++)
	{
		if (array[index] > max_array)
		{
			max_array = array[index];
		}
	}
	return (max_array);
}

/**
 * lsd_radix_sort - Sorts from the least significant digit
 * to the most significant digit.
 * @array: Array to sort
 * @size: Size of array to sort
 * @exp: exp
 * @copy: copy
 * Return: void
 */
void lsd_radix_sort(int *array, size_t size, int exp, int *copy)
{
	size_t index;
	int count[10] = {0};

	for (index = 0; index < size; index++)
	{
		count[(array[index] / exp) % 10]++;
	}

	for (index = 1; index < 10; index++)
	{
		count[index] = count[index] + count[index - 1];
	}

	for (index = size - 1; (int)index >= 0; index--)
	{
		copy[count[(array[index] / exp) % 10] - 1] = array[index];
		count[(array[index] / exp) % 10]--;
	}

	for (index = 0; index < size; index++)
	{
		array[index] = copy[index];
	}
}
/**
 * radix_sort - Sorts an array of integers in ascending 
 * order applying the Radix sort algorithm
 * @array: Array to sort
 * @size: Size of array to sort
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int max_array, exp, *copy;

	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;

	max_array = get_max_array(array, size);
	for (exp = 1; max_array / exp > 0; exp *= 10)
	{
		lsd_radix_sort(array, size, exp, copy);
		print_array(array, size);
	}
	free(copy);
}
