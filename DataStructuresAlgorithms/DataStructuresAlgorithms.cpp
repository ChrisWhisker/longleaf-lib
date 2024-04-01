#include <iostream>
#include "Search/BinarySearch.h"

int main()
{
	// Test QuickSort
	//#include "Sort/QuickSort.h"
	//int arr[] = { 10, 7, 8, 9, 1, 5 };
	//int n = sizeof(arr) / sizeof(arr[0]);
	//std::cout << "Original array: ";
	//QuickSort qs;
	//qs.printArray(arr, n);
	//qs.quickSort(arr, 0, n - 1);
	//std::cout << "Sorted array: ";
	//qs.printArray(arr, n);
	//return 0;

	// Test Binary Search
	int arr[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
	int size = sizeof(arr) / sizeof(arr[0]); // Calculate size of array
	int target = 12;

	BinarySearch bs;
	int result = bs.binarySearch(arr, size, target);
	if (result != -1)
		std::cout << "Element found at index: " << result << std::endl;
	else
		std::cout << "Element not found" << std::endl;

	return 0;
}
