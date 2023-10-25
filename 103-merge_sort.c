#include "sort.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>


void _copy(int *src, int *dest, size_t src_size);
void _print(const char *s);
void _merge(int *s_arr, int *d_arr, size_t start,
			size_t end, size_t middle);
void _divide(int *dest, size_t start, size_t end, int *src);

/**
 * _print - Print a string to the standard output.
 *
 * This function prints the characters in the input
 * string to the standard output.
 *
 * @s: The input string to be printed.
 */
void _print(const char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	write(1, s, i);
}

/**
 * _merge - Merge two subarrays into a sorted array.
 *
 * This function merges two subarrays into a single sorted array. It also
 * prints the intermediate steps of the merge process.
 *
 * @s_arr: The source array containing two subarrays to be merged.
 * @d_arr: The destination array where the merged subarrays will be stored.
 * @start: The start index of the first subarray.
 * @end: The end index of the second subarray.
 * @middle: The end index of the first subarray and
 * start index of the second subarray.
 */
void _merge(int *s_arr, int *d_arr, size_t start, size_t end, size_t middle)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(s_arr + start, middle - start);
	printf("[right]: ");
	print_array(s_arr + middle, end - middle);
	printf("[Done]: ");
	i = start;
	j = middle;
	for (k = start; k < end; k++)
	{
		if (i < middle && (j >= end || s_arr[i] <= s_arr[j]))
			d_arr[k] = s_arr[i++];
		else
			d_arr[k] = s_arr[j++];
	}
	print_array(d_arr + start, end - start);
}
/**
 * _divide - Recursively divide and merge an array.
 *
 * This function recursively divides and merges an array
 * to perform a merge sort.
 *
 * @dest: The destination array where the sorted elements will be stored.
 * @start: The start index of the current subarray.
 * @end: The end index of the current subarray.
 * @src: The source array to be divided and merged.
 */
void _divide(int *dest, size_t start, size_t end, int *src)
{
	size_t middle;

	if ((end - start) <= 1)
		return;

	middle = (start + end) / 2;

	_divide(src, start, middle, dest);
	_divide(src, middle, end, dest);

	_merge(dest, src, start, end, middle);

}

/**
 * _copy - Copies the elements from one array to another.
 *
 * This function copies the elements from the source
 * array to the destination array.
 *
 * @src: The source array to copy from.
 * @dest: The destination array to copy to.
 * @src_size: The number of elements to copy from the source array.
 */
void _copy(int *src, int *dest, size_t src_size)
{
	size_t i;

	for (i = 0; i < src_size; i++)
		dest[i] = src[i];
}
/**
 * merge_sort - Sorts an array of integers using the Merge Sort algorithm.
 *
 * @array: An array of integers to be sorted.
 * @size: The number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	int *cpy_array;

	if (array == NULL || size < 2)
		return;

	cpy_array = malloc(sizeof(int) * size);
	_copy(array, cpy_array, size);

	_divide(cpy_array, 0, size, array);
	free(cpy_array);
}
