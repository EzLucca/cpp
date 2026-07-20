#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "./program args[...]" << std::endl;
        return 1;
    }

    std::vector<unsigned int> sequence;
	std::deque<unsigned int> sequenceDeq;
    std::chrono::nanoseconds timeVec;
	std::chrono::nanoseconds timeDeq;
    PmergeMe    solve;

    if(!solve.isPositiveInteger(argc, argv, sequence, sequenceDeq))
    {
        std::cerr << "Invalid integer" << std::endl;
        exit(1);
    }

    timeVec = solve.sortVector(sequence);
    timeDeq = solve.sortDeque(sequenceDeq);

    solve.printResults(sequence, timeVec, timeDeq);
    return 0;
}
