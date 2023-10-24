#include "sort.h"
/**
 * counting_sort - sorts an array using a counting sort algorithm
 * @array: pointer to an array
 * @size: sie of the array
 */


To fix the errors in the code, you need to make the following changes:

Add the -std=c99 flag when compiling the code to allow for loop initial declarations.
Move the declaration of i outside of the for loop in line 13.
Move the declaration of count to the beginning of the function, before the first for loop.
Change the type of index from size_t to int to match the type of i in the last for loop.

Here’s the updated code:
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - sorts an array using a counting sort algorithm
 * @array: pointer to an array
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}

	int *count = (int *)malloc((max + 1) * sizeof(int));

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

	int index = 0;

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
