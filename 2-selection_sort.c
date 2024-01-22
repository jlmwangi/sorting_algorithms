#include "sort.h"

/**
 * selection_sort - sorts an array using selection sort
 * @array: pointer to int
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t n, i;
	int temp;

	for (n = 0; n < size - 1; n++)
	{
		for (i = n + 1; i < size; i++)
		{
			if (array[n] > array[i])
			{
				temp = array[n];
				array[n] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}
	}
}
