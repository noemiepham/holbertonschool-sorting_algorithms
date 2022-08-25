#include "sort.h"

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
 * partition -  take the last element like pivot
 * @array: array to be sort
 * @low: starting index
 * @hight: Ending index;
 * Return: index
 */
int partition(int *array, size_t low, size_t hight, size_t size)
{
	int pivot = array[hight];

	size_t i = low - 1; /* place for swapping*/
	size_t j;

	for (j = low; j <= hight - 1; j++)
	{
		if (pivot >= array[j])
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[hight], &array[i + 1]);
	print_array(array, size);
	return (i + 1);
}
/**
 * qs - sort right size de bivot
 *
 * @array: array to sort
 * @low: low index
 * @high: hight index
 * @size: size array
 */
void qs(int *array, int low, int high, size_t size)
{
	size_t pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		qs(array, low, pivot - 1, size);
		qs(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort -  a function that sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	qs(array, 0, size - 1, size);
}
