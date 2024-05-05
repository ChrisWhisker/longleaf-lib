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
        std::cout << "\nTESTING ARRAY CLASS\n";
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
        std::cout << "All Array tests passed!\n";
    }

    void Tester::test_linked_list()
    {
        std::cout << "\nTESTING LINKED LIST\n";
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
        std::cout << "[" << list.to_string() << "]\n";
        assert(strcmp(list.to_string(), "3 10 1 5 ") == 0); // Compare C-style strings

        assert(list.length() == 4);

        std::cout << "All Linked List tests passed!\n";
    }

    void Tester::test_stack()
    {
        std::cout << "\nTESTING STACK\n";
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
        std::cout << "All Stack tests passed!\n";
    }

    void Tester::test_binary_search()
    {
        std::cout << "\nTESTING BINARY SEARCH\n";
        char arr[] = {'a', 'd', 'f', 'i', 'j', 'k', 'o', 'r', 'w', 'y'};
        constexpr int size = sizeof(arr) / sizeof(arr[0]); // Determine size of array
        constexpr char target = 'k';
        const int result = search::BinarySearch<char>::binary_search(arr, size, target);
        if (result == -1)
        {
            std::cout << "Element not found"
                << "\n";
        }
        else
        {
            std::cout << "Element found at index: " << result << "\n";
        }
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
        std::cout << "Given array is \n";
        utils::ArrayUtils<double, size>::print(arr);
        sort::MergeSort<double> ms;
        ms.merge_sort(arr, 0, size - 1);
        std::cout << "Sorted array is \n";
        utils::ArrayUtils<double, size>::print(arr);
    }

    void Tester::test_quick_sort()
    {
        std::cout << "\nTESTING QUICK SORT\n";
        char arr[] = {'y', '6', 'z', '4', 'x', '0', '5'};
        constexpr int size = sizeof(arr) / sizeof(arr[0]);
        std::cout << "Original array: ";
        sort::QuickSort<char> qs;
        utils::ArrayUtils<char, size>::print(arr);
        qs.quick_sort(arr, 0, size - 1);
        std::cout << "Sorted array: ";
        utils::ArrayUtils<char, size>::print(arr);
    }

    void Tester::test_array_utils()
    {
        std::cout << "\nTESTING ARRAY UTILS\n";
        // Test array
        int arr[] = {10, 20, 30, 40, 50};
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
        assert((utils::ArrayUtils<int, 5>::contains_value(arr, 20)));
        assert(!(utils::ArrayUtils<int, 5>::contains_value(arr, 60)));
        // Test reverse
        utils::ArrayUtils<int, 5>::reverse(arr);
        assert(arr[0] == 50 && arr[4] == 10);
        std::cout << "All Array Utils tests passed!\n";
    }

    void Tester::test_string_utils()
    {
        std::cout << "\nTESTING STRING UTILS\n";
        const char* p_str1 = "Hello";
        const char* p_str2 = "World";

        // Test utils::StringUtils functions
        std::cout << "Length of str1: " << utils::StringUtils::length(p_str1) << '\n';
        std::cout << "Comparison of str1 and str2: " << utils::StringUtils::compare(p_str1, p_str2) << '\n';

        const char* p_concat_str = utils::StringUtils::concatenate(p_str1, p_str2);
        std::cout << "Concatenated string: " << p_concat_str << '\n';
        delete[] p_concat_str;

        const char* p_sub_str = utils::StringUtils::substring(p_str1, 1, 3);
        std::cout << "Substring of str1: " << p_sub_str << '\n';

        char upper_str[] = "hello";
        utils::StringUtils::to_upper(upper_str);
        std::cout << "Uppercase of 'hello': " << upper_str << '\n';

        char lower_str[] = "HELLO";
        utils::StringUtils::to_lower(lower_str);
        std::cout << "Lowercase of 'HELLO': " << lower_str << '\n';

        const char* p_found_char = utils::StringUtils::find_char(p_str1, 'e');
        if (p_found_char)
            std::cout << "Found character 'e' at index: " << (p_found_char - p_str1) << '\n';

        const char* p_found_last_char = utils::StringUtils::find_last_char(p_str1, 'l');
        if (p_found_last_char)
            std::cout << "Found last character 'l' at index: " << (p_found_last_char - p_str1) << '\n';

        const char* p_copied_str = utils::StringUtils::copy(p_str1, 3);
        std::cout << "Copied string: " << p_copied_str << '\n';
        delete[] p_copied_str;

        char reverse_str[] = "reverse";
        utils::StringUtils::reverse(reverse_str);
        std::cout << "Reversed string: " << reverse_str << '\n';
    }
    
    void Tester::test_strategy_pattern()
    {
        std::cout << "\nTESTING STRATEGY PATTERN\n";
        // Define the input text to be processed
        const std::string input_text = "Hello, World!";
        // Initialize a formatter for uppercase
        design_patterns::UppercaseFormatter uppercase_formatter;
        // Initialize a text processor with the uppercase formatter
        design_patterns::TextProcessor text_processor(&uppercase_formatter);
        // Process the input text using the uppercase formatter
        std::string formatted_text = text_processor.process(input_text);
        // Assertion to ensure correct uppercase formatting
        assert(formatted_text == "HELLO, WORLD!");
        // Change the formatter to lowercase
        design_patterns::LowercaseFormatter lowercase_formatter;
        text_processor.setFormatter(&lowercase_formatter);
        // Process the input text using the lowercase formatter
        formatted_text = text_processor.process(input_text);
        // Assertion to ensure correct lowercase formatting
        assert(formatted_text == "hello, world!");
        std::cout << "All strategy pattern tests passed!\n";
    }
}
