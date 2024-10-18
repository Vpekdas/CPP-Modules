#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "../include/colors.hpp"
#include "iostream"
#include <cstddef>
#include <exception>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

#define MAX_VAL 42
#define NUMBER_OF_TESTS 5

void announcementTitle(const std::string &title);
void announcementMessage(const std::string &message);

void testInt(bool skip);
void testChar(bool skip);
void testString(bool skip);
void testFloat(bool skip);
void testAll(bool skip = true);

void displayPressButton(bool skip);

typedef void (*TestFunction)(bool skip);

struct Test {
    const std::string type;
    TestFunction testFunction;
};

template <class T> class Array {
    public:
    // Default Constructor
    Array() : _size(0), _array(new T[0]) {
        std::cout << YELLOW << "🛠️ Default Array Constructor called. 🛠️" << RESET << std::endl;
    };

    // FIXME: If an unsigned int overflows due to a negative number being passed,
    // it results in an infinite loop of 0s because the value becomes a large positive number.
    // Consider adding a limit to the array size to prevent this issue.

    // Parametrized Constructor
    Array(unsigned int n) : _size(n), _array(new T[n]) {
        for (std::size_t i = 0; i < _size; i++) {
            _array[i] = T();
        }
        std::cout << YELLOW << "🛠️ Parameterized Array Constructor called. 🛠️" << RESET << std::endl;
    };

    // Copy Constructor
    Array(const Array &other) : _size(other._size), _array(new T[_size]) {
        for (std::size_t i = 0; i < _size; i++) {
            _array[i] = other._array[i];
        }
        std::cout << YELLOW << "🖨️ Array Copy Constructor called 🖨️" << RESET << std::endl;
    }

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    Array &operator=(const Array &other) {
        if (this != &other) {
            _size = other._size;
            delete[] _array;
            _array = new T[_size];
            for (std::size_t i = 0; i < _size; i++) {
                _array[i] = other._array[i];
            }
            std::cout << YELLOW << "📞 Array Copy Assignment Operator called 📞" << RESET << std::endl;
        }
        return *this;
    }

    // This operator provides access to the element at the given index in the array.
    // It ensures that the correct element is accessed and throws an exception if the index is out of range.
    // This is necessary to maintain the integrity of the array and avoid accessing invalid memory.
    T &operator[](std::size_t index) {
        if (index >= _size) {
            std::ostringstream oss;
            oss << "Error: Index " << index << " is out of range. Valid range is 0 to " << (_size - 1) << ".";
            throw std::out_of_range(oss.str());
        }
        return _array[index];
    }

    // Default Destructor
    ~Array() {
        delete[] _array;
        std::cout << RED << "🧨 Array Destructor called 🧨" << RESET << std::endl;
    };

    std::size_t size() {
        return _size;
    };

    private:
    std::size_t _size;
    T *_array;
};

#endif // ARRAY_HPP
