#pragma once

/*
	Quick Sort:
	Quick Sort efficiently sorts large datasets by recursively partitioning elements based on a chosen pivot.
	It has an average time complexity of O(n log n) and is best suited for large datasets.

	Use QuickSort:
	- When sorting large datasets efficiently is required.
	- When average-case time complexity is more important.

	Avoid QuickSort:
	- When worst-case time complexity is critical.
	- When memory usage needs to be minimized.
*/
class BinarySearch
{
public:
	// Function to perform binary search
	int binarySearch(int arr[], int size, int target);
};
