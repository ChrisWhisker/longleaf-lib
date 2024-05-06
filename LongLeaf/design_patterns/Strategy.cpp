#include "Strategy.h"
#include <cctype>
#include <iostream>

namespace design_patterns
{
    // Implementation of UppercaseFormatter::format
    std::string UppercaseFormatter::format(const std::string& text) const
    {
        std::string formatted_text = text;
        for (char& c : formatted_text)
        {
            c = static_cast<char>(std::toupper(c)); // Ensure proper handling of non-ASCII characters
        }
        return formatted_text;
    }

    // Implementation of LowercaseFormatter::format
    std::string LowercaseFormatter::format(const std::string& text) const
    {
        std::string formatted_text = text;
        for (char& c : formatted_text)
        {
            c = static_cast<char>(std::tolower(c)); // Ensure proper handling of non-ASCII characters
        }
        return formatted_text;
    }
}
