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
	// Parameters:
	//   str: The null-terminated C-style string whose length is to be calculated.
	// Returns: The length of the input string.
	static size_t length(const char* str);

	// Compare two C-style strings
	// Parameters:
	//   str1: The first null-terminated C-style string to be compared.
	//   str2: The second null-terminated C-style string to be compared.
	// Returns: An integer less than, equal to, or greater than zero if str1 is found,
	//		  respectively, to be less than, to match, or be greater than str2.
	static int compare(const char* str1, const char* str2);

	// Concatenate two C-style strings
	// Parameters:
	//   str1: The first null-terminated C-style string.
	//   str2: The second null-terminated C-style string to be concatenated.
	// Returns: A dynamically allocated null-terminated C-style string containing
	//		  the result of concatenating str1 and str2, or nullptr on failure.
	static char* concatenate(const char* str1, const char* str2);

	// Extract a substring from a C-style string
	// Parameters:
	//   str: The null-terminated C-style string from which the substring is extracted.
	//   start: The starting index of the substring.
	//   length: The length of the substring.
	// Returns: A pointer to the beginning of the extracted substring, or nullptr
	//		  if the input string is nullptr or if the start and length are out of bounds.
	static const char* substring(const char* str, size_t start, size_t length);

	// Convert C-style string to uppercase
	// Parameters:
	//   str: The null-terminated C-style string to be converted to uppercase.
	static void toUpper(char* str);

	// Convert C-style string to lowercase
	// Parameters:
	//   str: The null-terminated C-style string to be converted to lowercase.
	static void toLower(char* str);

	// Find the first occurrence of a character in a C-style string
	// Parameters:
	//   str: The null-terminated C-style string to be searched.
	//   ch: The character to search for in the string.
	// Returns: A pointer to the first occurrence of the character in the string,
	//		  or nullptr if the input string is nullptr.
	static const char* findChar(const char* str, char ch);

	// Find the last occurrence of a character in a C-style string
	// Parameters:
	//   str: The null-terminated C-style string to be searched.
	//   ch: The character to search for in the string.
	// Returns: A pointer to the last occurrence of the character in the string,
	//		  or nullptr if the input string is nullptr.
	static const char* findLastChar(const char* str, char ch);

	// Copy a portion of a C-style string
	// Parameters:
	//   source: The null-terminated C-style string to be copied.
	//   length: The length of the portion to be copied.
	// Returns: A dynamically allocated null-terminated C-style string containing
	//		  the copied portion of the source string, or nullptr on failure.
	static char* copy(const char* source, size_t length);

	// Reverse a C-style string
	// Parameters:
	//   str: The null-terminated C-style string to be reversed.
	static void reverse(char* str);
};
