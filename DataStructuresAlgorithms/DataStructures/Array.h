#pragma once

using std::size_t;

class Array
{
private:
	int* data;   // pointer to dynamically allocated memory
	size_t size; // size of the array

public:
	// Constructor
	Array(size_t s);

	// Destructor
	~Array();

	// Copy constructor
	Array(const Array& other);

	// Assignment operator
	Array& operator=(const Array& other);

	// Get the size of the array
	size_t getSize() const;

	// Access element at index (read-only)
	int operator[](size_t index) const;

	// Access element at index (read-write)
	int& operator[](size_t index);

	// Fill the array with a given value
	void fill(int value);

	// Swap contents with another array
	void swap(Array& other);

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
