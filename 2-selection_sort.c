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
