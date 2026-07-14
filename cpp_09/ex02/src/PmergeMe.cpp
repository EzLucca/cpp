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

bool PmergeMe::isPositiveInteger(int argc,
        char **argv,
        std::vector<unsigned int>& sequence,
        std::deque<unsigned int>& sequenceDeq)
{
    _vector.clear();
    _deque.clear();

    for (int i = 1; i < argc; ++i) {
        std::string_view sv(argv[i]);

        unsigned int value{};
        auto [ptr, ec] = std::from_chars(sv.data(), sv.data() + sv.size(), value);

        if (ec != std::errc{} || ptr != sv.data() + sv.size() || value == 0) {
            return false;
        }
        sequence.push_back(value);
        sequenceDeq.push_back(value);
    }
    return true;
}

std::vector<std::pair<unsigned int, unsigned int>>   PmergeMe::pairsSwap(std::vector<unsigned int>& vector)
{
    std::vector<std::pair<unsigned int, unsigned int>> pairs;
    for (size_t i = 0; i < vector.size(); i += 2){
        if (vector[i] < vector[i + 1]){
            pairs.push_back({vector[i + 1], vector[i]});
        } else {
            pairs.push_back({vector[i], vector[i + 1]});
        }
    }
    return pairs;
}

std::vector<std::pair<unsigned int, unsigned int>> PmergeMe::sortPairs(std::vector<std::pair<unsigned int, unsigned int>> pairs)
{
    if (pairs.size() <= 1){
        return pairs;
    }

    bool isOdd = (pairs.size() % 2 != 0);
    std::pair<unsigned int, unsigned int>  unpaired; 

    if (isOdd){
        unpaired = pairs.back();
        pairs.pop_back();
    }

    std::vector<std::pair<unsigned int, unsigned int>> winners;
    std::vector<std::pair<unsigned int, unsigned int>> losers;

    for (size_t i = 0; i < pairs.size(); i +=2){
		if (pairs[i].first < pairs[i + 1].first){
			winners.push_back(pairs[i + 1]);
            losers.push_back(pairs[i]);
		} else {
			winners.push_back(pairs[i]);
			losers.push_back(pairs[i + 1]);
		}
	}	
    std::vector<std::pair<unsigned int, unsigned int>> sortedPairs;
    sortedPairs = sortPairs(pairs);
    for (size_t i = 0; i < losers.size(); i++)
    {
        binaryInsertPairs(losers, sortedPairs);
	}	
    return winners;
}

std::vector<unsigned int> PmergeMe::fordJohnson(std::vector<unsigned int>& vector)
{
    // sort vector 
    if (vector.size() <= 1){
        return vector;
    }

    bool isOdd = (vector.size() % 2 != 0);
    int unpaired = 0; 

    if (isOdd){
        unpaired = vector.back();
        vector.pop_back();
    }
    std::vector<std::pair<unsigned int, unsigned int>> sortedPairs;
    sortedPairs = pairsSwap(vector);
    std::vector<std::pair<unsigned int, unsigned int>> mainChain;
    mainChain = sortPairs(sortedPairs);

    return vector;
}

std::deque<unsigned int> PmergeMe::fordJohnson(std::deque<unsigned int>& deque)
{
    // sort deque
    std::cout << "deque fordjohnson" << std::endl;
    return deque;
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

    std::cout << "Before: ";
    for (auto i : sequence) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    std::cout << "After: ";
    for (auto i : sortedV) {
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
