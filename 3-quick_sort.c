#include "sort.h"

/**
 * quick_sort - sorts an integer array in ascending order
 * @array: pointer to int
 * @size: size_t
 */

void quick_sort(int *array, size_t size)
{
	int pivot = array[size - 1];
	int i = -1, temp;
	size_t j;

	if (size < 2)
		return;
	for (j = 0; j < size - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[size - 1];
	array[size - 1] = temp;

	quick_sort(array, i + 1);
	quick_sort(array + i + 2, size - i - 2);
}
