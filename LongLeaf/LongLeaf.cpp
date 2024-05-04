#include "Core/Tester.h"
#include <iostream>

int main()
{
	// ********** DATA STRUCTURES **********
	Tester::testArray();
	Tester::testLinkedList();
	Tester::testStack();

	// ********** SEARCH **********
	Tester::testBinarySearch();

	// ********** SORT **********
	Tester::testMergeSort();
	Tester::testQuickSort();

	// ********** UTILS **********
	Tester::testArrayUtils();
	Tester::testStringUtils();
}
