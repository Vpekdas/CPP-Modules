#include "../include/convertToChar.hpp"
#include <cctype>
#include <cstdlib>

bool isContainingDigit(const std::string &input) {
    const char *str = input.c_str();

    for (std::size_t i = 0; i < input.length(); i++) {
        if (std::isdigit(str[i])) {
            return true;
        }
    }
    return false;
}

void convertToChar(Convertible *convertible, const std::string &input) {
    convertible->type = "char";

    std::stringstream out;
    std::string tillDot;

    int result = std::atoi(input.c_str());
    char c = input.c_str()[skipZeroAndSign(input)];

    out << result;

    if (!isValidFormat(input) || result < 0 || result > 127) {
        convertible->status = CONVERTIBLE_IMPOSSIBLE;
    } else if (isContainingDigit(input)) {
        if (!std::isprint(result)) {
            convertible->status = CONVERTIBLE_NON_DISPLAYABLE;
        } else {
            convertible->status = CONVERTIBLE_DISPLAYABLE;
            convertible->value = new char(result);
        }
    } else {
        convertible->status = CONVERTIBLE_DISPLAYABLE;
        convertible->value = new char(c);
    }
}