#pragma once

#include <string>

namespace design_patterns
{
    /*
     * This class represents a text formatter implementing the strategy pattern. The strategy pattern allows defining a
     * family of algorithms, encapsulating each one, and making them interchangeable.
     *
     * In this class, the strategy pattern is implemented by having a virtual process method, which is overridden by
     * subclasses to provide different formatting strategies. Subclasses, such as UppercaseFormatter and
     * LowercaseFormatter, inherit from this class and provide specific formatting implementations.
     *
     * The TextProcessor class uses a pointer to a TextFormatter object, allowing it to switch between different
     * formatting strategies dynamically.
     *
     * Benefits of the strategy pattern include improved code organization, flexibility to switch algorithms at runtime,
     * and easier maintenance and testing.
     *
     * This pattern is suitable when there are multiple related algorithms that can be encapsulated, when different
     * variants of an algorithm are required, and when the algorithm needs to be selected or changed dynamically.
     */
    class TextFormatter
    {
    public:
        // Virtual method to format text, to be overridden by subclasses
        virtual std::string format(const std::string& text) const = 0;
        // Virtual destructor to ensure proper cleanup of derived classes
        virtual ~TextFormatter() = default;
    };

    // Concrete Strategy: Uppercase Formatting
    class UppercaseFormatter : public TextFormatter
    {
    public:
        std::string format(const std::string& text) const override;
    };

    // Concrete Strategy: Lowercase Formatting
    class LowercaseFormatter : public TextFormatter
    {
    public:
        std::string format(const std::string& text) const override;
    };
}
