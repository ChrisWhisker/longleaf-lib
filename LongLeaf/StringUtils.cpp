#include "StringUtils.h"
#include <cstring>
#include <cctype>

size_t StringUtils::length(const char* str)
{
	if (str == nullptr)
		return 0;
	return std::strlen(str);
}

int StringUtils::compare(const char* str1, const char* str2)
{
	if (str1 == nullptr || str2 == nullptr)
		return -1;
	return std::strcmp(str1, str2);
}

char* StringUtils::concatenate(const char* str1, const char* str2)
{
	if (str1 == nullptr || str2 == nullptr)
		return nullptr;

	size_t len1 = std::strlen(str1);
	size_t len2 = std::strlen(str2);
	size_t newLen = len1 + len2 + 1;

	char* result = new char[newLen];
	strcpy_s(result, newLen, str1);
	strcat_s(result, newLen, str2);

	return result;
}

const char* StringUtils::substring(const char* str, size_t start, size_t length)
{
	if (str == nullptr || start >= std::strlen(str) || start + length > std::strlen(str))
		return nullptr;

	return str + start;
}

void StringUtils::toUpper(char* str)
{
	if (str == nullptr)
		return;

	size_t len = std::strlen(str);
	for (size_t i = 0; i < len; ++i)
	{
		str[i] = std::toupper(static_cast<unsigned char>(str[i]));
	}
}

void StringUtils::toLower(char* str)
{
	if (str == nullptr)
		return;

	size_t len = std::strlen(str);
	for (size_t i = 0; i < len; ++i)
	{
		str[i] = std::tolower(static_cast<unsigned char>(str[i]));
	}
}

const char* StringUtils::findChar(const char* str, char ch)
{
	if (str == nullptr)
		return nullptr;

	return std::strchr(str, ch);
}

const char* StringUtils::findLastChar(const char* str, char ch)
{
	if (str == nullptr)
		return nullptr;

	return std::strrchr(str, ch);
}

char* StringUtils::copy(const char* source, size_t length)
{
	if (source == nullptr)
		return nullptr;

	char* result = new char[length + 1];
	strncpy_s(result, length + 1, source, length);
	result[length] = '\0';

	return result;
}

void StringUtils::reverse(char* str)
{
	if (str == nullptr)
		return;

	size_t len = std::strlen(str);
	for (size_t i = 0; i < len / 2; ++i)
	{
		std::swap(str[i], str[len - i - 1]);
	}
}
