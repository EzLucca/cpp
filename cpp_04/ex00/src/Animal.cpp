#include "Animal.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes the Animal with a default type.
 */
Animal::Animal(void) : _type("default") {
	std::cout << "Animal default constructor called.\n";
}

/**
 * @brief Destructor.
 *
 * Called when the Animal object is destroyed.
 */
Animal::~Animal(void) {
	std::cout << "Animal default destructor called.\n";
}

/**
 * @brief Constructor with type.
 *
 * @param type The type assigned to the animal.
 */
Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal type constructor called.\n";
}

/**
 * @brief Copy constructor.
 *
 * Creates a new Animal by copying another one.
 *
 * @param other The Animal object to copy from.
 */
Animal::Animal(const Animal &other) {
	_type = other._type;
	std::cout << "Animal copy constructor called.\n";
}

/**
 * @brief Copy assignment operator.
 *
 * Assigns the values of another Animal to this instance.
 *
 * @param other The Animal object to assign from.
 * @return Reference to the assigned Animal.
 */
Animal &Animal::operator=(const Animal &other) {
	if (this != &other) {
		_type = other._type;
	}
	std::cout << "Animal copy assigment operator called.\n";
	return (*this);
}

/**
 * @brief Get the type of the animal.
 *
 * @return A string representing the animal type.
 */
std::string Animal::getType(void) const {
	return (_type);
}

/**
 * @brief Make the animal sound.
 *
 * Base implementation for Animal.
 * Intended to be overridden by derived classes.
 */
void Animal::makeSound(void) const {
	std::cout << "Animal ....\n";
}
