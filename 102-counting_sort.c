#include "sort.h"

/**
 * counting_sort - function that implement the counting sort algorithm
 * @array: the array that contain numbers
 * @size: size of array
 * Return: no return
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, max = array[0], i;

	for (i = 1; i < (int)size; i++)
		if (max < array[i])
			max = array[i];

	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;

	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);
	output = malloc(sizeof(int) * (size + 1));
	if (!output)
	{
		free(count);
		return;
	}

	for (i = size - 1; i >= 0; i--)
		output[--count[array[i]]] = array[i];

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(output);
	free(count);
}
