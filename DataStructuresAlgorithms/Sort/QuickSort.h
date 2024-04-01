#pragma once

#include <iostream>

class QuickSort
{
public:
	// The main function that implements QuickSort
	void quickSort(int arr[], int low, int high);

	void printArray(int arr[], int size) {
		for (int i = 0; i < size; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}

private:
	// Function to swap two elements in the array
	void swap(int* a, int* b);

	// Partition function to rearrange the array so that
	// elements smaller than pivot are on the left and larger
	// than pivot are on the right
	int partition(int arr[], int low, int high);
};
