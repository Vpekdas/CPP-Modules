#include "../include/VectorMergeInsert.hpp"
#include "../include/colors.hpp"
#include <cstddef>
#include <utility>
#include <vector>

VectorMergeInsert::VectorMergeInsert() : _intVector(), _pairVector(), _mainChain(), _pending() {
    std::cout << YELLOW << "🛠️ Default VectorMergeInsert Constructor called 🛠️" << RESET << std::endl;
}

VectorMergeInsert::~VectorMergeInsert() {
    std::cout << RED << "🧨 VectorMergeInsert Destructor called 🧨" << RESET << std::endl;
}

VectorMergeInsert::VectorMergeInsert(const VectorMergeInsert &other)
    : _intVector(other._intVector), _pairVector(other._pairVector), _mainChain(other._mainChain),
      _pending(other._pending) {
    std::cout << YELLOW << "🖨️ VectorMergeInsert Copy Constructor called 🖨️" << RESET << std::endl;
}

VectorMergeInsert &VectorMergeInsert::operator=(const VectorMergeInsert &other) {
    // Check for self-assignment
    if (this != &other) {
        _intVector = other._intVector;
        _pairVector = other._pairVector;
        _mainChain = other._mainChain;
        _pending = other._pending;
    }
    std::cout << YELLOW << "📞 VectorMergeInsert Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

void VectorMergeInsert::pushIntToVector(std::vector<std::string> input) {
    for (std::size_t i = 0; i < input.size(); i++) {
        _intVector.push_back(std::atoi(input[i].c_str()));
    }

    createPairs();
    sortPairs();
    mergeSort(_pairVector);
    createMainChainAndPending();
}

void VectorMergeInsert::createPairs() {
    for (std::size_t i = 0; i < _intVector.size() - 1; i += 2) {
        _pairVector.push_back(std::make_pair(_intVector[i], _intVector[i + 1]));
    }
}

void VectorMergeInsert::sortPairs() {
    int tmp;

    for (std::size_t i = 0; i < _pairVector.size(); i++) {
        if (_pairVector[i].first > _pairVector[i].second) {
            tmp = _pairVector[i].first;
            _pairVector[i].first = _pairVector[i].second;
            _pairVector[i].second = tmp;
        }
    }
}

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

void VectorMergeInsert::createMainChainAndPending() {
    for (std::size_t i = 0; i < _pairVector.size(); i++) {
        _mainChain.push_back(_pairVector[i].first);
        _pending.push_back(_pairVector[i].second);
    }
}

void VectorMergeInsert::insertSort() {
    
}