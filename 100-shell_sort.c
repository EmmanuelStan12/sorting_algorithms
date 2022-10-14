#include "sort.h"

/**
 * shell_sort - sorts an array
 * @array: the array to sort
 * @size: the size
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t h = 1, i, j;

	if (size < 2 || !array)
		return;
	while (h < (size / 3))
		h = (3 * h) + 1;
	while (h >= 1)
	{
		for (i = h; i < size; i++)
		{
			for (j = i; j >= h && (array[j] < array[j - h]); j -= h)
			{
				int temp = array[j];

				array[j] = array[j - h];
				array[j - h] = temp;
			}
		}
		h /= 3;
		print_array(array, size);
	}
}
