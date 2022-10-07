#include "sort.h"

/**
 * selection_sort - sorts an array with selection sort
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (compare(array[min], array[j]) == 1)
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(i, min, array);
			print_array(array, size);
		}
	}
}
