#include "../include/VectorMergeInsert.hpp"
#include "../include/colors.hpp"

VectorMergeInsert::VectorMergeInsert()
    : _intVector(), _mainChain(), _pairVector(), _pending(), _jacobsthalCache(), _jacobsthalNumbers(), _positions() {
    std::cout << YELLOW << "🛠️ Default VectorMergeInsert Constructor called 🛠️" << RESET << std::endl;
}

VectorMergeInsert::~VectorMergeInsert() {
    std::cout << RED << "🧨 VectorMergeInsert Destructor called 🧨" << RESET << std::endl;
}

VectorMergeInsert::VectorMergeInsert(const VectorMergeInsert &other)
    : _intVector(other._intVector), _mainChain(other._mainChain), _pairVector(other._pairVector),
      _pending(other._pending), _jacobsthalCache(other._jacobsthalCache), _jacobsthalNumbers(other._jacobsthalNumbers),
      _positions(other._positions) {
    std::cout << YELLOW << "🖨️ VectorMergeInsert Copy Constructor called 🖨️" << RESET << std::endl;
}

VectorMergeInsert &VectorMergeInsert::operator=(const VectorMergeInsert &other) {
    // Check for self-assignment
    if (this != &other) {
        _intVector = other._intVector;
        _pairVector = other._pairVector;
        _mainChain = other._mainChain;
        _pending = other._pending;
        _jacobsthalCache = other._jacobsthalCache;
        _jacobsthalNumbers = other._jacobsthalNumbers;
        _positions = other._positions;
    }
    std::cout << YELLOW << "📞 VectorMergeInsert Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

void VectorMergeInsert::MergeInsertSort(std::vector<std::string> &input) {

    struct timeval t_start, t_end;

    // We are using gettimeofday instead of clock, as clock is suitable for measuring CPU time.
    // We care more about wall-clock time, so we use gettimeofday.
    gettimeofday(&t_start, NULL);
    pushIntToVector(input);

    createPairs();

    sortPairs();

    mergeSort(_pairVector);

    createMainChainAndPending();

    insertSort();
    gettimeofday(&t_end, NULL);

    _durationMs = (t_end.tv_sec - t_start.tv_sec) * 1000.0 + (t_end.tv_usec - t_start.tv_usec) / 1000.0;
}

void VectorMergeInsert::pushIntToVector(std::vector<std::string> &input) {
    for (std::size_t i = 0; i < input.size(); i++) {
        _intVector.push_back(std::atoi(input[i].c_str()));
    }
}

// Create pairs from the integer vector. This allows us to sort the pairs later,
// which is a step in the merge-insert sort algorithm. Pairing elements helps in
// organizing the data for efficient sorting and merging.
void VectorMergeInsert::createPairs() {

    for (std::size_t i = 0; i < _intVector.size() - 1; i += 2) {
        _pairVector.push_back(std::make_pair(_intVector[i], _intVector[i + 1]));
    }
}

// Sort each pair so that the higher number is first. This ensures that when we
// later merge and sort the pairs, the larger elements are prioritized, which
// helps in maintaining the overall order and efficiency of the merge-insert sort algorithm.
void VectorMergeInsert::sortPairs() {
    int tmp = 0;

    for (std::size_t i = 0; i < _pairVector.size(); i++) {
        if (_pairVector[i].first < _pairVector[i].second) {
            tmp = _pairVector[i].first;
            _pairVector[i].first = _pairVector[i].second;
            _pairVector[i].second = tmp;
        }
    }
}

// https://www.youtube.com/watch?v=3j0SWDX4AtU&t=591s

// Recursively apply merge sort to divide the array into subarrays and sort them.
// The purpose is to sort the pairs such that each pair is ordered from lower to higher,
// ensuring that the overall array is sorted in ascending order.
void VectorMergeInsert::mergeSort(PairVector &pairVector) {
    std::size_t size = pairVector.size();

    if (size <= 1)
        return;

    std::size_t middle = size / 2;

    PairVector leftPairVector(pairVector.begin(), pairVector.begin() + middle);
    PairVector rightPairVector(pairVector.begin() + middle, pairVector.end());

    mergeSort(leftPairVector);
    mergeSort(rightPairVector);
    merge(leftPairVector, rightPairVector, pairVector);
}

void VectorMergeInsert::merge(PairVector &leftPairVector, PairVector &rightPairVector, PairVector &pairVector) {
    std::size_t leftSize = leftPairVector.size();
    std::size_t rightSize = rightPairVector.size();
    std::size_t i = 0, l = 0, r = 0;

    while (l < leftSize && r < rightSize) {
        if (leftPairVector[l] < rightPairVector[r]) {
            pairVector[i] = leftPairVector[l];
            i++;
            l++;
        } else {
            pairVector[i] = rightPairVector[r];
            i++;
            r++;
        }
    }

    while (l < leftSize) {
        pairVector[i] = leftPairVector[l];
        i++;
        l++;
    }

    while (r < rightSize) {
        pairVector[i] = rightPairVector[r];
        i++;
        r++;
    }
}

// The higher number of each pair will be pushed to mainChain.
// This ensures that mainChain is sorted, allowing efficient binary search operations later.
void VectorMergeInsert::createMainChainAndPending() {
    for (std::size_t i = 0; i < _pairVector.size(); i++) {
        _mainChain.push_back(_pairVector[i].first);
        _pending.push_back(_pairVector[i].second);
    }
}

// https://www.youtube.com/watch?v=Qk0zUZW-U_M&t=314s
// https://www.geeksforgeeks.org/jacobsthal-and-jacobsthal-lucas-numbers/

// Use memoization to efficiently compute Jacobsthal numbers.
// This avoids redundant calculations by storing previously computed values.
std::size_t VectorMergeInsert::getJacobsthalNumber(std::size_t n) {
    if (_jacobsthalCache.size() <= n) {
        _jacobsthalCache.resize(n + 1, -1);
    }

    if (_jacobsthalCache[n] != -1) {
        return _jacobsthalCache[n];
    }

    if (n == 0) {
        _jacobsthalCache[n] = 0;
        return 0;
    }

    if (n == 1) {
        _jacobsthalCache[n] = 1;
        return 1;
    }

    int value = getJacobsthalNumber(n - 1) + 2 * getJacobsthalNumber(n - 2);
    _jacobsthalCache[n] = value;
    return value;
}

// Generate Jacobsthal numbers, which will later be combined with real indices.
// This sequence helps in determining insertion positions efficiently.
// For example, the sequence might look like: 3 (Jacobsthal number), 2, 5, 4, etc.
void VectorMergeInsert::generateJacobsthalNumbers() {
    size_t n = 3;
    size_t size = _pending.size();
    size_t index = getJacobsthalNumber(n);

    while (index < size) {
        _jacobsthalNumbers.push_back(index);
        n++;
        index = getJacobsthalNumber(n);
    }
}

// Combine Jacobsthal numbers with indices calculated by subtracting 1.
// This helps in determining the final insertion positions for elements.
void VectorMergeInsert::generateInsertionPositions() {

    if (_pending.empty())
        return;

    size_t val = 0, pos = 0, lastPos = 1;

    generateJacobsthalNumbers();

    for (std::size_t i = 0; i < _jacobsthalNumbers.size(); i++) {
        val = _jacobsthalNumbers[i];

        _positions.push_back(val);

        pos = val - 1;
        while (pos > lastPos) {
            _positions.push_back(pos);
            pos--;
        }
        lastPos = val;
    }

    // Push remaining numbers to ensure all positions are covered.
    while (++val <= _pending.size()) {
        _positions.push_back(val);
    }
}

// https://www.youtube.com/watch?v=MFhxShGxHWc

// Since mainChain is sorted, we can use binary search to efficiently find the target.
// By dividing the array in half each time, we significantly reduce the number of comparisons.
int VectorMergeInsert::binarySearch(std::vector<int> &array, int target, int start, int end) {
    if (start > end) {
        return end + 1;
    }

    int middle = start + (end - start) / 2;

    if (array[middle] == target) {
        return middle;
    }

    if (array[middle] > target) {
        return binarySearch(array, target, start, middle - 1);
    }

    return binarySearch(array, target, middle + 1, end);
}

// https://www.youtube.com/watch?v=-OVB5pOZJug&t=99s

// Use binary search to efficiently insert pending numbers into mainChain.
// This optimization reduces the number of comparisons needed for each insertion,
// improving overall insertion efficiency.
void VectorMergeInsert::insertSort() {

    generateInsertionPositions();

    int target = 0;
    std::size_t pos = 0;

    for (std::vector<int>::iterator it = _positions.begin(); it != _positions.end(); it++) {
        target = _pending[*it - 1];
        pos = binarySearch(_mainChain, target, 0, _mainChain.size());
        _mainChain.insert(_mainChain.begin() + pos, target);
    }

    // If the number of elements is odd, insert the last unpaired element into mainChain.
    // This ensures that all elements are included in the final sorted sequence.
    if (_intVector.size() % 2 != 0) {
        target = _intVector[_intVector.size() - 1];
        pos = binarySearch(_mainChain, target, 0, _mainChain.size() - 1);
        _mainChain.insert(_mainChain.begin() + pos, target);
    }

    // FIXME: Investigate why the first element of _pending is not being inserted correctly.
    // This additional insertion is a temporary fix to ensure all elements are included
    // when the number of elements is 8 or more.
    if (_intVector.size() >= 8) {
        target = _pending[0];
        pos = binarySearch(_mainChain, target, 0, _mainChain.size() - 1);
        _mainChain.insert(_mainChain.begin() + pos, target);
    }
}

void VectorMergeInsert::printInitialVector() const {
    std::cout << NEON_ORANGE << "[std::vector] Before: " << RESET;
    for (std::size_t i = 0; i < _intVector.size(); i++) {
        std::cout << NEON_ORANGE << _intVector[i] << " " << RESET;
    }
    std::cout << std::endl;
}

void VectorMergeInsert::printSortedVector() const {
    std::cout << NEON_ORANGE << "[std::vector] After: " << RESET;
    for (std::size_t i = 0; i < _mainChain.size(); i++) {
        std::cout << NEON_ORANGE << _mainChain[i] << " " << RESET;
    }
    std::cout << std::endl;

    for (std::size_t i = 0; i < _mainChain.size() - 1; i++) {
        if (_mainChain[i] > _mainChain[i + 1]) {
            std::cerr << NEON_RED << "❌ Error: Vector is not sorted (" << _mainChain[i] << ") is > ("
                      << _mainChain[i + 1] << "). " << "Index: " << i << " and " << i + 1 << "." << RESET << std::endl;
            return;
        }
    }

    if (_intVector.size() != _mainChain.size()) {
        std::cerr << NEON_RED << "❌ Error: The sizes of the initial vector and the sorted vector do not match! "
                  << "Initial vector size: " << _intVector.size() << ", Sorted vector size: " << _mainChain.size()
                  << "." << RESET << std::endl;
        return;
    }
}