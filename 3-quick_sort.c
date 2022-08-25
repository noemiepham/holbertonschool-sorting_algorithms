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
 * partition -  Lomuto’s Partition Scheme
 * @array: array to be sort
 * @low: starting index
 * @hight: Ending index;
 * @size: size of array
 * Return: index
 */
int partition(int *array, size_t low, size_t hight, size_t size)
{
	int pivot = array[hight];
	size_t i = (low); /* place for swapping*/
	size_t j;

	if (!array || size < 2)
		return (0);

	for (j = low; j < hight; j++)
	{
		if (pivot >= array[j])
		{
			swap(&array[i], &array[j]);
			if (i != j)
			{
				print_array(array, size);
			}
			i++;
		}
	}
	swap(&array[i], &array[hight]);
	if (i != j)
	{
		print_array(array, size);
	}
	return (i);
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
	if (size < 2)
		return;
	qs(array, 0, size - 1, size);
}
