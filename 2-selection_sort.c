
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
	size_t i, j;
	int min_idx;
	bool swapped;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		swapped = false;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
				swapped = true;
			}
		}

		if (swapped)
		{
			swap(array, i, min_idx);
			print_array(array, size);
		}
	}
}
