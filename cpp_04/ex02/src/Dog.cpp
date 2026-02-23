#include "Dog.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes a Dog object with type "Dog" and allocates a new Brain.
 */
Dog::Dog(void) : Animal() {
	_type = "Dog";
	_dogBrain = new Brain();
	std::cout << "Dog default constructor called.\n\n";
}

/**
 * @brief Destructor.
 *
 * Deletes the dynamically allocated Brain to avoid memory leaks.
 */
Dog::~Dog(void) {
	delete _dogBrain;
	std::cout << "Dog default destructor called.\n\n";
}

/**
 * @brief Constructor with type.
 *
 * Initializes a Dog object with the given type and allocates a new Brain.
 *
 * @param type The type assigned to the dog (ignored, overridden as "Dog").
 */
Dog::Dog(std::string type) : Animal(type) {
	_type = "Dog";
	_dogBrain = new Brain();
	std::cout << "Dog type constructor called.\n\n";
};

/**
 * @brief Copy constructor.
 *
 * Creates a new Dog by copying another Dog, performing a deep copy of the Brain.
 *
 * @param other The Dog object to copy from.
 */
Dog::Dog(const Dog &other) : Animal(other) {
	_type = other._type;
	_dogBrain = new Brain(*other._dogBrain);
	std::cout << "Dog copy constructor called.\n\n";
};

/**
 * @brief Copy assignment operator.
 *
 * Performs deep copy of another Dog, including allocation of a new Brain.
 *
 * @param other The Dog object to assign from.
 * @return Reference to the assigned Dog.
 */
Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other);
		delete _dogBrain;
		_dogBrain = new Brain(*other._dogBrain);
	}
	std::cout	<< "Dog copy assigment operator called.\n\n";
	return (*this);
};

/**
 * @brief Make the dog sound.
 *
 * Overrides Animal::makeSound() with a dog-specific sound.
 */
void	Dog::makeSound(void) const {
	std::cout << "Dog hoooof hooooooff\n";
};

/**
 * @brief Get the idea from the dog.
 *
 * @return the idea stored on _dogBrain.
 */
Brain* Dog::getBrain() const {
    return _dogBrain;
}
