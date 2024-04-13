#include "DataStructures/Array.h"
#include "DataStructures/LinkedList.h"
#include "Search/BinarySearch.h"
#include "Sort/MergeSort.h"
#include "Sort/QuickSort.h"
#include "Utils/ArrayUtils.h"
#include "Utils/StringUtils.h"
#include <iostream>
using std::cout;

static void testArray()
{
	std::cout << "\nTESTING ARRAY CLASS\n";
	Array<int> arr(5);
	arr.fill(10);
	assert(arr.getSize() == 5); // Check if getSize() returns expected value
	assert(arr[2] == 10); // Check if value at index 2 is set correctly
	arr[2] = 20;
	assert(arr[2] == 20); // Check if value at index 2 is updated correctly
	const int& value = arr[3];
	assert(value == 10); // Check if value at index 3 is retrieved correctly
	arr.clear();
	assert(arr.getSize() == 0); // Check if clear() empties the array
	assert(arr.isEmpty() == true); // Check if isEmpty() returns true after clear()
	arr.resize(8);
	assert(arr.getSize() == 8); // Check if resize() works correctly
	arr.fill(9);
	arr.insert(2, 35);
	assert(arr[2] == 35); // Check if insert() inserts value correctly
	arr.remove(35);
	assert(arr.getSize() == 8); // Check if remove() changes array size
	arr.resize(2);
	arr.insert(0, 16);
	arr.reverse();
	Array<int> reversed(0);
	reversed.insert(0, 9);
	reversed.insert(1, 9);
	reversed.insert(2, 16);
	assert(arr == reversed); // Check reversed array
	arr.insert(2, 22);
	int index = arr.find(22);
	assert(index == 2); // Check if find() returns correct index
	size_t count = arr.count(10);
	assert(count == 0); // Check if count() returns correct count
	std::cout << "All tests passed successfully!\n";
}

static void testLinkedList()
{
	cout << "\nTESTING LINKED LIST\n";
	LinkedList<int> list;
	list.insertAtBeginning(1);
	list.insertAtBeginning(2);
	list.insertAtBeginning(3);
	cout << "List after insertAtBeginning: ";
	list.display(); // Expected output: 3 2 1
	list.insertAtEnd(4);
	list.insertAtEnd(5);
	cout << "List after insertAtEnd: ";
	list.display(); // Expected output: 3 2 1 4 5
	list.insertAtPosition(10, 2);
	cout << "List after insertAtPosition(10, 2): ";
	list.display(); // Expected output: 3 2 10 1 4 5
	list.remove(2);
	cout << "List after remove(2): ";
	list.display(); // Expected output: 3 10 1 4 5
	list.removeAtPosition(3);
	cout << "List after removeAtPosition(3): ";
	list.display();     	 // Expected output: 3 10 4 5
	cout << "Length of the list: " << list.length() << "\n"; // Expected output: 4
}

static void testBinarySearch()
{
	cout << "\nTESTING BINARY SEARCH\n";
	char arr[] = { 'a', 'd', 'f', 'i', 'j', 'k', 'o', 'r', 'w', 'y' };
	int size = sizeof(arr) / sizeof(arr[0]); // Calculate size of array
	char target = 'k';
	BinarySearch<char> bs;
	int result = bs.binarySearch(arr, size, target);
	if (result != -1)
		cout << "Element found at index: " << result << "\n";
	else
		cout << "Element not found" << "\n";
}

static void testMergeSort()
{
	cout << "\nTESTING MERGE SORT\n";
	double arr[] = { 8.23, 3.14159, 0.5, 2.77, -88, 0.01, 42.113, -42.5, 290, -17.5, };
	const int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Given array is \n";
	ArrayUtils<double, size>::print(arr);
	MergeSort<double> ms;
	ms.mergeSort(arr, 0, size - 1);
	cout << "Sorted array is \n";
	ArrayUtils<double, size>::print(arr);
}

static void testQuickSort()
{
	cout << "\nTESTING QUICK SORT\n";
	char arr[] = { 'y', '6', 'z', '4', 'x', '0', '5' };
	const int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Original array: ";
	QuickSort<char> qs;
	ArrayUtils<char, size>::print(arr);
	qs.quickSort(arr, 0, size - 1);
	cout << "Sorted array: ";
	ArrayUtils<char, size>::print(arr);
}

static void testStringUtils()
{
	cout << "\nTESTING STRING UTILS\n";
	const char* str1 = "Hello";
	const char* str2 = "World";

	// Test StringUtils functions
	std::cout << "Length of str1: " << StringUtils::length(str1) << std::endl;
	std::cout << "Comparison of str1 and str2: " << StringUtils::compare(str1, str2) << std::endl;

	char* concatStr = StringUtils::concatenate(str1, str2);
	std::cout << "Concatenated string: " << concatStr << std::endl;
	delete[] concatStr;

	const char* subStr = StringUtils::substring(str1, 1, 3);
	std::cout << "Substring of str1: " << subStr << std::endl;

	char upperStr[] = "hello";
	StringUtils::toUpper(upperStr);
	std::cout << "Uppercase of 'hello': " << upperStr << std::endl;

	char lowerStr[] = "HELLO";
	StringUtils::toLower(lowerStr);
	std::cout << "Lowercase of 'HELLO': " << lowerStr << std::endl;

	const char* foundChar = StringUtils::findChar(str1, 'e');
	if (foundChar)
		std::cout << "Found character 'e' at index: " << (foundChar - str1) << std::endl;

	const char* foundLastChar = StringUtils::findLastChar(str1, 'l');
	if (foundLastChar)
		std::cout << "Found last character 'l' at index: " << (foundLastChar - str1) << std::endl;

	char* copiedStr = StringUtils::copy(str1, 3);
	std::cout << "Copied string: " << copiedStr << std::endl;
	delete[] copiedStr;

	char reverseStr[] = "reverse";
	StringUtils::reverse(reverseStr);
	std::cout << "Reversed string: " << reverseStr << std::endl;
}

int main()
{
	// ********** DATA STRUCTURES **********
	testArray();
	testLinkedList();

	// ********** SEARCH **********
	testBinarySearch();

	// ********** SORT **********
	testMergeSort();
	testQuickSort();

	// ********** UTILS **********
	testStringUtils();
}
