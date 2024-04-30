include "sort.h"

/**
 * sub_merge_sort - function to merge sorting algorithm
 * @sub: Array split into sub array.
 * @buffer: Buffer of array.
 * @l: Lowest partition.
 * @mid: Middle partition.
 * @h: Highest partition.
 * Return: Always 0
 */
void sub_merge_sort(int *sub, int *buffer, size_t l, size_t mid, size_t h)
{
	size_t lowest;
	size_t midd;
	size_t i = 0;

	printf("Merging...\n[left]: ");
	print_array(sub + l, mid - l);

	printf("[right]: ");
	print_array(sub + mid, h - mid);

	for (lowest = l, midd = mid; lowest < mid && midd < h; i++)
	{
		if (sub[lowest] < sub[midd])
		{
			buffer[i] = sub[lowest++];
		}
		else
		{
			buffer[i] = sub[midd++];
		}
	}
	for (; lowest < mid; lowest++)
	{
		buffer[i++] = sub[lowest];
	}
	for (; midd < h; midd++)
	{
		buffer[i++] = sub[midd];
	}
	for (lowest = l, i = 0; lowest < h; lowest++)
	{
		sub[lowest] = buffer[i++];
	}
	printf("[Done]: ");
	print_array(sub + l, h - l);
}

/**
 * call_merge_sort - Calls merge sort function.
 * @sub: Sub array to sort.
 * @buffer: Buffer to the array.
 * @l: lowest partition.
 * @h: highest partition.
 * Return: Always 0
 */
void call_merge_sort(int *sub, int *buffer, size_t l, size_t h)
{
	size_t mid;

	if (h - l > 1)
	{
		mid = l + (h - l
    ) / 2;
		call_merge_sort(sub, buffer, l, mid);
		call_merge_sort(sub, buffer, mid, h);
		sub_merge_sort(sub, buffer, l, mid, h);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending 
 * order applying the Merge sort algorithm
 * @array: Array to sort
 * @size: Size of array
 * Return: void.
 */
void merge_sort(int *array, size_t size)
{
	int *temp_buffer;

	temp_buffer = malloc(sizeof(int) * size);
	if (temp_buffer == NULL)
		return;

	call_merge_sort(array, temp_buffer, 0, size);

	free(temp_buffer);
}

