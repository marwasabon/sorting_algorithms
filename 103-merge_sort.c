#include "sort.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 1024

void _printn(int n)
{
	int is_negative = 0, i = 0, j;
	char iBuffer[BUFSIZE], tmp;

	if (n < 0)
	{
		is_negative = 1;
		n *= -1;
	}

	while (n != 0)
	{
		iBuffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (is_negative)
		iBuffer[i++] = '-';

	iBuffer[i] = '\0';
	for (j = 0; j < (i / 2); j++)
	{
		tmp = iBuffer[j];
		iBuffer[j] = iBuffer[i - j - 1];
		iBuffer[i - j - 1] = tmp;
	}
	write(1, iBuffer, i);
}


void _merge(int *s_arr, int *d_arr, size_t start, size_t end, size_t middle)
{
	size_t i, j, k;

	write(1, "Merging...\n", 11);
	write(1, "[left]: ", 8);
	print_array(s_arr + start, middle - start);
	/* _printn(s_arr[start]); */
	/* write(1, "\n", 1); */
	write(1, "[right]: ", 9);
	print_array(s_arr + middle, end - middle);
	/* _printn(s_arr[end - 1]); */
	/* write(1, "\n", 1); */
	write(1, "[Done]: ", 8);
	i = start;
	j = middle;
	for (k = start; k < end; k++) {
		if (i < middle && (j >= end || s_arr[i] <= s_arr[j]))
		{
			d_arr[k] = s_arr[i++];
			/* _printn(d_arr[k]); */
		}
		else
		{
			d_arr[k] = s_arr[j++];
			/* _printn(d_arr[k]); */
		}
		/* if ((k + 1) != end) */
		/* 	write(1, ", ", 2); */
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
	free(cpy_array);
}
