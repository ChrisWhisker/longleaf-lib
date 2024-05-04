#pragma once

namespace sort {
	/*
		QuickSort efficiently sorts large datasets by recursively partitioning elements
		based on a chosen pivot. It has an average time complexity of O(n log n) and is
		best suited for large datasets.

		Use QuickSort:
		- When sorting large datasets efficiently is required.
		- When average-case time complexity is more important.

		Avoid QuickSort:
		- When worst-case time complexity is critical.
		- When memory usage needs to be minimized.
	*/
	template <typename T>
	class QuickSort
	{
	public:
		// The main function that implements QuickSort
		// Parameters:
		//   arr: The array to be sorted.
		//   low: The starting index of the array or subarray to be sorted.
		//   high: The ending index of the array or subarray to be sorted.
		void quickSort(T arr[], int low, int high)
		{
			if (low < high) // If there are more than one elements in the subarray
			{
				// arr[p] is now at right place
				const int partitionIndex = partition(arr, low, high);

				// Recursively sort elements before and after the partition
				quickSort(arr, low, partitionIndex - 1); // Sort the left subarray
				quickSort(arr, partitionIndex + 1, high); // Sort the right subarray
			}
		}

	private:
		// Swap two elements in the array
		// Parameters:
		//   a: Pointer to the first element to be swapped.
		//   b: Pointer to the second element to be swapped.
		void swap(T* a, T* b) noexcept
		{
			const T temp = *a;
			*a = *b;
			*b = temp;
		}

		// Rearrange the array so that elements smaller than pivot are on the left and larger than pivot are on the right
		// Parameters:
		//   arr: The array to be partitioned.
		//   low: The starting index of the array or subarray to be partitioned.
		//   high: The ending index of the array or subarray to be partitioned.
		// Returns: The index of the pivot element after partitioning.
		int partition(T arr[], int low, int high)
		{
			const T pivot = arr[high]; // Choose the last element of the array as the pivot
			int i = low - 1;		 // Initialize the index of the smaller element to one less than the low index

			for (int j = low; j <= high - 1; j++)
			{
				// If current element is smaller than the pivot
				if (arr[j] < pivot)
				{
					i++; // Increment index of smaller element
					swap(&arr[i], &arr[j]);
				}
			}
			swap(&arr[i + 1], &arr[high]); // Swap the pivot element with the element at index 'i + 1'
			return (i + 1);				 // Return the partitioning index
		}
	};
}
