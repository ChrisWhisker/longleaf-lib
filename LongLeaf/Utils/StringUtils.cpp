#include "StringUtils.h"
#include <cstring> // Include for C string manipulation functions
#include <cctype>  // Include for character handling functions
#include <iostream>

size_t StringUtils::length(const char* str)
{
	if (str == nullptr)		 // Check if the input string is nullptr
		return 0;			 // Return 0 if it is
	return std::strlen(str); // Otherwise, return the length of the string
}

int StringUtils::compare(const char* str1, const char* str2)
{
	if (str1 == nullptr || str2 == nullptr) // Check if either input string is nullptr
		return -1;							// Return -1 if either string is nullptr
	return std::strcmp(str1, str2);			// Otherwise, return the result of string comparison
}

char* StringUtils::concatenate(const char* str1, const char* str2)
{
	if (str1 == nullptr || str2 == nullptr) // Check if either input string is nullptr
		return nullptr;						// Return nullptr if either string is nullptr

	size_t len1 = std::strlen(str1); // Calculate length of first string
	size_t len2 = std::strlen(str2); // Calculate length of second string
	size_t newLen = len1 + len2 + 1; // Calculate total length of concatenated string

	char* result = new char[newLen]; // Allocate memory for concatenated string
	strcpy_s(result, newLen, str1);	 // Copy first string to result
	strcat_s(result, newLen, str2);	 // Append second string to result

	return result; // Return pointer to concatenated string
}

const char* StringUtils::substring(const char* str, size_t start, size_t length)
{
	if (str == nullptr || start >= std::strlen(str) || start + length > std::strlen(str))
		// Check if input string is nullptr or if start and length are out of bounds
		return nullptr; // Return nullptr if any condition is met

	return str + start; // Return pointer to start of substring
}

void StringUtils::toUpper(char* str)
{
	if (str == nullptr) // Check if input string is nullptr
		return;			// Return if it is

	size_t len = std::strlen(str);	 // Calculate length of string
	for (size_t i = 0; i < len; ++i) // Iterate over each character in the string
	{
		str[i] = std::toupper(static_cast<unsigned char>(str[i])); // Convert character to uppercase
	}
}

void StringUtils::toLower(char* str)
{
	if (str == nullptr) // Check if input string is nullptr
		return;			// Return if it is

	size_t len = std::strlen(str);	 // Calculate length of string
	for (size_t i = 0; i < len; ++i) // Iterate over each character in the string
	{
		str[i] = std::tolower(static_cast<unsigned char>(str[i])); // Convert character to lowercase
	}
}

const char* StringUtils::findChar(const char* str, char ch)
{
	if (str == nullptr) // Check if input string is nullptr
		return nullptr; // Return nullptr if it is

	return std::strchr(str, ch); // Find first occurrence of character in string
}

const char* StringUtils::findLastChar(const char* str, char ch)
{
	if (str == nullptr) // Check if input string is nullptr
		return nullptr; // Return nullptr if it is

	return std::strrchr(str, ch); // Find last occurrence of character in string
}

char* StringUtils::copy(const char* source, size_t length)
{
	if (source == nullptr) // Check if input string is nullptr
		return nullptr;	   // Return nullptr if it is

	char* result = new char[length + 1];		   // Allocate memory for copied string
	strncpy_s(result, length + 1, source, length); // Copy portion of source string to result
	result[length] = '\0';						   // Null-terminate result string

	return result; // Return pointer to copied string
}

void StringUtils::reverse(char* str)
{
	if (str == nullptr) // Check if input string is nullptr
		return;			// Return if it is

	size_t len = std::strlen(str);		 // Calculate length of string
	for (size_t i = 0; i < len / 2; ++i) // Iterate over first half of string
	{
		std::swap(str[i], str[len - i - 1]); // Swap characters to reverse the string
	}
}
