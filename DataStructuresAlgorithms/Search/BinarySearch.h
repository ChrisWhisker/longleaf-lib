#pragma once

/*
	Binary Search is a search algorithm that efficiently locates a target value within a sorted array by repeatedly dividing the search interval in half.
	It guarantees O(log n) time complexity in all cases and is particularly suitable for large sorted datasets.

	Use Binary Search:
	- When searching for a target value in a sorted array efficiently is required.
	- When a consistent O(log n) time complexity is preferred regardless of the input distribution.
	- When random access to elements in the array is available.

	Avoid Binary Search:
	- When the array is not sorted, as BinarySearch requires a sorted input.
	- When the dataset is small or not sorted, as simpler linear search algorithms may be more efficient.
	- When the overhead of maintaining a sorted array outweighs the benefits of faster search times.
*/
class BinarySearch
{
public:
	// Function to perform binary search
	int binarySearch(int arr[], int size, int target);
};
