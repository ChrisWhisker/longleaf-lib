#pragma once

// This class provides utility functions for working with C-style strings.
class StringUtils
{
public:
	// Calculate the length of a C-style string
	static size_t length(const char* str);

	// Compare two C-style strings
	static int compare(const char* str1, const char* str2);

	// Concatenate two C-style strings
	static char* concatenate(const char* str1, const char* str2);

	// Extract a substring from a C-style string
	static const char* substring(const char* str, size_t start, size_t length);

	// Convert C-style string to uppercase
	static void toUpper(char* str);

	// Convert C-style string to lowercase
	static void toLower(char* str);

	// Find the first occurrence of a character in a C-style string
	static const char* findChar(const char* str, char ch);

	// Find the last occurrence of a character in a C-style string
	static const char* findLastChar(const char* str, char ch);

	// Copy a portion of a C-style string
	static char* copy(const char* source, size_t length);

	// Reverse a C-style string
	static void reverse(char* str);
};
