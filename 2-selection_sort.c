#include "sort.h"

void
selection_sort(int *array, size_t size)
{
	size_t i, j, min_indx;
	int temp;


	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min_indx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_indx])
				min_indx = j;
		}
		if (array[min_indx] != array[i])
		{
			temp = array[min_indx];
			array[min_indx] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}

