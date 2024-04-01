#include "BinarySearch.h"
#include <iostream>


int BinarySearch::binarySearch(int arr[], int size, int target) {
	int left = 0;
	int right = size - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		// Check if the target is present at the middle
		if (arr[mid] == target)
			return mid;

		// If target is greater, ignore left half
		if (arr[mid] < target)
			left = mid + 1;

		// If target is smaller, ignore right half
		else
			right = mid - 1;
	}

	// Target not found
	return -1;
}
