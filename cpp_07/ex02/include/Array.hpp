#pragma once

#include <iostream>

template <typename T>
class Array {
	private:
		T*				_array;
		unsigned int	_size;

	public:
		Array(void);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array(void);

		Array(unsigned int n_size);
		T&	operator[](unsigned int index);
		unsigned int	size() const;
};

#include "Array.tpp"
