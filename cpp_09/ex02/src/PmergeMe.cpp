#include "PmergeMe.hpp"

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
        std::vector<unsigned int> &sequence,
        std::deque<unsigned int> &sequenceDeq)
{
    _vector.clear();
    _deque.clear();

    for (int i = 1; i < argc; ++i)
    {
        std::string_view sv(argv[i]);

        unsigned int value{};
        // from_chars return pointer and error
        auto [ptr, errorcode] =
            std::from_chars(sv.data(), sv.data() + sv.size(), value);

        if (errorcode != std::errc{} || ptr != sv.data() + sv.size())
        {
            return false;
        }
        sequence.emplace_back(value);
        sequenceDeq.emplace_back(value);
    }
    return true;
}

    std::vector<std::pair<unsigned int, unsigned int>>
PmergeMe::pairsSwap(std::vector<unsigned int> &vector)
{
    DBG(printContainer(vector));
    std::vector<std::pair<unsigned int, unsigned int>> pairs;
    for (size_t i = 0; i + 1 < vector.size(); i += 2)
    {
        if (vector[i] < vector[i + 1])
            pairs.emplace_back(vector[i + 1], vector[i]);
        else
            pairs.emplace_back(vector[i], vector[i + 1]);
    }
    DBG(printPairs(pairs));
    return pairs;
}

    std::vector<unsigned int>
PmergeMe::fordJohnson(std::vector<unsigned int> &vector)
{
    DBG(std::cout << RED << "\n--- Starting Vector ---" << RESET << std::endl);

    if (vector.size() <= 1)
        return vector;

    bool isOdd = vector.size() % 2;
    unsigned int odd = 0;

    if (isOdd)
    {
        odd = vector.back();
        vector.pop_back();
    }

    std::vector<std::pair<unsigned int, unsigned int>> pairs;

    pairs = pairsSwap(vector);

    std::vector<unsigned int> mainChain;
    std::vector<Pending> pending;

    // Separate winners and losers
    for (size_t i = 0; i < pairs.size(); i++) 
    {
        mainChain.emplace_back(pairs[i].first);
        pending.push_back({pairs[i].second, pairs[i].first});
    }

    // Recursively sort winners
    mainChain = fordJohnson(mainChain);
    DBG(std::cout << "mainChain: "; printContainer(mainChain););
    DBG(std::cout << "pending: "; printContainer(pending););

    // Insert losers
    std::vector<size_t> order = generateJacobsthal(pending.size());

    for (size_t index : order)
    {
        unsigned int value = pending[index].value;
        unsigned int limitValue = pending[index].limit;

        size_t limit = 0;

        for (size_t i = 0; i < mainChain.size(); i++)
        {
            if (mainChain[i] == limitValue)
            {
                limit = i + 1;
                break;
            }
        }

        binaryInsert(value, mainChain, limit);
        DBG(std::cout << "JacobSthal index[" << index + 1 << "]: ";
                std::cout << RED; std::cout << pending[index].value;
                std::cout << RESET << " -> "; printContainer(mainChain););
    }

    // Insert odd element
    if (isOdd)
    {
        binaryInsert(odd, mainChain, mainChain.size());
        DBG(std::cout << "unpaired: "; std::cout << RED; std::cout << odd;
                std::cout << RESET << " -> "; printContainer(mainChain););
    }

    return mainChain;
}

std::vector<size_t> PmergeMe::generateJacobsthal(size_t size)
{
    std::vector<size_t> insertionOrder;

    if (size == 0)
        return insertionOrder;

    std::vector<size_t> jacobsthal = {0, 1};
    while (jacobsthal.back() < size)
    {
        jacobsthal.emplace_back(jacobsthal.back() +
                2 * jacobsthal[jacobsthal.size() - 2]);
    }
    std::vector<bool> added(size, false);
    insertionOrder.emplace_back(0);
    added[0] = true;

    for (size_t i = 2; i < jacobsthal.size(); i++)
    {
        size_t upper = std::min(jacobsthal[i], size);

        for (size_t j = upper; j > jacobsthal[i - 1]; j--)
        {
            size_t index = j - 1;
            if (!added[index])
            {
                insertionOrder.emplace_back(index);
                added[index] = true;
            }
        }
    }
    for (size_t i = 0; i < size; i++)
    {
        if (!added[i])
            insertionOrder.emplace_back(i);
    }
    return insertionOrder;
}

std::deque<std::pair<unsigned int, unsigned int>>
PmergeMe::pairsSwap(std::deque<unsigned int> &deque)
{
    DBG(printContainer(deque));
    std::deque<std::pair<unsigned int, unsigned int>> pairs;
    for (size_t i = 0; i + 1 < deque.size(); i += 2)
    {
        if (deque[i] < deque[i + 1])
            pairs.emplace_back(deque[i + 1], deque[i]);
        else
            pairs.emplace_back(deque[i], deque[i + 1]);
    }
    DBG(printPairs(pairs));
    return pairs;
}

    std::deque<unsigned int>
PmergeMe::fordJohnson(std::deque<unsigned int> &deque)
{
    DBG(std::cout << RED << "\n--- Starting deque ---" << RESET << std::endl);

    if (deque.size() <= 1)
        return deque;

    bool isOdd = deque.size() % 2;
    unsigned int odd = 0;

    if (isOdd)
    {
        odd = deque.back();
        deque.pop_back();
    }
    std::deque<std::pair<unsigned int, unsigned int>> pairs;

    pairs = pairsSwap(deque);

    std::deque<unsigned int> mainChain;
    std::deque<Pending> pending;

    // Separate winners and losers
    for (size_t i = 0; i < pairs.size(); i++) 
    {
        mainChain.emplace_back(pairs[i].first);
        pending.push_back({pairs[i].second, pairs[i].first});
    }


    mainChain = fordJohnson(mainChain);
    DBG(std::cout << "mainChain: "; printContainer(mainChain););
    DBG(std::cout << "pending: "; printContainer(pending););

    std::vector<size_t> insertionOrder = generateJacobsthal(pending.size());
    for (size_t index : insertionOrder) 
    {
        unsigned int value = pending[index].value;
        unsigned int limitValue = pending[index].limit;

        size_t limit = 0;

        for (size_t i = 0; i < mainChain.size(); i++)
        {
            if (mainChain[i] == limitValue)
            {
                limit = i + 1;
                break;
            }
        }

        binaryInsert(value, mainChain, limit);
        DBG(std::cout << "JacobSthal index[" << index + 1 << "]: ";
                std::cout << RED; std::cout << pending[index].value;
                std::cout << RESET << " -> "; printContainer(mainChain););
    }

    if (isOdd)
    {
        binaryInsert(odd, mainChain, mainChain.size());
        DBG(std::cout << "unpaired: "; std::cout << RED; std::cout << odd;
                std::cout << RESET << " -> "; printContainer(mainChain););
    }

    return mainChain;
}

std::vector<unsigned int> PmergeMe::getVector() { return _vector; }

std::deque<unsigned int> PmergeMe::getDeque() { return _deque; }

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
    std::cout << "Before:\t\t";
    printContainer(sequence);

    std::cout << "After vector:\t";
    printContainer(sortedV);

    std::cout << "After deque:\t";
    printContainer(sortedDq);

    std::cout << "Time to process a range of " << sortedV.size()
        << " with std::vector: " << std::fixed << std::setprecision(5)
        << usVectorTime.count() << " us" << std::endl;
    std::cout << "Time to process a range of " << sortedDq.size()
        << " with std::deque: " << std::fixed << std::setprecision(5)
        << usDequeTime.count() << " us" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Pending& p)
{
    os << "(" << p.value << " -> " << p.limit << ")";
    return os;
}
