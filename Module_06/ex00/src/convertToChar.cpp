#include "../include/convertToChar.hpp"

// This function returns the index of the first non-digit character in the input string.
// It is used to verify that the input string contains only digit characters before converting it to an integer using
// std::atoi. This check is important to detect overflow or underflow conditions by comparing the original input string
// with the converted result. If the input string contains non-digit characters, the conversion may be incorrect, so
// this function helps ensure the integrity of the conversion process.
static unsigned long findNotADigitIndex(const char *str, int length) {
    for (int i = 0; i < length; i++) {
        if (!std::isdigit(str[i]))
            return i;
    }
    return std::string::npos;
}

// Convert the input string to a char and update the Convertible status accordingly.
// This function checks for overflow, underflow, and non-displayable characters to ensure a valid conversion.
void convertToChar(Convertible *convertible, const std::string &input) {
    std::string stringFromNumber;
    std::stringstream out;
    std::string onlyDigitInput;

    int result = std::atoi(input.c_str());
    unsigned long index = findNotADigitIndex(input.c_str(), input.length());

    // If the input string contains only digits, use the entire string for comparison.
    // This ensures that the conversion process accurately reflects the original input.
    if (index != std::string::npos)
        onlyDigitInput = input.substr(0, index);
    else {
        onlyDigitInput = input;
    }

    // Use std::stringstream to convert the integer to a string because itoa is not part of the standard library.
    out << result;
    stringFromNumber = out.str();

    // Check for overflow/underflow and not displayable.
    if (stringFromNumber != onlyDigitInput || result < 0 || result > 127) {
        convertible->status = CONVERTIBLE_IMPOSSIBLE;
    } else if (!std::isprint(result)) {
        convertible->status = CONVERTIBLE_NON_DISPLAYABLE;
    } else {
        convertible->status = CONVERTIBLE_DISPLAYABLE;
        convertible->value = new char(result);
    }
}
