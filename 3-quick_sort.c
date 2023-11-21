#include "sort.h"
#include <stdio.h>

/**
 * quickSort_partition - function that implement the quick sort algorithm
 * @array: the array that contain numbers
 * @low: low index in array
 * @high: high index in array
 * @len: size of array
 * Return: no return
 */
int quickSort_partition(int *array, int low, int high)
{
	int pivot_value = array[high];
	int i = low, j, temp;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot_value)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
		}
	}
	temp = array[high];
	array[high] = array[i];
	array[i] = temp;

	return (i);
}

/**
 * quickSort_recursion - function that implement the quick sort algorithm
 * @array: the array that contain numbers
 * @low: low index in array
 * @high: high index in array
 * @len: size of array
 * Return: no return
 */
void quickSort_recursion(int *array, int low, int high, int len)
{
	int pivot_pos;

	if (low < high)
	{
		pivot_pos = quickSort_partition(array, low, high);
		print_array(array, len);
		quickSort_recursion(array, low, pivot_pos - 1, len);
		quickSort_recursion(array, pivot_pos + 1, high, len);
	}
}

/**
 * quick_sort - function that implement the quick sort algorithm
 * @array: the array that contain numbers
 * @size: size of array
 * Return: no return
 */
void quick_sort(int *array, size_t size)
{
	quickSort_recursion(array, 0, size - 1, size);
}
