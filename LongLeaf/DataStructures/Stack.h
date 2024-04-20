#pragma once
#include <cassert>

/*
	A stack implementation in C++ using an underlying dynamic array. The Stack
	class provides functionality for creating and manipulating stacks of any
	data type.

	This class can be used in situations where a last-in, first-out (LIFO)
	data structure is needed. It allows flexibility in storing and accessing
	elements, while also providing efficient insertion and removal operations.

	When using this class, it's important to note that manual memory management
	is not required, as the Stack class internally manages memory through its
	dependency on the Array class, which handles dynamic resizing and memory
	allocation. However, users should exercise caution when accessing the
	underlying data directly using the getData() method.
*/
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
	// Returns: True if the stack is empty, false otherwise.
	bool isEmpty() const
	{
		return elements.isEmpty();
	}

	// Push an element onto the stack
	// Parameters:
	//   value: The value to be pushed onto the stack.
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
	// Returns: A reference to the top element of the stack.
	// Exception: Asserts that the stack is not empty.
	const T& top() const
	{
		assert(!isEmpty());
		return elements[elements.getSize() - 1];
	}

	// Get the size of the stack
	// Returns: The number of elements in the stack.
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
	// Returns: A pointer to the underlying data array.
	T* getData() const
	{
		return elements.getData();
	}

	// Swap the contents of this stack with another stack
	// Parameters:
	//   first: The first stack to be swapped.
	//   second: The second stack to be swapped.
	friend void swap(Stack& first, Stack& second) noexcept
	{
		swap(first.elements, second.elements);
	}

	// Check if two stacks are equal (have the same elements in the same order)
	// Parameters:
	//   other: The stack to be compared with.
	// Returns: True if the stacks are equal, false otherwise.
	bool operator==(const Stack& other) const
	{
		return elements == other.elements;
	}

	// Check if two stacks are not equal
	// Parameters:
	//   other: The stack to be compared with.
	// Returns: True if the stacks are not equal, false otherwise.
	bool operator!=(const Stack& other) const
	{
		return !(*this == other);
	}
};
