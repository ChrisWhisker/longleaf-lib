#include "Array.h"

#include <cassert>
#include <iostream>
#include <stdexcept> // for std::out_of_range exception

Array::Array(size_t s) : size(s)
{
	if (size > 0)
		data = new int[size]; // allocate memory for the array
	else
		data = nullptr; // empty array
}

// Destructor
Array::~Array()
{
	delete[] data; // release dynamically allocated memory
}

// Copy constructor
Array::Array(const Array& other) : size(other.size)
{
	if (size > 0)
	{
		data = new int[size];                           // allocate memory for the copy
		std::copy(other.data, other.data + size, data); // copy elements
	}
	else
		data = nullptr; // empty array
}

// Assignment operator
Array& Array::operator=(const Array& other)
{
	if (this != &other)
	{ // self-assignment check
		// Release existing resources
		delete[] data;

		// Copy size
		size = other.size;

		if (size > 0)
		{
			data = new int[size];                           // allocate memory for the copy
			std::copy(other.data, other.data + size, data); // copy elements
		}
		else
			data = nullptr; // empty array
	}
	return *this;
}

// Get the size of the array
size_t Array::getSize() const
{
	return size;
}

// Access element at index (read-only)
int Array::operator[](size_t index) const
{
	if (index >= size)
		throw std::out_of_range("Index out of range");
	return data[index];
}

// Access element at index (read-write)
int& Array::operator[](size_t index)
{
	if (index >= size)
		throw std::out_of_range("Index out of range");
	return data[index];
}

// Fill the array with a given value
void Array::fill(int value)
{
	for (size_t i = 0; i < size; ++i)
		data[i] = value;
}

// Swap contents with another array
void Array::swap(Array& other)
{
	std::swap(data, other.data);
	std::swap(size, other.size);
}

// Resize the array
void Array::resize(size_t newSize)
{
	if (newSize == size)
		return; // no change needed
	int* newData = new int[newSize]; // allocate new memory
	const size_t minSize = std::min(size, newSize);
	std::copy(data, data + minSize, newData); // copy existing elements
	delete[] data;                            // deallocate old memory
	data = newData;                           // update pointer
	size = newSize;                           // update size
}

// Clear the contents of the array (set size to 0)
void Array::clear()
{
	delete[] data;
	data = nullptr;
	size = 0;
}

// Check if the array is empty
bool Array::isEmpty() const
{
	return size == 0;
}

// Get a pointer to the underlying data (use with caution)
int* Array::getData() const
{
	return data;
}

// Reverse the elements of the array
void Array::reverse()
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
int Array::find(int value) const
{
	for (size_t i = 0; i < size; ++i)
	{
		if (data[i] == value)
			return static_cast<int>(i);
	}
	return -1; // not found
}

// Count the occurrences of a value in the array
size_t Array::count(int value) const
{
	size_t count = 0;
	for (size_t i = 0; i < size; ++i)
	{
		if (data[i] == value)
			++count;
	}
	return count;
}

// Remove the first occurrence of a value from the array
void Array::remove(int value)
{
	int index = find(value);
	if (index != -1)
	{
		for (size_t i = static_cast<size_t>(index); i < size - 1; ++i)
			data[i] = data[i + 1];
		resize(size - 1);
	}
}

// Insert a value at a specified index
void Array::insert(size_t index, int value)
{
	assert(index <= size); // ensure index is valid
	resize(size + 1);      // increase size by 1
	for (size_t i = size - 1; i > index; --i)
		data[i] = data[i - 1];
	data[index] = value;
}
