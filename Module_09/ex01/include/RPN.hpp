#ifndef RPN_HPP
#define RPN_HPP

#include <cctype>
#include <cstddef>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>

#define NUMBER_OF_OPERATIONS 4

struct Operation;

class RPN {
    public:
    // Default constructor
    RPN();

    // Copy Constructor
    RPN(const RPN &other);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    RPN &operator=(const RPN &other);

    // Default Destructor
    ~RPN();

    bool parseInput(const std::string &input);
    void calculate(const std::string &input);
    void popTwoNumberFromStack(int &topNumber, int &bottomNumber);

    void addition(int &topNumber, int &bottomNumber);
    void subtraction(int &topNumber, int &bottomNumber);
    void multiplication(int &topNumber, int &bottomNumber);
    void division(int &topNumber, int &bottomNumber);

    private:
    std::stack<int> _stack;
};

struct Operation {
    char operation;
    void (RPN::*function)(int &topNumber, int &bottomNumber);
};

#endif // RPN_HPP