#pragma once


/*
	A utility class for working with C-style strings in C++.

	StringUtils provides a set of static methods for performing common operations
	on null-terminated character arrays (C-style strings).

	This class is designed to offer convenience and efficiency when working with
	C-style strings in C++ projects. It abstracts away the complexity of manual
	memory management and provides a range of functionalities commonly found in
	string manipulation libraries.

	When using this class, it's important to ensure that input strings are properly
	null-terminated to avoid undefined behavior. Additionally, some methods may
	modify the input strings in place, so caution should be exercised when passing
	string literals or constant strings.
*/
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
