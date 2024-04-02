#include "ArrayUtils.h"
#include <iostream>

int main()
{
	// ********** DATA STRUCTURES **********

	// Test array    #include "DataStructures/Array.h"
	//// Create an array
	//Array arr(5);
	//// Fill the array with values
	//arr.fill(10);
	//// Test getSize()
	//std::cout << "Array size: " << arr.getSize() << std::endl;
	//// Test operator[] (read-write)
	//arr[2] = 20;
	//std::cout << "Value at index 2: " << arr[2] << std::endl;
	//// Test operator[] (read-only)
	//const int& value = arr[3];
	//std::cout << "Value at index 3 (read-only): " << value << std::endl;
	//// Test clear()
	//arr.clear();
	//std::cout << "Array size after clear: " << arr.getSize() << std::endl;
	//// Test isEmpty()
	//std::cout << "Is array empty? " << (arr.isEmpty() ? "Yes" : "No") << std::endl;
	//// Test resize()
	//arr.resize(8);
	//std::cout << "Array size after resize: " << arr.getSize() << std::endl;
	//// Test insert()
	//arr.insert(2, 30);
	//std::cout << "Value at index 2 after insertion: " << arr[2] << std::endl;
	//// Test remove()
	//arr.remove(20);
	//std::cout << "Array size after removal: " << arr.getSize() << std::endl;
	//// Test reverse()
	//arr.reverse();
	//std::cout << "Reversed array:";
	//for (size_t i = 0; i < arr.getSize(); ++i)
	//	std::cout << " " << arr[i];
	//std::cout << std::endl;
	//// Test find()
	//int index = arr.find(30);
	//std::cout << "Index of value 30: " << index << std::endl;
	//// Test count()
	//size_t count = arr.count(10);
	//std::cout << "Count of value 10: " << count << std::endl;

	// Test LinkedList    #include "DataStructures/LinkedList.h"
	//// Create a LinkedList object for integers
	// LinkedList<int> list;
	//// Test insertAtBeginning function
	// list.insertAtBeginning(1);
	// list.insertAtBeginning(2);
	// list.insertAtBeginning(3);
	// std::cout << "List after insertAtBeginning: ";
	// list.display(); // Expected output: 3 2 1
	//// Test insertAtEnd function
	// list.insertAtEnd(4);
	// list.insertAtEnd(5);
	// std::cout << "List after insertAtEnd: ";
	// list.display(); // Expected output: 3 2 1 4 5
	//// Test insertAtPosition function
	// list.insertAtPosition(10, 2);
	// std::cout << "List after insertAtPosition(10, 2): ";
	// list.display(); // Expected output: 3 2 10 1 4 5
	//// Test remove function
	// list.remove(2);
	// std::cout << "List after remove(2): ";
	// list.display(); // Expected output: 3 10 1 4 5
	//// Test removeAtPosition function
	// list.removeAtPosition(3);
	// std::cout << "List after removeAtPosition(3): ";
	// list.display(); // Expected output: 3 10 4 5
	//// Test length function
	// std::cout << "Length of the list: " << list.length() << std::endl; // Expected output: 4
	// return 0;

	// ********** SEARCH **********

	// Test Binary Search    #include "Search/BinarySearch.h"
	// int arr[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
	// int size = sizeof(arr) / sizeof(arr[0]); // Calculate size of array
	// int target = 12;
	// BinarySearch bs;
	// int result = bs.binarySearch(arr, size, target);
	// if (result != -1)
	//	std::cout << "Element found at index: " << result << std::endl;
	// else
	//	std::cout << "Element not found" << std::endl;
	// return 0;

	// ********** SORT **********

	// Test Merge Sort    #include "Sort/MergeSort.h"
	// int arr[] = { 12, 11, 13, 5, 6, 7 };
	// int arr_size = sizeof(arr) / sizeof(arr[0]);
	// std::cout << "Given array is \n";
	// ArrayUtils<int, 6>::print(arr);
	// MergeSort ms;
	// ms.mergeSort(arr, 0, arr_size - 1);
	// std::cout << "Sorted array is \n";
	// ArrayUtils<int, 6>::print(arr);
	// return 0;

	// Test QuickSort    #include "Sort/QuickSort.h"
	// int arr[] = { 10, 7, 8, 9, 1, 5 };
	// int n = sizeof(arr) / sizeof(arr[0]);
	// std::cout << "Original array: ";
	// QuickSort qs;
	// ArrayUtils<int, 6>::print(arr);
	// qs.quickSort(arr, 0, n - 1);
	// std::cout << "Sorted array: ";
	// ArrayUtils<int, 6>::print(arr);
	// return 0;
}
