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
 * Return: index
 */
int partition(int *array, size_t low, size_t hight)
{
	int pivot = array[hight - 1];

	size_t i = low - 1; /* place for swapping*/
	size_t j;

	for (j = 0; j < hight - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, hight);
		}
	}
	swap(&array[hight], &array[i + 1]);
	print_array(array, hight);
	return (i + 1);
}
/**
 * qs - sort right size de bivot
 *
 * @array: array to sort
 * @low: low index
 * @high: hight index
 */
void qs(int *array, int low, int high)
{
	size_t parti;

	if (low < high)
	{
		parti = partition(array, low, high);
		qs(array, low, parti - 1);
		qs(array, parti + 1, high);
	}
}

/**
 * quick_sort -  a function that sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	qs(array, 0, size);
}
