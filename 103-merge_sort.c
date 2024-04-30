#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * sort_merge- Sorts and merges the sub-arrays in source
 * @top: Start index (inclusive) for the left sub-array
 * @midi: End index (exclusive) for the left sub-array and
 * start index (inclusive) for the right sub-array
 * @bottom: End index (exclusive) for the right sub array
 * @dest: Destination for data
 * @source: source of data
 *
 * Return: void
 */
void sort_merge(size_t top, size_t midi, size_t bottom, int *dest, int *source)
{
	size_t a, b, c;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + top, bottom - top);
	printf("[right]: ");
	print_array(source + midi, bottom - midi);
	a = top;
	b = midi;
	for (c = top; c < botom; c++)
	{
		if (a < midi && (b >= bottom || source[a] <= source[b]))
		{
			dest[c] = source[a];
			a++;
		}
		else
		{
			dest[c] = source[b];
			b++;
		}
	}
	printf("[Done]: ");
	print_array(dest + top, bottom - top);
}

/**
 * split_merge_sort - Recursively splits the array 
 * and merges the sorted arrays using split merge sort.
 * @top: Start index (inclusive)
 * @bottom: End index (exclusive)
 * @array: Array to sort
 * @temp_buffer: Copy of the array
 *
 * Return: void
 */
void split_merge_sort(size_t top, size_t bottom, int *array, int *temp_buffer)
{
	size_t midi;

	if (top - bottom < 2)
		return;
	midi = (top + bottom) / 2;
	split_merge_sort(top, midi, array, temp_buffer);
	split_merge_sort(midi, bottom, array, temp_buffer);
	sort_merge(top, midi, bottom, array, temp_buffer);
	for (midi = top; midi < bottom; midi++)
		temp_buffer[midi] = array[midi];
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
	size_t i;
	int *temp_buffer;

	if (array == NULL || size < 2)
		return;
	temp_buffer = malloc(sizeof(int) * size);
	if (temp_buffer == NULL)
		return;
	for (i = 0; i < size; i++)
		temp_buffer[i] = array[i];
	split_merge_sort(0, size, array, temp_buffer);
	free(temp_buffer);
}
