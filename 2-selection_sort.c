#include "sort.h"

/**
 * selection_sort - sorts an array using selection sort
 * @array: pointer to int
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t n, i, j = 0;
	int temp;

	for (n = 0; n < size - 1; n++)
	{
		j = n;
		for (i = n + 1; i < size; i++)
		{
			if (array[j] > array[i])
			{
				j = i;
			}
		}
		if (n != j)
		{
			temp = array[j];
			array[j] = array[n];
			array[n] = temp;
			print_array(array, size);
		}
	}
}
