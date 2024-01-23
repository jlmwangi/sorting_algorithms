#include "sort.h"

/**
 * shell_sort - sorts using shell sort
 * @array: pointer to int
 * @size: size_t
 */

void shell_sort(int *array, size_t size)
{
	size_t n = 1;
	size_t i, j;
	int temp;

	while (n <= size / 3)
		n = 3 * n + 1;

	while (n > 0)
	{
		for (i = n; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= n && array[j - n] > temp)
			{
				array[j] = array[j - n];
				j -= n;
			}
			array[j] = temp;
		}
		n = (n - 1) / 3;
	}
}
