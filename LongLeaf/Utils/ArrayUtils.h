#pragma once
#include <iostream>

namespace utils
{
	/*
		A utility class providing functions for working with C-style arrays.

		The ArrayUtils class contains static methods for common operations on
		C-style arrays, including printing, finding the maximum and minimum elements,
		calculating the sum and average of elements, checking for the presence of a value,
		and reversing the elements.

		This class is useful when dealing with fixed-size arrays where the size is known
		at compile time. It simplifies common array operations and promotes code reuse.

		When using this class, ensure that the array passed to its methods is properly
		sized and not nullptr to avoid undefined behavior. Additionally, note that this
		class is templated on both the p_data type and size of the array, providing flexibility
		while maintaining type safety.
	*/
	template <typename T, size_t size>
	class ArrayUtils
	{
	public:
		// Print elements of an array
		// Parameters:
		//   arr: The C-style array to be printed.
		static void print(const T(&arr)[size])
		{
			for (const auto& elem : arr)
			{
				std::cout << elem << " ";
			}
			std::cout << "\n";
		}

		// Find the maximum element in an array
		// Parameters:
		//   arr: The C-style array in which the maximum element is to be found.
		// Returns: The maximum element found in the array.
		static T max(const T(&arr)[size])
		{
			T max_element = arr[0];
			for (size_t i = 1; i < size; ++i)
			{
				if (arr[i] > max_element)
				{
					max_element = arr[i];
				}
			}
			return max_element;
		}

		// Find the minimum element in an array
		// Parameters:
		//   arr: The C-style array in which the minimum element is to be found.
		// Returns: The minimum element found in the array.
		static T min(const T(&arr)[size])
		{
			T min_element = arr[0];
			for (size_t i = 1; i < size; ++i)
			{
				if (arr[i] < min_element)
				{
					min_element = arr[i];
				}
			}
			return min_element;
		}

		// Calculate the sum of elements in an array
		// Parameters:
		//   arr: The C-style array whose elements are to be summed.
		// Returns: The sum of all elements in the array.
		static T sum(const T(&arr)[size])
		{
			T sum = T();
			for (const auto& element : arr)
			{
				sum += element;
			}
			return sum;
		}

		// Calculate the average of elements in an array
		// Parameters:
		//   arr: The C-style array whose elements are to be averaged.
		// Returns: The average of all elements in the array.
		static double average(const T(&arr)[size])
		{
			T sum_val = sum(arr);
			return static_cast<double>(sum_val) / size;
		}

		// Check if a value is contained within an array
		// Parameters:
		//   arr: The C-style array to be searched.
		//   value: The value to search for in the array.
		// Returns: True if the value is found in the array, false otherwise.
		static bool contains_value(const T(&arr)[size], const T& value)
		{
			for (const auto& element : arr)
			{
				if (element == value)
				{
					return true;
				}
			}
			return false;
		}

		// Reverse the elements in an array
		// Parameters:
		//   arr: The C-style array whose elements are to be reversed.
		static void reverse(T(&arr)[size])
		{
			size_t i = 0;
			size_t j = size - 1;
			while (i < j)
			{
				std::swap(arr[i], arr[j]);
				++i;
				--j;
			}
		}
	};
}
