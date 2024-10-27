#ifndef VECTOR_MERGE_INSERT_HPP
#define VECTOR_MERGE_INSERT_HPP

#include <cstddef>
#include <iostream>
#include <iterator>
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

    void MergeInsertSort(std::vector<std::string> &input);

    void printInitialVector();
    void printSortedVector();

    private:
    typedef std::vector<std::pair<int, int> > PairVector;

    void pushIntToVector(std::vector<std::string> &input);

    void createPairs();
    void sortPairs();

    void mergeSort(PairVector &pairVector);
    void merge(PairVector &leftPairVector, PairVector &rightPairVector, PairVector &pairVector);

    void createMainChainAndPending();

    std::size_t getJacobsthalNumber(std::size_t n);
    void generateJacobsthalNumbers();
    void generateInsertionPositions();

    int binarySearch(std::vector<int> &array, int target, int start, int end);

    void insertSort();

    void MergeInsertSort();

    std::vector<int> _intVector;
    std::vector<std::pair<int, int> > _pairVector;
    std::vector<int> _mainChain;
    std::vector<int> _pending;
    std::vector<int> _jacobsthalNumbers;
    std::vector<int> _jacobsthalCache;
    std::vector<int> _positions;
};

#endif // VECTOR_MERGE_INSERT_HPP
