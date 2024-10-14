#include "../include/convertToChar.hpp"
#include <cctype>

static bool isValidFormatChar(const std::string &input) {

    return true;
}

void convertToChar(Convertible *convertible, const std::string &input) {

    int result = std::atoi(input.c_str());

    if (result < 0 || result > 127 || !isValidFormatChar(input)) {
        convertible->status = CONVERTIBLE_IMPOSSIBLE;
    } else if (!std::isprint(result) && result != 0) {
        convertible->status = CONVERTIBLE_NON_DISPLAYABLE;
    } else {
        convertible->status = CONVERTIBLE_DISPLAYABLE;
        if (result != 0) {
            convertible->value = new char(result);
        } else {
            const char *str = input.c_str();
            if (*str == '0') {
                convertible->status = CONVERTIBLE_NON_DISPLAYABLE;
            } else {
                convertible->value = new char(*str);
            }
        }
    }
    convertible->type = "char";
}
