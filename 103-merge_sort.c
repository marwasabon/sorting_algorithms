#include "sort.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

void _print(const char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	write(1, s, i);
}

void _merge(int *s_arr, int *d_arr, size_t start, size_t end, size_t middle)
{
	size_t i, j, k;

	_print("Merging...\n");
	_print("[left]: ");
	print_array(s_arr + start, middle - start);
	_print("[right]: ");
	print_array(s_arr + middle, end - middle);
	_print("[Done]: ");
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

void _copy(int *src, int *dest, size_t src_size)
{
	size_t i;

	for (i = 0; i < src_size; i++)
		dest[i] = src[i];
}
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
