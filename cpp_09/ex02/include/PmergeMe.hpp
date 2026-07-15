#pragma once

#include <iostream>
#include <charconv>
#include <string_view>

#include <deque>
#include <vector>
#include <chrono>
#include <algorithm>
#include <iomanip>

#ifdef DEBUG
#define DBG(x) do { x; } while (0)
#else
#define DBG(x) do {} while (0)
#endif

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

        std::deque<std::pair<unsigned int, unsigned int>>   pairsSwap(std::deque<unsigned int>& deque);
        std::deque<std::pair<unsigned int, unsigned int>>   sortPairs(std::deque<std::pair<unsigned int, unsigned int>> pairs);

        std::vector<unsigned int> getVector();
        std::deque<unsigned int> getDeque();
        std::vector<size_t> generateJacobsthal(size_t size);

        template <typename Container>
            static void binaryInsert(typename Container::value_type value, Container& container);

        template <typename Container>
            static void binaryInsertPairs( const typename Container::value_type& pair,
                    Container& container);

        template <typename Container>
            void printPairs(const Container& pairs);

        template <typename Container>
            void printContainer(const Container& container);
};

#include "PmergeMe.tpp"
