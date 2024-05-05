#pragma once

namespace sort
{
	/*
		MergeSort is a stable sorting algorithm that divides the array into smaller
		sub-arrays, sorts them independently, and then merges them back together. It
		guarantees O(n log n) time complexity in all cases and is suitable for sorting
		large datasets.

		Use MergeSort:
		- When stability in sorting order is important (i.e., equal elements maintain
		their relative order).
		- When a consistent O(n log n) time complexity is preferred regardless of the
		input distribution.
		- When sorting linked lists where random access is not efficient.

		Avoid MergeSort:
		- When sorting small arrays as the overhead of recursion and merging may
		outweigh the benefits.
		- When memory usage is a concern, as MergeSort typically requires additional
		space proportional to the size of the input.
	*/
	template <typename T>
	class MergeSort
	{
	public:
		// Main function that sorts arr[leftIndex..rightIndex] using merge()
		// Parameters:
		//   arr: The array to be sorted.
		//   leftIndex: The index of the first element of the array or sub-array to be sorted.
		//   rightIndex: The index of the last element of the array or sub-array to be sorted.
		void merge_sort(T arr[], int leftIndex, int rightIndex)
		{
			// Validate input parameters
			if (arr == nullptr || leftIndex < 0 || rightIndex < 0 || leftIndex >= rightIndex)
			{
				// Handle invalid input parameters
				return;
			}

			if (leftIndex < rightIndex)
			{
				const int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
				merge_sort(arr, leftIndex, middleIndex);
				merge_sort(arr, middleIndex + 1, rightIndex);
				merge(arr, leftIndex, middleIndex, rightIndex);
			}
		}

	private:
		// Merge two sub-arrays of arr[]
		// First sub-array is arr[leftIndex..middleIndex]
		// Second sub-array is arr[middleIndex+1..rightIndex]
		// Parameters:
		//   arr: The array containing the sub-arrays to be merged.
		//   leftIndex: The index of the first element of the left sub-array.
		//   middleIndex: The index of the last element of the left sub-array.
		//   rightIndex: The index of the last element of the right sub-array.
		void merge(T arr[], int leftIndex, int middleIndex, int rightIndex)
		{
			// Validate input parameters
			if (arr == nullptr || leftIndex < 0 || middleIndex < 0 || rightIndex < 0 || leftIndex >= rightIndex)
			{
				// Handle invalid input parameters
				return;
			}

			// Calculate sizes of sub-arrays
			const int leftSize = middleIndex - leftIndex + 1;
			const int rightSize = rightIndex - middleIndex;

			// Create temporary arrays using dynamic memory allocation
			T* leftArray = new T[leftSize];
			T* rightArray = new T[rightSize];

			// Check if memory allocation was successful
			if (leftArray == nullptr || rightArray == nullptr)
			{
				// Handle memory allocation failure
				delete[] leftArray;
				delete[] rightArray;
				return;
			}

			// Copy p_data to temporary arrays
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
	};
}
