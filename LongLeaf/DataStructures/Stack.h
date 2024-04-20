#pragma once
#include <cassert>

template <typename T>
class Stack
{
private:
    Array<T> elements; // Using the Array class for storage

public:
    // Constructor
    Stack() {}

    // Destructor is automatically generated and will call the destructor of Array

    // Check if the stack is empty
	bool isEmpty() const
    {
        return elements.isEmpty();
    }

    // Push an element onto the stack
	void push(const T& value)
    {
        elements.insert(elements.getSize(), value);
    }

    // Pop an element from the stack
    void pop()
    {
        if (!isEmpty())
        {
            elements.removeAtPosition(elements.getSize() - 1);
        }
    }

    // Get the top element of the stack
    const T &top() const
    {
        assert(!isEmpty());
        return elements[elements.getSize() - 1];
    }

    // Get the size of the stack
    size_t size() const
    {
        return elements.getSize();
    }

    // Clear the stack, removing all elements
    void clear()
    {
        elements.clear();
    }

    // Get a pointer to the underlying data (use with caution)
    T *getData() const
    {
        return elements.getData();
    }

    // Swap the contents of this stack with another stack
    friend void swap(Stack& first, Stack& second) noexcept
    {
        swap(first.elements, second.elements);
    }

    // Check if two stacks are equal (have the same elements in the same order)
    bool operator==(const Stack &other) const
    {
        return elements == other.elements;
    }

    // Check if two stacks are not equal
    bool operator!=(const Stack &other) const
    {
        return !(*this == other);
    }
};
