#ifndef DEQUE_MERGE_INSERT_HPP
#define DEQUE_MERGE_INSERT_HPP

#include <cstddef>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sys/time.h>

class DequeMergeInsert {
    public:
    // Default constructor
    DequeMergeInsert();

    // Copy Constructor
    DequeMergeInsert(const DequeMergeInsert &other);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    DequeMergeInsert &operator=(const DequeMergeInsert &other);

    // Default Destructor
    ~DequeMergeInsert();

    void MergeInsertSort(std::vector<std::string> &input);

    void printInitialDeque() const;
    void printSortedDeque() const;

    std::deque<int> _intDeque;
    std::deque<int> _mainChain;

    double _durationMs;

    private:
    typedef std::deque<std::pair<int, int> > PairDeque;

    void pushIntToDeque(std::vector<std::string> &input);

    void createPairs();
    void sortPairs();

    void mergeSort(PairDeque &pairDeque);
    void merge(PairDeque &leftPairDeque, PairDeque &rightPairDeque, PairDeque &pairDeque);

    void createMainChainAndPending();

    std::size_t getJacobsthalNumber(std::size_t n);
    void generateJacobsthalNumbers();
    void generateInsertionPositions();

    int binarySearch(std::deque<int> &array, int target, int start, int end);

    void insertSort();

    void MergeInsertSort();

    std::deque<std::pair<int, int> > _pairDeque;
    std::deque<int> _pending;
    std::deque<int> _jacobsthalCache;
    std::deque<int> _jacobsthalNumbers;
    std::deque<int> _positions;
};

#endif // DEQUE_MERGE_INSERT_HPP
