#include "search_algos.h"

/**
 * binary_search - binary search
 * @array: array to search
 * @size: size of @array
 * @value: value to find index
 *
 * Return: -1 on fail or index
 */
int binary_search(int *array, size_t size, int value)
{
	int i;
	int mid;
	int s = 0;
	int e = (int)size - 1;

	if (array == NULL)
		return (-1);

	while (s <= e)
	{
		i = s;
		printf("Searching in array: ");
		while (i <= e)
			if (i == e)
				printf("%d", array[i++]);
			else
				printf("%d, ", array[i++]);

		printf("\n");

		mid = ((e - s) / 2) + s;

		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			s = mid + 1;
		else
			e = mid;
	}

	return (-1);
}