#include "sort.h"


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
	int i = min - 1, x;

	for (x = min; x <= max; x++)
	{
		if (array[x] < pivot)
		{
			i++;

			swap(array, size, i, x);
		}
	}
	swap(array, size, i + 1, max);

	return (i + 1);
}


void
swap(int *array, size_t size, int min, int max)
{
	int temp;

	if (array[min] != array[max])
	{
		temp = array[min];
		array[min] = array[max];
		array[max] = temp;
		print_array(array, size);
	}
}
