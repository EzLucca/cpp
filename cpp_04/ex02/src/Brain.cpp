#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "Default idea";
	std::cout << "Brain default constructor called.\n";
}

Brain::Brain(const Brain &other) {
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
	std::cout	<< "Brain Copy constructor called.\n";
}

Brain &Brain::operator=(const Brain &other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	std::cout	<< "Brain Copy assigment operator called.\n";
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain default destructor called.\n";
}
