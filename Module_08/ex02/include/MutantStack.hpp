#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include "../include/colors.hpp"
#include <deque>
#include <iostream>
#include <stack>

// Using std::deque as the underlying container while providing stack operations :).
template <typename T, class container = std::deque<T> >
class MutantStack : public std::stack<T, container> {
    public:
    // Default constructor
    MutantStack() : std::stack<T, container>() {
        std::cout << YELLOW << "🛠️ Default MutantStack Constructor called 🛠️" << RESET << std::endl;
    }

    // Copy Constructor
    MutantStack(const MutantStack &other) : std::stack<T, container>(other) {
        std::cout << YELLOW << "🖨️ MutantStack Copy Constructor called 🖨️" << RESET << std::endl;
    }

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    MutantStack &operator=(const MutantStack &other) {
        if (this != &other) {
            std::stack<T, container>::operator=(other);
        }
        std::cout << YELLOW << "📞 MutantStack Copy Assignment Operator called 📞" << RESET << std::endl;
        return *this;
    }

    // Default Destructor
    ~MutantStack() {
        std::cout << RED << "🧨 MutantStack Destructor called 🧨" << RESET << std::endl;
    }

    // Typedef to simplify the use of iterator types from the underlying container.
    typedef typename container::iterator iterator;
    typedef typename container::const_iterator const_iterator;
    typedef typename container::reverse_iterator reverse_iterator;
    typedef typename container::const_reverse_iterator const_reverse_iterator;

    iterator begin() {
        return this->c.begin();
    }
    iterator end() {
        return this->c.end();
    }
    const_iterator begin() const {
        return this->c.begin();
    }
    const_iterator end() const {
        return this->c.end();
    }
    reverse_iterator rbegin() {
        return this->c.rbegin();
    }
    reverse_iterator rend() {
        return this->c.rend();
    }
    const_reverse_iterator rbegin() const {
        return this->c.rbegin();
    }
    const_reverse_iterator rend() const {
        return this->c.rend();
    }
};

#endif // MUTANT_STACK_HPP
