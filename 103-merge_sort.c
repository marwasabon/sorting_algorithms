#include "sort.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/* void _sort_recursively(int *arr, int *cp_arr, */
/* 					   size_t i_start, size_t i_end, size_t size); */
/* void _merge(int *arr, int *cp_arr, */
/* 					   size_t i_sta, size_t i_end, size_t i_mid, size_t size); */
/* void _copy(int *src, int *dest, size_t src_size); */

void _merge(int *s_arr, int *d_arr, size_t start, size_t end, size_t middle)
{
	size_t i, j, k;

	i = start, j = middle;
	for (k = start; k < end; k++) {
		if (i < middle && (j >= end || s_arr[i] <= s_arr[j]))
			d_arr[k] = s_arr[i++];
		else
			d_arr[k] = s_arr[j++];
	}
}

void _divide(int *dest, size_t start, size_t end, int *src)
{
	size_t middle;

	if ((end - start) <= 1)
		return;

	middle = (start + end) / 2;

	printf("START: %i\n", dest[start]);
	printf("END: %i\n", dest[end - 1]);
	printf("MIDDLE: %i\n", dest[middle]);
	_divide(src, start, middle, dest);
	_divide(src, middle, end,dest);

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
	/* cpy_array = malloc(sizeof(int) * size); */
	/* _copy(array, cpy_array, size); */
	/* _sort_recursively(array, cpy_array, 0, size, size); */
	/* print_array(cpy_array, size); */
	/* free(cpy_array); */
}



/* void _sort_recursively(int *arr, int *cp_arr, */
/* 					   size_t i_sta, size_t i_end, size_t size) */
/* { */
/* 	int i_mid; */

/* 	if ((i_end - i_sta) <= 1) */
/* 		return; */

/* 	i_mid = (i_sta + i_end) / 2; */

/* 	_sort_recursively(arr, cp_arr, i_sta, i_mid, size); */
/* 	_sort_recursively(arr, cp_arr, i_mid, i_end, size); */

/* 	_merge(cp_arr, arr, i_sta, i_end, i_mid, size); */
/* } */

