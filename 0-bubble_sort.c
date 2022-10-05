#include "sort.h"

/**
 * bubble_sort - sorts the array with bubble sort
 * array: the array to sort
 * size: the size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int swaps = 1, compares = 0;
	size_t i;

	while (swaps)
	{
		swaps = 0;
		for (i = 0; i < size; i++)
		{
			if (i + 1 != size)
			{
				int res = compare(array[i], array[i + 1]);

				compares++;
				if (res == 1)
				{
					swap(i, i + 1, array);
					swaps++;
					print_array(array, size);
				}
			}
		}
	}
}
