#include "QuickSort.h"
#include <iostream>

void QuickSort::swap(int* a, int* b) noexcept
{
	const int temp = *a;
	*a = *b;
	*b = temp;
}

int QuickSort::partition(int arr[], int low, int high)
{
	const int pivot = arr[high]; // Choose the last element of the array as the pivot
	int i = low - 1;	   // Initialize the index of the smaller element to one less than the low index

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // Increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]); // Swap the pivot element with the element at index 'i + 1'
	return (i + 1);				   // Return the partitioning index
}

void QuickSort::quickSort(int arr[], int low, int high)
{
	if (low < high) // If there are more than one elements in the subarray
	{
		// arr[p] is now at right place
		const int partitionIndex = partition(arr, low, high);

		// Recursively sort elements before and after the partition
		quickSort(arr, low, partitionIndex - 1);  // Sort the left subarray
		quickSort(arr, partitionIndex + 1, high); // Sort the right subarray
	}
}
