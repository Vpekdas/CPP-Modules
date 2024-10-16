#include "../include/convertToFloat.hpp"
#include <cmath>
#include <limits>
#include <math.h>

int countPrecision(const std::string &input) {
    int precision = 0;
    const char *str = input.c_str();
    std::size_t index = input.find(".");

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

void convertToFloat(Convertible *convertible, const std::string &input) {
    std::stringstream out;

    convertible->type = "float";

    float result = std::strtof(input.c_str(), NULL);
    char c = input.c_str()[skipZeroAndSign(input)];

    // Use a ternary operator to set the precision to 1 if no digits are found after the decimal point.
    convertible->precision = countPrecision(input) ? countPrecision(input) : 1;

    out << std::fixed << std::setprecision(convertible->precision) << result << 'f';

    if (isinf(result)) {
        convertible->status = CONVERTIBLE_DISPLAYABLE;
        convertible->value = new float(result);
        return;
    }

    else if (std::isnan(result)) {
        convertible->status = CONVERTIBLE_DISPLAYABLE;
        convertible->value = new float(NAN);
        return;
    }

    if ((result != 0.0f && std::fabs(result) < std::numeric_limits<float>::min()) ||
        (result != 0.0f && std::fabs(result) > std::numeric_limits<float>::max()) || !isValidFormat(input)) {
        convertible->status = CONVERTIBLE_IMPOSSIBLE;
    } else if (isContainingDigit(input)) {
        convertible->status = CONVERTIBLE_DISPLAYABLE;
        convertible->value = new float(result);
    } else {
        convertible->status = CONVERTIBLE_DISPLAYABLE;
        convertible->value = new float(c);
    }
}
