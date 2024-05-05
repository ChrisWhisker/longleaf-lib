#include "Strategy.h"
#include <cctype> // Include for std::toupper and std::tolower
#include <iostream>

namespace design_patterns
{
    // Implementation of UppercaseFormatter::format
    std::string UppercaseFormatter::format(const std::string& text) const
    {
        std::string formatted_text = text;
        for (char& c : formatted_text)
        {
            c = std::toupper(static_cast<unsigned char>(c)); // Ensure proper handling of non-ASCII characters
        }
        return formatted_text;
    }

    // Implementation of LowercaseFormatter::format
    std::string LowercaseFormatter::format(const std::string& text) const
    {
        std::string formatted_text = text;
        for (char& c : formatted_text)
        {
            c = std::tolower(static_cast<unsigned char>(c)); // Ensure proper handling of non-ASCII characters
        }
        return formatted_text;
    }
}
