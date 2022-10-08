#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}

/**
 * print_array - Prints an array of integers
 * @start: the start index
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_arr(const int *array, int start, size_t size)
{
    size_t i;

    i = start;
    while (array && i < size)
    {
        if (i > (size_t)start)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
