#ifndef VECTOR_MERGE_INSERT_HPP
#define VECTOR_MERGE_INSERT_HPP

#include <iostream>
#include <vector>

class VectorMergeInsert {
    public:
    // Default constructor
    VectorMergeInsert();

    // Copy Constructor
    VectorMergeInsert(const VectorMergeInsert &other);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    VectorMergeInsert &operator=(const VectorMergeInsert &other);

    // Default Destructor
    ~VectorMergeInsert();

    void pushIntToVector(std::vector<std::string> input);
    void createPairs();
    void sortPairs();

    typedef std::vector<std::pair<int, int> > PairVector;

    void mergeSort(PairVector &pairVector);
    void merge(PairVector &leftPairVector, PairVector &rightPairVector, PairVector &pairVector);
    void createMainChainAndPending();
    void insertSort();

    private:
    std::vector<int> _intVector;
    PairVector _pairVector;
    std::vector<int> _mainChain;
    std::vector<int> _pending;
};

#endif // VECTOR_MERGE_INSERT_HPP