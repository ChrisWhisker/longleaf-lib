#pragma once

namespace search
{
	/*
		Binary Search is a search algorithm that efficiently locates a target value
		within a sorted array by repeatedly dividing the search interval in half. It
		guarantees O(log n) time complexity in all cases and is particularly suitable
		for large sorted datasets.

		Use Binary Search:
		- When searching for a target value in a sorted array efficiently is required.
		- When a consistent O(log n) time complexity is preferred regardless of the
		input distribution.
		- When random access to elements in the array is available.

		Avoid Binary Search:
		- When the array is not sorted, as BinarySearch requires a sorted input.
		- When the dataset is small or not sorted, as simpler linear search algorithms
		may be more efficient.
		- When the overhead of maintaining a sorted array outweighs the benefits of
		faster search times.
	*/
	template <typename T>
	class BinarySearch
	{
	public:
		// Perform binary search
		// Parameters:
		//   arr: The sorted array to be searched.
		//   size: The number of elements in the array.
		//   target: The value to be searched for.
		// Returns: The index of the target value if found, or -1 if not found.
		static int binarySearch(T arr[], int size, T target)
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
	};
}
