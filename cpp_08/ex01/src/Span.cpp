#include "Span.hpp"

Span::Span(unsigned int N) : _max_N(N), _number() {}

Span::Span(const Span &other) : _max_N(other._max_N), _number(other._number){}

Span &Span::operator=(const Span &other) {
	if(this != &other)
	{
		_max_N = other._max_N;
		_number = other._number;
	}
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int number) {
	if(_number.size() >= _max_N)
		throw std::runtime_error("Cannot addNumber()");
	_number.push_back(number);
}

int	Span::shortestSpan() const {
	if(_number.size() < 2)
		throw std::runtime_error("Cannot find shortestSpan()");
	std::vector<int> tmp(_number);
	std::sort(tmp.begin(), tmp.end());

	int	shortest = std::numeric_limits<int>::max();

	for(size_t i = 1;i < tmp.size(); i++)
	{
		int	diff = tmp[i] - tmp[i - 1];
		if(diff < shortest)
			shortest = diff;
	}
	return shortest;
};

int	Span::longestSpan() const {
	if(_number.size() < 2)
		throw std::runtime_error("Cannot find longestSpan()");

	int	minVal = *std::min_element(_number.begin(), _number.end());
	int maxVal = *std::max_element(_number.begin(), _number.end());

	return maxVal - minVal;
};
