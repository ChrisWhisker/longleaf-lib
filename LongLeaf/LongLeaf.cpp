#include "Core/Tester.h"
#include <iostream>

int main()
{
	// ********** DATA STRUCTURES **********
	core::Tester::testArray();
	core::Tester::testLinkedList();
	core::Tester::testStack();

	// ********** SEARCH **********
	core::Tester::testBinarySearch();

	// ********** SORT **********
	core::Tester::testMergeSort();
	core::Tester::testQuickSort();

	// ********** UTILS **********
	core::Tester::testArrayUtils();
	core::Tester::testStringUtils();
}
