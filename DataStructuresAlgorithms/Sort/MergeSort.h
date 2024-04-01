#pragma once

/*
    MergeSort is a stable sorting algorithm that divides the array into smaller subarrays, sorts them independently, and then merges them back together.
    It guarantees O(n log n) time complexity in all cases and is suitable for sorting large datasets.

    Use MergeSort:
    - When stability in sorting order is important (i.e., equal elements maintain their relative order).
    - When a consistent O(n log n) time complexity is preferred regardless of the input distribution.
    - When sorting linked lists where random access is not efficient.

    Avoid MergeSort:
    - When sorting small arrays as the overhead of recursion and merging may outweigh the benefits.
    - When memory usage is a concern, as MergeSort typically requires additional space proportional to the size of the input.
*/
class MergeSort
{
public:
	// Main function that sorts arr[leftIndex..rightIndex] using merge()
	void mergeSort(int arr[], int leftIndex, int rightIndex);

private:
	// Function to merge two subarrays of arr[]
	// First subarray is arr[leftIndex..middleIndex]
	// Second subarray is arr[middleIndex+1..rightIndex]
	void merge(int arr[], int leftIndex, int middleIndex, int rightIndex);
};