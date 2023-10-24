#include "sort.h"
/**
 * counting_sort - sorts an array using a counting sort algorithm
 * @array: pointer to an array
 * @size: sie of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int *count;
	size_t max = 0;
	int index = 0;

	if (array == NULL || size <= 1)
		return;

	for (i = 0; i < size; i++)
	{
		if ((size_t)array[i] > max)
		{
			max = (size_t)array[i];
		}
	}

	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;

	for (i = 0; i <= max; i++)
	{
		count[i] = 0;
	}

	for (i = 0; i < size; i++)
	{
		count[array[i]]++;
	}

	printf("Counting array: ");
	for (i = 0; i <= max; i++)
	{
		printf("%d ", count[i]);
	}
	printf("\n");

	for (i = 0; i <= max; i++)
	{
		while (count[i] > 0)
		{
			array[index] = i;
			index++;
			count[i]--;
		}
	}

	free(count);
}
