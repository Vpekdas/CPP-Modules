#include "../include/convertToInt.hpp"

// This function checks if the input string is a valid format for an integer.
// It ensures that the string contains at most one 'f', one operator ('+' or '-'), and one dot ('.').
// It also ensures that the string does not end with a dot.
static bool isValidFormatInt(const std::string &input) {
    const char *str = input.c_str();
    int fNumber = 0;
    int operatorNumber = 0;
    int dotNumber = 0;

    for (int i = 0; i < input.length(); i++) {
        if (std::isalpha(str[i]) && str[i] != 'f') {
            return false;
        } else if (str[i] == 'f') {
            fNumber++;
        } else if (str[i] == '-' || str[i] == '+') {
            operatorNumber++;
        } else if (str[i] == '.') {
            dotNumber++;
        }
    }
    if (fNumber > 1 || operatorNumber > 1 || dotNumber > 1) {
        return false;
    } else if (str[input.length() - 1] == '.') {
        return false;
    }
    return true;
}

static bool containOnlyLetter(const std::string &input) {
    const char *str = input.c_str();
    for (int i = 0; i < input.length(); i++) {
        if (!std::isalpha(str[i])) {
            return false;
        }
    }
    return true;
}

// To accurately detect overflow or underflow, it's essential to ignore leading signs and zeros.
// This ensures that the comparison between the newly formatted string (from stringstream) and the original input is
// valid.
static int skipZeroAndSign(const std::string &input) {
    int index = 0;
    const char *str = input.c_str();

    for (int i = 0; str[i] && (str[i] == '0' || str[i] == '-' || str[i] == '+'); i++) {
        index++;
    }

    return index;
}

void convertToInt(Convertible *convertible, const std::string &input) {
    std::stringstream out;
    std::string tillDot;

    int result = std::atoi(input.c_str());

    // Extract the portion of the input string that represents the integer value to ensure accurate comparison with the
    // formatted result.
    tillDot = input.substr(skipZeroAndSign(input), input.find(".") - skipZeroAndSign(input));

    if (result < 0) {
        tillDot = "-" + tillDot;
    }

    // Convert the integer result to a string using stringstream to facilitate further processing and comparison.
    out << result;

    if (!isValidFormatInt(input) || out.str() != tillDot && !containOnlyLetter(input)) {
        convertible->status = CONVERTIBLE_IMPOSSIBLE;
    } else {
        convertible->status = CONVERTIBLE_DISPLAYABLE;

        // Ensure that the ASCII value of the character is stored when the input is a single letter, for accurate
        // representation.
        if (containOnlyLetter(input)) {
            convertible->value = new int(input.c_str()[0]);
        } else {
            convertible->value = new int(result);
        }
    }
    convertible->type = "int";
}
