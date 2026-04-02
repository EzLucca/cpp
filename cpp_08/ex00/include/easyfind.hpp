#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T &container, int needle)
{
	typename T::iterator it = std::find(container.begin(), container.end(), needle);
	if(it == container.end())
		throw std::runtime_error("Value not found");
	return it;
}

template<typename T>
typename T::const_iterator easyfind(const T &container, int needle)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), needle);
	if(it == container.end())
		throw std::runtime_error("Value not found");
	return it;
}
