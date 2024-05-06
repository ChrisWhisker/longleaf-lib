#include "StringUtils.h"
#include <cstring> // Include for C string manipulation functions
#include <cctype> // Include for character handling functions
#include <iostream>

namespace utils
{
    size_t StringUtils::length(const char* p_str)
    {
        if (p_str == nullptr) // Check if the input string is nullptr
            return 0; // Return 0 if it is
        return std::strlen(p_str); // Otherwise, return the length of the string
    }

    int StringUtils::compare(const char* p_str1, const char* p_str2)
    {
        if (p_str1 == nullptr || p_str2 == nullptr) // Check if either input string is nullptr
            return -1; // Return -1 if either string is nullptr
        return std::strcmp(p_str1, p_str2); // Otherwise, return the result of string comparison
    }

    char* StringUtils::concatenate(const char* p_str1, const char* p_str2)
    {
        if (p_str1 == nullptr || p_str2 == nullptr) // Check if either input string is nullptr
            return nullptr; // Return nullptr if either string is nullptr

        const size_t len1 = std::strlen(p_str1); // Calculate length of first string
        const size_t len2 = std::strlen(p_str2); // Calculate length of second string
        const size_t new_len = len1 + len2 + 1; // Calculate total length of concatenated string

        char* p_result = new char[new_len]; // Allocate memory for concatenated string
        strcpy_s(p_result, new_len, p_str1); // Copy first string to result
        strcat_s(p_result, new_len, p_str2); // Append second string to result

        return p_result; // Return pointer to concatenated string
    }

    const char* StringUtils::substring(const char* p_str, size_t start, size_t length)
    {
        if (p_str == nullptr) // Check if input string is nullptr
            return nullptr; // Return nullptr if it is

        const size_t str_length = std::strlen(p_str); // Calculate length of the string once

        if (start >= str_length) // Check if start is out of bounds
            return nullptr; // Return nullptr if it is

        // Adjust length if it exceeds the remaining length of the string
        length = std::min(length, str_length - start);

        // Allocate memory for the substring
        char* result = new char[length + 1];

        // Copy the substring
        strncpy_s(result, length + 1, p_str + start, length);
        result[length] = '\0'; // Null-terminate the substring

        return result; // Return pointer to the substring
    }

    void StringUtils::to_upper(char* p_str)
    {
        if (p_str == nullptr) // Check if input string is nullptr
            return; // Return if it is

        const size_t len = std::strlen(p_str); // Calculate length of string
        for (size_t i = 0; i < len; ++i) // Iterate over each character in the string
        {
            p_str[i] = static_cast<char>(std::toupper(p_str[i])); // Convert character to uppercase
        }
    }

    void StringUtils::to_lower(char* p_str)
    {
        if (p_str == nullptr) // Check if input string is nullptr
            return; // Return if it is

        const size_t len = std::strlen(p_str); // Calculate length of string
        for (size_t i = 0; i < len; ++i) // Iterate over each character in the string
        {
            p_str[i] = static_cast<char>(std::tolower(p_str[i])); // Convert character to lowercase
        }
    }

    const char* StringUtils::find_char(const char* p_str, char ch)
    {
        if (p_str == nullptr) // Check if input string is nullptr
            return nullptr; // Return nullptr if it is

        return std::strchr(p_str, ch); // Find first occurrence of character in string
    }

    const char* StringUtils::find_last_char(const char* p_str, char ch)
    {
        if (p_str == nullptr) // Check if input string is nullptr
            return nullptr; // Return nullptr if it is

        return std::strrchr(p_str, ch); // Find last occurrence of character in string
    }

    char* StringUtils::copy(const char* p_source, size_t length)
    {
        if (p_source == nullptr) // Check if input string is nullptr
            return nullptr; // Return nullptr if it is

        char* p_result = new char[length + 1]; // Allocate memory for copied string
        strncpy_s(p_result, length + 1, p_source, length); // Copy portion of p_source string to result
        p_result[length] = '\0'; // Null-terminate result string

        return p_result; // Return pointer to copied string
    }

    void StringUtils::reverse(char* p_str)
    {
        if (p_str == nullptr) // Check if input string is nullptr
            return; // Return if it is

        const size_t len = std::strlen(p_str); // Calculate length of string
        for (size_t i = 0; i < len / 2; ++i) // Iterate over first half of string
        {
            std::swap(p_str[i], p_str[len - i - 1]); // Swap characters to reverse the string
        }
    }
}
