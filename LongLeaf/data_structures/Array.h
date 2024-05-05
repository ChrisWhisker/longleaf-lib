#pragma once
#include <cassert>
#include <iostream>
#include <stdexcept> // for std::out_of_range exception

namespace data_structures
{
    /*
        A dynamic array implementation in C++ using raw pointers.

        The Array class provides functionality similar to std::vector, allowing
        dynamic resizing, element access, insertion, removal, and other common
        operations on a sequence of elements.

        This class can be used in situations where a dynamically resizable array
        is needed, but the overhead of std::vector or other standard containers
        is undesired or not available (e.g., in environments with restricted
        standard library support). Manual memory management is required when
        using this class.
     */
    template <typename T>
    class Array
    {
    private:
        T* p_data; // pointer to dynamically allocated memory
        size_t size; // size of the array

    public:
        // Constructors

        // Default constructor
        Array() : p_data(nullptr), size(0)
        {
        }

        // Constructor with initial size
        Array(size_t arraySize) : p_data(new T[arraySize]), size(arraySize)
        {
            for (size_t i = 0; i < arraySize; ++i)
                p_data[i] = T();
        }

        // Copy constructor
        Array(const Array& other) : p_data(new T[other.size]), size(other.size)
        {
            std::copy(other.p_data, other.p_data + size, p_data);
        }

        // Destructor
        ~Array()
        {
            delete[] p_data;
        }

        // Assignment operator
        Array& operator=(Array other)
        {
            swap(*this, other);
            return *this;
        }

        // Get the size of the array
        inline size_t get_size() const
        {
            return size;
        }

        // Access element at index (read-only)
        const T& operator[](size_t index) const
        {
            if (index >= size)
                throw std::out_of_range("Index out of range");
            return p_data[index];
        }

        // Access element at index (read-write)
        T& operator[](size_t index)
        {
            if (index >= size)
                throw std::out_of_range("Index out of range");
            return p_data[index];
        }

        // Fill the array with a given value
        void fill(T value)
        {
            std::fill(p_data, p_data + size, value);
        }

        // Print the elements of the array
        void print()
        {
            std::cout << "{";
            for (size_t i = 0; i < size; ++i)
                std::cout << " [" << p_data[i] << "]";
            std::cout << " }\n";
        }

        // Resize the array
        void resize(size_t newSize)
        {
            if (newSize == size) return; // If the size is unchanged, do nothing

            T* p_new_data = new T[newSize];

            // Copy elements up to the minimum of the old and new size
            size_t min_size = std::min(size, newSize);
            std::copy(p_data, p_data + min_size, p_new_data);

            // Initialize new elements to default value for type T if size is increased
            if (newSize > size)
            {
                for (size_t i = size; i < newSize; ++i)
                    p_new_data[i] = T();
            }

            // Update array pointer and size
            delete[] p_data;
            p_data = p_new_data;
            size = newSize;
        }

        // Clear the contents of the array (set size to 0)
        void clear()
        {
            delete[] p_data;
            p_data = nullptr;
            size = 0;
        }

        // Check if the array is empty
        bool is_empty() const
        {
            return size == 0;
        }

        // Get a pointer to the underlying data (use with caution)
        T* get_data() const
        {
            return p_data;
        }

        // Reverse the elements of the array
        void reverse()
        {
            size_t left = 0;
            size_t right = size - 1;
            while (left < right)
            {
                std::swap(p_data[left], p_data[right]);
                ++left;
                --right;
            }
        }

        // Find the index of the first occurrence of a value
        // Returns -1 if not found
        int find(T value) const
        {
            auto it = std::find(p_data, p_data + size, value);
            if (it == p_data + size)
                return -1;
            else
                return static_cast<int>(it - p_data);
        }

        // Count the occurrences of a value in the array
        size_t count(T value) const
        {
            return std::count(p_data, p_data + size, value);
        }

        // Remove the first occurrence of a value from the array
        void remove(T value)
        {
            auto it = std::find(p_data, p_data + size, value);
            if (it != p_data + size)
            {
                // Shift elements to cover the removed element
                std::copy(it + 1, p_data + size, it);

                // Resize the array to remove the last element
                resize(size - 1);
            }
        }

        // Remove the element at the specified position
        void remove_at_position(int position)
        {
            if (position < 0 || static_cast<size_t>(position) >= size)
                throw std::out_of_range("Position out of range");

            // Shift elements to cover the removed element
            std::copy(p_data + position + 1, p_data + size, p_data + position);

            // Resize the array to remove the last element
            resize(size - 1);
        }

        // Insert a value at a specified index
        void insert(size_t index, T value)
        {
            assert(index <= size);
            resize(size + 1);
            std::copy_backward(p_data + index, p_data + size - 1, p_data + size);
            p_data[index] = value;
        }

        // Swap contents with another array
        friend void swap(Array& first, Array& second) noexcept
        {
            using std::swap;
            swap(first.p_data, second.p_data);
            swap(first.size, second.size);
        }

        // Equality operator
        bool operator==(const Array& other) const
        {
            // If sizes are different, arrays are not equal
            if (size != other.size)
                return false;

            // Compare each element
            for (size_t i = 0; i < size; ++i)
            {
                if (p_data[i] != other.p_data[i])
                    return false;
            }

            return true; // All elements are equal
        }

        // Inequality operator
        bool operator!=(const Array& other) const
        {
            // Use the == operator to check for equality and negate the result
            return !(*this == other);
        }
    };
}
