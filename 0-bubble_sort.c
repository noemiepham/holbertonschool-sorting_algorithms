#include "sort.h"
#include <stddef.h>

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * @array: The array to sort
 * @size: The array's size
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	int swapped = 0;
	size_t i;

	for (i = 0; i < size; i++)
	{
		temp = array[i];

		if (array[i] > array[i + 1] && i < size - 1)
		{
			swapped = 1;
			array[i] = array[i + 1];
			array[i + 1] = temp;
			print_array(array, size);
		}
	}

	if (swapped == 1)
		bubble_sort(array, size);
}
