#pragma once

#include <cassert>
#include <iostream>
#include <stdexcept> // for std::out_of_range exception

/**
 * @brief A dynamic array implementation in C++ using raw pointers.
 *
 * The Array class provides functionality similar to std::vector, allowing
 * dynamic resizing, element access, insertion, removal, and other common
 * operations on a sequence of integers.
 *
 * This class can be used in situations where a dynamically resizable array
 * is needed, but the overhead of std::vector or other standard containers
 * is undesired or not available (e.g., in environments with restricted
 * standard library support). Manual memory management is required when
 * using this class.
 */
template <typename T>
class Array
{
private:
    T* data;    // pointer to dynamically allocated memory
    size_t size; // size of the array

public:
    // Constructors
    Array() : size(0), data(nullptr) {}

    Array(size_t arraySize) : size(arraySize), data(new T[arraySize]) {}

    Array(const Array& other) : size(other.size), data(new T[other.size])
    {
        std::copy(other.data, other.data + size, data);
    }

    // Destructor
    ~Array()
    {
        delete[] data;
    }

    // Assignment operator
    Array& operator=(Array other)
    {
        swap(*this, other);
        return *this;
    }

    // Get the size of the array
    size_t getSize() const
    {
        return size;
    }

    // Access element at index (read-only)
    const T& operator[](size_t index) const
    {
        if (index >= size)
            throw std::out_of_range("Index out of range");
        return data[index];
    }

    // Access element at index (read-write)
    T& operator[](size_t index)
    {
        if (index >= size)
            throw std::out_of_range("Index out of range");
        return data[index];
    }

    // Fill the array with a given value
    void fill(T value)
    {
        std::fill(data, data + size, value);
    }

    // Print the elements of the array
    void print()
    {
        for (size_t i = 0; i < size; ++i)
            std::cout << " " << data[i];
        std::cout << std::endl;
    }

    // Resize the array
    void resize(size_t newSize)
    {
        T* newData = new T[newSize];
        std::copy(data, data + std::min(size, newSize), newData);
        delete[] data;

        if (newSize > size)
        {
            // Initialize new elements to default value for type T
            for (size_t i = size; i < newSize; ++i)
                newData[i] = T();
        }

        data = newData;
        size = newSize;
    }

    // Clear the contents of the array (set size to 0)
    void clear()
    {
        delete[] data;
        data = nullptr;
        size = 0;
    }

    // Check if the array is empty
    bool isEmpty() const
    {
        return size == 0;
    }

    // Get a pointer to the underlying data (use with caution)
    T* getData() const
    {
        return data;
    }

    // Reverse the elements of the array
    void reverse()
    {
        size_t left = 0;
        size_t right = size - 1;
        while (left < right)
        {
            std::swap(data[left], data[right]);
            ++left;
            --right;
        }
    }

    // Find the index of the first occurrence of a value
    // Returns -1 if not found
    int find(T value) const
    {
        auto it = std::find(data, data + size, value);
        if (it == data + size)
            return -1;
        else
            return static_cast<int>(it - data);
    }

    // Count the occurrences of a value in the array
    size_t count(T value) const
    {
        return std::count(data, data + size, value);
    }

    // Remove the first occurrence of a value from the array
    void remove(T value)
    {
        auto it = std::find(data, data + size, value);
        if (it != data + size)
        {
            std::copy(it + 1, data + size, it);
        }
    }

    // Insert a value at a specified index
    void insert(size_t index, T value)
    {
        assert(index <= size);
        resize(size + 1);
        std::copy_backward(data + index, data + size - 1, data + size);
        data[index] = value;
    }

    // Swap contents with another array
    friend void swap(Array& first, Array& second) noexcept
    {
        using std::swap;
        swap(first.data, second.data);
        swap(first.size, second.size);
    }
};