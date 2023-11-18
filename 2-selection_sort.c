#include "sort.h"

/**
 * selection_sort - function that implement the selection sort algorithm
 * @array: the array that contain numbers
 * @size: size of array
 * Return: no return
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, minPos;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		minPos = i;

		for (j = i + 1; j < size; j++)
			if (array[minPos] > array[j])
				minPos = j;

		if (minPos != i)
		{
			temp = array[minPos];
			array[minPos] = array[i];
			array[i] = temp;

			print_array(array, size);
		}
	}
}
