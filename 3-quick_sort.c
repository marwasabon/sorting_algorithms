#include "sort.h"
#include <stddef.h>

/**
 * quick_sort - Sorts an array of integers in ascending order using the
 *              Quick Sort algorithm.
 *
 * This function sorts an array of integers using the Quick Sort algorithm.
 *
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	_sort(array, 0, size - 1, size);
}

/**
 * _sort - Recursively sorts an array of integers using Quick Sort algorithm.
 *
 * This function recursively sorts an array of integers in ascending order
 * using the Quick Sort algorithm.
 *
 * @array: The array of integers to be sorted.
 * @low: The starting index of the partition to be sorted.
 * @high: The ending index of the partition to be sorted.
 * @size: The size of the array.
 */
void _sort(int *array, int low, int high, size_t size)
{
	int p_idx;

	if (low >= high)
		return;
	p_idx = _partition(array, low, high, size);
	_sort(array, low, p_idx - 1, size);
	_sort(array, p_idx + 1, high, size);
}

/**
 * _partition - Partitions an array of integers for the Quick Sort algorithm.
 *
 * This function selects a pivot element and partitions the array such that
 * elements less than the pivot come before it, and elements greater than the
 * pivot come after it.
 *
 * @array: The array of integers to be partitioned.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 *
 * Return: The index where the pivot element is placed after partitioning.
 */
int _partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, tmp;

	pivot = array[high];
	for (i = j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			/*swap item at i with item at j*/
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			i++;
		}
	}
	tmp = array[i];
	array[i] = array[high];
	array[high] = tmp;

	print_array(array, size);

	return (i);
}
