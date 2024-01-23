#include "sort.h"
/**
 * partition - split array
 * @array: pointer to int
 * @i: first element
 * @j: second element
 * @size: size_t
 * Return: int
 */

int partition(int *array, int i, int j, size_t size)
{
	int temp;
	int first = i;
	int n;
	int pivot = array[j];

	for (n = i; n < j; n++)
	{
		if (array[n] <= pivot)
		{
			temp = array[first];
			array[first] = array[n];
			array[n] = temp;
			if (first != n)
				print_array(array, size);
			first++;
		}
	}
	temp = array[first];
	array[first] = array[j];
	array[j] = temp;
	if (first != n)
		print_array(array, size);
	return (first);
}

/**
 * QuickSort - sorts part of the list
 * @array: pointer to int
 * @i: first element
 * @j: last element
 * @size: size_t
 */
void QuickSort(int *array, int i, int j, size_t size)
{
	int pivot;

	if (i < j)
	{
		pivot = partition(array, i, j, size);
		QuickSort(array, i, pivot - 1, size);
		QuickSort(array, pivot + 1, j, size);
	}
}

/**
 * quick_sort - sorts an integer array in ascending order
 * @array: pointer to int
 * @size: size_t
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	QuickSort(array, 0, size - 1, size);
}
