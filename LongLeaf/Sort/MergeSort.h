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
                const int middle_index = leftIndex + (rightIndex - leftIndex) / 2;
                merge_sort(arr, leftIndex, middle_index);
                merge_sort(arr, middle_index + 1, rightIndex);
                merge(arr, leftIndex, middle_index, rightIndex);
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
            const int left_size = middleIndex - leftIndex + 1;
            const int right_size = rightIndex - middleIndex;

            // Create temporary arrays using dynamic memory allocation
            T* p_left_array = new T[left_size];
            T* p_right_array = new T[right_size];

            // Check if memory allocation was successful
            if (p_left_array == nullptr || p_right_array == nullptr)
            {
                // Handle memory allocation failure
                delete[] p_left_array;
                delete[] p_right_array;
                return;
            }

            // Copy p_data to temporary arrays
            for (int i = 0; i < left_size; i++)
                p_left_array[i] = arr[leftIndex + i];
            for (int j = 0; j < right_size; j++)
                p_right_array[j] = arr[middleIndex + 1 + j];

            // Merge the temporary arrays back into arr[leftIndex..rightIndex]
            int i = 0, j = 0, k = leftIndex;
            while (i < left_size && j < right_size)
            {
                if (p_left_array[i] <= p_right_array[j])
                    arr[k++] = p_left_array[i++];
                else
                    arr[k++] = p_right_array[j++];
            }

            // Copy remaining elements of leftArray[], if any
            while (i < left_size)
                arr[k++] = p_left_array[i++];

            // Copy remaining elements of rightArray[], if any
            while (j < right_size)
                arr[k++] = p_right_array[j++];

            // Free dynamically allocated memory
            delete[] p_left_array;
            delete[] p_right_array;
        }
    };
}
