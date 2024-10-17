#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "../include/colors.hpp"
#include <cstddef>
#include <exception>
#include <iostream>

template <class T> class Array {
    public:
    Array() : _array(new T[0]), _size(0){};

    Array(unsigned int n) : _array(new T[n]), _size(n) {
        for (std::size_t i = 0; i < _size; i++) {
            _array[i] = 0;
        }
    };

    int size() {
        return _size;
    };

    int &operator[](std::size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Out of bound.");
        }
        return _array[index];
    };

    ~Array() {
        delete[] _array;
    };

    private:
    T *_array;
    std::size_t _size;
};

#endif // ARRAY_HPP