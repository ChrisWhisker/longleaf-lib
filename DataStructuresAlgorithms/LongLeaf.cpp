#include "ArrayUtils.h"
#include <iostream>

int main()
{
	// ********** DATA STRUCTURES **********

	// Test array    #include "DataStructures/Array.h"
	// Array<int> arr(5);
	// arr.fill(10);
	// std::cout << "Array size: " << arr.getSize() << std::endl;
	// arr[2] = 20;
	// std::cout << "Value at index 2: " << arr[2] << std::endl;
	// const int& value = arr[3];
	// std::cout << "Value at index 3 (read-only): " << value << std::endl;
	// arr.clear();
	// std::cout << "Array size after clear: " << arr.getSize() << std::endl;
	// std::cout << "Is array empty? " << (arr.isEmpty() ? "Yes" : "No") << std::endl;
	// arr.resize(8);
	// std::cout << "Array size after resize: " << arr.getSize() << std::endl;
	// arr.insert(2, 30);
	// std::cout << "Value at index 2 after insertion: " << arr[2] << std::endl;
	// arr.remove(20);
	// std::cout << "Array size after removal: " << arr.getSize() << std::endl;
	// arr.reverse();
	// std::cout << "Reversed array:";
	// arr.print();
	// int index = arr.find(30);
	// std::cout << "Index of value 30: " << index << std::endl;
	// size_t count = arr.count(10);
	// std::cout << "Count of value 10: " << count << std::endl;

	// Test LinkedList    #include "DataStructures/LinkedList.h"
	// LinkedList<int> list;
	// list.insertAtBeginning(1);
	// list.insertAtBeginning(2);
	// list.insertAtBeginning(3);
	// std::cout << "List after insertAtBeginning: ";
	// list.display(); // Expected output: 3 2 1
	// list.insertAtEnd(4);
	// list.insertAtEnd(5);
	// std::cout << "List after insertAtEnd: ";
	// list.display(); // Expected output: 3 2 1 4 5
	// list.insertAtPosition(10, 2);
	// std::cout << "List after insertAtPosition(10, 2): ";
	// list.display(); // Expected output: 3 2 10 1 4 5
	// list.remove(2);
	// std::cout << "List after remove(2): ";
	// list.display(); // Expected output: 3 10 1 4 5
	// list.removeAtPosition(3);
	// std::cout << "List after removeAtPosition(3): ";
	// list.display(); // Expected output: 3 10 4 5
	// std::cout << "Length of the list: " << list.length() << std::endl; // Expected output: 4
	// return 0;

	// ********** SEARCH **********

	// Test Binary Search    #include "Search/BinarySearch.h"
	// char arr[] = { 'a', 'd', 'f', 'i', 'j', 'k', 'o', 'r', 'w', 'y'};
	// int size = sizeof(arr) / sizeof(arr[0]); // Calculate size of array
	// char target = 'k';
	// BinarySearch<char> bs;
	// int result = bs.binarySearch(arr, size, target);
	// if (result != -1)
	// std::cout << "Element found at index: " << result << std::endl;
	// else
	// std::cout << "Element not found" << std::endl;
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
