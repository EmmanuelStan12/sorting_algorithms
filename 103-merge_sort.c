#include "sort.h"

/**
 * copy_arr - copy array
 * @arr: original array
 * @m_arr: the new array
 * @high: the high index
 * @low: the low index
 * Return: void
 */
void copy_arr(int *arr, int *m_arr, size_t high, size_t low)
{
	size_t i, j = 0;

	for (i = low; i <= high; i++)
	{
		arr[i] = m_arr[j];
		j++;
	}
	printf("[Done]: ");
	print_array(m_arr, high + 1 - low);
}

/**
 * merge - merges two arrays
 * @arr: the array
 * @low: the low index
 * @mid: the mid index
 * @high: the high index
 * Return: void
 */
void merge(int *arr, size_t low, size_t mid, size_t high)
{
	size_t l_ptr = low, r_ptr = mid, i = 0;
	int *m_arr;

	printf("Merging...\n[left]: ");
	print_array(arr + low, mid - low);
	printf("[right]: ");
	print_array(arr + mid, high + 1 - mid);
	m_arr = malloc((high + 1 - low) * sizeof(*m_arr));
	while (l_ptr < mid && r_ptr <= high)
	{
		if (arr[l_ptr] <= arr[r_ptr])
		{
			m_arr[i] = arr[l_ptr];
			l_ptr++;
		}
		else
		{
			m_arr[i] = arr[r_ptr];
			r_ptr++;
		}
		i++;
	}
	while (l_ptr < mid)
	{
		m_arr[i] = arr[l_ptr];
		i++;
		l_ptr++;
	}
	while (r_ptr <= high)
	{
		m_arr[i] = arr[r_ptr];
		i++;
		r_ptr++;
	}
	copy_arr(arr, m_arr, high, low);
	free(m_arr);
}

/**
 * sort - sorts an array with merge sort
 * @low: the low index
 * @high: the high index
 * @arr: the array
 * Return: void
 */
void sort(int *arr, size_t low, size_t high)
{
	size_t mid;

	if (((high + 1) - low) <= 1)
		return;
	mid = (high + 1 + low) / 2;
	sort(arr, low, mid - 1);
	sort(arr, mid, high);
	merge(arr, low, mid, high);
}

/**
 * merge_sort - sorts an element with merge sort
 * @array: the array
 * @size: the size
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	sort(array, 0, size - 1);
}
