#include "Array.h"
#include <cassert>
#include <iostream>
#include <stdexcept> // for std::out_of_range exception

Array::Array(const Array& other) : size(other.size), data(new int[other.size])
{
	std::copy(other.data, other.data + size, data);
}

Array::~Array()
{
	delete[] data; // Release memory
}

Array& Array::operator=(Array other)
{
	// Use copy-swap idiom for assignment operator to ensure strong exception safety
	swap(*this, other);
	return *this;
}

size_t Array::getSize() const { return size; }

const int& Array::operator[](size_t index) const
{
	if (index >= size)
		throw std::out_of_range("Index out of range");
	return data[index];
}

int& Array::operator[](size_t index)
{
	if (index >= size)
		throw std::out_of_range("Index out of range");
	return data[index];
}

void Array::fill(int value)
{
	std::fill(data, data + size, value);
}

void Array::print()
{
	for (size_t i = 0; i < getSize(); ++i)
		std::cout << " " << data[i];
	std::cout << std::endl;
}

void swap(Array& first, Array& second) noexcept
{
	using std::swap;
	swap(first.data, second.data);
	swap(first.size, second.size);
}

void Array::resize(size_t newSize)
{
	int* newData = new int[newSize];
	std::copy(data, data + std::min(size, newSize), newData);
	delete[] data; // Release old memory

	if (newSize > size)
	{
		std::fill(newData + size, newData + newSize, 0); // Initialize new elements to 0
	}

	data = newData;
	size = newSize;
}

void Array::clear()
{
	delete[] data;  // Release memory
	data = nullptr; // Reset pointer
	size = 0;
}

bool Array::isEmpty() const { return size == 0; }

int* Array::getData() const { return data; }

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

int Array::find(int value) const
{
	auto it = std::find(data, data + size, value);
	if (it == data + size)
		return -1;
	else
		return static_cast<int>(it - data);
}

size_t Array::count(int value) const
{
	return std::count(data, data + size, value);
}

void Array::remove(int value)
{
	auto it = std::find(data, data + size, value);
	if (it != data + size)
	{
		std::copy(it + 1, data + size, it);
	}
}

void Array::insert(size_t index, int value)
{
	assert(index <= size); // ensure index is valid
	resize(size + 1);      // increase size by 1
	std::copy_backward(data + index, data + size - 1, data + size);
	data[index] = value;
}
