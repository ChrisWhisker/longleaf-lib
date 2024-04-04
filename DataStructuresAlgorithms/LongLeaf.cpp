#include "ArrayUtils.h"
#include "DataStructures/Array.h"
#include "DataStructures/LinkedList.h"
#include "Search/BinarySearch.h"
#include "Sort/MergeSort.h"
#include "Sort/QuickSort.h"
#include <iostream>
using std::cout;
using std::endl;

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
}

static void testArray()
{
	Array<int> arr(5);
	arr.fill(10);
	cout << "Array size: " << arr.getSize() << endl;
	arr[2] = 20;
	cout << "Value at index 2: " << arr[2] << endl;
	const int& value = arr[3];
	cout << "Value at index 3 (read-only): " << value << endl;
	arr.clear();
	cout << "Array size after clear: " << arr.getSize() << endl;
	cout << "Is array empty? " << (arr.isEmpty() ? "Yes" : "No") << endl;
	arr.resize(8);
	cout << "Array size after resize: " << arr.getSize() << endl;
	arr.insert(2, 30);
	cout << "Value at index 2 after insertion: " << arr[2] << endl;
	arr.remove(20);
	cout << "Array size after removal: " << arr.getSize() << endl;
	arr.reverse();
	cout << "Reversed array:";
	arr.print();
	int index = arr.find(30);
	cout << "Index of value 30: " << index << endl;
	size_t count = arr.count(10);
	cout << "Count of value 10: " << count << endl;
}

static void testLinkedList()
{
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
	cout << "Length of the list: " << list.length() << endl; // Expected output: 4
}

static void testBinarySearch()
{
	char arr[] = { 'a', 'd', 'f', 'i', 'j', 'k', 'o', 'r', 'w', 'y' };
	int size = sizeof(arr) / sizeof(arr[0]); // Calculate size of array
	char target = 'k';
	BinarySearch<char> bs;
	int result = bs.binarySearch(arr, size, target);
	if (result != -1)
		cout << "Element found at index: " << result << endl;
	else
		cout << "Element not found" << endl;
}

static void testMergeSort()
{
	float arr[] = { 8.23, 3.14159, 0.5, 2.77, -88, 0.01, 42.113, -42.5, 290, -17.5, };
	const int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Given array is \n";
	ArrayUtils<float, size>::print(arr);
	MergeSort<float> ms;
	ms.mergeSort(arr, 0, size - 1);
	cout << "Sorted array is \n";
	ArrayUtils<float, size>::print(arr);
}

static void testQuickSort()
{
	char arr[] = { 'y', '6', 'z', '4', 'x', '0', '5' };
	const int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Original array: ";
	QuickSort<char> qs;
	ArrayUtils<char, size>::print(arr);
	qs.quickSort(arr, 0, size - 1);
	cout << "Sorted array: ";
	ArrayUtils<char, size>::print(arr);
}