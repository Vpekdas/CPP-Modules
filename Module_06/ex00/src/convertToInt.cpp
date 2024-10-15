#include "../include/convertToInt.hpp"
#include <cctype>
#include <cstddef>

// To accurately detect overflow or underflow, it's essential to ignore leading signs and zeros.
// This ensures that the comparison between the newly formatted string (from stringstream) and the original input is
// valid.
int skipZeroAndSign(const std::string &input) {

    int index = 0;

    const char *str = input.c_str();

    for (int i = 0; str[i] && (str[i] == '0' || str[i] == '-' || str[i] == '+') && str[i + 1] && str[i + 1] != '.';
         i++) {
        index++;
    }

    return index;
}

void convertToInt(Convertible *convertible, const std::string &input) {
    std::stringstream out;
    std::string tillDot;

    convertible->type = "int";

    int result = std::atoi(input.c_str());
    char c = input.c_str()[skipZeroAndSign(input)];

    // Extract the portion of the input string that represents the integer value to ensure accurate comparison with the
    // formatted result.
    tillDot = input.substr(skipZeroAndSign(input), input.find(".") - skipZeroAndSign(input));

    if (result < 0) {
        tillDot = "-" + tillDot;
    }

    // Convert the integer result to a string using stringstream to facilitate further processing and comparison.
    out << result;

    if (!isValidFormat(input) ||
        (out.str() != tillDot && input.find("f") == std::string::npos && isContainingDigit(tillDot))) {
        convertible->status = CONVERTIBLE_IMPOSSIBLE;
    } else {
        if (isContainingDigit(input)) {
            convertible->status = CONVERTIBLE_DISPLAYABLE;
            convertible->value = new int(result);
        } else {
            convertible->status = CONVERTIBLE_DISPLAYABLE;
            convertible->value = new int(c);
        }
    }
}
