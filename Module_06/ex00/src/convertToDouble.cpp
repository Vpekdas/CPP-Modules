#include "../include/convertToDouble.hpp"

void convertToDouble(Convertible *convertible, const std::string &input) {
    std::stringstream out;

    convertible->type = "double";

    float result = std::strtod(input.c_str(), NULL);
    char c = input.c_str()[skipZeroAndSign(input)];

    // Use a ternary operator to set the precision to 1 if no digits are found after the decimal point.
    convertible->precision = countPrecision(input) ? countPrecision(input) : 1;

    out << std::fixed << std::setprecision(convertible->precision) << result << 'f';

    if (isinf(result) || !isValidFormat(input)) {
        convertible->status = CONVERTIBLE_IMPOSSIBLE;
    } else if (isContainingDigit(input)) {
        convertible->status = CONVERTIBLE_DISPLAYABLE;
        convertible->value = new double(result);
    } else {
        convertible->status = CONVERTIBLE_DISPLAYABLE;
        convertible->value = new double(c);
    }
}
