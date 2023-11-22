#include "sort.h"

/**
 * shellSort_implementation - function that implement the shell sort algorithm
 * @array: the array that contain numbers
 * @size: size of array
 * @n: the gap between array indexes
 * Return: no return
 */
void shellSort_implementation(int *array, size_t size, int n)
{
	int temp, i, j, len = size;

	for (i = n; i < len; i++)
	{
		for (j = i - n; j >= 0; j = j - n)
		{
			if (array[j + n] < array[j])
			{
				temp = array[j + n];
				array[j + n] = array[j];
				array[j] = temp;
			}
		}
	}
	print_array(array, size);
}

/**
 * shell_sort - function that implement the shell sort algorithm
 * @array: the array that contain numbers
 * @size: size of array
 * Return: no return
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1;

	while (n < size)
		n = n * 3 + 1;
	while (n > 1)
	{
		n = (n - 1) / 3;
		shellSort_implementation(array, size, n);
	}
}
