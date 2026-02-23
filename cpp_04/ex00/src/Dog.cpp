#include "Dog.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes a Dog object and sets its type to "Dog".
 */
Dog::Dog(void) : Animal() {
	_type = "Dog";
	std::cout << "Dog default constructor called.\n";
}

/**
 * @brief Destructor.
 *
 * Called when the Dog object is destroyed.
 */
Dog::~Dog(void) {
	std::cout << "Dog default destructor called.\n";
}

/**
 * @brief Constructor with type.
 *
 * Calls the Animal constructor and sets the type to "Dog".
 *
 * @param type Unused parameter kept for interface consistency.
 */
Dog::Dog(std::string type) : Animal(type) {
	_type = "Dog";
	std::cout << "Dog type constructor called.\n";
}

/**
 * @brief Copy constructor.
 *
 * Creates a new Dog by copying another one.
 *
 * @param other The Dog object to copy from.
 */
Dog::Dog(const Dog &other) : Animal(other) {
	_type = other._type;
	std::cout << "Dog copy constructor called.\n";
}

/**
 * @brief Copy assignment operator.
 *
 * Assigns the values of another Dog to this instance.
 *
 * @param other The Dog object to assign from.
 * @return Reference to the assigned Dog.
 */
Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	std::cout << "Dog copy assigment operator called.\n";
	return (*this);
}

/**
 * @brief Make the dog sound.
 *
 * Overrides Animal::makeSound() with a dog-specific sound.
 */
void Dog::makeSound(void) const {
	std::cout << "Dog hoooof hooooooff\n";
}
