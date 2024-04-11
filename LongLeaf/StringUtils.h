#pragma once
#include <iostream>
#include <cstring>

class StringUtils
{
public:
    // Function to calculate the length of a C-style string
    static size_t length(const char *str);

    // Function to compare two C-style strings
    static int compare(const char *str1, const char *str2);

    // Function to concatenate two C-style strings
    static char *concatenate(const char *str1, const char *str2);

    // Function to find a substring within a C-style string
    static const char *substring(const char *str, size_t start, size_t length);

    // Function to convert all characters in a C-style string to uppercase
    static void toUpper(char *str);

    // Function to convert all characters in a C-style string to lowercase
    static void toLower(char *str);

    // Function to find the first occurrence of a character in a C-style string
    static const char *findChar(const char *str, char ch);

    // Function to find the last occurrence of a character in a C-style string
    static const char *findLastChar(const char *str, char ch);

    // Function to copy a portion of a C-style string into another string
    static char *copy(const char *source, size_t length);

    // Function to reverse a C-style string
    static void reverse(char *str);
};
