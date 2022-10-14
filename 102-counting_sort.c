#include "sort.h"

/**
 * counting_sort - sorts the array with counting sort
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int max, i;
	int *count, *output;

	if (!array || size < 2)
		return;
	max = array[0];
	for (i = 0; i < (int) size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(max * sizeof(*count));
	output = malloc(size * sizeof(*output));
	for (i = 0; i < (int) size; i++)
		count[array[i]]++;
	for (i = 1; i < max; i++)
		count[i] += count[i - 1];
	print_array(count, (size_t)max);
	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; (size_t)i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
