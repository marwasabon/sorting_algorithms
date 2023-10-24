#include "sort.h"

/**
 * shell_sort - sorts an array using the shell sort algorithm.
 * @array: pointer to an array
 * @size: size of @array
 */


void shell_sort(int *array, size_t size)
{

	int i, j, interval;

	interval = 1;
	

	while (interval <= (int)(size / 3))
	{
		interval = interval * 3 + 1;
	}

	while (interval > 0)
	{
		for (i = interval; i < (int)size; i++)
		{
			int temp = array[i];
			j = i;

			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}

			array[j] = temp;
		}
		interval = (interval - 1) / 3;

		print_array(array, size);

	}
}
