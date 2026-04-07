#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <limits>

class Span {
	private:
		unsigned int _max_N;
		std::vector<int> _number;

	public:
		Span() = delete;
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void	addNumber(int number);
		int	shortestSpan() const;
		int	longestSpan() const;
};
