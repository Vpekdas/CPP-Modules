#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

#include "VectorMergeInsert.hpp"
#include <deque>
#include <iostream>
#include <vector>

class PMergeMe {
    public:
    // Default constructor
    PMergeMe();

    // Copy Constructor
    PMergeMe(const PMergeMe &other);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    PMergeMe &operator=(const PMergeMe &other);

    // Default Destructor
    ~PMergeMe();

    void parseInput(int ac, const char **av);

    private:
    std::vector<std::string> _inputVector;

    VectorMergeInsert _vectorMergeInsert;
};

#endif // P_MERGE_ME_HPP