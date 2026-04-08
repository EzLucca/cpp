#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
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

		const std::vector<int>& getNumbers() const { return _number; };
		void	addNumber(int number);
		int	shortestSpan() const;
		int	longestSpan() const;

		template <typename Iterator>
			void	addNumberRange(Iterator begin, Iterator end) {
				for (Iterator it = begin; it != end; ++it) {
					addNumber(*it);
				}
			}
};
