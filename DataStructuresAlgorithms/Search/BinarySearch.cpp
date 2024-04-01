#include "BinarySearch.h"
#include <iostream>

int binarySearch(int arr[], int size, int target)
{
    // Input validation
    if (arr == nullptr || size <= 0)
        return -1;

    int left = 0; // Initialize left pointer to the beginning of the array
    int right = size - 1; // Initialize right pointer to the end of the array

    while (left <= right) // Perform binary search until left pointer is less than or equal to right pointer
    {
        int mid = left + (right - left) / 2; // Calculate the middle index

        // Check if the target is present at the middle
        if (arr[mid] == target)
        {
            // Handle duplicate values by returning the first occurrence
            while (mid > 0 && arr[mid - 1] == target)
                mid--;
            return mid; // Return the index if target is found
        }

        // If target is greater than the middle element, ignore left half
        if (arr[mid] < target)
            left = mid + 1; // Update left pointer to mid + 1

        // If target is smaller than the middle element, ignore right half
        else
            right = mid - 1; // Update right pointer to mid - 1
    }

    // Target not found
    return -1;
}
