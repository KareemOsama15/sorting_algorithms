#include "sort.h"

/**
 * bubble_sort - function that implement the bubble sort algorithm
 * @array: the array that contain numbers
 * @size: size of array
 * Return: no return
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swap = 1;

	for (i = 0; (i < size) && swap; i++)
	{
		swap = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap = 1;
				print_array(array, size);
			}
		}
	}
}
