#include "sort.h"

/**
 * sort - quick sort
 * @array: the array
 * @size: the size
 * @from: the from index
 * @to: the to index
 * Return: the result array
 */
void sort(int *arr, int low_index, int high_index, size_t size)
{
	int i = low_index, j = low_index;
	int pivot = arr[high_index];

	if (low_index >= high_index)
		return;
	for (; i < high_index; i++)
	{
		if (arr[i] <= pivot)
		{
			if (i == j)
			{
				j++;
				continue;
			}
			swap(i, j, arr);
			print_array(arr, size);
			j++;
		}
	}
	swap(j, high_index, arr);
	print_array(arr, size);
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
	sort(array, 0, (int)size - 1, size);
}
