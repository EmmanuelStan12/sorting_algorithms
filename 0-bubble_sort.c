#include "sort.h"

/**
 * swap - swaps two digits in an array
 * first_index: the first index
 * second_index: the second index
 * array: the array
 * Return: void
 */
void swap(int first_index, int second_index, int *array)
{
	int temp;

	temp = array[first_index];
	array[first_index] = array[second_index];
	array[second_index] = temp;
}

/**
 * compare: compares two digits
 * first: the first number
 * second: the second number
 * Return: 0 if equal, -1 if less, and 1 if greater
 */
int compare(int first, int second)
{
	if (first == second)
		return (0);
	else if (first > second)
		return (1);
	else if (first < second)
		return (-1);
	return (-1);
}

/**
 * bubble_sort - sorts the array with bubble sort
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int swaps = 1, compares = 0;
	size_t i;

	if (size < 2)
		return;
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
