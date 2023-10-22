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

	n = size - 1;
	while (n)
	{
		swapped = false;
		for (i = 0; i < n; i++)
		{
			tmp = array[i];
			if (tmp > array[i + 1])
			{
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swapped = true;
				print_array(array, size);


			}
		}

		if (!swapped)
			break;

		n -= 1;
	}

}
