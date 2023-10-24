#include "sort.h"
/**
 * counting_sort - sorts an array using a counting sort algorithm
 * @array: pointer to an array
 * @size: sie of the array
 */


void counting_sort(int *array, size_t size)
{
  int max = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

     int *count = (int *)malloc((max + 1) * sizeof(int));
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

     for (size_t i = 0; i < size; i++) {
        count[array[i]]++;
    }

     printf("Counting array: ");
    for (int i = 0; i <= max; i++) {
        printf("%d ", count[i]);
    }
    printf("\n");

     size_t index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            array[index] = i;
            index++;
            count[i]--;
        }
    }

     free(count);
}
