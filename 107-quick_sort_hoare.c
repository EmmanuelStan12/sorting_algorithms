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
	int i = low_index, j = high_index;
	int pivot = arr[low_index];

	if (low_index >= high_index)
		return;
	while (1)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i >= j)
			break;
		swap(i, j, arr);
		print_array(arr, size);
		if (arr[i] == pivot)
			i++;
	}
	sort(arr, low_index, j, size);
	sort(arr, j + 1, high_index, size);
}

/**
 * quick_sort - sorts an array with quick sort
 * @array: the array
 * @size: the size of the array
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort(array, 0, (int)size - 1, size);
}
