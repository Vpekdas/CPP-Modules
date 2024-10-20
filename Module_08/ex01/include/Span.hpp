#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

class Span {
    public:
    // Default constructor
    Span();

    // Parameterized constructor
    Span(unsigned int n);

    // Copy Constructor
    Span(const Span &other);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    Span &operator=(const Span &other);

    // Default Destructor
    ~Span();

    void addNumber(int number);
    void addMultipleNumber(std::vector<int>::iterator first, std::vector<int>::iterator last);
    long shortestSpan();
    long longestSpan();
    void displayNumber() const;

    private:
    unsigned int _maxSize;
    unsigned int _currentSize;
    std::vector<int> _vec;
};

#endif // SPAN_HPP