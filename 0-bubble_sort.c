#include "sort.h"

/**
 * bubble_sort - Function that applies the Bubble Sort algorithm 
 * @array: Array to be sorted
 * @size: Size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t pass, i;
	int temp;
	int swapped;

	if (array == NULL || size < 2)
		return;

	/* number of passes required to sort the array*/
	for (pass = 0; pass < size - 1; pass++)
	{
		swapped = 0;
		/* check if any swaps has occurred in this pass*/

		/*Compare and swap adjacent elements*/
		for (i = 0; i < size - pass - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				/*Swap the elements*/
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = 1; 
				print_array(array, size);
			}
		}

		/*If no swaps, the array is sorted*/
		if (swapped == 0)
		{
			return;
		}
	}
}

