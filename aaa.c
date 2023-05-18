#include "sort.h"
#include <stddef.h>


void
quick_sort(int *array, size_t size)
{
	if (!array)
		return;

	recursion(array, size, 0, size - 1);
}

void
recursion(int *array, size_t size, int min, int max)
{
	int pivot;

	if (min < max)
	{
		pivot = partition(array, size, min, max);
		recursion(array, size, min, pivot - 1);
		recursion(array, size, pivot + 1, max);
	}
}

int
partition(int *array, size_t size, int min, int max)
{
	int pivot = array[max];
	int i = min - 1, j;

	for (j = min; j <= max; j++)
	{
		if (array[j] < pivot)
		{
			i++;

			swap(array, size, i, j);
		}
	}
	
	swap(array, size, i + 1, max);

	return (i + 1);
}

void
swap(int *array, size_t size, int min, int max)
{
	int aux;

	if (array[min] != array[max])
	{
		aux = array[min];
		array[min] = array[max];
		array[max] = aux;
		print_array(array, size);
	}
}