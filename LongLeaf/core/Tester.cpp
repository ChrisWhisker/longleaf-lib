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
        using namespace data_structures; // Import the namespace

        // Create an Array object
        Array<int> arr(5);

        // Test get_size() function
        assert(arr.get_size() == 5);

        // Test operator[] (read and write)
        arr[0] = 10;
        assert(arr[0] == 10);

        // Test fill() function
        arr.fill(20);
        for (size_t i = 0; i < arr.get_size(); ++i)
        {
            assert(arr[i] == 20);
        }

        // Test resize() function
        arr.resize(10);
        assert(arr.get_size() == 10);

        // Test clear() function
        arr.clear();
        assert(arr.get_size() == 0 && arr.is_empty());

        // Test insert() function
        arr.insert(0, 100);
        arr.insert(1, 200);
        assert(arr[0] == 100 && arr[1] == 200);

        // Test remove() function
        arr.remove(100);
        assert(arr[0] == 200 && arr.get_size() == 1);

        // Test remove_at_position() function
        arr.remove_at_position(0);
        assert(arr.get_size() == 0 && arr.is_empty());

        // Test reverse() function
        Array<int> reversedArr(5);
        for (size_t i = 0; i < reversedArr.get_size(); ++i)
        {
            reversedArr[i] = static_cast<int>(i + 1);
        }
        reversedArr.reverse();
        for (size_t i = 0; i < reversedArr.get_size(); ++i)
        {
            assert(reversedArr[i] == static_cast<int>(5 - i));
        }

        // Test find() function
        Array<int> find_arr(5);
        for (size_t i = 0; i < find_arr.get_size(); ++i)
        {
            find_arr[i] = static_cast<int>(i * 2);
        }
        assert(find_arr.find(4) == 2);

        // Test count() function
        assert(find_arr.count(4) == 1);

        // Test swap() function
        Array<int> arr1(3);
        Array<int> arr2(5);
        arr1[0] = 1;
        arr1[1] = 2;
        arr1[2] = 3;
        arr2[0] = 4;
        arr2[1] = 5;
        arr2[2] = 6;
        arr2[3] = 7;
        arr2[4] = 8;
        swap(arr1, arr2);
        assert(arr1.get_size() == 5 && arr1[0] == 4 && arr2.get_size() == 3 && arr2[0] == 1);

        // Test equality operators
        Array<int> arr3(3);
        arr3[0] = 1;
        arr3[1] = 2;
        arr3[2] = 3;
        Array<int> arr4(3);
        arr4[0] = 1;
        arr4[1] = 2;
        arr4[2] = 3;
        assert(arr3 == arr4);
        assert(arr3 == arr4);

        std::cout << "All Array tests passed!\n";
    }

    void Tester::test_linked_list()
    {
        std::cout << "\nTesting Linked List...\n";
        using namespace data_structures;

        // Test cases for integer type
        LinkedList<int> int_list;

        // Test is_empty() function
        assert(int_list.is_empty());

        // Test insert_at_beginning() function
        int_list.insert_at_beginning(10);
        assert(!int_list.is_empty());
        assert(int_list.length() == 1);
        assert(strcmp(int_list.to_string(), "10 ") == 0);

        // Test insert_at_end() function
        int_list.insert_at_end(20);
        assert(int_list.length() == 2);
        assert(strcmp(int_list.to_string(), "10 20 ") == 0);

        // Test insert_at_position() function
        int_list.insert_at_position(15, 1);
        assert(int_list.length() == 3);
        assert(strcmp(int_list.to_string(), "10 15 20 ") == 0);

        // Test remove() function
        int_list.remove(15);
        assert(int_list.length() == 2);
        assert(strcmp(int_list.to_string(), "10 20 ") == 0);

        // Test remove_at_position() function
        int_list.remove_at_position(1);
        assert(int_list.length() == 1);
        assert(strcmp(int_list.to_string(), "10 ") == 0);

        // Test clear the list
        int_list.remove(10);
        assert(int_list.is_empty());

        // Test cases for string type
        LinkedList<std::string> str_list;

        // Test is_empty() function
        assert(str_list.is_empty());

        // Test insert_at_beginning() function
        str_list.insert_at_beginning("hello");
        assert(!str_list.is_empty());
        assert(str_list.length() == 1);
        assert(strcmp(str_list.to_string(), "hello ") == 0);

        // Test insert_at_end() function
        str_list.insert_at_end("world");
        assert(str_list.length() == 2);
        assert(strcmp(str_list.to_string(), "hello world ") == 0);

        // Test insert_at_position() function
        str_list.insert_at_position("beautiful", 1);
        assert(str_list.length() == 3);
        assert(strcmp(str_list.to_string(), "hello beautiful world ") == 0);

        // Test remove() function
        str_list.remove("beautiful");
        assert(str_list.length() == 2);
        assert(strcmp(str_list.to_string(), "hello world ") == 0);

        // Test remove_at_position() function
        str_list.remove_at_position(1);
        assert(str_list.length() == 1);
        assert(strcmp(str_list.to_string(), "hello ") == 0);

        // Test clear the list
        str_list.remove("hello");
        assert(str_list.is_empty());

        std::cout << "All Linked List tests passed!\n";
    }

    void Tester::test_stack()
    {
        std::cout << "\nTesting Stack...\n";
        using namespace data_structures; // Import the namespace

        // Create an empty stack
        Stack<int> stack;

        // Test is_empty() on an empty stack
        assert(stack.is_empty());

        // Test push() and top() on an empty stack
        stack.push(10);
        assert(!stack.is_empty());
        assert(stack.top() == 10);

        // Test size() after pushing one element
        assert(stack.size() == 1);

        // Test push() and top() on a non-empty stack
        stack.push(20);
        assert(stack.top() == 20);

        // Test size() after pushing another element
        assert(stack.size() == 2);

        // Test pop() on a non-empty stack
        stack.pop();
        assert(stack.top() == 10);

        // Test size() after popping one element
        assert(stack.size() == 1);

        // Test clear() on a non-empty stack
        stack.clear();
        assert(stack.is_empty());
        assert(stack.size() == 0);

        // Test swap() with another stack
        Stack<int> stack2;
        stack2.push(30);
        swap(stack, stack2);
        assert(stack.top() == 30);
        assert(stack2.is_empty());

        // Test operator==
        stack2.push(30);
        assert(stack == stack2);

        // Test operator!=
        stack2.push(40);
        assert(stack != stack2);

        // Test get_data()
        stack.push(50);
        const int* p_data = stack.get_data();
        assert(*p_data == 30);

        // Clean up
        stack.clear();
        stack2.clear();

        std::cout << "All Stack tests passed!\n";
    }

    // Test Binary Search
    void Tester::test_binary_search()
    {
        std::cout << "\nTesting Binary Search...\n";
        using namespace search;

        // Test case 1: Single element array
        int single_arr[] = {5};
        assert(BinarySearch<int>::binary_search(single_arr, 1, 5) == 0);
        assert(BinarySearch<int>::binary_search(single_arr, 1, 10) == -1);

        // Test case 2: Multiple elements with duplicate targets
        double arr[] = {1, 2, 2, 3, 4, 5, 5, 5, 6, 7};
        assert(BinarySearch<double>::binary_search(arr, 10, 5) == 5); // First occurrence
        assert(BinarySearch<double>::binary_search(arr, 10, 2) == 1); // First occurrence
        assert(BinarySearch<double>::binary_search(arr, 10, 8) == -1); // Not found

        // Test case 3: Target at extremes
        assert(BinarySearch<double>::binary_search(arr, 10, 1) == 0); // First element
        assert(BinarySearch<double>::binary_search(arr, 10, 7) == 9); // Last element

        // Test case 4: Target not found
        assert(BinarySearch<double>::binary_search(arr, 10, 0) == -1); // Target smaller than any element
        assert(BinarySearch<double>::binary_search(arr, 10, 8) == -1); // Target larger than any element
        assert(BinarySearch<double>::binary_search(arr, 10, 100) == -1); // Target not in array

        // Test case 5: Negative numbers
        int neg_arr[] = {-5, -4, -3, -2, -1, 0};
        assert(BinarySearch<int>::binary_search(neg_arr, 6, -3) == 2);
        assert(BinarySearch<int>::binary_search(neg_arr, 6, -5) == 0);
        assert(BinarySearch<int>::binary_search(neg_arr, 6, -1) == 4);

        std::cout << "All Binary Search tests passed!\n";
    }

    void Tester::test_merge_sort()
    {
        std::cout << "\nTesting Merge Sort...\n";
        using namespace sort;

        // Test with integer array
        {
            MergeSort<int> sorter;

            int arr[] = {12, 11, 13, 5, 6, 7};
            constexpr int arr_size = std::size(arr);

            sorter.merge_sort(arr, 0, arr_size - 1);

            for (int i = 0; i < arr_size - 1; ++i)
            {
                assert(arr[i] <= arr[i + 1]);
            }
        }

        // Test with floating-point array
        {
            MergeSort<float> sorter;

            float arr[] = {12.5f, 11.2f, 13.7f, 5.3f, 6.8f, 7.1f};
            constexpr int arr_size = std::size(arr);

            sorter.merge_sort(arr, 0, arr_size - 1);

            for (int i = 0; i < arr_size - 1; ++i)
            {
                assert(arr[i] <= arr[i + 1]);
            }
        }

        // Test with character array
        {
            MergeSort<char> sorter;

            char arr[] = {'c', 'a', 'b', 'e', 'd'};
            constexpr int arr_size = std::size(arr);

            sorter.merge_sort(arr, 0, arr_size - 1);

            for (int i = 0; i < arr_size - 1; ++i)
            {
                assert(arr[i] <= arr[i + 1]);
            }
        }

        std::cout << "All Merge Sort tests passed!\n";
    }


    void Tester::test_quick_sort()
    {
        std::cout << "\nTesting Quick Sort...\n";
        using namespace sort;

        // Test with integer data type
        {
            QuickSort<int> sorter;
            int arr[] = {12, 5, 7, -3, 8, 10, 2};
            constexpr int size = std::size(arr);

            sorter.quick_sort(arr, 0, size - 1);

            // Assert sorted array
            for (int i = 0; i < size - 1; ++i)
            {
                assert(arr[i] <= arr[i + 1]);
            }
        }

        // Test with double data type
        {
            QuickSort<double> sorter;
            double arr[] = {12.5, 5.3, 7.1, -3.2, 8.9, 10.7, 2.4};
            constexpr int size = std::size(arr);

            sorter.quick_sort(arr, 0, size - 1);

            // Assert sorted array
            for (int i = 0; i < size - 1; ++i)
            {
                assert(arr[i] <= arr[i + 1]);
            }
        }

        // Test with char data type
        {
            QuickSort<char> sorter;
            char arr[] = {'z', 'a', 'b', 'd', 'c'};
            constexpr int size = std::size(arr);

            sorter.quick_sort(arr, 0, size - 1);

            // Assert sorted array
            for (int i = 0; i < size - 1; ++i)
            {
                assert(arr[i] <= arr[i + 1]);
            }
        }

        std::cout << "All Quick Sort tests passed!\n";
    }

    void Tester::test_array_utils()
    {
        std::cout << "\nTesting Array Utils...\n";
        using namespace utils;

        // Test with int array
        int int_array[] = {1, 2, 3, 4, 5};

        // Test max function
        assert((ArrayUtils<int, 5>::max(int_array)) == 5);

        // Test min function
        assert((ArrayUtils<int, 5>::min(int_array)) == 1);

        // Test sum function
        assert((ArrayUtils<int, 5>::sum(int_array)) == 15);

        // Test average function
        assert((ArrayUtils<int, 5>::average(int_array)) == 3.0);

        // Test contains_value function
        assert((ArrayUtils<int, 5>::contains_value(int_array, 3)));
        assert(!(ArrayUtils<int, 5>::contains_value(int_array, 6)));

        // Test reverse function
        const int reversed_int_array[] = {5, 4, 3, 2, 1};
        ArrayUtils<int, 5>::reverse(int_array);
        for (int i = 0; i < 5; ++i)
        {
            assert(int_array[i] == reversed_int_array[i]);
        }

        // Test with double array
        double double_array[] = {1.5, 2.5, 3.5, 4.5, 5.5};

        // Test max function
        assert((ArrayUtils<double, 5>::max(double_array) == 5.5));

        // Test min function
        assert((ArrayUtils<double, 5>::min(double_array) == 1.5));

        // Test sum function
        assert((ArrayUtils<double, 5>::sum(double_array) == 17.5));

        // Test average function
        assert((ArrayUtils<double, 5>::average(double_array) == 3.5));

        // Test contains_value function
        assert((ArrayUtils<double, 5>::contains_value(double_array, 3.5)));
        assert(!(ArrayUtils<double, 5>::contains_value(double_array, 6.0)));

        // Test reverse function
        constexpr double reversed_double_array[] = {5.5, 4.5, 3.5, 2.5, 1.5};
        ArrayUtils<double, 5>::reverse(double_array);
        for (int i = 0; i < 5; ++i)
        {
            // Compare the absolute difference to the tolerance value
            assert(std::abs(double_array[i] - reversed_double_array[i]) < 0.0001);
        }

        // Test with char array
        char char_array[] = {'a', 'b', 'c', 'd', 'e'};

        // Test max function
        assert((ArrayUtils<char, 5>::max(char_array) == 'e'));

        // Test min function
        assert((ArrayUtils<char, 5>::min(char_array) == 'a'));

        // Test contains_value function
        assert((ArrayUtils<char, 5>::contains_value(char_array, 'c')));
        assert(!(ArrayUtils<char, 5>::contains_value(char_array, 'z')));

        // Test reverse function
        constexpr char reversed_char_array[] = {'e', 'd', 'c', 'b', 'a'};
        ArrayUtils<char, 5>::reverse(char_array);
        for (int i = 0; i < 5; ++i)
        {
            assert(char_array[i] == reversed_char_array[i]);
        }

        std::cout << "All Array Utils tests passed!\n";
    }

    // Test String Utils
    void Tester::test_string_utils()
    {
        std::cout << "\nTesting String Utils...\n";
        using namespace utils;

        // Test data
        const char* str1 = "Hello";
        const char* str2 = "World";
        const char* str3 = "HelloWorld";
        const char* empty_str = "";

        // Test length function
        assert(StringUtils::length(str1) == 5);
        assert(StringUtils::length(empty_str) == 0);

        // Test compare function
        assert(StringUtils::compare(str1, str2) < 0);
        assert(StringUtils::compare(str1, str1) == 0);
        assert(StringUtils::compare(str2, str1) > 0);  // NOLINT(readability-suspicious-call-argument)

        // Test concatenate function
        const char* concatenated = StringUtils::concatenate(str1, str2);
        assert(StringUtils::compare(concatenated, str3) == 0);
        delete[] concatenated; // Free the dynamically allocated memory

        // Test substring function
        const char* substr = StringUtils::substring(str3, 3, 5);
        assert(StringUtils::compare(substr, "loWor") == 0);

        // Test to_upper function
        char mixed_case[] = "HeLLo";
        StringUtils::to_upper(mixed_case);
        assert(StringUtils::compare(mixed_case, "HELLO") == 0);

        // Test to_lower function
        char uppercase[] = "HELLO";
        StringUtils::to_lower(uppercase);
        assert(StringUtils::compare(uppercase, "hello") == 0);

        // Test find_char function
        assert(StringUtils::find_char(str1, 'e') == str1 + 1);
        assert(StringUtils::find_char(str1, 'z') == nullptr);

        // Test find_last_char function
        assert(StringUtils::find_last_char(str1, 'l') == str1 + 3);
        assert(StringUtils::find_last_char(str1, 'z') == nullptr);

        // Test copy function
        const char* copied = StringUtils::copy(str1, 3);
        assert(StringUtils::compare(copied, "Hel") == 0);
        delete[] copied; // Free the dynamically allocated memory

        // Test reverse function
        char to_reverse[] = "Reverse";
        StringUtils::reverse(to_reverse);
        assert(StringUtils::compare(to_reverse, "esreveR") == 0);

        // Test with non-null-terminated strings
        constexpr char non_null_terminated[] = { 'N', 'o', 'n', 'e', '\0', 'T', 'e', 'r', 'm', 'i', 'n', 'a', 't', 'e', 'd' };
        assert(StringUtils::length(non_null_terminated) == 4);
        assert(StringUtils::compare(str1, non_null_terminated) < 0);

        std::cout << "All String Utils tests passed!\n";
    }

    void Tester::test_strategy_pattern()
    {
        std::cout << "\nTesting Strategy Pattern...\n";
        using namespace design_patterns;

        // Create instances of the formatters
        const UppercaseFormatter upper_formatter;
        const LowercaseFormatter lower_formatter;

        // Test cases
        std::string input_text = "Hello World!";
        std::string expected_upper = "HELLO WORLD!";
        std::string expected_lower = "hello world!";

        // Test UppercaseFormatter
        assert(upper_formatter.format(input_text) == expected_upper);

        // Test LowercaseFormatter
        assert(lower_formatter.format(input_text) == expected_lower);

        // Additional test cases
        input_text = "This Is a TeSt StrIng";
        expected_upper = "THIS IS A TEST STRING";
        expected_lower = "this is a test string";

        // Test UppercaseFormatter with different input
        assert(upper_formatter.format(input_text) == expected_upper);

        // Test LowercaseFormatter with different input
        assert(lower_formatter.format(input_text) == expected_lower);

        std::cout << "All Strategy Pattern tests passed!\n";
    }
}
