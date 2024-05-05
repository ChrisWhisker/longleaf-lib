#include "Tester.h"
#include "../data_structures/Array.h"
#include "../data_structures/LinkedList.h"
#include "../data_structures/Stack.h"
#include "../design_patterns/Strategy.h"
#include "../search/BinarySearch.h"
#include "../sort/MergeSort.h"
#include "../sort/QuickSort.h"
#include "../utils/ArrayUtils.h"
#include "../utils/StringUtils.h"

namespace core
{
    void Tester::test_array()
    {
        std::cout << "\nTesting Array class...\n";
        data_structures::Array<int> arr(5);
        arr.fill(10);
        assert(arr.get_size() == 5); // Check if get_size() returns expected value
        assert(arr[2] == 10); // Check if value at index 2 is set correctly
        arr[2] = 20;
        assert(arr[2] == 20); // Check if value at index 2 is updated correctly
        const int& value = arr[3];
        assert(value == 10); // Check if value at index 3 is retrieved correctly
        arr.clear();
        assert(arr.get_size() == 0); // Check if clear() empties the array
        assert(arr.is_empty() == true); // Check if isEmpty() returns true after clear()
        arr.resize(8);
        assert(arr.get_size() == 8); // Check if resize() works correctly
        arr.fill(9);
        arr.insert(2, 35);
        assert(arr[2] == 35); // Check if insert() inserts value correctly
        arr.remove(35);
        assert(arr.get_size() == 8); // Check if remove() changes array size
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
        std::cout << "All array tests passed!\n";
    }

    void Tester::test_linked_list()
    {
        std::cout << "\nTesting Linked List...\n";
        data_structures::LinkedList<int> list;
        list.insert_at_beginning(1);
        list.insert_at_beginning(2);
        list.insert_at_beginning(3);
        assert(strcmp(list.to_string(), "3 2 1 ") == 0); // Compare C-style strings

        list.insert_at_end(4);
        list.insert_at_end(5);
        assert(strcmp(list.to_string(), "3 2 1 4 5 ") == 0); // Compare C-style strings

        list.insert_at_position(10, 2);
        assert(strcmp(list.to_string(), "3 2 10 1 4 5 ") == 0); // Compare C-style strings

        list.remove(2);
        assert(strcmp(list.to_string(), "3 10 1 4 5 ") == 0); // Compare C-style strings

        list.remove_at_position(3);
        assert(strcmp(list.to_string(), "3 10 1 5 ") == 0); // Compare C-style strings

        assert(list.length() == 4);

        std::cout << "All linked list tests passed!\n";
    }

    void Tester::test_stack()
    {
        std::cout << "\nTesting Stack...\n";
        // Test default constructor and isEmpty
        data_structures::Stack<int> stack;
        assert(stack.is_empty());
        // Test push and top
        stack.push(10);
        assert(!stack.is_empty());
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
        assert(stack.is_empty());
        assert(stack.size() == 0);
        // Test swap
        data_structures::Stack<int> other_stack;
        other_stack.push(100);
        other_stack.push(200);
        swap(stack, other_stack);
        assert(stack.size() == 2);
        assert(other_stack.size() == 0);
        assert(stack.top() == 200);
        // Test operator==
        assert(stack == stack); // Same stack should be equal
        assert(stack != other_stack); // Different stacks should not be equal
        // Test operator!=
        assert(stack != other_stack); // Different stacks should not be equal
        assert(stack == stack); // Same stack should be equal
        std::cout << "All stack tests passed!\n";
    }

    void Tester::test_binary_search()
    {
        std::cout << "\nTesting Binary Search...\n";
        char arr[] = {'a', 'd', 'f', 'i', 'j', 'k', 'o', 'r', 'w', 'y'};
        constexpr int size = sizeof(arr) / sizeof(arr[0]); // Determine size of array
        constexpr char target = 'k';
        const int result = search::BinarySearch<char>::binary_search(arr, size, target);
        assert(result != -1);
        std::cout << "All binary search tests passed!\n";
    }

    void Tester::test_merge_sort()
    {
        std::cout << "\nTESTING MERGE SORT\n";
        double arr[] = {
            8.23,
            3.14159,
            0.5,
            2.77,
            -88,
            0.01,
            42.113,
            -42.5,
            290,
            -17.5,
        };
        constexpr int size = sizeof(arr) / sizeof(arr[0]);

        sort::MergeSort<double> ms;
        ms.merge_sort(arr, 0, size - 1);

        // Assert to check if the array is sorted
        for (int i = 0; i < size - 1; ++i)
        {
            assert("Array is sorted" && (arr[i] <= arr[i + 1]));
        }
        std::cout << "All merge sort tests passed!\n";
    }


    void Tester::test_quick_sort()
    {
        std::cout << "\nTesting Quick Sort...\n";
        char arr[] = {'y', '6', 'z', '4', 'x', '0', '5'};
        constexpr int size = sizeof(arr) / sizeof(arr[0]);

        sort::QuickSort<char> qs;
        qs.quick_sort(arr, 0, size - 1);

        // Assert to check if the array is sorted
        for (int i = 0; i < size - 1; ++i)
        {
            assert("Array is sorted" && (arr[i] <= arr[i + 1]));
        }
        std::cout << "All quick sort tests passed!\n";
    }

    void Tester::test_array_utils()
    {
        std::cout << "\nTesting Array Utils...\n";
        // Test array
        int arr[] = {10, 20, 30, 40, 50};
        // Test max
        assert((utils::ArrayUtils<int, 5>::max(arr)) == 50);
        // Test min
        assert((utils::ArrayUtils<int, 5>::min(arr)) == 10);
        // Test sum
        assert((utils::ArrayUtils<int, 5>::sum(arr)) == 150);
        // Test average
        assert((utils::ArrayUtils<int, 5>::average(arr)) == 30.0);
        // Test containsValue
        assert((utils::ArrayUtils<int, 5>::contains_value(arr, 20)));
        assert(!(utils::ArrayUtils<int, 5>::contains_value(arr, 60)));
        // Test reverse
        utils::ArrayUtils<int, 5>::reverse(arr);
        assert(arr[0] == 50 && arr[4] == 10);
        std::cout << "All Array Utils tests passed!\n";
    }

    void Tester::test_string_utils()
    {
        std::cout << "\nTesting String Utils...\n";
        // Test StringUtils::length()
        assert(utils::StringUtils::length("hello") == 5);
        assert(utils::StringUtils::length("") == 0);
        assert(utils::StringUtils::length(nullptr) == 0);

        // Test StringUtils::compare()
        assert(utils::StringUtils::compare("hello", "world") < 0);
        assert(utils::StringUtils::compare("world", "hello") > 0);
        assert(utils::StringUtils::compare("hello", "hello") == 0);

        // Test StringUtils::concatenate()
        char* concat = utils::StringUtils::concatenate("hello", " world");
        assert(concat != nullptr);
        assert(utils::StringUtils::compare(concat, "hello world") == 0);
        delete[] concat;

        // Test StringUtils::substring()
        const char* substr = utils::StringUtils::substring("hello world", 6, 5);
        assert(utils::StringUtils::compare(substr, "world") == 0);

        // Test StringUtils::to_upper() and StringUtils::to_lower()
        char str[] = "Hello World";
        utils::StringUtils::to_upper(str);
        assert(utils::StringUtils::compare(str, "HELLO WORLD") == 0);
        utils::StringUtils::to_lower(str);
        assert(utils::StringUtils::compare(str, "hello world") == 0);

        // Test StringUtils::find_char() and StringUtils::find_last_char()
        const char* str1 = "hello world";
        assert(utils::StringUtils::find_char(str1, 'o') != nullptr);
        assert(utils::StringUtils::find_char(str1, 'z') == nullptr);
        assert(utils::StringUtils::find_last_char(str1, 'o') != nullptr);
        assert(utils::StringUtils::find_last_char(str1, 'z') == nullptr);

        // Test StringUtils::copy()
        char* copied = utils::StringUtils::copy("hello world", 5);
        assert(utils::StringUtils::compare(copied, "hello") == 0);
        delete[] copied;

        // Test StringUtils::reverse()
        char reverseStr[] = "hello";
        utils::StringUtils::reverse(reverseStr);
        assert(utils::StringUtils::compare(reverseStr, "olleh") == 0);
        std::cout << "All String Utils tests passed!\n";
    }

    void Tester::test_strategy_pattern()
    {
        std::cout << "\nTesting Strategy Pattern...\n";
        // Create instances of formatters
        const design_patterns::UppercaseFormatter upper_formatter;
        const design_patterns::LowercaseFormatter lower_formatter;

        // Test uppercase_formatter
        assert(upper_formatter.format("hello, world!") == "HELLO, WORLD!");
        assert(upper_formatter.format("HeLLo") == "HELLO");
        assert(upper_formatter.format("").empty());

        // Test lowercase_formatter
        assert(lower_formatter.format("HELLO, WORLD!") == "hello, world!");
        assert(lower_formatter.format("HeLLo") == "hello");
        assert(lower_formatter.format("").empty());
        std::cout << "All strategy pattern tests passed!\n";
    }
}
