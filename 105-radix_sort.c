#include "sort.h"

/**
 * sort - sorts an array from a given unit
 * @arr: the array
 * @size: the size
 * @unit: the unit
 * Return: the sorted array
 */
int *sort(int *arr, size_t size, int unit)
{
	int *res, count[10] = { 0 };
	size_t i = 0;

	for (i = 0; i < size; i++)
		count[(arr[i] / unit) % 10]++;
	res = malloc(size * sizeof(*res));
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; (int) i >= 0; i--)
	{
		res[count[(arr[i] / unit) % 10] - 1] = arr[i];
		count[(arr[i] / unit) % 10]--;
	}
	for (i = 0; i < size; i++)
		arr[i] = res[i];
	free(res);
	return (arr);
}

/**
 * find_max - finds the max integer
 * @array: the array
 * @size: the size
 * Return: the max integer
 */
int find_max(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * radix_sort - sorts an array
 * @array: the array
 * @size: the size
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int max;
	size_t i = 1;

	if (!array || size < 2)
		return;
	max = find_max(array, size);
	for (; (max / i) > 0; i *= 10)
	{
		sort(array, size, i);
		print_array(array, size);
	}
}
