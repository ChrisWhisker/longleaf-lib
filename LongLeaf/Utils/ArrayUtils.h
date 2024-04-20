#pragma once
#include <iostream>

// This class provides utility functions for working with C-style arrays.
template <typename T, size_t size>
class ArrayUtils
{
public:
	// Print elements of an array
	static void print(const T(&arr)[size])
	{
		for (const auto& elem : arr)
		{
			std::cout << elem << " ";
		}
		std::cout << "\n";
	}

	// Find the maximum element in an array
	static T max(const T(&arr)[size])
	{
		T maxElement = arr[0];
		for (size_t i = 1; i < size; ++i)
		{
			if (arr[i] > maxElement)
			{
				maxElement = arr[i];
			}
		}
		return maxElement;
	}

	// Find the minimum element in an array
	static T min(const T(&arr)[size])
	{
		T minElement = arr[0];
		for (size_t i = 1; i < size; ++i)
		{
			if (arr[i] < minElement)
			{
				minElement = arr[i];
			}
		}
		return minElement;
	}

	// Calculate the sum of elements in an array
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
	static double average(const T(&arr)[size])
	{
		T sumVal = sum(arr);
		return static_cast<double>(sumVal) / size;
	}

	// Check if a value is contained within an array
	static bool containsValue(const T(&arr)[size], const T& value)
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
