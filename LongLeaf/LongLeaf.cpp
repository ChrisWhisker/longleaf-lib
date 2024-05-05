#include "Core/Tester.h"

int main()
{
	// ********** DATA STRUCTURES **********
	core::Tester::test_array();
	core::Tester::test_linked_list();
	core::Tester::test_stack();

	// ********** SEARCH **********
	core::Tester::test_binary_search();

	// ********** SORT **********
	core::Tester::test_merge_sort();
	core::Tester::test_quick_sort();

	// ********** UTILS **********
	core::Tester::test_array_utils();
	core::Tester::test_string_utils();

	// ********** DESIGN PATTERNS **********
	core::Tester::test_strategy_pattern();
}
