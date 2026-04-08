#pragma once

#include <stack>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() = default;
		MutantStack(const MutantStack &original) = default;
		MutantStack &operator=(const MutantStack &original) = default;
		~MutantStack() = default;

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }

		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }
};
