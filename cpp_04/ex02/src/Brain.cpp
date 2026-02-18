#include "Brain.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes a Brain object by filling all 100 ideas
 * with the default string "Default idea".
 */
Brain::Brain() {
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "Default idea";
	std::cout << "Brain default constructor called.\n";
}

/**
 * @brief Copy constructor.
 *
 * Creates a new Brain by copying the ideas from another Brain.
 *
 * @param other The Brain object to copy from.
 */
Brain::Brain(const Brain &other) {
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
	std::cout << "Brain Copy constructor called.\n";
}

/**
 * @brief Copy assignment operator.
 *
 * Performs a deep copy of another Brain's ideas into this Brain.
 *
 * @param other The Brain object to assign from.
 * @return Reference to the assigned Brain.
 */
Brain &Brain::operator=(const Brain &other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	std::cout << "Brain Copy assigment operator called.\n";
	return (*this);
}

/**
 * @brief Destructor.
 *
 * Cleans up the Brain object.
 */
Brain::~Brain() {
	std::cout << "Brain default destructor called.\n";
}
