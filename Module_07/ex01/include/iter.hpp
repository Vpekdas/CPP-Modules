#ifndef ITER_HPP
#define ITER_HPP

#include <iomanip>
#include <iostream>

void testInt();
void testDouble();
void testString();

template <typename T, typename F>
void iter(T *address, int length, void (*function)(F &arg)) {
    for (std::size_t i = 0; i < length; i++) {
        function(address[i]);
    }
}

#endif // ITER_HPP