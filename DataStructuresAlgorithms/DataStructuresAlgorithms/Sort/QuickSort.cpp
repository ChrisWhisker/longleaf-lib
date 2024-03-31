#include "QuickSort.h"
#include <iostream>

void QuickSort::swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int QuickSort::partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // Choose the last element as pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high - 1; j++) {
		// If current element is smaller than the pivot
		if (arr[j] < pivot) {
			i++; // Increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void QuickSort::quickSort(int arr[], int low, int high)
{
	if (low < high) {
		// pi is partitioning index, arr[p] is now at right place
		int pi = partition(arr, low, high);

		// Separately sort elements before partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}