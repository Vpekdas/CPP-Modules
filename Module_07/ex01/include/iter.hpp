#ifndef ITER_HPP
#define ITER_HPP

#include <iomanip>
#include <iostream>

void testInt();
void testDouble();
void testString();

template <typename T> void iter(T *address, int length, void (*function)(T &arg)) {
    for (int i = 0; i < length; i++) {
        function(address[i]);
    }
}

#endif // ITER_HPP