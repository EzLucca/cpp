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

#define RESET   "\033[0m"
#define RED     "\033[31m"

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

        bool isUnsignedInteger(int argc, char** argv,
                std::vector<unsigned int>& sequence,
                std::deque<unsigned int>& sequenceDeq);
        void    printResults(std::vector<unsigned int> sequence,
                std::chrono::nanoseconds timeVec,
                std::chrono::nanoseconds timeDeq);

        std::vector<std::pair<unsigned int, unsigned int>>  pairsSwap(std::vector<unsigned int>& vector);
        std::deque<std::pair<unsigned int, unsigned int>>   pairsSwap(std::deque<unsigned int>& deque);

        std::vector<unsigned int> getVector();
        std::deque<unsigned int> getDeque();
        std::vector<size_t> generateJacobsthal(size_t size);

        template <typename Container>
            size_t binaryInsert( typename Container::value_type value, Container& container,
                    size_t limit);

        template <typename Container>
            void printPairs(const Container& pairs);

        template <typename Container>
            void printContainer(const Container& container);

};

struct Pending
{
    unsigned int value;  // b_i
    unsigned int limit;  // a_i value
};

std::ostream& operator<<(std::ostream& os, const Pending& p);

#include "PmergeMe.tpp"
