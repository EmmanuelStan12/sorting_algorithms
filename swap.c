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
