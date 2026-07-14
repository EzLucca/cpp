#pragma once

#include <iostream>
#include <charconv>
#include <string_view>

#include <deque>
#include <vector>
#include <chrono>
#include <algorithm>
#include <iomanip>

class PmergeMe
{
    private:
        std::deque<unsigned int> _deque;
        std::vector<unsigned int> _vector;

        std::vector<unsigned int> fordJohnson(std::vector<unsigned int>& vector);
        std::deque<unsigned int> fordJohnson(std::deque<unsigned int>& deque);
    public:
        std::chrono::nanoseconds sortVector(std::vector<unsigned int>& input);
        std::chrono::nanoseconds sortDeque(std::deque<unsigned int>& input);

        bool isPositiveInteger(int argc, char** argv,
                std::vector<unsigned int>& sequence,
                std::deque<unsigned int>& sequenceDeq);
        void    printResults(std::vector<unsigned int> sequence,
                std::chrono::nanoseconds timeVec,
                std::chrono::nanoseconds timeDeq);
        std::vector<std::pair<unsigned int, unsigned int>>  pairsSwap(std::vector<unsigned int>& vector);

        std::vector<std::pair<unsigned int, unsigned int>>  sortPairs(std::vector<std::pair<unsigned int, unsigned int>> sortedPairs);
        std::vector<unsigned int> getVector();
        std::deque<unsigned int> getDeque();
        template <typename Container>
            static void binaryInsert(int value, Container& container);

        template <typename Container>
            static void binaryInsertPairs(const std::pair<int, int>& pair,
                    Container& container);
};

template <typename Container>
void PmergeMe::binaryInsert(int value, Container& container)
{
    typename Container::iterator pos =
        std::upper_bound(container.begin(), container.end(), value);
    container.insert(pos, value);
}

struct ComparePairs
{
    bool operator()(const std::pair<int, int>& a,
                    const std::pair<int, int>& b) const
    {
        return a.first < b.first;
    }
};

template <typename Container>
void PmergeMe::binaryInsertPairs(const std::pair<int, int>& pair,
                                 Container& container)
{
    typename Container::iterator pos =
        std::upper_bound(container.begin(), container.end(), pair, ComparePairs());
    container.insert(pos, pair);
}
