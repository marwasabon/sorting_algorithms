#include "sort.h"

/**
 * bubble_sort - sortsan array for integer using the bubble sort algorithm
 *
 * @size: size of the array
 * @array: is a pointer to an array
 */


void bubble_sort(int *array, size_t size)

{
	int i, n, tmp;

	bool swapped;

	if (array == NULL || size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = true;
				print_array(array, size);
			}
		}

		if (!swapped)
			break;
	}
}
