#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

#include "DequeMergeInsert.hpp"
#include "VectorMergeInsert.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <set>
#include <sstream>
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

    void mergeInsertSort(int ac, char **av);

    void printInitialVector() const;
    void printSortedVector() const;
    void printInitialDeque() const;
    void printSortedDeque() const;

    double _durationMsVector;
    double _durationMsDeque;

    private:
    void parseInput(int ac, char **av);
    void validateOverflow();
    void validateDuplicate();

    std::vector<std::string> _inputStringVector;

    VectorMergeInsert _vectorMergeInsert;
    DequeMergeInsert _dequeMergeInsert;
};

#endif // P_MERGE_ME_HPP