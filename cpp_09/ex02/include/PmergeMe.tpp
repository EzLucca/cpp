#pragma once

#include <iostream>
#include <algorithm>

    template <typename Container>
size_t PmergeMe::binaryInsert(typename Container::value_type value, Container& container,
        size_t limit)
{
    auto pos = std::lower_bound(
            container.begin(),
            container.begin() + limit,
            value 
            );

    size_t index = pos - container.begin();

    container.insert(pos, value);

    return index;
}

    template <typename Container>
void PmergeMe::printPairs(const Container& pairs)
{
    for (const auto& pair : pairs)
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    std::cout << '\n';
}

    template <typename Container>
void PmergeMe::printContainer(const Container& container)
{
    for (const auto& value : container)
        std::cout << value << " ";
    std::cout << '\n';
}
