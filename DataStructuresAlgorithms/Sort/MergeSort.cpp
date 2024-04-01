#include "MergeSort.h"
#include <iostream>

void MergeSort::merge(int arr[], int leftIdx, int middleIdx, int rightIdx)
{
	int i, j, k;
	int leftSize = middleIdx - leftIdx + 1;
	int rightSize = rightIdx - middleIdx;

	// Create temporary arrays using dynamic memory allocation
	int* leftArray = new int[leftSize];
	int* rightArray = new int[rightSize];

	// Copy data to temporary arrays
	for (i = 0; i < leftSize; i++)
		leftArray[i] = arr[leftIdx + i]; // Copy elements from arr to the left subarray
	for (j = 0; j < rightSize; j++)
		rightArray[j] = arr[middleIdx + 1 + j]; // Copy elements from arr to the right subarray

	// Merge the temporary arrays back into arr[leftIdx..rightIdx]
	i = 0;       // Initial index of the first subarray
	j = 0;       // Initial index of the second subarray
	k = leftIdx; // Initial index of the merged subarray
	while (i < leftSize && j < rightSize)
	{
		if (leftArray[i] <= rightArray[j])
		{
			arr[k] = leftArray[i]; // Put smaller element from leftArray[] into arr
			i++;
		}
		else
		{
			arr[k] = rightArray[j]; // Put smaller element from rightArray[] into arr
			j++;
		}
		k++;
	}

	// Copy the remaining elements of leftArray[], if there are any
	while (i < leftSize)
	{
		arr[k] = leftArray[i]; // Copy remaining elements of leftArray[] into arr
		i++;
		k++;
	}

	// Copy the remaining elements of rightArray[], if there are any
	while (j < rightSize)
	{
		arr[k] = rightArray[j]; // Copy remaining elements of rightArray[] into arr
		j++;
		k++;
	}

	// Free dynamically allocated memory to prevent memory leaks
	delete[] leftArray;  // Deallocate memory used for the left temporary array
	delete[] rightArray; // Deallocate memory used for the right temporary array
}

void MergeSort::mergeSort(int arr[], int leftIdx, int rightIdx)
{
	if (leftIdx < rightIdx)
	{
		int middleIdx = leftIdx + (rightIdx - leftIdx) / 2; // Calculate the middle index to divide the array into halves

		// Recursively sort the first and second halves
		mergeSort(arr, leftIdx, middleIdx);
		mergeSort(arr, middleIdx + 1, rightIdx);

		// Merge the sorted halves
		merge(arr, leftIdx, middleIdx, rightIdx);
	}
}
