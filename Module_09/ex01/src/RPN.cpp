#include "../include/RPN.hpp"
#include "../include/colors.hpp"
#include <climits>
#include <stdexcept>

static bool isOperator(char c);

// https://stackoverflow.com/questions/199333/how-do-i-detect-unsigned-integer-overflow

void RPN::addition(int &topNumber, int &bottomNumber) {
    if ((bottomNumber > 0 && topNumber > INT_MAX - bottomNumber) ||
        (bottomNumber < 0 && topNumber < INT_MIN - bottomNumber)) {
        throw std::overflow_error("❌ Error: Overflow/Underflow occurred during addition.");
    }
    _stack.push(topNumber + bottomNumber);
}

void RPN::subtraction(int &topNumber, int &bottomNumber) {
    if ((bottomNumber < 0 && topNumber > INT_MAX + bottomNumber) ||
        (bottomNumber > 0 && topNumber < INT_MIN + bottomNumber)) {
        throw std::overflow_error("❌ Error: Overflow/Underflow occurred during subtraction.");
    }
    _stack.push(topNumber - bottomNumber);
}

void RPN::multiplication(int &topNumber, int &bottomNumber) {
    // General case
    if (bottomNumber != 0) {
        if ((topNumber > 0 && bottomNumber > 0 && topNumber > INT_MAX / bottomNumber) ||
            (topNumber > 0 && bottomNumber < 0 && bottomNumber < INT_MIN / topNumber) ||
            (topNumber < 0 && bottomNumber > 0 && topNumber < INT_MIN / bottomNumber) ||
            (topNumber < 0 && bottomNumber < 0 && topNumber < INT_MAX / bottomNumber)) {
            throw std::overflow_error("❌ Error: Overflow/Underflow occurred during multiplication.");
        }
    }
    // Special case for two's complement machines
    if ((topNumber == -1 && bottomNumber == INT_MIN) || (bottomNumber == -1 && topNumber == INT_MIN)) {
        throw std::overflow_error("❌ Error: Overflow/Underflow occurred during multiplication.");
    }
    _stack.push(topNumber * bottomNumber);
}

void RPN::division(int &topNumber, int &bottomNumber) {
    if (bottomNumber == 0) {
        throw std::runtime_error("❌ Error: Division by zero is not allowed.");
    }
    _stack.push(topNumber / bottomNumber);
}

static const Operation operations[] = {
    {'+', &RPN::addition}, {'-', &RPN::subtraction}, {'*', &RPN::multiplication}, {'/', &RPN::division}};

RPN::RPN() : _stack() {
    std::cout << YELLOW << "🛠️ Default RPN Constructor called 🛠️" << RESET << std::endl;
}

RPN::~RPN() {
    std::cout << RED << "🧨 RPN Destructor called 🧨" << RESET << std::endl;
}

RPN::RPN(const RPN &other) : _stack(other._stack) {
    std::cout << YELLOW << "🖨️ RPN Copy Constructor called 🖨️" << RESET << std::endl;
}

RPN &RPN::operator=(const RPN &other) {
    // Check for self-assignment
    if (this != &other) {
        _stack = other._stack;
    }
    std::cout << YELLOW << "📞 RPN Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

bool RPN::parseInput(const std::string &input) {
    std::size_t operatorCount = 0;
    std::size_t operandCount = 0;

    for (std::size_t i = 0; i < input.length(); i++) {
        if (std::isdigit(input[i])) {
            operandCount++;
        } else if ((input[i] == '-' || input[i] == '+') && input[i + 1] && std::isdigit(input[i + 1])) {
            operandCount++;
            i++;
        } else if (isOperator(input[i])) {
            operatorCount++;
        } else if (std::isspace(input[i])) {
            continue;
        } else {
            std::cerr << NEON_RED << "❌ Error: The character '" << input[i] << "' is not allowed in the input."
                      << RESET << std::endl;
            return false;
        }
    }

    if (operandCount != (operatorCount + 1)) {
        std::cerr << NEON_RED << "❌ Error: The number of operands should be equal to the number of operators plus one."
                  << RESET << std::endl;
        return false;
    }

    return true;
}

void RPN::popTwoNumberFromStack(int &topNumber, int &bottomNumber) {
    if (_stack.size() < 2) {
        throw std::runtime_error("❌ Error: Stack must contain exactly two elements for this operation.");
    }
    bottomNumber = _stack.top();
    _stack.pop();
    topNumber = _stack.top();
    _stack.pop();
}

void RPN::calculate(const std::string &input) {
    int topNumber = 0;
    int bottomNumber = 0;

    for (std::size_t i = 0; i < input.length(); i++) {
        if (std::isdigit(input[i])) {
            if (input[i - 1] && input[i - 1] == '-') {
                _stack.push(-(input[i] - '0'));
            } else {
                _stack.push((input[i] - '0'));
            }
        } else if (std::isspace(input[i])) {
            continue;
        } else if (isOperator(input[i]) && ((input[i + 1] && input[i + 1] == ' ') || i == input.length() - 1)) {
            popTwoNumberFromStack(topNumber, bottomNumber);
            for (std::size_t indexFunction = 0; indexFunction < NUMBER_OF_OPERATIONS; indexFunction++) {
                if (operations[indexFunction].operation == input[i]) {
                    (this->*operations[indexFunction].function)(topNumber, bottomNumber);
                }
            }
        }
    }
    std::cout << NEON_CYAN << "✅ Calculation complete! The final result is: " << _stack.top() << RESET << std::endl;
}

static bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}