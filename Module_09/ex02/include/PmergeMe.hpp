#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

#include "VectorMergeInsert.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>

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

    void mergeInsertSort(int ac, char **av);

    private:
    void parseInput(int ac, char **av);
    void validateOverflow();
    void validateDuplicate();

    std::vector<std::string> _inputStringVector;
    VectorMergeInsert _vectorMergeInsert;
};

#endif // P_MERGE_ME_HPP