#include "sort.h"
#include <stdio.h>
/**
 * swap - change place 2 element
 * @num1: numero premier
 * @num2: numero deuxiem
 */
void swap(int *num1, int *num2)
{
	int tmp;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}
/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: the array to be sort
 * @size: size the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
			{
				min = j;
			}
		if (min != i)
		{
			swap(&array[i], &array[min]);
			print_array(array, size);
		}
	}
}
