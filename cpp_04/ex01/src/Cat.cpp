#include "Cat.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes a Cat object with type "Cat" and allocates a new Brain.
 */
Cat::Cat(void) : Animal() {
	this->_type = "Cat";
	this->_catBrain = new Brain();
	std::cout << "Cat default constructor called.\n";
}

/**
 * @brief Destructor.
 *
 * Deletes the dynamically allocated Brain to avoid memory leaks.
 */
Cat::~Cat(void) {
	delete this->_catBrain;
	std::cout << "Cat default destructor called.\n";
}

/**
 * @brief Constructor with type.
 *
 * Initializes a Cat object with the given type and allocates a new Brain.
 *
 * @param type The type assigned to the cat (ignored, overridden as "Cat").
 */
Cat::Cat(std::string type) : Animal(type) {
	this->_type = "Cat";
	this->_catBrain = new Brain();
	std::cout << "Cat type constructor called.\n";
};

/**
 * @brief Copy constructor.
 *
 * Creates a new Cat by copying another Cat, performing a deep copy of the Brain.
 *
 * @param other The Cat object to copy from.
 */
Cat::Cat(const Cat &other) : Animal(other) {
	_type = other._type;
	this->_catBrain = new Brain(*other._catBrain);
	std::cout << "Cat copy constructor called.\n";
};

/**
 * @brief Copy assignment operator.
 *
 * Performs deep copy of another Cat, including allocation of a new Brain.
 *
 * @param other The Cat object to assign from.
 * @return Reference to the assigned Cat.
 */
Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		Animal::operator=(other);
		delete this->_catBrain;
		this->_catBrain = new Brain(*other._catBrain);
	}
	std::cout	<< "Cat copy assigment operator called.\n";
	return (*this);
};

/**
 * @brief Make the cat sound.
 *
 * Overrides Animal::makeSound() with a cat-specific sound.
 */
void	Cat::makeSound(void) const {
	std::cout << "Cat meow meow\n";
};
