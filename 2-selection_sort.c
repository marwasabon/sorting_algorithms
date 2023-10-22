
#include "sort.h"

/**
 * swap - swap two elements in an array
 * @array: pointer to an array
 * @i: index of first element
 * @j: index of second element
 */
void swap(int *array, size_t i, size_t j)
{
	int tmp = array[i];

	array[i] = array[j];
	array[j] = tmp;
}

/**
 * selection_sort - sort an array using a selection sort algorithm
 * @array: pointer to an array
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	if (!array || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}

		if (min_idx != i)
		{
			int temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}
	}
}
