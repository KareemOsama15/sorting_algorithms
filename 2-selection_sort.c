#include "sort.h"

/**
 * selection_sort - function that implement the selection sort algorithm
 * @array: the array that contain numbers
 * @size: size of array
 * Return: no return
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int minNum, temp, index;

	for (i = 0; i < size - 1; i++)
	{
		minNum = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (minNum >= array[j])
			{
				minNum = array[j];
				index = j;
			}
		}
		if (array[i] > minNum)
		{
			temp = array[index];
			array[index] = array[i];
			array[i] = temp;

			print_array(array, size);
		}
	}
}
