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
    PmergeMe    fJ;

    if(!fJ.isPositiveInteger(argc, argv, sequence, sequenceDeq))
        exit(1);

    timeVec = fJ.sortVector(sequence);
    timeDeq = fJ.sortDeque(sequenceDeq);

    fJ.printResults(sequence, timeVec, timeDeq);
    return 0;
}
