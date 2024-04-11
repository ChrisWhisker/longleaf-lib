#include "StringUtils.h"

size_t StringUtils::length(const char* str)
{
	if (str == nullptr)
		return 0;
	return strlen(str);
}

int StringUtils::compare(const char* str1, const char* str2)
{
	if (str1 == nullptr || str2 == nullptr)
		return -1;
	return strcmp(str1, str2);
}

char* StringUtils::concatenate(const char* str1, const char* str2)
{
	if (str1 == nullptr || str2 == nullptr)
		return nullptr;

	size_t len1 = strlen(str1);
	size_t len2 = strlen(str2);
	size_t newLen = len1 + len2 + 1; // +1 for the null terminator

	char* result = new char[newLen];
	strcpy_s(result, newLen, str1);
	strcat_s(result, newLen, str2); // Use strcat_s instead of strcat

	return result;
}

const char* StringUtils::substring(const char* str, size_t start, size_t length)
{
	if (str == nullptr || start >= strlen(str))
		return nullptr;

	return str + start;
}

void StringUtils::toUpper(char* str)
{
	if (str == nullptr)
		return;

	size_t len = strlen(str);
	for (size_t i = 0; i < len; ++i)
	{
		str[i] = toupper(str[i]);
	}
}

void StringUtils::toLower(char* str)
{
	if (str == nullptr)
		return;

	size_t len = strlen(str);
	for (size_t i = 0; i < len; ++i)
	{
		str[i] = tolower(str[i]);
	}
}

const char* StringUtils::findChar(const char* str, char ch)
{
	if (str == nullptr)
		return nullptr;

	return strchr(str, ch);
}

const char* StringUtils::findLastChar(const char* str, char ch)
{
	if (str == nullptr)
		return nullptr;

	return strrchr(str, ch);
}

char* StringUtils::copy(const char* source, size_t length)
{
	if (source == nullptr)
		return nullptr;

	// Allocate memory for the destination string
	char* result = new char[length + 1]; // +1 for the null terminator

	// Use strncpy_s to copy the source string to the destination buffer
	// Ensure that strncpy_s is used safely by specifying the buffer size as the second parameter
	strncpy_s(result, length + 1, source, length);

	// Ensure null-termination
	result[length] = '\0';

	return result;
}

void StringUtils::reverse(char* str)
{
	if (str == nullptr)
		return;

	size_t len = strlen(str);
	for (size_t i = 0; i < len / 2; ++i)
	{
		std::swap(str[i], str[len - i - 1]);
	}
}
