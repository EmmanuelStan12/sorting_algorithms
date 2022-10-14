#include "sort.h"

/**
 * swap - swaps two digits in an array
 * @first_index: the first index
 * @second_index: the second index
 * @array: the array
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
 * sort - quick sort
 * @arr: the array
 * @size: the size
 * @low_index: the from index
 * @high_index: the to index
 * Return: the result array
 */
void sort(int *arr, int low_index, int high_index, size_t size)
{
	int i = low_index, j = low_index;
	int swaps = 0, pivot = arr[high_index];

	if (low_index >= high_index)
		return;
	for (; i < high_index; i++)
	{
		if (arr[i] < pivot)
		{
			if (i == j)
			{
				j++;
				continue;
			}
			swap(i, j, arr);
			swaps++;
			print_array(arr, size);
			j++;
		}
	}
	if (j != high_index && arr[j] != pivot)
	{
		swap(j, high_index, arr);
		print_array(arr, size);
	}
	sort(arr, low_index, j - 1, size);
	sort(arr, j + 1, high_index, size);
}

/**
 * quick_sort - sorts an array with quick sort
 * @array: the array
 * @size: the size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort(array, 0, (int)size - 1, size);
}
