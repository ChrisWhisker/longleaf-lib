#pragma once

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
class Array
{
private:
	int* data;   // pointer to dynamically allocated memory
	size_t size; // size of the array

public:
	// Constructors
	explicit Array(size_t arraySize) : size(arraySize), data(new int[arraySize]) {}

	Array(const Array& other);

	// Destructor
	~Array();

	// Assignment operator
	Array& operator=(Array other);

	// Get the size of the array
	size_t getSize() const;

	// Access element at index (read-only)
	const int& operator[](size_t index) const;

	// Access element at index (read-write)
	int& operator[](size_t index);

	// Fill the array with a given value
	void fill(int value);

	void print();

	// Swap contents with another array
	friend void swap(Array& first, Array& second) noexcept;

	// Resize the array
	void resize(size_t newSize);

	// Clear the contents of the array (set size to 0)
	void clear();

	// Check if the array is empty
	bool isEmpty() const;

	// Get a pointer to the underlying data (use with caution)
	int* getData() const;

	// Reverse the elements of the array
	void reverse();

	// Find the index of the first occurrence of a value
	// Returns -1 if not found
	int find(int value) const;

	// Count the occurrences of a value in the array
	size_t count(int value) const;

	// Remove the first occurrence of a value from the array
	void remove(int value);

	// Insert a value at a specified index
	void insert(size_t index, int value);
};
