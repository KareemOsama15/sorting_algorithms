#include "sort.h"
#include <stdio.h>

/**
 * partition - function that implement the quick sort algorithm
 * @array: the array that contain numbers
 * @low: low index in array
 * @high: high index in array
 * @len: size of array
 * Return: no return
 */
int partition(int *array, int low, int high, int len)
{
	int pivot = array[high], i = low - 1, j = high, temp;

	while (i < j)
	{
		do {
			j--;
		} while (array[j] > pivot && j >= 0);
		do {
			i++;
		} while (array[i] <= pivot && i < high);

		if (i < j)
		{
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, len);
			}
		}
	}
	if (i != high)
	{
		temp = array[high];
		array[high] = array[i];
		array[i] = temp;
		print_array(array, len);
	}
	return (i);
}

/**
 * quick_sort_recursion - function that implement the quick sort algorithm
 * @array: the array that contain numbers
 * @low: low index in array
 * @high: high index in array
 * @len: size of array
 * Return: no return
 */
void quick_sort_recursion(int *array, int low, int high, int len)
{
	int pivot_pos;

	if (low < high)
	{
		pivot_pos = partition(array, low, high, len);
		quick_sort_recursion(array, low, pivot_pos - 1, len);
		quick_sort_recursion(array, pivot_pos + 1, high, len);
	}
}

/**
 * quick_sort_hoare - function that implement the quick sort algorithm
 *      with hoare partition algorithm
 * @array: the array that contain numbers
 * @size: size of array
 * Return: no return
 */
void quick_sort_hoare(int *array, size_t size)
{
	quick_sort_recursion(array, 0, size - 1, size);
}
