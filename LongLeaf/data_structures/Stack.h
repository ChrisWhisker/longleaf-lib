#pragma once
#include <cassert>

namespace data_structures
{
	/*
		A stack implementation in C++ using an underlying dynamic array. The Stack
		class provides functionality for creating and manipulating stacks of any
		p_data type.

		This class can be used in situations where a last-in, first-out (LIFO)
		p_data structure is needed. It allows flexibility in storing and accessing
		elements, while also providing efficient insertion and removal operations.

		When using this class, it's important to note that manual memory management
		is not required, as the Stack class internally manages memory through its
		dependency on the Array class, which handles dynamic resizing and memory
		allocation. However, users should exercise caution when accessing the
		underlying p_data directly using the getData() method.
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
		bool is_empty() const
		{
			return elements.is_empty();
		}

		// Push an element onto the stack
		// Parameters:
		//   value: The value to be pushed onto the stack.
		void push(const T& value)
		{
			elements.insert(elements.get_size(), value);
		}

		// Pop an element from the stack
		void pop()
		{
			if (!is_empty())
			{
				elements.remove_at_position(elements.get_size() - 1);
			}
		}

		// Get the top element of the stack
		// Returns: A reference to the top element of the stack.
		// Exception: Asserts that the stack is not empty.
		const T& top() const
		{
			assert(!is_empty());
			return elements[elements.get_size() - 1];
		}

		// Get the size of the stack
		// Returns: The number of elements in the stack.
		size_t size() const
		{
			return elements.get_size();
		}

		// Clear the stack, removing all elements
		void clear()
		{
			elements.clear();
		}

		// Get a pointer to the underlying p_data (use with caution)
		// Returns: A pointer to the underlying p_data array.
		T* get_data() const
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
}
