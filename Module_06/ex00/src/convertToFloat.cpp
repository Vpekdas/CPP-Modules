#include "../include/convertToFloat.hpp"
#include <cctype>

int countPrecision(const std::string &input) {
    int precision = 0;
    const char *str = input.c_str();
    int index = input.find(".");

    if (index == std::string::npos) {
        return precision;
    } else {
        index++;
    }

    for (; index < input.length(); index++) {
        if (std::isdigit(str[index])) {
            precision++;
        }
    }
    return precision;
}

static bool isValidFormatCharFloat(const std::string &input) {

    return true;
}

void convertToFloat(Convertible *convertible, const std::string &input) {
    std::stringstream out;
    char **ptr = NULL;

    float result = std::strtof(input.c_str(), ptr);

    convertible->type = "float";

    // Use a ternary operator to set the precision to 1 if no digits are found after the decimal point.
    convertible->precision = countPrecision(input) ? countPrecision(input) : 1;

    out << std::fixed << result << 'f';

    if ((out.str() != input || !isValidFormatCharFloat(input))) {
        convertible->status = CONVERTIBLE_IMPOSSIBLE;
    } else {
        convertible->status = CONVERTIBLE_DISPLAYABLE;
        convertible->value = new float(result);
    }
}
