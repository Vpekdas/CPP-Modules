#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include "../include/colors.hpp"
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <stack>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    return it;
}
#endif // EASY_FIND_HPP