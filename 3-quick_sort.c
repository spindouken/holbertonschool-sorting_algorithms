#include "sort.h"

/**
 * Lumoto_partition - partitions an array using the Lomuto scheme
 * @array: the array to partition
 * @low: the lower index of the partition
 * @high: the upper index of the partition
 * @size: the size of the array
 * Return: the index of the pivot
 */

int Lumoto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{
	int low, high;

	if (array == NULL || size < 2)
		return;

	low = 0;
	high = size - 1;
	while (low < high)
	{
		int pivot = Lumoto_partition(array, low, high, size);

		if (pivot - low < high - pivot)
		{
			quick_sort(array, pivot);
			low = pivot + 1;
		}
		else
		{
			quick_sort(array + pivot + 1, high - pivot);
			high = pivot - 1;
		}
	}
}
