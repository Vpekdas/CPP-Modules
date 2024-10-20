#include "../include/Span.hpp"
#include "../include/colors.hpp"
#include <algorithm>
#include <climits>
#include <exception>
#include <iterator>
#include <stdexcept>
#include <vector>

Span::Span() : _maxSize(0), _currentSize(0) {
    std::cout << YELLOW << "🛠️ Default Span Constructor called 🛠️" << RESET << std::endl;
}

Span::Span(unsigned int n) : _maxSize(n), _currentSize(0) {
    std::cout << YELLOW << "🛠️ Default Span Constructor called 🛠️" << RESET << std::endl;
}

Span::~Span() {
    std::cout << RED << "🧨 Span Destructor called 🧨" << RESET << std::endl;
}

Span::Span(const Span &other) : _maxSize(other._maxSize), _vec(other._vec) {
    std::cout << YELLOW << "🖨️ Span Copy Constructor called 🖨️" << RESET << std::endl;
}

Span &Span::operator=(const Span &other) {
    // Check for self-assignment
    if (this != &other) {
        _maxSize = other._maxSize;
        _currentSize = other._currentSize;
        _vec = other._vec;
    }
    std::cout << YELLOW << "📞 Span Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

void Span::addNumber(int number) {
    if (_currentSize >= _maxSize) {
        throw std::length_error("Error: You cannot add more numbers.");
    }
    _vec.push_back(number);
    _currentSize++;
}

long Span::shortestSpan() {

    if (_vec.empty() || _vec.size() == 1) {
        throw std::range_error("Error: Cannot find the shortest span. The container must have at least two elements.");
    }
    std::vector<int>::iterator first = _vec.begin();
    std::vector<int>::iterator second = _vec.begin() + 1;
    std::vector<int>::iterator last = _vec.end();

    std::sort(first, last);

    long span = LONG_MAX;

    int firstLowestNumber = 0;
    int secondLowestNumber = 0;

    for (; second != last; ++first, ++second) {
        if (*second - *first < span) {
            span = *second - *first;
            firstLowestNumber = *first;
            secondLowestNumber = *second;
        }
    }

    if (span == LONG_MAX) {
        throw std::range_error("Error: No valid span found. Ensure the container has distinct elements.");
    }

    std::cout << BOLD_ITALIC_ORANGE << "Shortest span is " << span << " between (" << firstLowestNumber << ") and ("
              << secondLowestNumber << ")" << RESET << std::endl;
    return span;
}

long Span::longestSpan() {
    if (_vec.empty() || _vec.size() == 1) {
        throw std::range_error("Error: Cannot find the longest span. The container must have at least two elements.");
    }
    std::vector<int>::iterator first = _vec.begin();
    std::vector<int>::iterator last = _vec.end();

    std::sort(first, last);

    --last;

    long span = *last - *first;

    std::cout << BOLD_ITALIC_BLUE << "Longest span is " << span << " between (" << *last << ") and (" << *first << ")"
              << RESET << std::endl;
    return span;
}

void Span::addMultipleNumber(std::vector<int>::iterator first, std::vector<int>::iterator last) {

    std::size_t numElementsToAdd = std::distance(first, last);

    if (numElementsToAdd > _maxSize) {
        throw std::length_error("Error: Adding these elements would exceed the maximum capacity of the Span.");
    }
    std::vector<int>::iterator position = _vec.begin();

    _vec.insert(position, first, last);

    _currentSize = std::distance(first, last);
}

void Span::displayNumber() const {
    std::cout << NEON_CYAN << "[Span]: " << RESET;
    for (std::vector<int>::const_iterator it = _vec.begin(); it != _vec.end(); it++) {
        std::cout << NEON_CYAN << *it << " " << RESET;
    }
    std::cout << std::endl;
}