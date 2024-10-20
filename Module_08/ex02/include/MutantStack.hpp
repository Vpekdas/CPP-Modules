#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <stack>
#include <vector>

template <typename T, class container = std::deque<T> > class MutantStack : public std::stack<T, container> {
    public:
    MutantStack() {
    }
    ~MutantStack() {
    }
    MutantStack(const MutantStack &stack) : std::stack<T, container>(stack) {
        *this = stack;
    }

    typedef typename container::iterator iterator;
    iterator begin() {
        return this->c.begin();
    }
    iterator end() {
        return this->c.end();
    }
};

#endif // MUTANT_STACK_HPP