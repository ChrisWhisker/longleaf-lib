#pragma once

// Quick Sort is known for its efficient sorting algorithm that follows the Divide and Conquer strategy.
// It works by selecting a 'pivot' element from the array and partitioning the other elements into two
// sub-arrays according to whether they are less than or greater than the pivot. The sub-arrays are then
// recursively sorted. Quick Sort is generally fast in practice and is widely used for sorting large datasets.
// However, it may not be suitable for small datasets or datasets with many duplicate elements,
// as it can degrade to O(n^2) time complexity in the worst case.
class BinarySearch
{
public:
	// Function to perform binary search
	int binarySearch(int arr[], int size, int target);
};
