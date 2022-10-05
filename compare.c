#include "sort.h"

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
