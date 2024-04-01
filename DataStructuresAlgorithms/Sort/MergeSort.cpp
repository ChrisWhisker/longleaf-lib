#include "MergeSort.h"
#include <iostream>

void MergeSort::merge(int arr[], int leftIndex, int middleIndex, int rightIndex)
{
	// Validate input parameters
	if (arr == nullptr || leftIndex < 0 || middleIndex < 0 || rightIndex < 0 || leftIndex >= rightIndex)
	{
		// Handle invalid input parameters
		return;
	}

	// Calculate sizes of subarrays
	int leftSize = middleIndex - leftIndex + 1;
	int rightSize = rightIndex - middleIndex;

	// Create temporary arrays using dynamic memory allocation
	int* leftArray = new int[leftSize];
	int* rightArray = new int[rightSize];

	// Check if memory allocation was successful
	if (leftArray == nullptr || rightArray == nullptr)
	{
		// Handle memory allocation failure
		delete[] leftArray;
		delete[] rightArray;
		return;
	}

	// Copy data to temporary arrays
	for (int i = 0; i < leftSize; i++)
		leftArray[i] = arr[leftIndex + i];
	for (int j = 0; j < rightSize; j++)
		rightArray[j] = arr[middleIndex + 1 + j];

	// Merge the temporary arrays back into arr[leftIndex..rightIndex]
	int i = 0, j = 0, k = leftIndex;
	while (i < leftSize && j < rightSize)
	{
		if (leftArray[i] <= rightArray[j])
			arr[k++] = leftArray[i++];
		else
			arr[k++] = rightArray[j++];
	}

	// Copy remaining elements of leftArray[], if any
	while (i < leftSize)
		arr[k++] = leftArray[i++];

	// Copy remaining elements of rightArray[], if any
	while (j < rightSize)
		arr[k++] = rightArray[j++];

	// Free dynamically allocated memory
	delete[] leftArray;
	delete[] rightArray;
}

void MergeSort::mergeSort(int arr[], int leftIndex, int rightIndex)
{
	// Validate input parameters
	if (arr == nullptr || leftIndex < 0 || rightIndex < 0 || leftIndex >= rightIndex)
	{
		// Handle invalid input parameters
		return;
	}

	if (leftIndex < rightIndex)
	{
		int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
		mergeSort(arr, leftIndex, middleIndex);
		mergeSort(arr, middleIndex + 1, rightIndex);
		merge(arr, leftIndex, middleIndex, rightIndex);
	}
}
