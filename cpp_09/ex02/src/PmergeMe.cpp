#include "PmergeMe.hpp"

void PmergeMe::printPair(const std::pair<unsigned int, unsigned int>& p)
{
    std::cout << "(" << p.first << ", " << p.second << ")";
}

    std::chrono::nanoseconds
PmergeMe::sortVector(std::vector<unsigned int> &input)
{
    _vector = input;
    auto start = std::chrono::steady_clock::now();
    _vector = fordJohnson(_vector);
    auto stop = std::chrono::steady_clock::now();
    return stop - start;
}

std::chrono::nanoseconds PmergeMe::sortDeque(std::deque<unsigned int> &input)
{
    _deque = input;
    auto start = std::chrono::steady_clock::now();
    _deque = fordJohnson(_deque);
    auto stop = std::chrono::steady_clock::now();
    return stop - start;
}

bool PmergeMe::isPositiveInteger(int argc, char **argv,
        std::vector<unsigned int>& sequence,
        std::deque<unsigned int>& sequenceDeq)
{
    _vector.clear();
    _deque.clear();

    for (int i = 1; i < argc; ++i)
    {
        std::string_view sv(argv[i]);

        unsigned int value{};
        // from_chars return pointer and error
        auto [ptr, errorcode] = std::from_chars(sv.data(), sv.data() + sv.size(), value);

        if (errorcode != std::errc{} || ptr != sv.data() + sv.size()) {
            return false;
        }
        sequence.push_back(value);
        sequenceDeq.push_back(value);
    }
    return true;
}

std::vector<std::pair<unsigned int, unsigned int>>   PmergeMe::pairsSwap(std::vector<unsigned int>& vector)
{
    DBG(printContainer(vector));
    std::vector<std::pair<unsigned int, unsigned int>> pairs;
    for (size_t i = 0; i + 1 < vector.size(); i += 2){
        if (vector[i] < vector[i + 1]){
            pairs.push_back({vector[i + 1], vector[i]});
        } else {
            pairs.push_back({vector[i], vector[i + 1]});
        }
    }
    DBG(printPairs(pairs));
    return pairs;
}

std::vector<std::pair<unsigned int, unsigned int>> 
PmergeMe::sortPairs(const std::vector<std::pair<unsigned int, unsigned int>>& pairs)
{
    if (pairs.size() <= 1)
        return pairs;

    std::vector<std::pair<unsigned int, unsigned int>> winners;
    std::vector<std::pair<unsigned int, unsigned int>> losers;

    size_t size = pairs.size();
    bool isOdd = size % 2;

    std::pair<unsigned int, unsigned int> unpaired;

    if (isOdd)
    {
        unpaired = pairs.back();
        size--;   // ignore last element
    }

    for (size_t i = 0; i < size; i += 2)
    {
        if (pairs[i].first > pairs[i + 1].first)
        {
            winners.push_back(pairs[i]);
            losers.push_back(pairs[i + 1]);
        }
        else
        {
            winners.push_back(pairs[i + 1]);
            losers.push_back(pairs[i]);
        }
    }

    DBG(std::cout << "winners: "; printPairs(winners););
    DBG(std::cout << "losers: "; printPairs(losers););

    winners = sortPairs(winners);

    std::vector<std::pair<unsigned int, unsigned int>> result;
    result.push_back(winners[0]);

    for (size_t i = 1; i < winners.size(); i++)
        result.push_back(winners[i]);

    for (size_t i = 0; i < losers.size(); i++)
    {
        binaryInsertPairs(losers[i], result);
        DBG(std::cout << "inserting " << RED;
                printPair(losers[i]);
                std::cout << RESET << " -> ";
                printPairs(result););
    }	
    if (isOdd)
    {
        binaryInsertPairs(unpaired, result);
        DBG(std::cout << "unpaired " << RED;
                printPair(unpaired);
                std::cout << RESET << " -> ";
                printPairs(result););
    }

    return result;
}

std::vector<unsigned int> PmergeMe::fordJohnson(std::vector<unsigned int>& vector)
{
    if (vector.size() <= 1)
        return vector;

    bool isOdd = vector.size() % 2;
    unsigned int unpaired = 0; 

    if (isOdd)
    {
        unpaired = vector.back();
        vector.pop_back();
    }
    DBG(std::cout << RED << "\n--- Starting Vector ---" << RESET << std::endl);
    std::vector<std::pair<unsigned int, unsigned int>> pairs;
    DBG(std::cout << "Starting to swap inner pairs." << std::endl;);
    pairs = pairsSwap(vector);
    std::vector<std::pair<unsigned int, unsigned int>> sortedPairs;
    DBG(std::cout << "Starting to swap between pairs." << std::endl;);
    sortedPairs = sortPairs(pairs);

    std::vector<unsigned int> result;

    std::vector<unsigned int> mainChain;
    std::vector<unsigned int> pending;
    std::vector<size_t> limits;

    mainChain.push_back(sortedPairs[0].second);
    for (size_t i = 0; i < sortedPairs.size(); i++)
    {
        mainChain.push_back(sortedPairs[i].first);

        if (i > 0)
        {
            pending.push_back(sortedPairs[i].second);
            limits.push_back(i + 1);
        }
    }

    DBG(std::cout << "mainChain: "; printContainer(mainChain););
    DBG(std::cout << "pending: "; printContainer(pending););

    std::vector<size_t> insertionOrder = generateJacobsthal(pending.size());
    for (size_t index : insertionOrder)
    {
        size_t insertedAt = binaryInsert( pending[index], mainChain, limits[index]);

        for (size_t i = 0; i < limits.size(); i++)
        {
            if (i != index && limits[i] >= insertedAt)
                limits[i]++;
        }
        DBG(std::cout << "JacobSthal index[" << index + 1 << "]: ";
                std::cout << RED;
                std::cout << pending[index];
                std::cout << RESET << " -> ";
                printContainer(mainChain););
    }

    if (isOdd)
    {
        binaryInsert( unpaired, mainChain, mainChain.size());
        DBG(std::cout << "unpaired: ";
                std::cout << RED;
                std::cout << unpaired;
                std::cout << RESET << " -> ";
                printContainer(mainChain););
    }
    return mainChain;
}

std::vector<size_t> PmergeMe::generateJacobsthal(size_t size)
{
    std::vector<size_t> insertionOrder;

    if (size == 0)
        return insertionOrder;

    std::vector<size_t> jacobsthal = {0 , 1};
    while (jacobsthal.back() < size)
    {
        jacobsthal.push_back( jacobsthal.back() + 2 * jacobsthal[jacobsthal.size() - 2]);
    }
    std::vector<bool> added(size, false);
    insertionOrder.push_back(0);
    added[0] = true;

    for (size_t i = 2; i < jacobsthal.size(); i++)
    {
        size_t upper = std::min(jacobsthal[i], size);

        for (size_t j = upper; j > jacobsthal[i - 1]; j--)
        {
            size_t index = j - 1;
            if (!added[index])
            {
                insertionOrder.push_back(index);
                added[index] = true;
            }
        }
    }
    for (size_t i = 0; i < size; i++)
    {
        if (!added[i])
            insertionOrder.push_back(i);
    }
    return insertionOrder;
}

std::deque<std::pair<unsigned int, unsigned int>>   PmergeMe::pairsSwap(std::deque<unsigned int>& deque)
{
    DBG(printContainer(deque));
    std::deque<std::pair<unsigned int, unsigned int>> pairs;
    for (size_t i = 0; i + 1 < deque.size(); i += 2){
        if (deque[i] < deque[i + 1]){
            pairs.push_back({deque[i + 1], deque[i]});
        } else {
            pairs.push_back({deque[i], deque[i + 1]});
        }
    }
    DBG(printPairs(pairs));
    return pairs;
}

std::deque<std::pair<unsigned int, unsigned int>> PmergeMe::sortPairs(const std::deque<std::pair<unsigned int, unsigned int>> &pairs)
{
    if (pairs.size() <= 1)
        return pairs;

    std::deque<std::pair<unsigned int, unsigned int>> winners;
    std::deque<std::pair<unsigned int, unsigned int>> losers;

    size_t size = pairs.size();
    bool isOdd = size % 2;
    std::pair<unsigned int, unsigned int>  unpaired; 

    if (isOdd)
    {
        unpaired = pairs.back();
        size--;   // ignore last element
    }
    for (size_t i = 0; i < size; i +=2)
    {
        if (pairs[i].first > pairs[i + 1].first)
        {
            winners.push_back(pairs[i]);
            losers.push_back(pairs[i + 1]);
        }
        else
        {
            winners.push_back(pairs[i + 1]);
            losers.push_back(pairs[i]);
        }
    }	

    DBG(std::cout << "winners: "; printPairs(winners););
    DBG(std::cout << "losers: "; printPairs(losers););

    winners = sortPairs(winners);

    std::deque<std::pair<unsigned int, unsigned int>> result;
    result.push_back(winners[0]);

    for (size_t i = 1; i < winners.size(); i++)
        result.push_back(winners[i]);
    for (size_t i = 0; i < losers.size(); i++)
    {
        binaryInsertPairs(losers[i], result);
        DBG(std::cout << "inserting " << RED;
                printPair(losers[i]);
                std::cout << RESET << " -> ";
                printPairs(result););
    }	
    if (isOdd)
    {
        binaryInsertPairs(unpaired, result);
        DBG(std::cout << "unpaired " << RED;
                printPair(unpaired);
                std::cout << RESET << " -> ";
                printPairs(result););
    }
    return result;
}
std::deque<unsigned int> PmergeMe::fordJohnson(std::deque<unsigned int>& deque)
{
    if (deque.size() <= 1)
        return deque;

    bool isOdd = deque.size() % 2;
    unsigned int unpaired = 0; 

    if (isOdd){
        unpaired = deque.back();
        deque.pop_back();
    }
    DBG(std::cout << RED << "\n--- Starting deque ---" << RESET << std::endl);
    std::deque<std::pair<unsigned int, unsigned int>> pairs;
    DBG(std::cout << "Starting to swap inner pairs." << std::endl;);
    pairs = pairsSwap(deque);
    std::deque<std::pair<unsigned int, unsigned int>> sortedPairs;
    DBG(std::cout << "Starting to swap between pairs." << std::endl;);
    sortedPairs = sortPairs(pairs);

    std::deque<unsigned int> result;

    std::deque<unsigned int> mainChain;
    std::deque<unsigned int> pending;
    std::deque<size_t> limits;

    mainChain.push_back(sortedPairs[0].second);

    for (size_t i = 0; i < sortedPairs.size(); i++)
    {
        mainChain.push_back(sortedPairs[i].first);

        if (i > 0)
        {
            pending.push_back(sortedPairs[i].second);
            limits.push_back(i + 1);
        }
    }

    DBG(std::cout << "mainChain: "; printContainer(mainChain););
    DBG(std::cout << "pending: "; printContainer(pending););

    std::vector<size_t> insertionOrder = generateJacobsthal(pending.size());
    for (size_t index : insertionOrder)
    {
        size_t insertedAt = binaryInsert( pending[index], mainChain, limits[index]);

        for (size_t i = 0; i < limits.size(); i++)
        {
            if (i != index && limits[i] >= insertedAt)
                limits[i]++;
        }
        DBG(std::cout << "JacobSthal index[" << index + 1 << "]: ";
                std::cout << RED;
                std::cout << pending[index];
                std::cout << RESET << " -> ";
                printContainer(mainChain););
    }

    if (isOdd)
    {
        binaryInsert( unpaired, mainChain, mainChain.size());
        DBG(std::cout << "unpaired: ";
                std::cout << RED;
                std::cout << unpaired;
                std::cout << RESET << " -> ";
                printContainer(mainChain););
    }
    return mainChain;
}

std::vector<unsigned int> PmergeMe::getVector()
{
    return _vector;
}

std::deque<unsigned int> PmergeMe::getDeque()
{
    return _deque;
}

void PmergeMe::printResults(std::vector<unsigned int> sequence,
        std::chrono::nanoseconds timeVec,
        std::chrono::nanoseconds timeDeq)
{
    std::chrono::duration<double, std::micro> usVectorTime = timeVec;
    std::chrono::duration<double, std::micro> usDequeTime = timeDeq;
    std::vector<unsigned int> sortedV;
    std::deque<unsigned int> sortedDq;

    sortedV = getVector();
    sortedDq = getDeque();

    std::cout << " --------  -------- " << std::endl;
    std::cout << "Before: ";
    for (auto i : sequence) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    std::cout << "After vector: ";
    for (auto i : sortedV) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    std::cout << "After deque: ";
    for (auto i : sortedDq) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << sortedV.size() << " with "
        << "std::vector: " << std::fixed << std::setprecision(5)
        << usVectorTime.count() << " us" << std::endl;
    std::cout << "Time to process a range of " << sortedDq.size() << " with "
        << "std::deque: " << std::fixed << std::setprecision(5)
        << usDequeTime.count() << " us" << std::endl;
}
