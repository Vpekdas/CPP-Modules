#include "../include/RPN.hpp"
#include "../include/colors.hpp"
#include <climits>

static bool isOperator(char c);

// https://stackoverflow.com/questions/199333/how-do-i-detect-unsigned-integer-overflow

void RPN::addition(int &topNumber, int &bottomNumber) {
    if ((bottomNumber > 0 && topNumber > INT_MAX - bottomNumber) ||
        (bottomNumber < 0 && topNumber < INT_MIN - bottomNumber)) {
        throw std::runtime_error("❌ Error: Overflow/Underflow occurred during addition.");
    }
    _stack.push(topNumber + bottomNumber);
}

void RPN::subtraction(int &topNumber, int &bottomNumber) {
    if ((bottomNumber < 0 && topNumber > INT_MAX + bottomNumber) ||
        (bottomNumber > 0 && topNumber < INT_MIN + bottomNumber)) {
        throw std::runtime_error("❌ Error: Overflow/Underflow occurred during subtraction.");
    }
    _stack.push(topNumber - bottomNumber);
}

void RPN::multiplication(int &topNumber, int &bottomNumber) {
    // general case
    if ((bottomNumber != 0 && topNumber > INT_MAX / bottomNumber) ||
        (bottomNumber != 0 && topNumber < INT_MIN / bottomNumber)) {
        throw std::runtime_error("❌ Error: Overflow/Underflow occurred during multiplication.");
    }
    // There may be a need to check for -1 for two's complement machines.
    // If one number is -1 and another is INT_MIN, multiplying them we get abs(INT_MIN) which is 1 higher than
    // INT_MAX
    else if ((topNumber == -1 && bottomNumber == INT_MIN) || (bottomNumber == -1 && topNumber == INT_MIN)) {
        throw std::runtime_error("❌ Error: Overflow/Underflow occurred during multiplication.");
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
        if (isOperator(input[i])) {
            operatorCount++;
        } else if (std::isdigit(input[i])) {
            operandCount++;
        } else if (std::isspace(input[i])) {
            continue;
        } else {
            std::cout << NEON_RED << "❌ Error: The character '" << input[i] << "' is not allowed in the input."
                      << RESET << std::endl;
            return false;
        }
    }

    if (operandCount != (operatorCount + 1)) {
        std::cout << NEON_RED << "❌ Error: The number of operands should be equal to the number of operators plus one."
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
            _stack.push((input[i] - '0'));
        } else if (std::isspace(input[i])) {
            continue;
        } else if (isOperator(input[i])) {
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