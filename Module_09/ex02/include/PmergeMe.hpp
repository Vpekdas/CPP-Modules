#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

#include <cstddef>
#include <deque>
#include <iostream>
#include <vector>

// The exact threshold must be determined experimentally and depends on the machine, but is commonly around ten.
// https://en.wikipedia.org/wiki/Insertion_sort
#define INSERTION_SORT_THRESHOLD 10

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

    void insertionSortVector(std::vector<int> &vector, std::size_t left, std::size_t right);
    void mergeSortVector(std::vector<int> &vector, std::size_t left, std::size_t right);
    void mergeVector(std::vector<int> &vector, std::size_t left, std::size_t middle, std::size_t right);

    private:
};

#endif // P_MERGE_ME_HPP