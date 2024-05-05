#include "Tester.h"
#include "../data_structures/Array.h"
#include "../data_structures/LinkedList.h"
#include "../data_structures/Stack.h"
#include "../search/BinarySearch.h"
#include "../sort/MergeSort.h"
#include "../sort/QuickSort.h"
#include "../utils/ArrayUtils.h"
#include "../utils/StringUtils.h"

namespace core
{
	void Tester::testArray()
	{
		std::cout << "\nTESTING ARRAY CLASS\n";
		data_structures::Array<int> arr(5);
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
		data_structures::Array<int> reversed(0);
		reversed.insert(0, 9);
		reversed.insert(1, 9);
		reversed.insert(2, 16);
		assert(arr == reversed); // Check reversed array
		arr.insert(2, 22);
		const int index = arr.find(22);
		assert(index == 2); // Check if find() returns correct index
		const size_t count = arr.count(10);
		assert(count == 0); // Check if count() returns correct count
		std::cout << "All Array tests passed!\n";
	}

	void Tester::testLinkedList()
	{
		std::cout << "\nTESTING LINKED LIST\n";
		data_structures::LinkedList<int> list;
		list.insertAtBeginning(1);
		list.insertAtBeginning(2);
		list.insertAtBeginning(3);
		assert(strcmp(list.toString(), "3 2 1 ") == 0); // Compare C-style strings using strcmp

		list.insertAtEnd(4);
		list.insertAtEnd(5);
		assert(strcmp(list.toString(), "3 2 1 4 5 ") == 0); // Compare C-style strings using strcmp

		list.insertAtPosition(10, 2);
		assert(strcmp(list.toString(), "3 2 10 1 4 5 ") == 0); // Compare C-style strings using strcmp

		list.remove(2);
		assert(strcmp(list.toString(), "3 10 1 4 5 ") == 0); // Compare C-style strings using strcmp

		list.removeAtPosition(3);
		std::cout << "[" << list.toString() << "]\n";
		assert(strcmp(list.toString(), "3 10 1 5 ") == 0); // Compare C-style strings using strcmp

		assert(list.length() == 4);

		std::cout << "All Linked List passed!\n";
	}

	void Tester::testStack()
	{
		std::cout << "\nTESTING STACK\n";
		// Test default constructor and isEmpty
		data_structures::Stack<int> stack;
		assert(stack.isEmpty());
		// Test push and top
		stack.push(10);
		assert(!stack.isEmpty());
		assert(stack.top() == 10);
		// Test size
		assert(stack.size() == 1);
		// Test push and top with more elements
		stack.push(20);
		stack.push(30);
		assert(stack.top() == 30);
		assert(stack.size() == 3);
		// Test pop
		stack.pop();
		assert(stack.top() == 20);
		assert(stack.size() == 2);
		// Test clear and isEmpty
		stack.clear();
		assert(stack.isEmpty());
		assert(stack.size() == 0);
		// Test swap
		data_structures::Stack<int> otherStack;
		otherStack.push(100);
		otherStack.push(200);
		swap(stack, otherStack);
		assert(stack.size() == 2);
		assert(otherStack.size() == 0);
		assert(stack.top() == 200);
		// Test operator==
		assert(stack == stack); // Same stack should be equal
		assert(stack != otherStack); // Different stacks should not be equal
		// Test operator!=
		assert(stack != otherStack); // Different stacks should not be equal
		assert(!(stack != stack)); // Same stack should be equal
		std::cout << "All Stack tests passed!\n";
	}

	void Tester::testBinarySearch()
	{
		std::cout << "\nTESTING BINARY SEARCH\n";
		char arr[] = { 'a', 'd', 'f', 'i', 'j', 'k', 'o', 'r', 'w', 'y' };
		constexpr int size = sizeof(arr) / sizeof(arr[0]); // Calculate size of array
		constexpr char target = 'k';
		const int result = search::BinarySearch<char>::binarySearch(arr, size, target);
		if (result != -1)
			std::cout << "Element found at index: " << result << "\n";
		else
			std::cout << "Element not found" << "\n";
	}

	void Tester::testMergeSort()
	{
		std::cout << "\nTESTING MERGE SORT\n";
		double arr[] = { 8.23, 3.14159, 0.5, 2.77, -88, 0.01, 42.113, -42.5, 290, -17.5, };
		constexpr int size = sizeof(arr) / sizeof(arr[0]);
		std::cout << "Given array is \n";
		utils::ArrayUtils<double, size>::print(arr);
		sort::MergeSort<double> ms;
		ms.mergeSort(arr, 0, size - 1);
		std::cout << "Sorted array is \n";
		utils::ArrayUtils<double, size>::print(arr);
	}

	void Tester::testQuickSort()
	{
		std::cout << "\nTESTING QUICK SORT\n";
		char arr[] = { 'y', '6', 'z', '4', 'x', '0', '5' };
		constexpr int size = sizeof(arr) / sizeof(arr[0]);
		std::cout << "Original array: ";
		sort::QuickSort<char> qs;
		utils::ArrayUtils<char, size>::print(arr);
		qs.quickSort(arr, 0, size - 1);
		std::cout << "Sorted array: ";
		utils::ArrayUtils<char, size>::print(arr);
	}

	void Tester::testArrayUtils()
	{
		std::cout << "\nTESTING ARRAY UTILS\n";
		// Test array
		int arr[] = { 10, 20, 30, 40, 50 };
		// Test print
		utils::ArrayUtils<int, 5>::print(arr);
		// Test max
		assert((utils::ArrayUtils<int, 5>::max(arr)) == 50);
		// Test min
		assert((utils::ArrayUtils<int, 5>::min(arr)) == 10);
		// Test sum
		assert((utils::ArrayUtils<int, 5>::sum(arr)) == 150);
		// Test average
		assert((utils::ArrayUtils<int, 5>::average(arr)) == 30.0);
		// Test containsValue
		assert((utils::ArrayUtils<int, 5>::containsValue(arr, 20)));
		assert(!(utils::ArrayUtils<int, 5>::containsValue(arr, 60)));
		// Test reverse
		utils::ArrayUtils<int, 5>::reverse(arr);
		assert(arr[0] == 50 && arr[4] == 10);
		std::cout << "All Array Utils tests passed!\n";
	}

	void Tester::testStringUtils()
	{
		std::cout << "\nTESTING STRING UTILS\n";
		const char* str1 = "Hello";
		const char* str2 = "World";

		// Test utils::StringUtils functions
		std::cout << "Length of str1: " << utils::StringUtils::length(str1) << '\n';
		std::cout << "Comparison of str1 and str2: " << utils::StringUtils::compare(str1, str2) << '\n';

		const char* concatStr = utils::StringUtils::concatenate(str1, str2);
		std::cout << "Concatenated string: " << concatStr << '\n';
		delete[] concatStr;

		const char* subStr = utils::StringUtils::substring(str1, 1, 3);
		std::cout << "Substring of str1: " << subStr << '\n';

		char upperStr[] = "hello";
		utils::StringUtils::toUpper(upperStr);
		std::cout << "Uppercase of 'hello': " << upperStr << '\n';

		char lowerStr[] = "HELLO";
		utils::StringUtils::toLower(lowerStr);
		std::cout << "Lowercase of 'HELLO': " << lowerStr << '\n';

		const char* foundChar = utils::StringUtils::findChar(str1, 'e');
		if (foundChar)
			std::cout << "Found character 'e' at index: " << (foundChar - str1) << '\n';

		const char* foundLastChar = utils::StringUtils::findLastChar(str1, 'l');
		if (foundLastChar)
			std::cout << "Found last character 'l' at index: " << (foundLastChar - str1) << '\n';

		const char* copiedStr = utils::StringUtils::copy(str1, 3);
		std::cout << "Copied string: " << copiedStr << '\n';
		delete[] copiedStr;

		char reverseStr[] = "reverse";
		utils::StringUtils::reverse(reverseStr);
		std::cout << "Reversed string: " << reverseStr << '\n';
	}
}
